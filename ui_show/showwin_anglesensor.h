#ifndef SHOWWIN_ANGLESENSOR_H
#define SHOWWIN_ANGLESENSOR_H

#include <QWidget>
#include <QThreadPool>
#include <QThread>
#include <QTimer>

#include "sensors/anglesensor.h"
#include "assist_func/assist.h"

namespace Ui {
class showWin_angleSensor;
}

class showWin_angleSensor : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_angleSensor(AngleSensor *angle_sensor, QWidget *parent = nullptr);
    ~showWin_angleSensor();

private slots:
    void on_btn_ok_clicked();

    void on_btn_start_finish_mea_toggled(bool checked);

    // 接收到来自传感器的数据然后显示出来
    void get_data_and_plot_angle(QVector<double> angle);        // 画角度（传感器+电机）
    void get_data_and_plot_current(QVector<double> current);    // 画电流
    void get_data_and_plot_vlotage(QVector<double> voltage);    // 画电压

private:
    Ui::showWin_angleSensor *ui;

    AngleSensor *_angle_sensor;
};

#endif // SHOWWIN_ANGLESENSOR_H
