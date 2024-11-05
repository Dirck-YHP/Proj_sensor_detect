#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->btn_exit->setStyleSheet("color:rgb(254,254,254);background-color:rgb(67,211,128);");

    ui->btn_AE->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_AS->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_PS->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_PxS->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_Resis->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");

    // 板子上电，待测
    Assist::board_init(true);
}

mainWindow::~mainWindow()
{
    delete ui;
}

/***************************************************************
  *  @brief     软件退出
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void mainWindow::on_btn_exit_clicked()
{
    qApp->quit();
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      槽函数——参数配置窗口关闭时重新显示主窗口
  *  @Sample usage:
 **************************************************************/
void mainWindow::showMainWindow()
{
    this->show();
}

void mainWindow::on_btn_AS_clicked()
{
    paramWin_angleSensor *param_win_angle_sensor = new paramWin_angleSensor;
    connect(param_win_angle_sensor, &paramWin_angleSensor::subWindowClosed,
            this, &mainWindow::showMainWindow);

    this->hide();
    param_win_angle_sensor->setStyleSheet("background-color:rgb(67,67,67);");
    param_win_angle_sensor->show();
}

void mainWindow::on_btn_AE_clicked()
{
    paramWin_angleEncoder *param_win_angle_encoder = new paramWin_angleEncoder;
    connect(param_win_angle_encoder, &paramWin_angleEncoder::subWindowClosed,
            this, &mainWindow::showMainWindow);

    this->hide();
    param_win_angle_encoder->setStyleSheet("background-color:rgb(67,67,67);");
    param_win_angle_encoder->show();
}

void mainWindow::on_btn_PxS_clicked()
{
    paramWin_proximitySwitch *param_win_proximity_switch = new paramWin_proximitySwitch;
    connect(param_win_proximity_switch, &paramWin_proximitySwitch::subWindowClosed,
            this, &mainWindow::showMainWindow);

    this->hide();
    param_win_proximity_switch->setStyleSheet("background-color:rgb(67,67,67);");
    param_win_proximity_switch->show();
}

void mainWindow::on_btn_PS_clicked()
{
    paramWin_pressureSensor *param_win_pressure_sensor = new paramWin_pressureSensor;
    connect(param_win_pressure_sensor, &paramWin_pressureSensor::subWindowClosed,
            this, &mainWindow::showMainWindow);

    this->hide();
    param_win_pressure_sensor->setStyleSheet("background-color:rgb(67,67,67);");
    param_win_pressure_sensor->show();
}

void mainWindow::on_btn_Resis_clicked()
{
    paramWin_mea_resis *param_win_mea_r = new paramWin_mea_resis;
    connect(param_win_mea_r, &paramWin_mea_resis::subWindowClosed,
            this, &mainWindow::showMainWindow);

    this->hide();
    param_win_mea_r->setStyleSheet("background-color:rgb(67,67,67);");
    param_win_mea_r->show();
}
