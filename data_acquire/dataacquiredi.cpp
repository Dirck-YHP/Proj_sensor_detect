#include "dataacquiredi.h"

DataAcquireDI::DataAcquireDI()
{
    setAutoDelete(true);
}

void DataAcquireDI::__init__()
{
    // 创建任务
    DAQmxCreateTask("NI9403", &_task);

    // 配置通道
    for (int i = 0; i < CHANNEL_NUM; i++) {
        QString lines = "cDAQ2Mod2/port0/line" + QString::number(i + 18);
        DAQmxCreateDIChan(_task, lines.toUtf8(), "", DAQmx_Val_ChanPerLine);
    }

    // 配置定时器
    DAQmxCfgSampClkTiming(_task, NULL, _sample_rate, DAQmx_Val_Rising, DAQmx_Val_ContSamps, _sampsPerChanToAcquire);

    // 开始任务
    DAQmxStartTask(_task);

    // 开始
    STOP = false;

}

void DataAcquireDI::stop_acquire()
{
    STOP = true;
    DAQmxStopTask(_task);
    DAQmxWaitUntilTaskDone(_task, -1);
    DAQmxClearTask(_task);
}

void DataAcquireDI::run() {
    // 初始化配置
    __init__();

    while (!STOP) {
        // 读取数据
        DAQmxReadDigitalLines(_task, _numSampsPerChan, -1, DAQmx_Val_GroupByChannel,
                              data, DATA_SIZE, &_sampsPerChanRead, &_numBytesPerSamp, NULL);

        QVector<QVector<double>> data_final(CHANNEL_NUM, QVector<double>(_sampsPerChanRead, 0));
        for (int i = 0; i < CHANNEL_NUM; i++) {
            for (int j = 0; j < _sampsPerChanRead; j++) {
                data_final[i][j] = double(data[j + i * _sampsPerChanRead]);
            }
        }

        qDebug() << "-3 ";
        qDebug() << "-2 " + QString::number(data_final[0][0]);

        // 发送数据
        emit send_data(data_final);

        QThread::usleep(100);
    }
}

