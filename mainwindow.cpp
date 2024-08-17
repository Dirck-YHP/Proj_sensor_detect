#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->btn_exit->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_start->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_data_export->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->cbox_choose_sensor->setStyleSheet("color:rgb(254,254,254);background-color:rgb(84,80,107);");

    // 板子上电，待测
//    Assist::board_init();
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
  *  @brief     ok键按下
  *  @param     无
  *  @note      槽函数——根据选择弹出对应窗口
  *  @Sample usage:
 **************************************************************/
void mainWindow::on_btn_start_clicked()
{
    if (ui->cbox_choose_sensor->currentText() == "角位移传感器") {
        paramWin_angleSensor *param_win_angle_sensor = new paramWin_angleSensor;
        connect(param_win_angle_sensor, &paramWin_angleSensor::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_angle_sensor->setStyleSheet("background-color:rgb(67,67,67);");
        param_win_angle_sensor->show();
    } else if (ui->cbox_choose_sensor->currentText() == "角位移编码器") {
        paramWin_angleEncoder *param_win_angle_encoder = new paramWin_angleEncoder;
        connect(param_win_angle_encoder, &paramWin_angleEncoder::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_angle_encoder->setStyleSheet("background-color:rgb(67,67,67);");
        param_win_angle_encoder->show();
    } else if (ui->cbox_choose_sensor->currentText() == "接近开关") {
        paramWin_proximitySwitch *param_win_proximity_switch = new paramWin_proximitySwitch;
        connect(param_win_proximity_switch, &paramWin_proximitySwitch::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_proximity_switch->setStyleSheet("background-color:rgb(67,67,67);");
        param_win_proximity_switch->show();
    } else if (ui->cbox_choose_sensor->currentText() == "压力传感器") {
        paramWin_pressureSensor *param_win_pressure_sensor = new paramWin_pressureSensor;
        connect(param_win_pressure_sensor, &paramWin_pressureSensor::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_pressure_sensor->setStyleSheet("background-color:rgb(67,67,67);");
        param_win_pressure_sensor->show();
    } else if (ui->cbox_choose_sensor->currentText() == "电阻") {
        paramWin_mea_resis *param_win_mea_r = new paramWin_mea_resis;
        connect(param_win_mea_r, &paramWin_mea_resis::subWindowClosed,
                this, &mainWindow::showMainWindow);

        this->hide();
        param_win_mea_r->setStyleSheet("background-color:rgb(67,67,67);");
        param_win_mea_r->show();
    }
}

/***************************************************************
  *  @brief     数据导出
  *  @param     无
  *  @note      槽函数——弹出数据导出窗口
  *  @Sample usage:
 **************************************************************/
void mainWindow::on_btn_data_export_clicked()
{
    // 数据导出功能
    funcWin_DataExport *func_win_data_export = new funcWin_DataExport;
    connect(func_win_data_export, &funcWin_DataExport::subWindowClosed,
            this, &mainWindow::showMainWindow);

    this->hide();
    func_win_data_export->setStyleSheet("background-color:rgb(67,67,67);");
    func_win_data_export->show();
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
