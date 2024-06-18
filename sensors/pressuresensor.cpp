#include "pressuresensor.h"

PressureSensor::PressureSensor(QObject *parent) : QObject(parent)
{

}

void PressureSensor::set_label(QString label)
{
    _label = label;
}

QString PressureSensor::get_label() const
{
    return _label;
}

void PressureSensor::set_range(QString pressure_4mA, QString pressure_20mA)
{
    _range.first = pressure_4mA.toInt();
    _range.second = pressure_20mA.toInt();
}

QPair<int, int> PressureSensor::get_range() const
{
    return _range;
}

void PressureSensor::set_channel(QString channel)
{
    _channel = channel;
}

QString PressureSensor::get_channel() const
{
    return _channel;
}

void PressureSensor::start_acquire()
{
    data_acquire_ai = new DataAcquireAI;
    data_acquire_ai->get_channel(get_channel());

    // 未完待续
}

void PressureSensor::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}
