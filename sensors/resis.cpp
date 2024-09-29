#include "resis.h"

Resis::Resis(QObject *parent) : QObject(parent)
{
    if (data_acquire_ai == nullptr) {
        data_acquire_ai = new DataAcquireAI;
        qDebug() << "(In resis)new acq_ai succeed";
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
    qDebug() << "(In resis)way choosed: " << channel;
    QVector<int> selected_channel_arr  = Assist::extractNumbers(channel);

    _channel = "";
    bool isFirst = true; // 用于判断是否是第一个元素，避免在字符串开头添加逗号

    for (int i = 1; i <= 5; ++i) {
        if (selected_channel_arr.contains(i)) {
            if (!isFirst) {
                _channel.append(",");
            }

            if (i == 1) _channel.append(chToStr(CH_R_1));
            if (i == 2) _channel.append(chToStr(CH_R_2));
            if (i == 3) _channel.append(chToStr(CH_R_3));
            if (i == 4) _channel.append(chToStr(CH_R_4));
            if (i == 5) _channel.append(chToStr(CH_R_5));

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
    qDebug() << "(In resis)fi: " << channel_final;

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
        qDebug() << "in resis:通道和接收数据的size不一致！";
        return;
    }

    int len = data.size();
    QVector<double> data_after_process;

    // 判断哪些通道被选中
    QVector<QString> channel_choosed;
    QString selected_channel_str = get_channel();
    QVector<int> selected_channel_arr  = Assist::extractNumbers(selected_channel_str);

    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        if (selected_channel_arr.contains(ch_num + 9)) {
            QString dir = "cDAQ1Mod2/port0/line" +
                    QString::number(4+2*ch_num) + ":" +
                    QString::number(5+2*ch_num);
//            qDebug() << "(In resis)dir: " << dir;

            channel_choosed.append(dir);
        }
    }

    // 电阻
    for (int i = 0; i <= len - 2; i++) {
        double vol = data[i];
        double resis = map_from_vol_to_resis(vol, channel_choosed[i]);
        data_after_process.append(resis);
    }

    // 电池电量
    double bat = data[len - 1];
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
    qDebug() << "(In resis)get delete sig";

    if (data_acquire_ai != nullptr) {
        delete data_acquire_ai;
        qDebug() << "(In resis)delete acq_ai succeed!!!!!!!!!!";
    }
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      功能函数：实现电压到电阻的映射
  *  @Sample usage:
 **************************************************************/
double Resis::map_from_vol_to_resis(double voltage, QString DI_str)
{
    double vol = std::min(voltage, 4.9999);
    double resis = 0;
    qDebug() << rType;
    switch (rType) {
    case RType::high:
        resis = vol * (1e6 + 3.5) / (5 - vol);
        // 下面对电阻值进行修正

        break;
    case RType::middle:
        resis = vol * (1e4 + 3.5) / (5 - vol);
        // 下面对电阻值进行修正

        break;
    case RType::low:
        resis = vol / ((1.25 / 120) + 5e-4);
        // 下面对电阻值进行修正

        break;
    default:
        break;
    }


    RType rTempType = RType::middle;
    // 下面的判断条件待定
    if (resis < 200) {
        rTempType = RType::low;
    }else if(resis < 5e4 && resis > 220) {
        rTempType = RType::middle;
    }else if (resis > 5e4 && resis < 2e7) {
        rTempType = RType::high;
    }

    uInt8 writeArray[2] = {0, 0};
    // 下面进行测电阻档位选择
    if(rTempType != rType && allowChange){
        m_timer->start();
        allowChange = false;
        rType = rTempType;
        TaskHandle taskHandleSwitch;
        DAQmxCreateTask("ASSIST", &taskHandleSwitch);

        // 这里的数字io要根据用户的选择来变动
        DAQmxCreateDOChan(taskHandleSwitch, DI_str.toStdString().c_str(), "", DAQmx_Val_ChanPerLine);

        int32 writeSuccessNum;
        if(rType == RType::low){
            writeArray[0] = 0;
            writeArray[1] = 1;
            qDebug() << "(In resis)R LOW!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }else if(rType == RType::middle){
            writeArray[0] = 1;
            writeArray[1] = 0;
            qDebug() << "(In resis)R MIDDLE!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }else if(rType == RType::high){
            writeArray[0] = 0;
            writeArray[1] = 0;
            qDebug() << "(In resis)R HIGH!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }
        int error = DAQmxWriteDigitalLines(taskHandleSwitch, 1, true, -1,
                                           DAQmx_Val_GroupByChannel, writeArray, &writeSuccessNum, NULL);
        qDebug() << QString::number(error);
        DAQmxClearTask(taskHandleSwitch);
    }

        qDebug() << "(In resis)vol: " << vol << ", resis: " << resis << "x: " << writeArray[0] << " " << writeArray[1];

    return resis;
}
