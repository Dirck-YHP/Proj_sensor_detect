#include "paramwin_pressuresensor.h"
#include "ui_paramwin_pressuresensor.h"

paramWin_pressureSensor::paramWin_pressureSensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_pressureSensor)
{
    ui->setupUi(this);
}

paramWin_pressureSensor::~paramWin_pressureSensor()
{
    delete ui;
}

void paramWin_pressureSensor::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

void paramWin_pressureSensor::on_btn_exit_clicked()
{
    qApp->quit();
}

void paramWin_pressureSensor::on_btn_ok_clicked()
{
    _pressure_sensor = new PressureSensor;
    _pressure_sensor->set_label(ui->cBox_pressure_sensor_type->currentText());
    _pressure_sensor->set_range(ui->lineE_4mA->text(), ui->lineE_20mA->text());
}
