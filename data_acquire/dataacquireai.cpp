#include "dataacquireai.h"
#include "QDebug"

DataAcquireAI::DataAcquireAI(QObject *parent) : QObject(parent)
{
    setAutoDelete(true);

    _task = NULL;
    _channel = "";
}

/***************************************************************
  *  @brief     采集
  *  @param     无
  *  @note      线程池start之后自动执行该函数
  *  @Sample usage:
 **************************************************************/
void DataAcquireAI::run()
{
    // 初始化配置
    __init__(_channel);

    while (!STOP) {
        // 读数据
        DAQmxReadAnalogF64(_task, _numSampsPerChan, -1, DAQmx_Val_GroupByChannel,
                           data, DATA_SIZE, &_sampsPerChanRead, NULL);
        // 获取通道
        DAQmxGetTaskNumChans(_task, &_channel_num);

        // LowPass
        for (int i = 0; i < _sampsPerChanRead * _channel_num; i++) {
            data[i] = _filters[i / _sampsPerChanRead].update(data[i]);
        }

        // 发送数据
        if(_sampsPerChanRead > 0) emit send_data(QVector<double>(data, data + _sampsPerChanRead * _channel_num));
        else L_ERROR("没有采集到数据！");

        QThread::msleep(10);
    }
}

/***************************************************************
  *  @brief     初始化采集卡配置
  *  @param     无
  *  @note      将用户输入的通道映射成实际板子上的通道
  *  @Sample usage:
 **************************************************************/
void DataAcquireAI::__init__(QString channel)
{
    QVector<int> idx;

    // 创建任务
    DAQmxCreateTask("NI9205", &_task);

    // 将字符串形式的通道转化成数组
    idx = str_to_int(channel);

    // 配置通道
    for (int i = 0; i < idx.size(); i++) {
        double U = choose_min_max(idx[i]);
        QString physicalChannel = "cDAQ2Mod3/ai" + QString::number(idx[i]);
        DAQmxCreateAIVoltageChan(_task, physicalChannel.toUtf8(), "",
                                 DAQmx_Val_RSE, -U, U, DAQmx_Val_Volts, NULL);
    }

    // 配置定时器
    DAQmxCfgSampClkTiming(_task, NULL, _sample_rate, DAQmx_Val_Rising, DAQmx_Val_ContSamps, _sampsPerChanToAcquire);

    // 开始任务
    DAQmxStartTask(_task);

    // 开始
    STOP = false;

    // 创建滤波器
    for (int i = 0; i < idx.size(); i++) {
        _filters.push_back(LowpassFilter(taps));
    }
}

/***************************************************************
  *  @brief     获取通道（未拆分的字符串）
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void DataAcquireAI::get_channel(QString channel)
{
    _channel = channel;
}

/***************************************************************
  *  @brief     停止采集
  *  @param     无
  *  @note      结束采集卡的任务
  *  @Sample usage:
 **************************************************************/
void DataAcquireAI::stop_acquire()
{
    STOP = true;
    DAQmxStopTask(_task);
    DAQmxWaitUntilTaskDone(_task, -1);
    DAQmxClearTask(_task);
}

/***************************************************************
  *  @brief     将通道字符串转成数组
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QVector<int> DataAcquireAI::str_to_int(QString channel)
{
    QVector<int> ans;
    ans = Assist::extractNumbers(channel);

    return ans;
}

/***************************************************************
  *  @brief     确定最值
  *  @param     无
  *  @note      根据通道来确定采集的量程（硬件层面就确定好）
  *  @Sample usage:
 **************************************************************/
double DataAcquireAI::choose_min_max(int channel)
{
    double U = 0.0;
    switch (channel) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        U = 5.0;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        U = 10.0;
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        U = 0.2;
        break;
    }

    return U;
}
