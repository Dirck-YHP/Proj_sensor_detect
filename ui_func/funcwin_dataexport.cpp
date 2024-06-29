#include "funcwin_dataexport.h"
#include "ui_funcwin_dataexport.h"

funcWin_DataExport::funcWin_DataExport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::funcWin_DataExport)
{
    ui->setupUi(this);

    if (_data_export == nullptr) {
        qDebug() << "new data_export!";
        _data_export = new DataExport();
    }

    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);
}

funcWin_DataExport::~funcWin_DataExport()
{
    if (_data_export != nullptr) {
        delete _data_export;
        qDebug() << "delete data_export!";
    }
    delete ui;
}

void funcWin_DataExport::on_btn_ok_clicked()
{
    _data_export->set_ip_addr(ui->lineE_ip->text());
    _data_export->set_port(ui->lineE_port->text());

    qDebug() << "ip_addr: " << ui->lineE_ip->text() << " port: " << ui->lineE_port->text();
    _data_export->socket_connect();
}

void funcWin_DataExport::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}
