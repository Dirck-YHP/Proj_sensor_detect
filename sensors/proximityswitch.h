#ifndef PROXIMITYSWITCH_H
#define PROXIMITYSWITCH_H

#include <QObject>
#include <QThreadPool>
#include <QDebug>

#include "data_acquire/dataacquireai.h"

class ProximitySwitch : public QObject
{
    Q_OBJECT
public:
    explicit ProximitySwitch(QObject *parent = nullptr);

private:
    QString _label;             // 传感器类型
    QString _sensing_distance;  // 感应距离
    QString _using_time;        // 使用时间
    QString _sensing_matirial;  // 感应材料
    QString _channel;           // 通道
    QString channel_final;

    DataAcquireAI *data_acquire_ai = nullptr;     // NI 9205

    const int THREAD_VOL_TO_PUL = 3;

public:
    void set_label(QString label);  // 设置传感器类型
    QString get_label() const;

    void set_sensing_dis(QString sensing_dis);
    QString get_sensing_dis() const;

    void set_using_time(QString using_time);
    QString get_using_time() const;

    void set_sensing_matirial(QString sensing_matirial);
    QString get_sensing_matirial() const;

    void set_channel(QString channel);
    QString get_channel() const;

    void start_acquire();
    void stop_acquire();

    double map_from_cur_to_varDis(double current);

private slots:
    // 这个函数负责接收来自采集卡的原始数据并做处理，然后发出去
    void rev_data_from_ni9205(QVector<double> data);

public slots:
    void slot_acq_delete();

signals:
    void send_vol_cur_pul_dis_to_ui(QVector<double> data);

};

#endif // PROXIMITYSWITCH_H
