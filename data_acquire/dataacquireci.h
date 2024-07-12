#ifndef DATAACQUIRECI_H
#define DATAACQUIRECI_H

#include <QObject>
#include <NIDAQmx.h>
#include <QRunnable>
#include <QThread>
#include <QDebug>

class DataAcquireCI : public QObject, public QRunnable
{
    Q_OBJECT
public:
    DataAcquireCI();

    void run() override;
    void __init__(uInt32 pulses_per_rev = 500);
    void stop_acquire();
    void get_pulses_per_rev(uInt32 pulses_per_rev);

private:
    TaskHandle _task;
    bool STOP = false;
    uInt32 _pulses_per_rev;

    const int DATA_SIZE = 1000;
    double* data = new double[DATA_SIZE];
    int32 _sampsPerChanRead;

signals:
    void send_data(QVector<double> data);
};

#endif // DATAACQUIRECI_H
