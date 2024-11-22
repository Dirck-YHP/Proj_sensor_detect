#include "resis.h"

Resis::Resis(QObject *parent) : QObject(parent)
{
    rType = QVector<RType>(5, RType::middle);

    if (data_acquire_ai == nullptr) {
        data_acquire_ai = new DataAcquireAI;
        // qDebug() << "(In resis)new acq_ai succeed";
    }

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &Resis::rev_data_from_ni9205);

    // 设置定时器，为了能够切换电阻挡位的时候维持两秒，不至于跳变
    m_timer = new QTimer(this);
    m_timer->setInterval(2000);
    allowChange = true;
    connect(m_timer, &QTimer::timeout, this, [=](){
        allowChange = true;
        m_timer->stop();
    });

}

/***************************************************************
  *  @brief     设置通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void Resis::set_channel(QString channel)
{
    // qDebug() << "(In resis)way choosed: " << channel;
    QVector<int> selected_channel_arr  = Assist::extractNumbers(channel);

    _channel = "";
    bool isFirst = true; // 用于判断是否是第一个元素，避免在字符串开头添加逗号

    for (int i = 1; i <= 5; ++i) {
        if (selected_channel_arr.contains(i)) {
            if (!isFirst) {
                _channel.append(",");
            }

            /*  这里由于硬件连线问题，映射顺序做个调换
                用户选择的 1   映射到   实际的 5
                用户选择的 2   映射到   实际的 4
                ...
                以此类推
            */
            if (i == 1) _channel.append(chToStr(CH_R_5));
            if (i == 2) _channel.append(chToStr(CH_R_4));
            if (i == 3) _channel.append(chToStr(CH_R_3));
            if (i == 4) _channel.append(chToStr(CH_R_2));
            if (i == 5) _channel.append(chToStr(CH_R_1));

            isFirst = false;
        }
    }
}

/***************************************************************
  *  @brief     返回通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString Resis::get_channel() const
{
    return _channel;
}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
void Resis::start_acquire()
{
//    data_acquire_ai = new DataAcquireAI;

    // 电阻：(10),...,(14) + 电池电量(31)
    channel_final = get_channel() + "," +
                            chToStr(CH_BAT);
    // qDebug() << "(In resis)fi: " << channel_final;

    data_acquire_ai->get_channel(channel_final);
    QThreadPool::globalInstance()->start(data_acquire_ai);
}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止9205的数据采集
  *  @Sample usage:
 **************************************************************/
void Resis::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理（涉及多路转换）
  *  @param     无
  *  @note      根据选择的通道分别转化成:
  *             电压并计算出电阻然后送给上层
  *             电阻：(10),...,(14) + 电池电量(31)
  *  @Sample usage:
 **************************************************************/
void Resis::rev_data_from_ni9205(QVector<double> data)
{
    // 判断channel_final的size和data的size是否一致，根据channel_final的顺序取数据
//    qDebug() << "(In resis)通道size: " << channel_final.length() << " 接收数据size: " << data.size();
    if (data.size() != Assist::extractNumbers(channel_final).size()) {
        // qDebug() << "in resis:通道和接收数据的size不一致！";
        return;
    }

    int len = data.size();
    QVector<double> data_after_process;

    // 判断哪些通道被选中
    QVector<QString> channel_choosed;
    QString selected_channel_str = get_channel();
    QVector<int> selected_channel_arr  = Assist::extractNumbers(selected_channel_str);

    // qDebug() << "(In resis)resis_vec: " << selected_channel_arr;
    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        // y1 = 15 - x
        if (selected_channel_arr.contains(15 - ch_num)) {
            // y2 = -2x + 16;       y2 = -2x + 17
            QString dir = "cDAQ1Mod2/port0/line" +
                    QString::number(-2*ch_num + 16) + ":" +
                    QString::number(-2*ch_num + 17);
            // qDebug() << "(In resis)dir: " << dir;

            channel_choosed.append(dir);
        }
    }

    // qDebug() << len;
    // 电阻
    for (int i = 0; i <= len - 2; i++) {
        double vol = data[i];
        double resis = map_from_vol_to_resis(vol, channel_choosed[i], i);
        data_after_process.append(resis);
    }

    // qDebug() << "--------";

    // 电池电量
    double bat = data[len - 1] * 3;
    data_after_process.append(bat);

    // 组合成一个vector发出去，data中数据顺序如下：
    // 电阻 * (len - 1)、电池电量
    emit send_resis_to_ui(data_after_process);
}

/***************************************************************
  *  @brief     在win中connect，窗口关闭，删除对象
  *  @param     无
  *  @note      槽函数——负责删除对象
  *  @Sample usage:
 **************************************************************/
void Resis::slot_acq_delete()
{
    // qDebug() << "(In resis)get delete sig";

    if (data_acquire_ai != nullptr) {
        delete data_acquire_ai;
        // qDebug() << "(In resis)delete acq_ai succeed!!!!!!!!!!";
    }
}

void Resis::slot_get_r_idx(int idx)
{
    qDebug() << "(In resis)idx: " << idx;
    _idx = idx;
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      功能函数：实现电压到电阻的映射
  *  @Sample usage:
 **************************************************************/
double Resis::map_from_vol_to_resis(double voltage, QString DI_str, int idx)
{
    double vol = std::min(voltage, 4.9999);
    double resis = 0;

    switch (rType[idx]) {
    case RType::high:
        resis = vol * (1e6 + 3.5) / (5 - vol);
        // 下面对电阻值进行修正
        if (resis > 2e5)
            resis = resis * 0.8576 + 32971;

        break;
    case RType::middle:
        resis = vol * (1e4 + 3.5) / (5 - vol);
        // 下面对电阻值进行修正
        resis = resis * 1.008 - 1.8016;

        break;
    case RType::low:
        resis = vol / ((1.25 / 120) + 5e-4);
        // 下面对电阻值进行修正
        resis = resis * 1.0603 - 0.886;

        break;
    default:
        break;
    }


    RType rTempType = RType::middle;

    // 测试代码
    // if (_idx == 0)
    //     rTempType = RType::high;
    // else if (_idx == 1)
    //     rTempType = RType::middle;
    // else if (_idx == 2)
    //     rTempType = RType::low;

    // 下面的判断条件待定
    if (resis < 70) {
        rTempType = RType::low;
    }else if(resis < 2e3 && resis > 80) {
        rTempType = RType::middle;
    }else if (resis > 6e3 && resis < 2e7) {
        rTempType = RType::high;
    }

   // qDebug() << "(In resis)rT: " << rType[idx] << " r: " << rTempType << ", resis: " << resis;

    uInt8 writeArray[2] = {0, 0};
    // 下面进行测电阻档位选择
    if(rTempType != rType[idx] && allowChange){
        m_timer->start();
        allowChange = false;
        rType[idx] = rTempType;
        TaskHandle taskHandleSwitch;
        DAQmxCreateTask("ASSIST", &taskHandleSwitch);

        // 这里的数字io要根据用户的选择来变动
        DAQmxCreateDOChan(taskHandleSwitch, DI_str.toStdString().c_str(), "", DAQmx_Val_ChanPerLine);

        int32 writeSuccessNum;
        if(rType[idx] == RType::low){
            writeArray[0] = 0;
            writeArray[1] = 1;
            // qDebug() << "(In resis)R LOW!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }else if(rType[idx] == RType::middle){
            writeArray[0] = 1;
            writeArray[1] = 0;
            // qDebug() << "(In resis)R MIDDLE!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }else if(rType[idx] == RType::high){
            writeArray[0] = 0;
            writeArray[1] = 0;
            // qDebug() << "(In resis)R HIGH!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }
        int error = DAQmxWriteDigitalLines(taskHandleSwitch, 1, true, -1,
                                           DAQmx_Val_GroupByChannel, writeArray, &writeSuccessNum, NULL);
        DAQmxClearTask(taskHandleSwitch);
    }
    return resis;
}
