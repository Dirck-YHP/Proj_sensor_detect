#include "angleencoder.h"

AngleEncoder::AngleEncoder(QObject *parent) : QObject(parent)
{

}

void AngleEncoder::set_label(QString label)
{
    _label = label;
}

QString AngleEncoder::get_label() const
{
    return _label;
}

void AngleEncoder::set_pul_per_cir(QString pul_per_rev)
{
    _pulse_per_rev = pul_per_rev;
}

QString AngleEncoder::get_pul_per_cir() const
{
    return _pulse_per_rev;
}

void AngleEncoder::set_channel(QString channel)
{
    _channel = channel;
}

QString AngleEncoder::get_channel() const
{
    return _channel;
}

void AngleEncoder::start_acquire()
{
    //--------------------------NI 9205--------------------------------------
    data_acquire_ai = new DataAcquireAI;
    data_acquire_ai->get_channel(get_channel());    // 把传感器获取到的通道传给数据采集
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &AngleEncoder::rev_data_from_ni9205);

    //--------------------------NI 9403--------------------------------------
    data_acquire_di = new DataAcquireDI;

    QThreadPool::globalInstance()->start(data_acquire_di);

    connect(data_acquire_di, &DataAcquireDI::send_data,
            this, &AngleEncoder::rev_data_from_ni9403);

    //--------------------------NI 9401--------------------------------------
    data_acquire_ci = new DataAcquireCI;
    data_acquire_ci->get_pulses_per_rev(get_pul_per_cir().toUInt());

    QThreadPool::globalInstance()->start(data_acquire_ci);

    connect(data_acquire_ci, &DataAcquireCI::send_data,
            this, &AngleEncoder::rev_data_from_ni9401);
}

void AngleEncoder::stop_acquire()
{
    data_acquire_ai->stop_acquire();
    data_acquire_di->stop_acquire();
    data_acquire_ci->stop_acquire();
}


// 接收9205的电压信号，后续需要根据通道不同，单独转化成角度、供电/信号回路的电压电流分别发送出去
void AngleEncoder::rev_data_from_ni9205(QVector<double> data)
{
    emit send_ni9205_to_ui(data);
}

// 接收9403的数字信号，后续似乎不需要做处理，直接转发就行
void AngleEncoder::rev_data_from_ni9403(QVector<QVector<double> > data_final)
{
    emit send_ni9403_to_ui(data_final);
}

// 接收9403的计数信号，后续似乎也不需要做处理，已经是角度值了
void AngleEncoder::rev_data_from_ni9401(QVector<double> data)
{
    emit send_ni9401_to_ui(data);
}






