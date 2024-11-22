#include "dataexport.h"

DataExport::DataExport(QObject *parent) : QObject(parent)
{
    if (socket == nullptr) {
        // qDebug() << "new socket!";
        socket = new QTcpSocket();
    }
}

DataExport::~DataExport()
{
    if (socket != nullptr) {
        delete socket;
        // qDebug() << "delete socket!";
    }
}

void DataExport::set_ip_addr(QString ip_addr)
{
    _ip_addr = ip_addr;
}

void DataExport::set_port(QString port)
{
    _port = port;
}

void DataExport::socket_connect()
{
    socket->connectToHost(_ip_addr, _port.toInt());

    if (socket->waitForConnected(3000)) {
        // qDebug() << "Connected to the server!";
        socket->write("Hello, server!");
        socket->flush();
        socket->waitForBytesWritten(3000);
        socket->disconnect();
    } else {
        // qDebug() << "Failed to connect to the server!";
    }
}
