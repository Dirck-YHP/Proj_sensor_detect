#include "showwin_anglesensor.h"
#include "ui_showwin_anglesensor.h"

showWin_angleSensor::showWin_angleSensor(AngleSensor *angle_sensor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_angleSensor),
    _angle_sensor(angle_sensor)
{
    ui->setupUi(this);
}

showWin_angleSensor::~showWin_angleSensor()
{
    delete ui;
}

void showWin_angleSensor::on_btn_ok_clicked()
{
    this->close();
}

void showWin_angleSensor::on_btn_test_clicked()
{

    ui->textB_test->append(_angle_sensor->get_label());
    ui->textB_test->append("   hahaha   ");
    QPair range = _angle_sensor->get_range();
    ui->textB_test->append(QString::number(range.first) + " " + QString::number(range.second));
}
