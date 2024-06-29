#include "modbus.h"

Modbus::Modbus(QObject *parent) : QObject(parent)
{
     qDebug() <<  "1 线程ID：" << QThread::currentThreadId();
    _angle_calibration = false;
}

Modbus::~Modbus()
{
}

int Modbus::put_read_num()
{
    // 读电机当前绝对位置的值
    read(2, 2);

    return _read_num;
}

QModbusDevice::State Modbus::put_modbusdevice_state()
{
    return _modbusDevice->state();
}

void Modbus::get_input_angle(QString input_angle)
{
    _input_angle = input_angle.toDouble();
}

void Modbus::build_connecttion()
{
    _modbusDevice = new QModbusRtuSerialMaster();

    // 设置串口参数
    _modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, COM);
    _modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, QSerialPort::Baud9600);
    _modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    _modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
    _modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);
    // 设置流控制参数
    QSerialPort serial_port;
    serial_port.setFlowControl(QSerialPort::NoFlowControl);
    // 打开连接
    if (!_modbusDevice->connectDevice()) {
        // 连接失败，处理错误
        qDebug() << "Connect Error!";
    }
}

void Modbus::enable_motor()
{
    qDebug() << "write: en";
    write(0, 1, 0x101);
}

void Modbus::run_motor()
{
//    qDebug() << "write:run begin";
    if (!_angle_calibration) {  // 如果不进行角度校准，默认从0开始
        // 设置当前位置为0°
        qDebug() << "write:run 1 begin";
        write(0, 1, 0x200);
        qDebug() << "write:run 1 end";
    }

//        // 绝对位移
//        write(0, 1, 0x301);

    // 相对位移
    qDebug() << "write:run 2 begin";
    write(0, 1, 0x302);
    qDebug() << "write:run 2 end";

    int parameter = _input_angle * 12800 / 360;
    qDebug() << "write:run 3 begin";
    write(1, 2, parameter);
    qDebug() << "write:run 3 end";

//    qDebug() << "write:run end";

    // 确保写命令执行完之后再开始读取角度
    BEGIN_READ = true;
}



void Modbus::disable_motor()
{
    qDebug() << "write:disable";
    write(0, 1, 0x100);
}

void Modbus::break_connection()
{
    _modbusDevice->disconnectDevice();
}

void Modbus::stop_motor()
{
    qDebug() << "write:stop";
    write(0, 1, 0x401);
}



void Modbus::angle_cali()
{
    _angle_calibration = true;

    // 失能状态下，首先写入位置参数
    disable_motor();     // 先失能

    write(0, 1, 0x302); // 写入位置参数
    write(0, 1, 0x200);     // 设置当前位置

    enable_motor();         // 再使能
    _angle_calibration = false;
}

QModbusRtuSerialMaster *Modbus::get_modbus_dev()
{
    return _modbusDevice;
}

void Modbus::write_run(int address, int count, int parameter)
{
    // 创建一个写入请求
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, address, count);
    for(int i = 0; i < count; i++){
        uint16_t val = parameter & 0xFFFF;
        writeRequest.setValue(i, val);
        parameter = parameter >> 16;
    }

    // 发送请求
    if (auto *reply = _modbusDevice->sendWriteRequest(writeRequest, 1)) {
//        if (!reply->isFinished()) {
//            connect(reply, &QModbusReply::finished, this, [reply,this]() {
//                // 请求完成，处理结果
//                if (reply->error() == QModbusDevice::NoError) {
//                    // 请求成功
////                    qDebug() << "Success Write!";
////                    WRITE = false;
//                } else {
//                    // 请求出错，处理错误
////                    qDebug() << "Error Write!";
//                }
//                // 删除已完成的回复
//                reply->deleteLater();
//            });
//        } else {
//            delete reply;
//        }
    } else {
        // 发送请求失败，处理错误
        qDebug() << "Error Write Request!";
    }
}

void Modbus::read(int address, int count)
{
    // 创建一个读取请求
    QModbusDataUnit readRequest(QModbusDataUnit::InputRegisters, address, count);
    // 发送请求
    auto *reply = _modbusDevice->sendReadRequest(readRequest, 1);
    if (reply) {
        if (!reply->isFinished()) {
            connect(reply, &QModbusReply::finished, this, [=](){
                _read_num = 0;
                // 请求完成，处理结果
                if (reply->error() == QModbusDevice::NoError) {
                    const QModbusDataUnit result = reply->result();
                    for(int i = 0; i < count; i++){
                        int val = result.value(count - i - 1);
                        _read_num += val;
                        if(i != count - 1) _read_num = _read_num << 16;
                    }
//                    qDebug() << "Success Read!" ;
                } else {
                    // 请求出错，处理错误
//                    qDebug() << "Error Read!" << reply->errorString();
                }
                // 删除已完成的回复
                reply->deleteLater();
            });
        } else {
            delete reply;
        }
    } else {
        // 发送请求失败，处理错误
        qDebug() << "Error Read Request!";
    }
}

void Modbus::write(int address, int count, int parameter)
{
    _addr = address;
    _cnt = count;
    _param = parameter;
    WRITE = true;

    while (WRITE);      // 阻塞
    qDebug() << "阻塞结束";
}

void Modbus::read_and_write_Data()
{
    if (WRITE) {
        write_run(_addr, _cnt, _param);
        WRITE = false;
    }

    if (BEGIN_READ) {
        // 读取数据
        int read_num = put_read_num();
        // 发送数据
        emit send_data(read_num);
    } else {
        qDebug() << "waiting for writing......";
    }

}

void Modbus::slot_modbus_init()
{
    qDebug() << "启动线程";
    // 创建定时 - Ps: 如果线程中需要定时一定要在线程中Start
    timer_modbus = new QTimer();
    connect(timer_modbus, &QTimer::timeout, this, &Modbus::read_and_write_Data);
    qDebug() << "定时器配置完成。";
    qDebug() << "init conn cur thread: " << QThread::currentThreadId();
}

void Modbus::slot_configModbus()
{
    qDebug() << "modbus cfg cur thread: " << QThread::currentThreadId();
    build_connecttion();

    bool if_port_connected = checkPortAvailability(COM);
    if (if_port_connected) {
        qDebug() << "检查：串口已连接";
        timer_modbus->start(10);
    } else {
        qDebug() << "检查：串口连接失败";
    }
}

void Modbus::slot_closeOpneModbus()
{
    qDebug() << "close modbus current thread: " << QThread::currentThreadId();

    // 关闭modbus
//    break_connection();
    stop_motor();

    BEGIN_READ = false;
    // 关闭定时器
    timer_modbus->stop();

    qDebug() << put_modbusdevice_state();

    _modbusDevice->deleteLater();
    _modbusDevice = NULL;
    delete _modbusDevice;

}

/***************************************************************
  *  @brief     检查指定端口是否已经被占用
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
bool Modbus::checkPortAvailability(const QString &portName) {
    // 获取系统中所有串口的信息
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();

    // 遍历所有串口信息
    foreach (const QSerialPortInfo &portInfo, portList) {
        if (portInfo.portName() == portName) {
            // 如果找到匹配的串口名称，检查其是否可用
            if (portInfo.isBusy()) {
                qDebug() << portName << "is used.";
                return true;
            } else {
                qDebug() << portName << "is not used.";
                return false;
            }
        }
    }

    // 如果没有找到匹配的串口
    qDebug() << portName << "not found.";
    return false;
}
