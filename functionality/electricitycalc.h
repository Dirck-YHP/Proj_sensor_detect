#ifndef ELECTRICITYCALC_H
#define ELECTRICITYCALC_H

#include <QObject>
#include <QThreadPool>

#include "data_acquire/dataacquireai.h"

class ElectricityCalc : public QObject
{
    Q_OBJECT
public:
    explicit ElectricityCalc(QObject *parent = nullptr);

private:
    const QString CHANNEL = "31";           // 通道

    DataAcquireAI *data_acquire_ai;     // NI 9205的数据

public:
    void start_acquire();
    void stop_acquire();

private slots:
    // 这个函数负责接收来自采集卡的原始数据并做处理，然后发出去
    void rev_data_from_ni9205(QVector<double> data);

signals:
    // 这里需要做转化，原始电压信号——>电池电量，发送的是电池电量
   void send_battery_to_ui(QVector<double> data);
};

#endif // ELECTRICITYCALC_H
