#include "dataacquiredi.h"

DataAcquireDI::DataAcquireDI()
{
    setAutoDelete(true);
}

/***************************************************************
  *  @brief     初始化采集卡配置
  *  @param     无
  *  @note      目前数字信号的通道还是老版，需改
  *  @Sample usage:
 **************************************************************/
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

/***************************************************************
  *  @brief     停止采集
  *  @param     无
  *  @note      结束采集卡的任务
  *  @Sample usage:
 **************************************************************/
void DataAcquireDI::stop_acquire()
{
    STOP = true;
    DAQmxStopTask(_task);
    DAQmxWaitUntilTaskDone(_task, -1);
    DAQmxClearTask(_task);
}

/***************************************************************
  *  @brief     采集
  *  @param     无
  *  @note      线程池start之后自动执行该函数
  *  @Sample usage:
 **************************************************************/
void DataAcquireDI::run() {
    // 初始化配置
    __init__();

    while (!STOP) {
        // 读取数据
        DAQmxReadDigitalLines(_task, _numSampsPerChan, -1, DAQmx_Val_GroupByChannel,
                              data, DATA_SIZE, &_sampsPerChanRead, &_numBytesPerSamp, NULL);

        // 将数据存到该二维数组中，size:(CHANNEL_NUM, _sampsPerChanRead)
        QVector<QVector<double>> data_final(CHANNEL_NUM, QVector<double>(_sampsPerChanRead, 0));
        for (int i = 0; i < CHANNEL_NUM; i++) {
            for (int j = 0; j < _sampsPerChanRead; j++) {
                data_final[i][j] = double(data[j + i * _sampsPerChanRead]);
            }
        }

        // 发送信号
        emit send_data(data_final);

        // 延时100us（高频）
        QThread::usleep(100);
    }
}

