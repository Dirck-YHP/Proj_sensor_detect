#ifndef ANGLESENSOR_H
#define ANGLESENSOR_H

#include <QObject>
#include <QThreadPool>

#include "data_acquire/dataacquireai.h"
#include "assist_func/assist.h"

class AngleSensor : public QObject
{
    Q_OBJECT
public:
    explicit AngleSensor(QObject *parent = nullptr);

private:
    QString _label;             // 标签
    QPair<int, int> _range;     // 范围
    QString _channel;           // 通道

    DataAcquireAI *data_acquire_ai;     // NI 9205的数据


public:
    void set_label(QString label);
    QString get_label() const;

    void set_range(QString angle_4mA, QString angle_20mA);
    QPair<int, int> get_range() const;

    void set_channel(QString channel);
    QString get_channel() const;

    void start_acquire();
    void stop_acquire();

public slots:
    void rev_data_from_ni9205(QVector<double> data);

signals:
    void send_angle_to_ui(QVector<double> data);
    void send_voltage_to_ui(QVector<double> data);
    void send_current_to_ui(QVector<double> data);

};

#endif // ANGLESENSOR_H
