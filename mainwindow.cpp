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
       // 隐藏当前窗口，而不是销毁

    if (ui->cbox_choose_sensor->currentText() == "角位移传感器") {
        paramWin_angleSensor *param_win_angle_sensor = new paramWin_angleSensor;
        connect(param_win_angle_sensor, &paramWin_angleSensor::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_angle_sensor->show();
    } else if (ui->cbox_choose_sensor->currentText() == "角位移编码器") {
        paramWin_angleEncoder *param_win_angle_encoder = new paramWin_angleEncoder;
        connect(param_win_angle_encoder, &paramWin_angleEncoder::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_angle_encoder->show();
    } else if (ui->cbox_choose_sensor->currentText() == "接近开关") {
        paramWin_proximitySwitch *param_win_proximity_switch = new paramWin_proximitySwitch;
        connect(param_win_proximity_switch, &paramWin_proximitySwitch::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_proximity_switch->show();
    } else if (ui->cbox_choose_sensor->currentText() == "压力传感器") {
        paramWin_pressureSensor *param_win_pressure_sensor = new paramWin_pressureSensor;
        connect(param_win_pressure_sensor, &paramWin_pressureSensor::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_pressure_sensor->show();
    } else if (ui->cbox_choose_sensor->currentText() == "电阻") {
        paramWin_mea_resis *param_win_mea_r = new paramWin_mea_resis;
        connect(param_win_mea_r, &paramWin_mea_resis::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_mea_r->show();
    }
}

void mainWindow::on_btn_data_export_clicked()
{
    // 数据导出功能
    funcWin_DataExport *func_win_data_export = new funcWin_DataExport;
    connect(func_win_data_export, &funcWin_DataExport::subWindowClosed,
            this, &mainWindow::showMainWindow);

    this->hide();
    func_win_data_export->show();
}

void mainWindow::showMainWindow()
{
    this->show();
}
