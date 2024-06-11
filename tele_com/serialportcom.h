#ifndef SERIALPORTCOM_H
#define SERIALPORTCOM_H

#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>

class SerialPortCom : public QObject
{
    Q_OBJECT
public:
    SerialPortCom(QObject *parent = nullptr);
    void serial_port_connect();     // 连接
    void serial_port_break();       // 断开
    void serial_snd_msg(QString msg);
    QString serial_rev_msg();

public:
    QSerialPort serialPort;
};

#endif // SERIALPORTCOM_H
