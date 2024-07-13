#include "electricitycalc.h"

ElectricityCalc::ElectricityCalc(QObject *parent) : QObject(parent)
{

}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
void ElectricityCalc::start_acquire()
{
    data_acquire_ai = new DataAcquireAI;
    data_acquire_ai->get_channel(CHANNEL);
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &ElectricityCalc::rev_data_from_ni9205);
}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止9205的数据采集
  *  @Sample usage:
 **************************************************************/
void ElectricityCalc::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理
  *  @param     无
  *  @note      转化成电池电量，然后送给上层
  *  @Sample usage:
 **************************************************************/
void ElectricityCalc::rev_data_from_ni9205(QVector<double> data)
{
    // 目前还没做转化，直接发送原始数据
    emit send_battery_to_ui(data);
}


