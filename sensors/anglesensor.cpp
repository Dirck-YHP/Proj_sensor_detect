#include "anglesensor.h"

AngleSensor::AngleSensor(QObject *parent) : QObject(parent)
{
    data_acquire_ai = new DataAcquireAI;
    connect(data_acquire_ai, &DataAcquireAI::send_data, this, &AngleSensor::on_data_acquired);

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
//    data_acquire_ai = new DataAcquireAI;
    data_acquire_ai->get_channel(_channel);
    QThreadPool::globalInstance()->start(data_acquire_ai);
}

void AngleSensor::finish_acquire()
{
    data_acquire_ai->stop_acquire();
}

void AngleSensor::on_data_acquired(QVector<double> data)
{
    emit emit_data(data);
}



























