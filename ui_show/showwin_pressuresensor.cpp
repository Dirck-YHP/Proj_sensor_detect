#include "showwin_pressuresensor.h"
#include "ui_showwin_pressuresensor.h"

showWin_pressureSensor::showWin_pressureSensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_pressureSensor)
{
    ui->setupUi(this);
}

showWin_pressureSensor::~showWin_pressureSensor()
{
    delete ui;
}
