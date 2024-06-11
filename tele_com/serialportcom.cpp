#include "serialportcom.h"

SerialPortCom::SerialPortCom(QObject *parent) : QObject(parent)
{

}

void SerialPortCom::serial_port_connect()
{
    serialPort.setPortName("COM2");
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // 打开失败，处理错误
        qDebug() << "Connect Error";
    }
    serialPort.setBaudRate(QSerialPort::Baud9600);
    serialPort.setDataBits(QSerialPort::Data8); // 设置为8位数据位
    // 设置奇偶校验
    serialPort.setParity(QSerialPort::NoParity); // 设置为无奇偶校验
    // 设置停止位
    serialPort.setStopBits(QSerialPort::OneStop); // 设置为1位停止位
    serialPort.setFlowControl(QSerialPort::NoFlowControl);
}

void SerialPortCom::serial_port_break()
{
    serialPort.close();
}

void SerialPortCom::serial_snd_msg(QString msg)
{
    serialPort.write(msg.toUtf8());
}

QString SerialPortCom::serial_rev_msg()
{
    return QString::fromUtf8(serialPort.readAll());
}
