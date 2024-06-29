#include "serialportcom.h"

SerialPortCom::SerialPortCom(QObject *parent) : QObject(parent)
{
    qDebug() <<  "1 线程ID：" << QThread::currentThreadId();
}

SerialPortCom::~SerialPortCom()
{
    qDebug() << "~SerialPort";
}

/***************************************************************
  *  @brief     建立连接
  *  @param     无
  *  @note      在这里创建对象并配置连接
  *  @Sample usage:
 **************************************************************/
void SerialPortCom::serial_port_connect()
{
    serialPort = new QSerialPort();

    // 建立连接：一旦读取到消息，就处理
    connect(serialPort, &QSerialPort::readyRead, this, &SerialPortCom::slots_readData);

    // 以下是串口的配置
    serialPort->setPortName(COM);
    if (!serialPort->open(QIODevice::ReadWrite)) {
        // 打开失败，处理错误
        qDebug() << "Connect Error";
    }
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8); // 设置为8位数据位
    // 设置奇偶校验
    serialPort->setParity(QSerialPort::NoParity); // 设置为无奇偶校验
    // 设置停止位
    serialPort->setStopBits(QSerialPort::OneStop); // 设置为1位停止位
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
}

/***************************************************************
  *  @brief     断开连接
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void SerialPortCom::serial_port_break()
{
    serialPort->close();
}

/***************************************************************
  *  @brief     发送数据
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void SerialPortCom::serial_snd_msg(QString msg)
{
    serialPort->write(msg.toUtf8());
}

/***************************************************************
  *  @brief     接收数据
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
QString SerialPortCom::serial_rev_msg()
{
    return QString::fromUtf8(serialPort->readAll());
}

/***************************************************************
  *  @brief     串口配置，并开启定时器
  *  @param     无
  *  @note      槽函数，子线程中执行
  *  @Sample usage:
 **************************************************************/
void SerialPortCom::slot_configSrialport()
{
    qDebug() << "serial port cfg cur thread: " << QThread::currentThreadId();
    serial_port_connect();

    bool if_port_connected = checkPortAvailability(COM);
    if (if_port_connected) {
        qDebug() << "串口打开";
        timer_Serialport->start(200);   // 开启定时器
    } else {
        qDebug() << "串口打开失败";
    }
}

/***************************************************************
  *  @brief     串口关闭，断开连接，删除对象，并关闭定时器
  *  @param     无
  *  @note      槽函数，子线程中执行
  *  @Sample usage:
 **************************************************************/
void SerialPortCom::slot_closeOpneSrialport()
{
    qDebug() << "close serial current thread: " << QThread::currentThreadId();
    // 关闭串口
    serial_port_break();
    serialPort->deleteLater();
    serialPort = NULL;
    delete serialPort;      // 这里待定
    // 关闭定时器
    timer_Serialport->stop();
}

/***************************************************************
  *  @brief     接收数据，并将数据通过信号发送到液压站
  *  @param     无
  *  @note      槽函数，子线程中执行
  *  @Sample usage:
 **************************************************************/
void SerialPortCom::slots_readData()
{
    QString rev_data = serial_rev_msg();
    emit send_data(rev_data);
//    qDebug() << "read_data: " << rev_data << "cur thread: " << QThread::currentThreadId();
}

/***************************************************************
  *  @brief     发送数据
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void SerialPortCom::writeData()
{
    qDebug() << "snd thread: " << QThread::currentThreadId();
    serial_snd_msg(SEND_MSG);
}

/***************************************************************
  *  @brief     初始化，主要进行定时器的创建
  *  @param     无
  *  @note      槽函数，线程开启时触发
  *  @Sample usage:
 **************************************************************/
void SerialPortCom::slot_serialport_init()
{
    qDebug() << "启动线程";
    // 创建定时 - Ps: 如果线程中需要定时一定要在线程中Start
    timer_Serialport = new QTimer();
    connect(timer_Serialport, &QTimer::timeout, this, &SerialPortCom::writeData);
    qDebug() << "定时器配置完成。";
    qDebug() << "init conn cur thread: " << QThread::currentThreadId();
}

/***************************************************************
  *  @brief     检查指定端口是否已经被占用
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
bool SerialPortCom::checkPortAvailability(const QString &portName) {
    // 获取系统中所有串口的信息
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();

    // 遍历所有串口信息
    foreach (const QSerialPortInfo &portInfo, portList) {
        if (portInfo.portName() == portName) {
            // 如果找到匹配的串口名称，检查其是否可用
            if (portInfo.isBusy()) {
                qDebug() << portName << "is busy.";
                return true;
            } else {
                qDebug() << portName << "is available.";
                return false;
            }
        }
    }

    // 如果没有找到匹配的串口
    qDebug() << portName << "not found.";
    return false;
}
