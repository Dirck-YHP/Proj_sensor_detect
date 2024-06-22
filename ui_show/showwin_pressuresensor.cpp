#include "showwin_pressuresensor.h"
#include "ui_showwin_pressuresensor.h"

showWin_pressureSensor::showWin_pressureSensor(PressureSensor *pressure_sensor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_pressureSensor),
    _pressure_sensor(pressure_sensor)
{
    ui->setupUi(this);

    if (_hydraulic_station == nullptr) {
        _hydraulic_station = new HydraulicStation;
        _hydraulic_station->build_connection();
        qDebug() << "first new HydraulicStation and build conn";
    }

    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);
}

showWin_pressureSensor::~showWin_pressureSensor()
{
    qDebug() << "pressure window destroyed";
    delete ui;
}

void showWin_pressureSensor::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");
    } else {
        ui->btn_start_finish_mea->setText("开始测量");


    }
}

void showWin_pressureSensor::on_btn_ok_clicked()
{
    if (_hydraulic_station != nullptr) {
        _hydraulic_station->break_connection();     // 断开连接
        qDebug() << "HydraulicStation break conn and delete succeed";
        delete _hydraulic_station;
    }

    this->close();
}
