#include "resis.h"

Resis::Resis(QObject *parent) : QObject(parent)
{

}

/***************************************************************
  *  @brief     设置通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void Resis::set_channel(QString channel)
{
    _channel = channel;
}

/***************************************************************
  *  @brief     返回通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString Resis::get_channel() const
{
    return _channel;
}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
void Resis::start_acquire()
{
    data_acquire_ai = new DataAcquireAI;
    data_acquire_ai->get_channel(get_channel());
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &Resis::rev_data_from_ni9205);
}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止9205的数据采集
  *  @Sample usage:
 **************************************************************/
void Resis::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理（涉及多路转换）
  *  @param     无
  *  @note      根据通道分别转化成电压并计算出电阻然后送给上层
  *  @Sample usage:
 **************************************************************/
void Resis::rev_data_from_ni9205(QVector<double> data)
{
    // 目前还没做转化，直接发送原始数据
    emit send_ni9205_to_ui(data);
}
