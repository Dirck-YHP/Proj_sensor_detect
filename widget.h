#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include "dataacquireai.h"
#include "dataacquiredi.h"
#include "dataacquireci.h"
#include "modbus.h"

#include "qcustomplot.h"
#include "assist.h"
#include <QThreadPool>
#include <QThread>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void get_data_and_plot_9205(QVector<double> data);
    void get_data_and_plot_9403(QVector<QVector<double>> data);
    void get_data_and_plot_9401(QVector<double> data);
    void on_btn_startAcquire_toggled(bool checked);

    void on_btn_run_stop_toggled(bool checked);
    void on_btn_stop_now_clicked();
    void on_btn_angle_cali_clicked();

    void on_btn_break_connect_clicked();

    void on_btn_build_connect_clicked();

private:
    QVector<QVector<double>> add_data_to_queue(QVector<QVector<double>> data);

private:
    Ui::Widget *ui;
    int channel_num;

    DataAcquireAI *data_acquire_ai;
    DataAcquireDI *data_acquire_di;
    DataAcquireCI *data_acquire_ci;

    Modbus *modbus;

    QTimer timer_modbus;

    const int PLOT_9403_QUEUE_SIZE = 100;
    QVector<QQueue<double>> plot_queue;

};
#endif // WIDGET_H
