#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include <QObject>
#include <QDebug>
#include <QThreadPool>

#include "data_acquire/dataacquireai.h"

class PressureSensor : public QObject
{
    Q_OBJECT
public:
    explicit PressureSensor(QObject *parent = nullptr);

private:
    QString _label;             // 标签
    QPair<int, int> _range;     // 范围
    QString _channel;           // 通道

    DataAcquireAI *data_acquire_ai;     // NI 9205的数据

public:
    void set_label(QString label);
    QString get_label() const;

    void set_range(QString pressure_4mA, QString pressure_20mA);
    QPair<int, int> get_range() const;

    void set_channel(QString channel);
    QString get_channel() const;

    void start_acquire();
    void stop_acquire();

private slots:
    // 这个函数负责接收来自采集卡的原始数据并做处理，然后发出去
    void rev_data_from_ni9205(QVector<double> data);

signals:
    void send_ni9205_to_ui(QVector<double> data);
};

#endif // PRESSURESENSOR_H
