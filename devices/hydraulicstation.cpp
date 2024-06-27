#include "hydraulicstation.h"

HydraulicStation::HydraulicStation(QObject *parent) : QObject(parent)
{
    // 线程 Begin ----------------------------
    serial_port_com = new SerialPortCom();
    thread_serial_port = new QThread;
    qDebug() << "fisrt new serialport";

    serial_port_com->moveToThread(thread_serial_port);
    // 回收，这边的垃圾回收待优化
    connect(thread_serial_port, &QThread::finished, serial_port_com, &SerialPortCom::deleteLater);
    connect(thread_serial_port, &QThread::finished, thread_serial_port, &QThread::deleteLater);
    connect (serial_port_com,SIGNAL(destroyed(QObject*)), thread_serial_port,SLOT(quit()));
    // 串口配置初始化
    connect(thread_serial_port, &QThread::started, serial_port_com, &SerialPortCom::slot_serialport_init);
    // 启动线程
    thread_serial_port->start();

    // 接收到来自ui界面的开始测量信号，触发 串口的配置
    connect(this, &HydraulicStation::signal_set_config_serial_port,
            serial_port_com, &SerialPortCom::slot_configSrialport);

    // 接收来自ui界面的关闭测量信号，触发 串口关闭
    connect(this, &HydraulicStation::signal_close_seriao_port,
            serial_port_com, &SerialPortCom::slot_closeOpneSrialport);
}

HydraulicStation::~HydraulicStation()
{

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

void HydraulicStation::get_serial_data(QString rev_data)
{
    _tik_num++;
    if (_tik_num == 10)
        _tik_num = 0;

    // 这里加上对data的处理，取出压力值
    QStringList parts = rev_data.split(':'); // 使用冒号作为分隔符分割字符串
    QString valueAfterColon = "";
    if (parts.size() > 1) {
        valueAfterColon = parts.at(1); // 获取冒号后面的部分
    }


    _hydrau_value = valueAfterColon;
    qDebug() << _tik_num << ": rev_data: " << rev_data << "hydra: " << _hydrau_value;
}

void HydraulicStation::get_config_signal()
{
    qDebug() << "收到界面的配置信号";
    emit signal_set_config_serial_port();
}

void HydraulicStation::get_close_signal()
{
    qDebug() << "收到界面的关闭信号";
    emit signal_close_seriao_port();
}


