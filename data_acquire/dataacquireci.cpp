#include "dataacquireci.h"

DataAcquireCI::DataAcquireCI()
{
    setAutoDelete(false);
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

    // 开始
    STOP = false;

    int result = DAQmxCreateCIAngEncoderChan(_task, "cDAQ1Mod1/ctr0", "CI", DAQmx_Val_X4, false, 0, DAQmx_Val_AHighBHigh, DAQmx_Val_Degrees, pulses_per_rev, 0, NULL);

    result |= DAQmxSetCIEncoderAInputTerm(_task, "CI", "/cDAQ1Mod1/PFI0");
    result |= DAQmxSetCIEncoderBInputTerm(_task, "CI", "/cDAQ1Mod1/PFI2");
    result |= DAQmxSetCIEncoderZInputTerm(_task, "CI", "/cDAQ1Mod1/PFI4");

    result |= DAQmxCreateTask("A_edge_detc", &_task_A_edge);
    result |= DAQmxCreateTask("B_edge_detc", &_task_B_edge);
    result |= DAQmxCreateCICountEdgesChan(_task_A_edge, "cDAQ1Mod1/ctr1", "A_chan", DAQmx_Val_Rising, 0, DAQmx_Val_CountUp);
    result |= DAQmxCreateCICountEdgesChan(_task_B_edge, "cDAQ1Mod1/ctr2", "B_chan", DAQmx_Val_Rising, 0, DAQmx_Val_CountUp);
    result |= DAQmxSetCICountEdgesTerm(_task_A_edge, "A_chan", "/cDAQ1Mod1/PFI0");
    result |= DAQmxSetCICountEdgesTerm(_task_B_edge, "B_chan", "/cDAQ1Mod1/PFI2");

    if (result < 0) {
        emit sig_err(true);
        STOP = true;
    }

    // 开始任务
    DAQmxStartTask(_task);
    DAQmxStartTask(_task_A_edge);
    DAQmxStartTask(_task_B_edge);


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

    DAQmxStopTask(_task_A_edge);
    DAQmxWaitUntilTaskDone(_task_A_edge, -1);
    DAQmxClearTask(_task_A_edge);

    DAQmxStopTask(_task_B_edge);
    DAQmxWaitUntilTaskDone(_task_B_edge, -1);
    DAQmxClearTask(_task_B_edge);
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
    int result = 0;

    while (!STOP) {
        result |= DAQmxReadCounterF64(_task, -1, -1, data, DATA_SIZE, &_sampsPerChanRead, NULL);
        result |= DAQmxReadCounterU32(_task_A_edge, -1, -1, A_chan_detc, DATA_SIZE, &_sampsPerChanRead_A, NULL);
        result |= DAQmxReadCounterU32(_task_B_edge, -1, -1, B_chan_detc, DATA_SIZE, &_sampsPerChanRead_B, NULL);

        if (result < 0) {
            emit sig_err(true);
            STOP = true;
            continue;
        }

//        qDebug() << "(In acq_ci)" << _sampsPerChanRead;
        // 发送信号到上层【一维数组】
        emit send_data(QVector<double>(data, data + _sampsPerChanRead),
                       QVector<uInt32>(A_chan_detc, A_chan_detc + _sampsPerChanRead_A),
                       QVector<uInt32>(B_chan_detc, B_chan_detc + _sampsPerChanRead_B));

        // 延时20ms
        QThread::msleep(20);
    }
}
