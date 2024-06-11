#include "paramwin_angleencoder.h"
#include "ui_paramwin_angleencoder.h"

paramWin_angleEncoder::paramWin_angleEncoder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_angleEncoder)
{
    ui->setupUi(this);
}

paramWin_angleEncoder::~paramWin_angleEncoder()
{
    delete ui;
}

void paramWin_angleEncoder::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

void paramWin_angleEncoder::on_btn_exit_clicked()
{
    qApp->quit();
}
