#ifndef PARAMWIN_ANGLESENSOR_H
#define PARAMWIN_ANGLESENSOR_H

#include <QWidget>
#include <QDebug>
#include "sensors/anglesensor.h"
#include "ui_show/showwin_anglesensor.h"
#include "ui_func/funcwin_datareview.h"

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

    void on_checkBox_no_need_device_stateChanged(int arg1);

    void on_btn_exit_clicked();

    void on_btn_back_mainW_clicked();


    void on_cBox_file_save_stateChanged(int arg1);

    void on_btn_load_data_clicked();

private:
    Ui::paramWin_angleSensor *ui;
    AngleSensor *angle_sensor;
    showWin_angleSensor *show_win_angle_sensor;

    funcWin_DataReview *func_win_data_review;
    QString m_file_save_dir;

signals:
    void subWindowClosed();
};

#endif // PARAMWIN_ANGLESENSOR_H
