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
