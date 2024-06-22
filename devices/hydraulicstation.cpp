#include "hydraulicstation.h"

HydraulicStation::HydraulicStation(QObject *parent) : QObject(parent)
{
    if (serial_port_com == nullptr) {
        qDebug() << "first new serialport";
        serial_port_com = new SerialPortCom;

        connect(&serial_port_com->serialPort, &QSerialPort::readyRead,
                this, &HydraulicStation::get_serial_data);
    }

}

HydraulicStation::~HydraulicStation()
{
    if (serial_port_com != nullptr) {
        qDebug() << "serial_port_com delete succeed";
        delete serial_port_com;
    }
}

void HydraulicStation::build_connection()
{
    serial_port_com->serial_port_connect();
    qDebug() << "serial build connection";
}

void HydraulicStation::break_connection()
{
    serial_port_com->serial_port_break();
    qDebug() << "serial break connection";
}

void HydraulicStation::send_msg()
{
    serial_port_com->serial_snd_msg(SEND_MSG);
}

QString HydraulicStation::get_msg()
{
    return _hydrau_value;
}

void HydraulicStation::get_serial_data()
{
    QString data = QString(serial_port_com->serialPort.readAll());

    // 这里加上对data的处理，取出压力值
    data = "1124";

    _hydrau_value = data;
}
