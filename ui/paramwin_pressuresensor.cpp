#include "paramwin_pressuresensor.h"
#include "ui_paramwin_pressuresensor.h"

paramWin_pressureSensor::paramWin_pressureSensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_pressureSensor)
{
    ui->setupUi(this);
}

paramWin_pressureSensor::~paramWin_pressureSensor()
{
    delete ui;
}
