#ifndef RESIS_H
#define RESIS_H

#include <QObject>
#include <QDebug>
#include <QThreadPool>

#include "data_acquire/dataacquireai.h"

class Resis : public QObject
{
    Q_OBJECT
public:
    explicit Resis(QObject *parent = nullptr);

private:
    QString _channel;           // 通道

    DataAcquireAI *data_acquire_ai;     // NI 9205的数据

public:
    void set_channel(QString channel);
    QString get_channel() const;

    void start_acquire();
    void stop_acquire();

private slots:
    // 这个函数负责接收来自采集卡的原始数据并做处理，然后发出去
    void rev_data_from_ni9205(QVector<double> data);

signals:
     // 这里需要做转化，原始电压信号——>是否“触发”，发送的是“是否触发”的信号
    void send_ni9205_to_ui(QVector<double> data);
};

#endif // RESIS_H
