#ifndef SHOWWIN_ANGLESENSOR_H
#define SHOWWIN_ANGLESENSOR_H

#include <QWidget>
#include "sensors/anglesensor.h"

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

    void on_btn_test_clicked();

private:
    Ui::showWin_angleSensor *ui;
    AngleSensor *_angle_sensor;
};

#endif // SHOWWIN_ANGLESENSOR_H
