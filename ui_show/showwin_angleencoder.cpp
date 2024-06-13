#include "showwin_angleencoder.h"
#include "ui_showwin_angleencoder.h"

showWin_angleEncoder::showWin_angleEncoder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_angleEncoder)
{
    ui->setupUi(this);
}

showWin_angleEncoder::~showWin_angleEncoder()
{
    delete ui;
}
