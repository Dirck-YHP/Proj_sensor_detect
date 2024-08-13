#ifndef RESIS_H
#define RESIS_H

#include <QObject>
#include <QDebug>
#include <QThreadPool>
#include <QTimer>

#include "data_acquire/dataacquireai.h"

class Resis : public QObject
{
    Q_OBJECT
public:
    explicit Resis(QObject *parent = nullptr);

private:
    QString _channel;           // 通道
    QString channel_final;

    DataAcquireAI *data_acquire_ai = nullptr;     // NI 9205的数据

    enum RType{
        high = 0,
        middle = 1,
        low = 2,
    };

    RType rType = RType::middle;
    QTimer* m_timer;
    bool allowChange;

public:
    void set_channel(QString channel);
    QString get_channel() const;

    void start_acquire();
    void stop_acquire();

    double map_from_vol_to_resis(double voltage, QString DI_str);

private slots:
    // 这个函数负责接收来自采集卡的原始数据并做处理，然后发出去
    void rev_data_from_ni9205(QVector<double> data);
public slots:
    void slot_acq_delete();

signals:
    void send_resis_to_ui(QVector<double> data);
};

#endif // RESIS_H
