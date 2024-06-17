#include "proximityswitch.h"

ProximitySwitch::ProximitySwitch(QObject *parent) : QObject(parent)
{

}

void ProximitySwitch::set_label(QString label)
{
    _label = label;
}

QString ProximitySwitch::get_label() const
{
    return _label;
}

void ProximitySwitch::set_sensing_dis(QString sensing_dis)
{
    _sensing_distance = sensing_dis;
}

QString ProximitySwitch::get_sensing_dis() const
{
    return _sensing_distance;
}

void ProximitySwitch::set_using_time(QString using_time)
{
    _using_time = using_time;
}

QString ProximitySwitch::get_using_time() const
{
    return _using_time;
}

void ProximitySwitch::set_sensing_matirial(QString sensing_matirial)
{
    _sensing_matirial = sensing_matirial;
}

QString ProximitySwitch::get_sensing_matirial() const
{
    return _sensing_matirial;
}

void ProximitySwitch::start_acquire()
{
    //--------------------------NI 9205--------------------------------------
    data_acquire_ai = new DataAcquireAI;
    QString channel_temp = "6";
    data_acquire_ai->get_channel(channel_temp);    // 把传感器获取到的通道传给数据采集
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &ProximitySwitch::rev_data_from_ni9205);
}

void ProximitySwitch::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}
