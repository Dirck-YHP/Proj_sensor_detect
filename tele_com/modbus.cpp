#include "modbus.h"

Modbus::Modbus(QObject *parent) : QObject(parent)
{
     qDebug() <<  "(In modbus)Modbus构造。cur thread：" << QThread::currentThreadId();
    _angle_calibration = false;
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
    qDebug() << "(In modbus)ag:   " << _input_angle;
}

/***************************************************************
  *  @brief     获取用户输入的速度
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::get_input_spd(QString input_spd)
{
    _input_spd = input_spd.toFloat();
    qDebug() << "(In modbus)spd:" << _input_spd;
}

/***************************************************************
  *  @brief     命令——建立连接
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::build_connecttion()
{
    qDebug() << "(In modbus)0 BUILD cur thread: " << QThread::currentThreadId();
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
        qDebug() << "(In modbus)Connect Error!";
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
    qDebug() << "(In modbus)1 ENABLE cur thread: " << QThread::currentThreadId();
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
    qDebug() << "(In modbus)2 RUN cur thread: " << QThread::currentThreadId();
    qDebug() << "(In modbus)2   : " << _angle_calibration;
    if (!_angle_calibration) {  // 如果不进行角度校准，默认从0开始
        // 设置当前位置为0°
        write_run(0, 1, 0x200);
    } else {
        angle_cali();
        qDebug() << "(In modbus)2 angle_cali!!";
    }

//        // 绝对位移
//        write(0, 1, 0x301);

    // 相对位移
    write_run(0, 1, 0x302);

    int parameter = _input_angle * 12800 / 360;
    write_run(1, 2, parameter);

//    qDebug() << _input_spd;
    write_spd(3, 2, _input_spd);

    // 确保写命令执行完之后再开始读取角度
    BEGIN_READ = true;
    qDebug() << "(In modbus)2 RUN FINISH!!!!!!!!!!!!!!!";
}

/***************************************************************
  *  @brief     写命令——电机失能
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::disable_motor()
{
    qDebug() << "(In modbus)DISABLE cur thread: " << QThread::currentThreadId();
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
    qDebug() << "(In modbus)5 BREAK cur thread: " << QThread::currentThreadId();
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
    qDebug() << "(In modbus)4 STOP cur thread: " << QThread::currentThreadId();
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
    qDebug() << "(In modbus)now angle cali";
    // 失能状态下，首先写入位置参数
    disable_motor();            // 先失能

    write_run(0, 1, 0x302);     // 写入位置参数
    write_run(0, 1, 0x200);     // 设置当前位置

    // 待定
    write_run(0, 1, 0x302);     // 写入位置参数


    int parameter = _angle_cali * 12800 / 360;
    write_run(1, 2, parameter);
    qDebug() << "(In modbus)cali: " << _angle_cali;

    enable_motor();             // 再使能

    // 确保写命令执行完之后再开始读取角度
    BEGIN_READ = true;
    qDebug() << "(In modbus)finish angle cali";
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
        qDebug() << "(In modbus)Succeed Write!";
    } else {
        // 发送请求失败，处理错误
        qDebug() << "(In modbus)Error Write Request!";
    }
}

void Modbus::write_spd(int address, int count, float speed)
{
    // 创建一个写入请求
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, address, count);

    // 使用联合体将float转换为uint16_t
    union {
        float input;  // 输入的float值
        uint16_t words[2];  // 输出的uint16_t值
    } converter;

    converter.input = speed;

    // 设置写入请求的值
    writeRequest.setValue(0, converter.words[0]);
    writeRequest.setValue(1, converter.words[1]);

    // 发送请求
    if (auto *reply = _modbusDevice->sendWriteRequest(writeRequest, 1)) {
        if (!reply->isFinished()) {
            connect(reply, &QModbusReply::finished, this, [reply, this]() {
                // 请求完成，处理结果
                if (reply->error() == QModbusDevice::NoError) {
                    // 请求成功
                    qDebug() << "(In modbus)Succeed Write Float!";
                } else {
                    // 请求出错，处理错误
                    qDebug() << "(In modbus)Error Write Float!";
                }
                // 删除已完成的回复
                reply->deleteLater();
            });
        } else {
            delete reply;
        }
    } else {
        // 发送请求失败，处理错误
        qDebug() << "(In modbus)Error Write Request Float!";
    }
}

/***************************************************************
  *  @brief     读命令，子线程中执行
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Modbus::readMotorStatus(int address, int angleCount, int speedCount)
{
    // 创建一个读取请求，读取角度和速度的寄存器
        QModbusDataUnit readRequest(QModbusDataUnit::InputRegisters, address, angleCount + speedCount);
        // 发送请求
        auto *reply = _modbusDevice->sendReadRequest(readRequest, 1);
        if (reply) {
            if (!reply->isFinished()) {
                connect(reply, &QModbusReply::finished, this, [=]() mutable{
                    if (reply->error() == QModbusDevice::NoError) {
                        const QModbusDataUnit result = reply->result();
                        // 处理角度
                        quint32 raw_angle = (result.value(2) & 0xFFFF) | ((result.value(3) & 0xFFFF) << 16);
                        _read_num = *reinterpret_cast<int*>(&raw_angle);

                        // 处理速度
                        quint32 rawValue = (result.value(0) & 0xFFFF) | ((result.value(1) & 0xFFFF) << 16);
                        _read_speed = *reinterpret_cast<float*>(&rawValue);
                    }
                    // 删除已完成的回复
                    reply->deleteLater();
                });
            } else {
                delete reply;
            }
        } else {
            // 发送请求失败，处理错误
            qDebug() << "(In modbus)Error Read Motor Status Request!";
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
        readMotorStatus(0, 2, 2);
        int read_angle = _read_num;
        double read_spd = _read_speed;

        emit send_data(read_angle);
        emit send_spd(read_spd);
    } else {
        qDebug() << "(In modbus)waiting for writing......";
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
    qDebug() << "(In modbus)启动线程";
    // 建立连接
    build_connecttion();

    // 创建定时 - Ps: 如果线程中需要定时一定要在线程中Start
    timer_modbus = new QTimer();
    connect(timer_modbus, &QTimer::timeout, this, &Modbus::read_Data);
    qDebug() << "(In modbus)定时器配置完成。cur thread: " << QThread::currentThreadId();
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
    qDebug() << "(In modbus)before break: " << put_modbusdevice_state();
    break_connection();
    qDebug() << "(In modbus)after break: " << put_modbusdevice_state();

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
        qDebug() << "(In modbus)检查：串口已连接";
        timer_modbus->start(20);
    } else {
        qDebug() << "(In modbus)检查：串口连接失败";
    }
    qDebug() << "(In modbus)Modbus配置完成。cur thread: " << QThread::currentThreadId();

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
    qDebug() << "(In modbus)now in slot close!";

    // 停止电机
    stop_motor();

    // 停止读取数据
    BEGIN_READ = false;

    // 关闭定时器
    timer_modbus->stop();

    qDebug() << "(In modbus)Modbus关闭。current thread: " << QThread::currentThreadId();
}

/***************************************************************
  *  @brief     在Motor中connect。获取校准角度，并进行角度校准
  *  @param     无
  *  @note      槽函数——角度校准
  *  @Sample usage:
 **************************************************************/
void Modbus::slot_get_angle_cali(double angle_cali)
{
    _angle_calibration = true;

    _angle_cali = angle_cali;

//    _angle_calibration = false;
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
