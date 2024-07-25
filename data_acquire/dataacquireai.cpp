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

//        qDebug() << "(In acq_ai) sampPerChanRead: " << _sampsPerChanRead << "chan: " << _channel_num;
        // LowPass
        for (int i = 0; i < _sampsPerChanRead * _channel_num; i++) {
            data[i] = _filters[i / _sampsPerChanRead].update(data[i]);
        }

        // 发送数据
        if(_sampsPerChanRead > 0) emit send_data(QVector<double>(data, data + _sampsPerChanRead * _channel_num));
        else qDebug() << "没有采集到数据！";

        QThread::msleep(20);
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

    qDebug() << "(In acq_ai)idx: " << idx;
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
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 31:
        U = 10;
        break;
    }

    return U;
}

/***************************************************************
  *  @brief     将枚举类型转换成字符串
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString chToStr(CHANNEL_9205 channel)
{
    switch (channel) {
        case CH_SUPV: return QStringLiteral("0");

        case CH_AS_SIGV_SIGC_ANGLE: return QStringLiteral("1");
        case CH_AS_SUPC: return QStringLiteral("2");

        case CH_AE_SIGV_SIGC_A:  return QStringLiteral("3");
        case CH_AE_SIGV_SIGC_A_: return QStringLiteral("4");
        case CH_AE_SIGV_SIGC_B:  return QStringLiteral("5");
        case CH_AE_SIGV_SIGC_B_: return QStringLiteral("6");
        case CH_AE_SIGV_SIGC_C:  return QStringLiteral("7");
        case CH_AE_SIGV_SIGC_C_: return QStringLiteral("8");
        case CH_AE_SUPC: return QStringLiteral("9");

        case CH_R_1: return QStringLiteral("10");
        case CH_R_2: return QStringLiteral("11");
        case CH_R_3: return QStringLiteral("12");
        case CH_R_4: return QStringLiteral("13");
        case CH_R_5: return QStringLiteral("14");

        case CH_PS_SIGV_SIGC_PUL_1: return QStringLiteral("15");
        case CH_PS_SUPC_1: return QStringLiteral("16");
        case CH_PS_SIGV_SIGC_PUL_2: return QStringLiteral("17");
        case CH_PS_SUPC_2: return QStringLiteral("18");
        case CH_PS_SIGV_SIGC_PUL_3: return QStringLiteral("19");
        case CH_PS_SUPC_3: return QStringLiteral("20");
        case CH_PS_SIGV_SIGC_PUL_4: return QStringLiteral("21");
        case CH_PS_SUPC_4: return QStringLiteral("22");
        case CH_PS_SIGV_SIGC_PUL_5: return QStringLiteral("23");
        case CH_PS_SUPC_5: return QStringLiteral("24");

        case CH_VR_DIS: return QStringLiteral("25");

        case CH_PRES_SIGV_SIGC_PRE_1: return QStringLiteral("26");
        case CH_PRES_SIGV_SIGC_PRE_2: return QStringLiteral("27");
        case CH_PRES_SIGV_SIGC_PRE_3: return QStringLiteral("28");
        case CH_PRES_SIGV_SIGC_PRE_4: return QStringLiteral("29");
        case CH_PRES_SIGV_SIGC_PRE_5: return QStringLiteral("30");

        case CH_BAT: return QStringLiteral("31");
    }

}
