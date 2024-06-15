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

void showWin_angleSensor::get_data_and_plot_angle(QVector<double> angle)
{

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

void showWin_angleSensor::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");


    } else {
        ui->btn_start_finish_mea->setText("开始测量");
    }
}






















