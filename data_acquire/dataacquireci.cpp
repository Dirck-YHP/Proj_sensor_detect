#include "dataacquireci.h"

DataAcquireCI::DataAcquireCI()
{
    setAutoDelete(true);
}

/***************************************************************
  *  @brief     初始化采集卡配置
  *  @param     无
  *  @note      目前通道是老板子上，后续需要更改
  *  @Sample usage:
 **************************************************************/
void DataAcquireCI::__init__(uInt32 pulses_per_rev) {
    // 创建任务
    DAQmxCreateTask("NI9401", &_task);
    DAQmxCreateCIAngEncoderChan(_task, "cDAQ2Mod1/ctr0", "CI", DAQmx_Val_X4, true, 0, DAQmx_Val_AHighBHigh, DAQmx_Val_Degrees, pulses_per_rev, 0, NULL);
    DAQmxSetCIEncoderAInputTerm(_task, "CI", "/cDAQ2Mod1/PFI0");
    DAQmxSetCIEncoderBInputTerm(_task, "CI", "/cDAQ2Mod1/PFI2");
    DAQmxSetCIEncoderZInputTerm(_task, "CI", "/cDAQ2Mod1/PFI4");

    // 开始任务
    DAQmxStartTask(_task);

    // 开始
    STOP = false;
}

/***************************************************************
  *  @brief     停止采集
  *  @param     无
  *  @note      结束采集卡的任务
  *  @Sample usage:
 **************************************************************/
void DataAcquireCI::stop_acquire()
{
    STOP = true;
    DAQmxStopTask(_task);
    DAQmxWaitUntilTaskDone(_task, -1);
    DAQmxClearTask(_task);
}

/***************************************************************
  *  @brief     每圈脉冲数
  *  @param     无
  *  @note      获取用户输入的每圈脉冲数
  *  @Sample usage:
 **************************************************************/
void DataAcquireCI::get_pulses_per_rev(uInt32 pulses_per_rev)
{
    _pulses_per_rev = pulses_per_rev;
}

/***************************************************************
  *  @brief     采集
  *  @param     无
  *  @note      线程池start之后自动执行该函数
  *  @Sample usage:
 **************************************************************/
void DataAcquireCI::run() {
    // 初始化配置
    __init__(_pulses_per_rev);

    while (!STOP) {
        DAQmxReadCounterF64(_task, -1, -1, data, DATA_SIZE, &_sampsPerChanRead, NULL);

//        qDebug() << "(In acq_ci)" << _sampsPerChanRead;
        // 发送信号到上层【一维数组】
        emit send_data(QVector<double>(data, data + _sampsPerChanRead));
    }

    // 延时20ms
    QThread::msleep(20);
}
