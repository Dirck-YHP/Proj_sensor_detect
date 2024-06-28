#include "funcwin_dataexport.h"
#include "ui_funcwin_dataexport.h"

funcWin_DataExport::funcWin_DataExport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::funcWin_DataExport)
{
    ui->setupUi(this);
}

funcWin_DataExport::~funcWin_DataExport()
{
    delete ui;
}

void funcWin_DataExport::on_btn_ok_clicked()
{
    _ip_addr = ui->lineE_ip->text();
    _port = ui->lineE_port->text();
}

void funcWin_DataExport::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}
