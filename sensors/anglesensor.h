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
    QString _label;
    QPair<int, int> _range;
    QString _channel;

    DataAcquireAI *data_acquire_ai;


public:
    void set_label(QString label);
    QString get_label() const;

    void set_range(QString angle_4mA, QString angle_20mA);
    QPair<int, int> get_range() const;

    void set_channel(QString channel);
    QString get_channel() const;

    void start_acquire();
    void finish_acquire();

public slots:
    void on_data_acquired(QVector<double> data);

signals:
    void emit_data(QVector<double> data);   // 转发信号

};

#endif // ANGLESENSOR_H
