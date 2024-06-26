#ifndef ANGLEENCODER_H
#define ANGLEENCODER_H

#include <QObject>
#include <QThreadPool>
#include <QDebug>

#include "data_acquire/dataacquireai.h"
#include "data_acquire/dataacquireci.h"
#include "data_acquire/dataacquiredi.h"

class AngleEncoder : public QObject
{
    Q_OBJECT
public:
    explicit AngleEncoder(QObject *parent = nullptr);

private:
    QString _label;             // 标签
    QString _pulse_per_rev;     // 每圈脉冲数
    QString _channel;           // 通道

    DataAcquireAI *data_acquire_ai;     // NI 9205
    DataAcquireDI *data_acquire_di;     // NI 9403
    DataAcquireCI *data_acquire_ci;     // NI 9401

public:
    void set_label(QString label);
    QString get_label() const;

    void set_pul_per_cir(QString pul_per_rev);
    QString get_pul_per_cir() const;

    void set_channel(QString channel);
    QString get_channel() const;

    void start_acquire();
    void stop_acquire();

private slots:
    // 这三个函数负责接收来自采集卡的原始数据并做处理，然后发出去
    void rev_data_from_ni9205(QVector<double> data);
    void rev_data_from_ni9403(QVector<QVector<double>> data_final);
    void rev_data_from_ni9401(QVector<double> data);

signals:
    void send_ni9205_to_ui(QVector<double> data);
    void send_ni9403_to_ui(QVector<QVector<double>> data_final);
    void send_ni9401_to_ui(QVector<double> data);
};

#endif // ANGLEENCODER_H
