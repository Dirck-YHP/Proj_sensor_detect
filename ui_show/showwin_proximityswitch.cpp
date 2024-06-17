#include "showwin_proximityswitch.h"
#include "ui_showwin_proximityswitch.h"

showWin_proximitySwitch::showWin_proximitySwitch(ProximitySwitch *proxi_switch, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_proximitySwitch),
    _proxi_switch(proxi_switch)
{
    ui->setupUi(this);
}

showWin_proximitySwitch::~showWin_proximitySwitch()
{
    delete ui;
}

void showWin_proximitySwitch::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");


    }else {
        ui->btn_start_finish_mea->setText("开始测量");


    }
}
