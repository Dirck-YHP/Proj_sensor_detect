#ifndef FUNCWIN_DATAEXPORT_H
#define FUNCWIN_DATAEXPORT_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>

#include "functionality/dataexport.h"

namespace Ui {
class funcWin_DataExport;
}

class funcWin_DataExport : public QWidget
{
    Q_OBJECT

public:
    explicit funcWin_DataExport(QWidget *parent = nullptr);
    ~funcWin_DataExport();

private slots:
    void on_btn_ok_clicked();
    void on_btn_back_mainW_clicked();

    void on_btn_choose_clicked();
    void on_btn_send_clicked();

    void RcvData();

    void HaveNewConnection();

    void SendFile();
signals:
    void subWindowClosed();

private:
    Ui::funcWin_DataExport *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QFile file;
    QString fileName;
    qint64 fileSize;
    qint64 sendSize;

    DataExport *_data_export = nullptr;
    QString _ip_addr;
    QString _port;
};

#endif // FUNCWIN_DATAEXPORT_H
