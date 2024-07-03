#include "funcwin_dataexport.h"
#include "ui_funcwin_dataexport.h"

funcWin_DataExport::funcWin_DataExport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::funcWin_DataExport)
{
    ui->setupUi(this);

    tcpServer = new QTcpServer(this);
    tcpSocket = NULL;
    // 设置窗口标题
    setWindowTitle(QString::fromLocal8Bit("server port: 6666"));
    // 监听端口：默认为6666
    tcpServer->listen(QHostAddress::Any, 6666);

    connect(tcpServer, &QTcpServer::newConnection, this, &funcWin_DataExport::HaveNewConnection);

    // old code
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

/***************************************************************
  *  @brief     确认键按下
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataExport::on_btn_ok_clicked()
{

//    qDebug() << "ip_addr: " << ui->lineE_ip->text() << " port: " << ui->lineE_port->text();
    _data_export->socket_connect();
}

/***************************************************************
  *  @brief     返回主界面
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataExport::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

/***************************************************************
  *  @brief     按键——选择文件
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataExport::on_btn_choose_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"open","../");
    if(!filePath.isEmpty()) {
        fileName.clear();
        fileSize = 0;
        sendSize = 0;
        QFileInfo info(filePath);
        fileName = info.fileName();
        fileSize = info.size();
        file.setFileName(filePath);
        if(file.open(QIODevice::ReadOnly)) {
            ui->textE->setText(QString::fromUtf8("open file: ").append(filePath).append("\n"));
        }
        else {
            qDebug()<<"文件打开失败";
        }
    } else {
        qDebug()<<"文件路径出错";
    }
}

/***************************************************************
  *  @brief     按键——发送文件
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataExport::on_btn_send_clicked()
{
    QString head = tr("%1##%2").arg(fileName).arg(fileSize);
    quint64 len = tcpSocket->write(head.toUtf8().data());

    if(len <= 0) {
        qDebug()<<"头部信息发送失败 ";
        file.close();
    }
}

/***************************************************************
  *  @brief     接收client的信息用来确认
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataExport::RcvData()
{
    QByteArray buf = tcpSocket->readAll();
    if(QString(buf) == fileName) {
        SendFile();
    }
}

/***************************************************************
  *  @brief     检测到连接，触发文件发送函数
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataExport::HaveNewConnection()
{
    // 接收到ip和端口号
    tcpSocket = tcpServer->nextPendingConnection();
    QString ip = tcpSocket->peerAddress().toString();
    quint16 port = tcpSocket->peerPort();
    qDebug() << ip << " " << port;

    QString str = "Connected!";
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(RcvData()));
    QMessageBox::information(this, "Info", str, QMessageBox::Ok);
}

/***************************************************************
  *  @brief     文件发送
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataExport::SendFile()
{
    // 分size发送文件
    qint64 len = 0;
    do{
        static quint32 cnt = 0;
        char buf[64*1024] = {0};
        len = 0;
        len = file.read(buf, sizeof(buf));
        len = tcpSocket->write(buf, len);
        sendSize += len;
        qDebug() << cnt++;
    } while(len > 0);

    // 文件发送完成
    if (sendSize == fileSize) {
        ui->textE->setText(QString::fromUtf8("Finish sending file,please click connect on client.\n"));
        file.close();
        tcpSocket->disconnect();
        tcpSocket->close();
    }
}
