#ifndef SERIALPORTCOM_H
#define SERIALPORTCOM_H

#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QThread>
#include <QTimer>
#include <QSerialPortInfo>

#include <QtSerialPort/QSerialPort>

class SerialPortCom : public QObject//, public QThread
{
    Q_OBJECT
public:
    SerialPortCom(QObject *parent = nullptr);
    ~SerialPortCom();

    void serial_port_connect();     // 连接
    void serial_port_break();       // 断开
    void serial_snd_msg(QString msg);
    QString serial_rev_msg();

private:
    QSerialPort *serialPort;
    QTimer *timer_Serialport;

signals:
    void slot_configSerialport();

    void dataReceived(QString data);

public slots:
    void slot_configSrialport();
    void slot_closeOpneSrialport();

    void slot_serialport_init();        // 配置
private slots :
    void slots_readData();

private:
    const QString COM = "COM2";       // 暂定COM2
    const QString SEND_MSG = "001100";      // 发送给液压站的命令，固定的

    void writeData();
    bool checkPortAvailability(const QString &portName);
};

#endif // SERIALPORTCOM_H
