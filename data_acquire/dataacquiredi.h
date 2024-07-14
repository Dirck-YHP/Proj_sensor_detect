#ifndef DATAACQUIREDI_H
#define DATAACQUIREDI_H

#include <QObject>
#include <NIDAQmx.h>
#include <QRunnable>
#include <QThread>
#include <QDebug>

class DataAcquireDI : public QObject, public QRunnable
{
    Q_OBJECT

public:
    DataAcquireDI();

    void run() override;
    void __init__();
    void stop_acquire();

private:
    TaskHandle _task;
    int32 _numSampsPerChan = 500;               // 每通道采样数
    float64 _sample_rate = 1e4;                 // 采样率
    uint64_t _sampsPerChanToAcquire = 1000;     // 定时器 缓冲区大小
    bool STOP = false;

    const int DATA_SIZE = 5000;                 // 数据大小，目前初始化成一个较大的数
    uInt8* data = new uInt8[DATA_SIZE];
    int32 _sampsPerChanRead;
    int32 _numBytesPerSamp;

public:
    const int CHANNEL_NUM = 6;                  // 通道数

signals:
    void send_data(QVector<QVector<double>> data_final);        // 将采集到的数据发送给上层
};



#endif // DATAACQUIREDI_H
