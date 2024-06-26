#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include "dataacquireai.h"
#include "dataacquiredi.h"
#include "dataacquireci.h"
#include "modbus.h"
#include "serialportcom.h"

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
    /***************数据采集********************/
    void get_data_and_plot_9205(QVector<double> data);
    void get_data_and_plot_9403(QVector<QVector<double>> data);
    void get_data_and_plot_9401(QVector<double> data);
    void on_btn_startAcquire_toggled(bool checked);

    /***************modbus********************/
    void on_btn_run_stop_toggled(bool checked);
    void on_btn_stop_now_clicked();
    void on_btn_angle_cali_clicked();
    void on_btn_break_connect_clicked();
    void on_btn_build_connect_clicked();

    /***************串口通信********************/
    void on_btn_serial_snd_clicked();

private:
    QVector<QVector<double>> add_data_to_queue(QVector<QVector<double>> data);

private:
    Ui::Widget *ui;

    /***************数据采集********************/
    int channel_num;
    DataAcquireAI *data_acquire_ai;
    DataAcquireDI *data_acquire_di;
    DataAcquireCI *data_acquire_ci;

    /***************modbus*******************/
    Modbus *modbus;
    QTimer timer_modbus;
    bool MODBUS = false;        // 调试用

    /***************数串口通信********************/
    SerialPortCom *serialPort_com;


    /***************辅助********************/
    const int PLOT_9403_QUEUE_SIZE = 100;
    QVector<QQueue<double>> plot_queue;

};
#endif // WIDGET_H
