#ifndef ANGLESENSOR_H
#define ANGLESENSOR_H

#include <QObject>
#include <QDebug>
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
    QString channel_final;

    DataAcquireAI *data_acquire_ai = nullptr;     // NI 9205的数据

public:
    void set_label(QString label);
    QString get_label() const;

    void set_range(QString angle_4mA, QString angle_20mA);
    QPair<int, int> get_range() const;

    void set_channel();
    QString get_channel() const;

    void start_acquire();
    void stop_acquire();

    double map_from_cur_to_angle(double current);

public slots:
    void rev_data_from_ni9205(QVector<double> data);

    // 接收采集卡发送的错误信号
    void slot_get_err(bool err);

    void slot_acq_delete();

signals:
    void send_vol_cur_angle_to_ui(QVector<double> data);

    void sig_err_to_ui(bool err);     // 发送错误信号给界面
};

#endif // ANGLESENSOR_H
