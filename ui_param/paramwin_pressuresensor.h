#ifndef PARAMWIN_PRESSURESENSOR_H
#define PARAMWIN_PRESSURESENSOR_H

#include <QWidget>
#include <QFileDialog>

#include "sensors/pressuresensor.h"
#include "ui_show/showwin_pressuresensor.h"

namespace Ui {
class paramWin_pressureSensor;
}

class paramWin_pressureSensor : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_pressureSensor(QWidget *parent = nullptr);
    ~paramWin_pressureSensor();

private:
    Ui::paramWin_pressureSensor *ui;
    PressureSensor *_pressure_sensor;
    showWin_pressureSensor *show_win_press_sensor;
    QString m_file_save_dir;

signals:
    void subWindowClosed();

public:
    QString check_channel_choosed();

private slots:
    void on_btn_back_mainW_clicked();
    void on_btn_exit_clicked();
    void on_btn_ok_clicked();
    void on_checkBox_measure_r_stateChanged(int arg1);
    void on_cBox_file_save_stateChanged(int arg1);
};

#endif // PARAMWIN_PRESSURESENSOR_H
