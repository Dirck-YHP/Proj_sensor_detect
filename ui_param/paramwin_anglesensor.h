#ifndef PARAMWIN_ANGLESENSOR_H
#define PARAMWIN_ANGLESENSOR_H

#include <QWidget>
#include <QDebug>
#include "sensors/anglesensor.h"
#include "ui_show/showwin_measureresis.h"

namespace Ui {
class paramWin_angleSensor;
}

class paramWin_angleSensor : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_angleSensor(QWidget *parent = nullptr);
    ~paramWin_angleSensor();

private slots:
    void on_btn_ok_clicked();

    void on_checkBox_measure_resis_stateChanged(int arg1);

    void on_checkBox_need_device_stateChanged(int arg1);

    void on_btn_exit_clicked();

    void on_btn_back_mainW_clicked();


private:
    Ui::paramWin_angleSensor *ui;
    AngleSensor *angle_sensor;
    showWin_measureResis *show_win_measure_r;

signals:
    void subWindowClosed();
};

#endif // PARAMWIN_ANGLESENSOR_H
