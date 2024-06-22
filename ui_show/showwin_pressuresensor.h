#ifndef SHOWWIN_PRESSURESENSOR_H
#define SHOWWIN_PRESSURESENSOR_H

#include <QWidget>

#include "sensors/pressuresensor.h"
#include "devices/hydraulicstation.h"

namespace Ui {
class showWin_pressureSensor;
}

class showWin_pressureSensor : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_pressureSensor(PressureSensor *pressure_sensor, QWidget *parent = nullptr);
    ~showWin_pressureSensor();

private slots:
    void on_btn_start_finish_mea_toggled(bool checked);

    void on_btn_ok_clicked();

private:
    Ui::showWin_pressureSensor *ui;
    PressureSensor *_pressure_sensor;
    HydraulicStation *_hydraulic_station = nullptr;
};

#endif // SHOWWIN_PRESSURESENSOR_H
