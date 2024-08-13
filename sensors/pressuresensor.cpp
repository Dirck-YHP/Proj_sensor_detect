#include "pressuresensor.h"

PressureSensor::PressureSensor(QObject *parent) : QObject(parent)
{
    if (data_acquire_ai == nullptr) {
        data_acquire_ai = new DataAcquireAI;
        qDebug() << "(In PS)new acq_ai succeed";
    }

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &PressureSensor::rev_data_from_ni9205);
}

/***************************************************************
  *  @brief     设置标签
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void PressureSensor::set_label(QString label)
{
    _label = label;
}

/***************************************************************
  *  @brief     返回标签
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString PressureSensor::get_label() const
{
    return _label;
}

/***************************************************************
  *  @brief     设置量程
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void PressureSensor::set_range(QString pressure_4mA, QString pressure_20mA)
{
    _range.first = pressure_4mA.toInt();
    _range.second = pressure_20mA.toInt();
}

/***************************************************************
  *  @brief     返回量程
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QPair<int, int> PressureSensor::get_range() const
{
    return _range;
}

/***************************************************************
  *  @brief     设置通道：这里需要将用户选择的路 转换成 通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void PressureSensor::set_channel(QString channel)
{
    qDebug() << "(In PS)way choosed: " << channel;
    QVector<int> selected_channel_arr  = Assist::extractNumbers(channel);

    _channel = "";
    bool isFirst = true; // 用于判断是否是第一个元素，避免在字符串开头添加逗号

    for (int i = 1; i <= 5; ++i) {
        if (selected_channel_arr.contains(i)) {
            if (!isFirst) {
                _channel.append(",");
            }

            if (i == 1) _channel.append(chToStr(CH_PRES_SIGV_SIGC_PRE_1));
            if (i == 2) _channel.append(chToStr(CH_PRES_SIGV_SIGC_PRE_2));
            if (i == 3) _channel.append(chToStr(CH_PRES_SIGV_SIGC_PRE_3));
            if (i == 4) _channel.append(chToStr(CH_PRES_SIGV_SIGC_PRE_4));
            if (i == 5) _channel.append(chToStr(CH_PRES_SIGV_SIGC_PRE_5));

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
QString PressureSensor::get_channel() const
{
    return _channel;
}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
void PressureSensor::start_acquire()
{
//    data_acquire_ai = new DataAcquireAI;

    // 供电电压(0) + 压力传感器(26),...,(30) + 电池电量(31)
    channel_final = chToStr(CH_SUPV) + "," +
                            get_channel() + "," +
                            chToStr(CH_BAT);
    qDebug() << "fi: " << channel_final;

    data_acquire_ai->get_channel(channel_final);
    QThreadPool::globalInstance()->start(data_acquire_ai);

//    connect(data_acquire_ai, &DataAcquireAI::send_data,
//            this, &PressureSensor::rev_data_from_ni9205);
}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止9205的数据采集
  *  @Sample usage:
 **************************************************************/
void PressureSensor::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理（涉及多路转换）
  *  @param     无
  *  @note      根据通道分别转化成压力1、供电/信号回路的电压电流并发送给上层
  *             供电电压(0) + 压力传感器(26),...,(30) + 电池电量(31)
  *  @Sample usage:
 **************************************************************/
void PressureSensor::rev_data_from_ni9205(QVector<double> data)
{
    // 判断channel_final的size和data的size是否一致，根据channel_final的顺序取数据
//    qDebug() << "(In PS)接收数据size: " << data.size();
    if (data.size() != Assist::extractNumbers(channel_final).size()) {
        qDebug() << "(In PS):通道和接收数据的size不一致！";
        return;
    }

    int len = data.size();
    QVector<double> data_after_process;
    // 供电电压
    double sup_vol = data[0];
    data_after_process.append(sup_vol);

    // 信号电压、信号电流=供电电流、压力值 * (len - 2)
    for (int i = 1; i < len - 1; i++) {
        double sig_vol = data[i];
        double sig_cur = sig_vol / 1;
        double press = map_from_cur_to_press(sig_cur);
        data_after_process.append(sig_vol);
        data_after_process.append(sig_cur);
        data_after_process.append(press);
    }

    // 电池电量
    double bat = data[len - 1];
    data_after_process.append(bat);

    // 组合成一个vector发出去，data中数据顺序如下：
    // 供电电压、(信号电压、信号电流、压力) * (len - 1)、电池电量
    emit send_vol_cur_pres_to_ui(data_after_process);
}

/***************************************************************
  *  @brief     在win中connect，窗口关闭，删除对象
  *  @param     无
  *  @note      槽函数——负责删除对象
  *  @Sample usage:
 **************************************************************/
void PressureSensor::slot_acq_delete()
{
    qDebug() << "(In PS)get delete sig";

    if (data_acquire_ai != nullptr) {
        delete data_acquire_ai;
        qDebug() << "(In PS)delete acq_ai succeed!!!!!!!!!!";
    }
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      功能函数：实现电流到压力的映射（暂时还没映射）
  *  @Sample usage:
 **************************************************************/
double PressureSensor::map_from_cur_to_press(double current)
{
    return current;
}
