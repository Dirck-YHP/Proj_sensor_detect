#include "anglesensor.h"

AngleSensor::AngleSensor(QObject *parent) : QObject(parent)
{

}

void AngleSensor::set_label(QString label)
{
    _label = label;
}

QString AngleSensor::get_label() const
{
    return _label;
}

void AngleSensor::set_range(QString angle_4mA, QString angle_20mA)
{
    _range.first = angle_4mA.toInt();
    _range.second = angle_20mA.toInt();
}

QPair<int, int> AngleSensor::get_range() const
{
    return _range;
}

void AngleSensor::set_channel(QString channel)
{
    _channel = channel;
}

QString AngleSensor::get_channel() const
{
    return _channel;
}

void AngleSensor::start_acquire()
{
    data_acquire_ai = new DataAcquireAI;
    data_acquire_ai->get_channel(get_channel());
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &AngleSensor::rev_data_from_ni9205);
}

void AngleSensor::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

// 接收9205的电压信号，后续需要根据通道不同，单独转化成角度、供电/信号回路的电压电流
void AngleSensor::rev_data_from_ni9205(QVector<double> data)
{
    emit send_angle_to_ui(data);
    emit send_current_to_ui(data);
    emit send_voltage_to_ui(data);
}




























