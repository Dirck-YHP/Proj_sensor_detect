#include "resis.h"

Resis::Resis(QObject *parent) : QObject(parent)
{

}

void Resis::set_channel(QString channel)
{
    _channel = channel;
}

QString Resis::get_channel() const
{
    return _channel;
}

void Resis::start_acquire()
{
    data_acquire_ai = new DataAcquireAI;
    data_acquire_ai->get_channel(get_channel());
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &Resis::rev_data_from_ni9205);
}

void Resis::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

// 接收9205的电压信号，后续需要根据通道不同，单独转化成压力、供电/信号回路的电压电流
void Resis::rev_data_from_ni9205(QVector<double> data)
{
    // 目前还没做转化，直接发送原始数据
    emit send_ni9205_to_ui(data);
}
