#ifndef DATAACQUIREAI_H
#define DATAACQUIREAI_H

#include <QObject>
#include <NIDAQmx.h>
#include <QRunnable>
#include <QRegExp>
#include <QThread>
#include <QMessageBox>
#include "lowpassfilter.h"
#include "simpleQtLogger.h"
#include "assist.h"
#include "errorprompt.h"


enum CHANNEL_9205 {
    CH_SUPV,                        // 供电电压

    CH_AS_SIGV_SIGC_ANGLE,          // 角位移传感器 信号电压、信号电流、角度
    CH_AS_SUPC,                     // 角位移传感器 供电电流

    CH_AE_SIGV_SIGC_A,              // 角位移编码器 信号电压、信号电流 * 6
    CH_AE_SIGV_SIGC_A_,
    CH_AE_SIGV_SIGC_B,
    CH_AE_SIGV_SIGC_B_,
    CH_AE_SIGV_SIGC_C,
    CH_AE_SIGV_SIGC_C_,
    CH_AE_SUPC,                     // 角位移编码器 供电电流

    CH_R_1,                         // 测电阻，1~5路
    CH_R_2,
    CH_R_3,
    CH_R_4,
    CH_R_5,

    CH_PS_SIGV_SIGC_PUL_1,          // 接近开关 信号电压、信号电流、是否触发，1~5路
    CH_PS_SUPC_1,                   // 接近开关 供电电流，1~5路
    CH_PS_SIGV_SIGC_PUL_2,
    CH_PS_SUPC_2,
    CH_PS_SIGV_SIGC_PUL_3,
    CH_PS_SUPC_3,
    CH_PS_SIGV_SIGC_PUL_4,
    CH_PS_SUPC_4,
    CH_PS_SIGV_SIGC_PUL_5,
    CH_PS_SUPC_5,

    CH_VR_DIS,                      // 滑动变阻器 距离

    CH_PRES_SIGV_SIGC_PRE_1,        // 压力传感器 信号电压、信号电流、压力值，1~5路
    CH_PRES_SIGV_SIGC_PRE_2,
    CH_PRES_SIGV_SIGC_PRE_3,
    CH_PRES_SIGV_SIGC_PRE_4,
    CH_PRES_SIGV_SIGC_PRE_5,

    CH_BAT                          // 电池电量
};

// 函数：将枚举值转换为QString
QString chToStr(CHANNEL_9205 channel);

class DataAcquireAI : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit DataAcquireAI(QObject *parent = nullptr);
    ~DataAcquireAI() {
        delete [] data;
    };

    void run() override;
    void __init__(QString channel);

signals:
    void send_data(QVector<double> data);       // 将采集到的数据发送给上层

public:
    void get_channel(QString channel);
    void stop_acquire();

private:
    TaskHandle _task;
    QString _channel;
    float64 _sample_rate = 50.0;
    uint64_t _sampsPerChanToAcquire = 1000;
    int32 _numSampsPerChan = 1;                // 每通道采样数
    uInt32 _channel_num;
    bool STOP = false;

    const int DATA_SIZE = 1000;

    double* data = new double[DATA_SIZE];
    int32 _sampsPerChanRead;

    // 低通滤波
    QVector<double> taps = createLowpassFilter(30, 100, 1000);
    // 创建FIR滤波器
    QVector<LowpassFilter> _filters;

private:
    QVector<int> str_to_int(QString channel);
    double choose_min_max(int channel);
};

#endif // DATAACQUIREAI_H
