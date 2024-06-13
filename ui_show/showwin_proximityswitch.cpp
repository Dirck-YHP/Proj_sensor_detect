#include "showwin_proximityswitch.h"
#include "ui_showwin_proximityswitch.h"

showWin_proximitySwitch::showWin_proximitySwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_proximitySwitch)
{
    ui->setupUi(this);
}

showWin_proximitySwitch::~showWin_proximitySwitch()
{
    delete ui;
}
