#include "dataacquireci.h"

DataAcquireCI::DataAcquireCI()
{
    setAutoDelete(true);
}

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

void DataAcquireCI::stop_acquire()
{
    STOP = true;
    DAQmxStopTask(_task);
    DAQmxWaitUntilTaskDone(_task, -1);
    DAQmxClearTask(_task);
}

void DataAcquireCI::get_pulses_per_rev(uInt32 pulses_per_rev)
{
    _pulses_per_rev = pulses_per_rev;
}


void DataAcquireCI::run() {
    // 初始化配置
    __init__(_pulses_per_rev);

    while (!STOP) {
        DAQmxReadCounterF64(_task, -1, -1, data, DATA_SIZE, &_sampsPerChanRead, NULL);
        emit send_data(QVector<double>(data, data + _sampsPerChanRead));
    }

    QThread::usleep(1000);
}
