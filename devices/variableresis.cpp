#include "variableresis.h"

VariableResis::VariableResis(QObject *parent) : QObject(parent)
{

}

void VariableResis::rev_data_from_ni9205(QVector<double> data)
{
    emit send_ni9205_to_ui(data);
}

void VariableResis::start_acquire()
{
    //--------------------------NI 9205--------------------------------------
    data_acquire_ai = new DataAcquireAI;
    QString channel_temp = "6";         // 暂定一个通道
    data_acquire_ai->get_channel(channel_temp);    // 把传感器获取到的通道传给数据采集
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &VariableResis::rev_data_from_ni9205);
}

void VariableResis::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}
