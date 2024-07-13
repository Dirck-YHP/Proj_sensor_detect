#include "variableresis.h"

VariableResis::VariableResis(QObject *parent) : QObject(parent)
{

}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
void VariableResis::start_acquire()
{
    //--------------------------NI 9205--------------------------------------
    data_acquire_ai = new DataAcquireAI;
    QString channel_temp = "6";         // 暂定一个通道
    data_acquire_ai->get_channel(channel_temp);    // 把传感器获取到的通道传给数据采集类
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &VariableResis::rev_data_from_ni9205);
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理
  *  @param     无
  *  @note      根据通道转化成距离，并发送给上层
  *  @Sample usage:
 **************************************************************/
void VariableResis::rev_data_from_ni9205(QVector<double> data)
{
    // 目前还没做转化，直接发送原始数据
    emit send_ni9205_to_ui(data);
}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止9205的数据采集
  *  @Sample usage:
 **************************************************************/
void VariableResis::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}
