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
    // 开始
    STOP = false;

    // ----- 计数器一：角度  -----
    DAQmxCreateTask("NI9401", &_task);
    int result = DAQmxCreateCIAngEncoderChan(_task, "cDAQ1Mod1/ctr0", "CI", DAQmx_Val_X4, false, 0, DAQmx_Val_AHighBHigh, DAQmx_Val_Degrees, pulses_per_rev, 0, NULL);
    result |= DAQmxSetCIEncoderAInputTerm(_task, "CI", "/cDAQ1Mod1/PFI0");
    result |= DAQmxSetCIEncoderBInputTerm(_task, "CI", "/cDAQ1Mod1/PFI2");
    result |= DAQmxSetCIEncoderZInputTerm(_task, "CI", "/cDAQ1Mod1/PFI4");

    //  ----- 计数器二：A相脉冲数  -----
    result |= DAQmxCreateTask("A_edge_detc", &_task_A_edge);
    result |= DAQmxCreateCICountEdgesChan(_task_A_edge, "cDAQ1Mod1/ctr1", "A_chan", DAQmx_Val_Rising, 0, DAQmx_Val_CountUp);
    result |= DAQmxSetCICountEdgesTerm(_task_A_edge, "A_chan", "/cDAQ1Mod1/PFI0");

    // 计数器三：两边沿间隔
    result |= DAQmxCreateTask("Two_edge_interval", &_task_two_edge_sep);
    result |= DAQmxCreateCITwoEdgeSepChan(_task_two_edge_sep, "cDAQ1Mod1/ctr2", "Two_edge_interval", 1e-6, 0.1, DAQmx_Val_Seconds,
                                          DAQmx_Val_Rising, DAQmx_Val_Rising, NULL);
    result |= DAQmxSetCITwoEdgeSepFirstTerm(_task_two_edge_sep, "Two_edge_interval", "/cDAQ1Mod1/PFI0");
    result |= DAQmxSetCITwoEdgeSepSecondTerm(_task_two_edge_sep, "Two_edge_interval", "/cDAQ1Mod1/PFI2");

    // 计数器四：周期
    result |= DAQmxCreateTask("Period", &_task_period);
    result |= DAQmxCreateCIPeriodChan(_task_period, "cDAQ1Mod1/ctr3", "Period", 1e-6, 0.1, DAQmx_Val_Seconds, DAQmx_Val_Rising,
                                      DAQmx_Val_LowFreq1Ctr, 0.001, 4, NULL);
    result |= DAQmxSetCIPeriodTerm(_task_period, "Period", "/cDAQ1Mod1/PFI0");


    if (result < 0) {
        emit sig_err(true);
        STOP = true;
    }

    // 开始任务
    DAQmxStartTask(_task);
    DAQmxStartTask(_task_A_edge);
    DAQmxStartTask(_task_period);
    DAQmxStartTask(_task_two_edge_sep);


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

    DAQmxStopTask(_task_period);
    DAQmxWaitUntilTaskDone(_task_period, -1);
    DAQmxClearTask(_task_period);

    DAQmxStopTask(_task_two_edge_sep);
    DAQmxWaitUntilTaskDone(_task_two_edge_sep, -1);
    DAQmxClearTask(_task_two_edge_sep);
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
        DAQmxReadCounterF64(_task_period, -1, 0, period, DATA_SIZE, &_sampsPerChanRead_period, NULL);
        DAQmxReadCounterF64(_task_two_edge_sep, -1, 0, two_edge_sep, DATA_SIZE, &_sampsPerChanRead_two_edge_sep, NULL);

        if (result < 0) {
            emit sig_err(true);
            STOP = true;
            continue;
        }

        emit send_data(QVector<double>(data, data + _sampsPerChanRead),
                       QVector<uInt32>(A_chan_detc, A_chan_detc + _sampsPerChanRead_A),
                       QVector<double>(period, period + _sampsPerChanRead_period),
                       QVector<double>(two_edge_sep, two_edge_sep + _sampsPerChanRead_two_edge_sep));

//        qDebug() << "(In acq_ci)" << two_edge_sep[0];
        // 延时20ms
        QThread::msleep(20);
    }
}
