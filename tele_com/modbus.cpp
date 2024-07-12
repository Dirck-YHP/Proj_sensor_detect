#include "modbus.h"

Modbus::Modbus(QObject *parent) : QObject(parent)
{
     qDebug() <<  "Modbus构造。cur thread：" << QThread::currentThreadId();
    _angle_calibration = false;
}

/***************************************************************
  *  @brief     读命令——读电机当前绝对位置的值
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
int Modbus::put_read_num()
{
    // 读电机当前绝对位置的值
    read(2, 2);

    return _read_num;
}

/***************************************************************
  *  @brief     返回当前连接状态
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
QModbusDevice::State Modbus::put_modbusdevice_state()
{
    return _modbusDevice->state();
}

/***************************************************************
  *  @brief     获取用户输入的目标角度
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::get_input_angle(QString input_angle)
{
    _input_angle = input_angle.toDouble();
}

/***************************************************************
  *  @brief     命令——建立连接
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::build_connecttion()
{
    qDebug() << "0 BUILD cur thread: " << QThread::currentThreadId();
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

/***************************************************************
  *  @brief     写命令——电机使能
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::enable_motor()
{
    qDebug() << "1 ENABLE cur thread: " << QThread::currentThreadId();
    write_run(0, 1, 0x101);
}

/***************************************************************
  *  @brief     写命令——电机运行
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::run_motor()
{
    qDebug() << "2 RUN cur thread: " << QThread::currentThreadId();
    if (!_angle_calibration) {  // 如果不进行角度校准，默认从0开始
        // 设置当前位置为0°
        write_run(0, 1, 0x200);
    }

//        // 绝对位移
//        write(0, 1, 0x301);

    // 相对位移
    write_run(0, 1, 0x302);

    int parameter = _input_angle * 12800 / 360;
    write_run(1, 2, parameter);

    // 确保写命令执行完之后再开始读取角度
    BEGIN_READ = true;
    qDebug() << "2 RUN FINISH";
}

/***************************************************************
  *  @brief     写命令——电机失能
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::disable_motor()
{
    qDebug() << "DISABLE cur thread: " << QThread::currentThreadId();
    write_run(0, 1, 0x100);
}

/***************************************************************
  *  @brief     命令——断开连接
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::break_connection()
{
    qDebug() << "5 BREAK cur thread: " << QThread::currentThreadId();
    _modbusDevice->disconnectDevice();
}

/***************************************************************
  *  @brief     写命令——电机停止
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::stop_motor()
{
    qDebug() << "4 STOP cur thread: " << QThread::currentThreadId();
    write_run(0, 1, 0x401);
}

/***************************************************************
  *  @brief     角度校准，待定！！！
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::angle_cali()
{
    _angle_calibration = true;

    // 失能状态下，首先写入位置参数
    disable_motor();     // 先失能

    write_run(0, 1, 0x302); // 写入位置参数
    write_run(0, 1, 0x200);     // 设置当前位置

    enable_motor();         // 再使能
    _angle_calibration = false;
}

/***************************************************************
  *  @brief     返回_modbusDev对象
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
QModbusRtuSerialMaster *Modbus::get_modbus_dev()
{
    return _modbusDevice;
}

/***************************************************************
  *  @brief     写命令，子线程中执行
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
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
        qDebug() << "Succeed Write!";
    } else {
        // 发送请求失败，处理错误
        qDebug() << "Error Write Request!";
    }
}

/***************************************************************
  *  @brief     读命令，子线程中执行
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
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

/***************************************************************
  *  @brief     执行读操作
  *  @param     无
  *  @note      槽函数——由定时器触发的读函数
  *  @Sample usage:
 **************************************************************/
void Modbus::read_Data()
{
    if (BEGIN_READ) {
        // 读取数据
        int read_num = put_read_num();
        // 发送数据
        emit send_data(read_num);
    } else {
        qDebug() << "waiting for writing......";
    }
}

/***************************************************************
  *  @brief     在Motor中connect，创建定时器，并建立连接
  *  @param     无
  *  @note      槽函数——定时器配置
  *  @Sample usage:
 **************************************************************/
void Modbus::slot_modbus_init()
{
    qDebug() << "启动线程";
    // 建立连接
    build_connecttion();

    // 创建定时 - Ps: 如果线程中需要定时一定要在线程中Start
    timer_modbus = new QTimer();
    connect(timer_modbus, &QTimer::timeout, this, &Modbus::read_Data);
    qDebug() << "定时器配置完成。cur thread: " << QThread::currentThreadId();
}

/***************************************************************
  *  @brief     在Motor中connect，断开连接，删除对象
  *  @param     无
  *  @note      槽函数——负责断开连接并删除对象
  *  @Sample usage:
 **************************************************************/
void Modbus::slot_modbus_delete()
{
    // 断开连接
    qDebug() << "before break: " << put_modbusdevice_state();
    break_connection();
    qDebug() << "after break: " << put_modbusdevice_state();

    _modbusDevice->deleteLater();
    _modbusDevice = NULL;
    delete _modbusDevice;
}

/***************************************************************
  *  @brief     在Motor中connect。建立modbus连接，判断端口，启动定时器，电机使能和运行
  *  @param     无
  *  @note      槽函数——modbus配置
  *  @Sample usage:
 **************************************************************/
void Modbus::slot_configModbus()
{
    bool if_port_connected = checkPortAvailability(COM);
    if (if_port_connected) {
        qDebug() << "检查：串口已连接";
        timer_modbus->start(20);
    } else {
        qDebug() << "检查：串口连接失败";
    }
    qDebug() << "Modbus配置完成。cur thread: " << QThread::currentThreadId();

    // 电机使能
    enable_motor();

    // 电机运行
    run_motor();
}

/***************************************************************
  *  @brief     在Motor中connect。停止电机，关闭定时器
  *  @param     无
  *  @note      槽函数——modbus关闭
  *  @Sample usage:
 **************************************************************/
void Modbus::slot_closeOpneModbus()
{
    qDebug() << "now in slot close!";

    // 停止电机
    stop_motor();

    // 停止读取数据
    BEGIN_READ = false;

    // 关闭定时器
    timer_modbus->stop();

    qDebug() << "Modbus关闭。current thread: " << QThread::currentThreadId();
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
                return true;
            } else {
                return false;
            }
        }
    }

    // 如果没有找到匹配的串口
    qDebug() << portName << "not found.";
    return false;
}
