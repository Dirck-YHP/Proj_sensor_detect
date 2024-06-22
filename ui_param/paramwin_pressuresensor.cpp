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

    if (ui->checkBox_measure_r->isChecked()) {
        show_win_measure_r = new showWin_measureResis;
        show_win_measure_r->show();
    } else {
        show_win_press_sensor = new showWin_pressureSensor(_pressure_sensor);
        show_win_press_sensor->show();
    }
}

void paramWin_pressureSensor::on_checkBox_measure_r_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {      // 如果测电阻，则工装及电机不可用
        ui->gridGroupBox->setEnabled(false);
        ui->label_7->setEnabled(false);

    } else if (arg1 == Qt::Unchecked) { // 如果不测电阻，则可用
        ui->gridGroupBox->setEnabled(true);
        ui->label_7->setEnabled(true);
    }
}
