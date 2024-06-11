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
