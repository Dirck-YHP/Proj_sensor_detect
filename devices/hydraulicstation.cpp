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
    // 如果全局变量改变，则返回压力值，如果没变，就返回空，UI界面提示用户没接收到数据
    if (_pre_tik_num != _tik_num) {
        _pre_tik_num = _tik_num;
        return _hydrau_value;
    } else
        return "";
}

void HydraulicStation::get_serial_data()
{
    QString data = QString(serial_port_com->serialPort.readAll());

    // 如果触发了，全局变量改变一下
    _tik_num++;
    if (_tik_num == 10)
        _tik_num = 0;
    qDebug() << _tik_num;

    // 这里加上对data的处理，取出压力值
    QStringList parts = data.split(':'); // 使用冒号作为分隔符分割字符串
    QString valueAfterColon = "";
    if (parts.size() > 1) {
        valueAfterColon = parts.at(1); // 获取冒号后面的部分
    }

    _hydrau_value = valueAfterColon;
}
