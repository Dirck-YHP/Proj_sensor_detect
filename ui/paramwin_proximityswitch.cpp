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
