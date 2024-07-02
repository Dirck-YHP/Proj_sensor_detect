#include "paramwin_proximityswitch.h"
#include "ui_paramwin_proximityswitch.h"

paramWin_proximitySwitch::paramWin_proximitySwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_proximitySwitch)
{
    ui->setupUi(this);
}

paramWin_proximitySwitch::~paramWin_proximitySwitch()
{
    delete ui;
}

void paramWin_proximitySwitch::on_btn_exit_clicked()
{
    qApp->quit();
}

void paramWin_proximitySwitch::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

void paramWin_proximitySwitch::on_btn_ok_clicked()
{
    _proxi_switch = new ProximitySwitch;
    _proxi_switch->set_label(ui->cBox_prox_switch_type->currentText());
    _proxi_switch->set_sensing_dis((ui->cBox_distance->currentText()));
    _proxi_switch->set_using_time(ui->cBox_use_time->currentText());
    _proxi_switch->set_sensing_matirial((ui->cBox_material->currentText()));

    _show_win_prox_switch = new showWin_proximitySwitch(_proxi_switch);
    _show_win_prox_switch->show();

}
