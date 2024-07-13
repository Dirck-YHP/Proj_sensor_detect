#include "pressuresensor.h"

PressureSensor::PressureSensor(QObject *parent) : QObject(parent)
{

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
    _channel = channel;
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
    data_acquire_ai = new DataAcquireAI;
    data_acquire_ai->get_channel(get_channel());
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &PressureSensor::rev_data_from_ni9205);
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
  *  @Sample usage:
 **************************************************************/
void PressureSensor::rev_data_from_ni9205(QVector<double> data)
{
    // 目前还没做转化，直接发送原始数据
    emit send_ni9205_to_ui(data);
}
