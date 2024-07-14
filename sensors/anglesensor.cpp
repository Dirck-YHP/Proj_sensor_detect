#include "anglesensor.h"

AngleSensor::AngleSensor(QObject *parent) : QObject(parent)
{

}

/***************************************************************
  *  @brief     设置标签
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void AngleSensor::set_label(QString label)
{
    _label = label;
}

/***************************************************************
  *  @brief     返回标签
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString AngleSensor::get_label() const
{
    return _label;
}

/***************************************************************
  *  @brief     设置量程
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void AngleSensor::set_range(QString angle_4mA, QString angle_20mA)
{
    _range.first = angle_4mA.toInt();
    _range.second = angle_20mA.toInt();
}

/***************************************************************
  *  @brief     返回量程
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QPair<int, int> AngleSensor::get_range() const
{
    return _range;
}

/***************************************************************
  *  @brief     设置通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void AngleSensor::set_channel()
{
    _channel = chToStr(CH_AS_SIGV_SIGC_ANGLE) + "," +
               chToStr(CH_AS_SUPC);
}

/***************************************************************
  *  @brief     返回通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString AngleSensor::get_channel() const
{
    return _channel;
}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
void AngleSensor::start_acquire()
{
    data_acquire_ai = new DataAcquireAI;

    // 供电电压(0) + 角位移传感器(1,2) + 电池电量(31)
    QString channel_final = chToStr(CH_SUPV) + "," +
                            get_channel() + "," +
                            chToStr(CH_BAT);
    qDebug() << "fi: " << channel_final;

    data_acquire_ai->get_channel(channel_final);            // 把传感器获取到的通道传给数据采集
    QThreadPool::globalInstance()->start(data_acquire_ai);  // 丢进线程池

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &AngleSensor::rev_data_from_ni9205);
}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止9205的数据采集
  *  @Sample usage:
 **************************************************************/
void AngleSensor::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理
  *  @param     无
  *  @note      根据通道分别转化成:
  *           供电电压(0) + 角位移传感器(1,2) + 电池电量(31)
  *             角度、供电/信号回路的电压电流并发送给上层
  *  @Sample usage:
 **************************************************************/
void AngleSensor::rev_data_from_ni9205(QVector<double> data)
{


    emit send_angle_to_ui(data);
    emit send_current_to_ui(data);
    emit send_voltage_to_ui(data);
}










