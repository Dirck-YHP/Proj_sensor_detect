#ifndef DATAEXPORT_H
#define DATAEXPORT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>

class DataExport : public QObject
{
    Q_OBJECT
public:
    explicit DataExport(QObject *parent = nullptr);
    ~DataExport();

public:
    void set_ip_addr(QString ip_addr);
    void set_port(QString port);

    void socket_connect();

private:
    QTcpSocket *socket = nullptr;

    QString _ip_addr;
    QString _port;

signals:

};

#endif // DATAEXPORT_H
