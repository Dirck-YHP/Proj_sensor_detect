#ifndef PARAMWIN_PRESSURESENSOR_H
#define PARAMWIN_PRESSURESENSOR_H

#include <QWidget>

#include "sensors/pressuresensor.h"
#include "ui_show/showwin_measureresis.h"
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
    showWin_measureResis *show_win_measure_r;
    showWin_pressureSensor *show_win_press_sensor;

signals:
    void subWindowClosed();

private slots:
    void on_btn_back_mainW_clicked();
    void on_btn_exit_clicked();
    void on_btn_ok_clicked();
};

#endif // PARAMWIN_PRESSURESENSOR_H
