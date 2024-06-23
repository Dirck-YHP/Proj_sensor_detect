#include "showwin_anglesensor.h"
#include "ui_showwin_anglesensor.h"

showWin_angleSensor::showWin_angleSensor(AngleSensor *angle_sensor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_angleSensor),
    _angle_sensor(angle_sensor)
{
    ui->setupUi(this);

    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);
}

showWin_angleSensor::~showWin_angleSensor()
{
    qDebug() << "angle window destroyed";
    delete ui;
}

// 接收到来自传感器的数据，然后显示出来
// 接收到角度值并显示
void showWin_angleSensor::get_data_and_plot_angle(QVector<double> angle)
{
    angle[0]++;     // 防warning代码
}

// 接收到电流值并显示
void showWin_angleSensor::get_data_and_plot_current(QVector<double> current)
{
    current[0]++;   // 防warning代码
}

// 接收到电压值并显示
void showWin_angleSensor::get_data_and_plot_vlotage(QVector<double> voltage)
{
    voltage[0]++;   // 防warning代码
}

void showWin_angleSensor::on_btn_ok_clicked()
{
    this->close();
}


void showWin_angleSensor::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");

        _angle_sensor->start_acquire();

        // 下面开始把数据显示出来
        // ------------------- 角度 -----------------------------
        connect(_angle_sensor, &AngleSensor::send_angle_to_ui,
                this, &showWin_angleSensor::get_data_and_plot_angle);

        // ------------------- 电压 -----------------------------
        connect(_angle_sensor, &AngleSensor::send_voltage_to_ui,
               this, &showWin_angleSensor::get_data_and_plot_vlotage);

        // ------------------- 电流 -----------------------------
        connect(_angle_sensor, &AngleSensor::send_current_to_ui,
                this, &showWin_angleSensor::get_data_and_plot_current);

    } else {
        ui->btn_start_finish_mea->setText("开始测量");

        _angle_sensor->stop_acquire();
    }
}






















