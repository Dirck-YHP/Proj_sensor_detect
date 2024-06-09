#ifndef DATAACQUIREAI_H
#define DATAACQUIREAI_H

#include <QObject>
#include <NIDAQmx.h>
#include <QRunnable>
#include <QRegExp>
#include <QThread>
#include "lowpassfilter.h"
#include "simpleQtLogger.h"
#include "assist.h"

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
    void send_data(QVector<double> data);

public:
    void get_channel(QString channel);
    void stop_acquire();
//    int get_numSampsPerChan();

private:
    TaskHandle _task;
    QString _channel;
    float64 _sample_rate = 1000.0;
    uint64_t _sampsPerChanToAcquire = 1000;
    int32 _numSampsPerChan = 50;
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
