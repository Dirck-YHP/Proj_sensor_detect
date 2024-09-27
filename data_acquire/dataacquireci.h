#ifndef DATAACQUIRECI_H
#define DATAACQUIRECI_H

#include <QObject>
#include <NIDAQmx.h>
#include <QRunnable>
#include <QThread>
#include <QMessageBox>
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
    TaskHandle _task_A_edge;
    TaskHandle _task_two_edge_sep, _task_period;
    bool STOP = false;
    uInt32 _pulses_per_rev;

    const int DATA_SIZE = 1000;
    double* data = new double[DATA_SIZE];
    uInt32* A_chan_detc = new uInt32[DATA_SIZE];
    double* period = new double[DATA_SIZE];
    double* two_edge_sep = new double[DATA_SIZE];

    int32 _sampsPerChanRead;
    int32 _sampsPerChanRead_A;
    int32 _sampsPerChanRead_period;
    int32 _sampsPerChanRead_two_edge_sep;

signals:
    void send_data(QVector<double> data, QVector<uInt32> data2, QVector<double> data3, QVector<double> data4);

    void sig_err(bool err);

};

#endif // DATAACQUIRECI_H
