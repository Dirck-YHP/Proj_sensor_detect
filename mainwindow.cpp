#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_btn_exit_clicked()
{
    qApp->quit();
}

void mainWindow::on_btn_start_clicked()
{
    if (ui->cbox_choose_sensor->currentText() == "角位移传感器") {
        paramWin_angleSensor *param_win_angle_sensor = new paramWin_angleSensor;
        param_win_angle_sensor->show();
    } else if (ui->cbox_choose_sensor->currentText() == "角位移编码器") {
        paramWin_angleEncoder *param_win_angle_encoder = new paramWin_angleEncoder;
        param_win_angle_encoder->show();
    } else if (ui->cbox_choose_sensor->currentText() == "接近开关") {
        paramWin_proximitySwitch *param_win_proximity_switch = new paramWin_proximitySwitch;
        param_win_proximity_switch->show();
    } else if (ui->cbox_choose_sensor->currentText() == "压力传感器") {
        paramWin_pressureSensor *param_win_pressure_sensor = new paramWin_pressureSensor;
        param_win_pressure_sensor->show();
    }
}

void mainWindow::on_btn_data_export_clicked()
{
    // 数据导出功能
}
