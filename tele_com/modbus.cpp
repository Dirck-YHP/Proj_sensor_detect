#include "modbus.h"

Modbus::Modbus(QObject *parent) : QObject(parent)
{
    _angle_calibration = false;

}



int Modbus::put_read_num()
{
    // 读电机当前绝对位置的值
    read(2, 2);

    return _read_num;
}

QModbusDevice::State Modbus::put_modbusdevice_state()
{
    return _modbusDevice.state();
}

void Modbus::get_input_angle(QString input_angle)
{
    _input_angle = input_angle.toDouble();
}

void Modbus::build_connecttion()
{
    // 设置串口参数
    _modbusDevice.setConnectionParameter(QModbusDevice::SerialPortNameParameter, "COM3");
    _modbusDevice.setConnectionParameter(QModbusDevice::SerialBaudRateParameter, QSerialPort::Baud9600);
    _modbusDevice.setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    _modbusDevice.setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
    _modbusDevice.setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);
    // 设置流控制参数
    QSerialPort serial_port;
    serial_port.setFlowControl(QSerialPort::NoFlowControl);
    // 打开连接
    if (!_modbusDevice.connectDevice()) {
        // 连接失败，处理错误
        qDebug() << "Connect Error!";
    }
}

void Modbus::enable_motor()
{
    write(0, 1, 0x101);
}

void Modbus::run_motor()
{
    if (!_angle_calibration) {  // 如果不进行角度校准，默认从0开始
        // 设置当前位置为0°
        write(0, 1, 0x200);
    }

//        // 绝对位移
//        write(0, 1, 0x301);

    // 相对位移
    write(0, 1, 0x302);

    int parameter = _input_angle * 12800 / 360;
    write(1, 2, parameter);
}



void Modbus::disable_motor()
{
    write(0, 1, 0x100);
}

void Modbus::break_connection()
{
    _modbusDevice.disconnectDevice();
}

void Modbus::stop_motor()
{
    write(0, 1, 0x401);
}



void Modbus::angle_cali(double cali_angle)
{
    _angle_calibration = true;

    // 失能状态下，首先写入位置参数
    disable_motor();     // 先失能

    int parameter = cali_angle * 12800 / 360;
    write(1, 2, parameter); // 写入位置参数：即传感器当前的角度
    write(0, 1, 0x200);     // 设置当前位置

    enable_motor();         // 再使能
}



void Modbus::write(int address, int count, int parameter)
{
    // 创建一个写入请求
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, address, count);
    for(int i = 0; i < count; i++){
        uint16_t val = parameter & 0xFFFF;
        writeRequest.setValue(i, val);
        parameter = parameter >> 16;
    }

    // 发送请求
    if (auto *reply = _modbusDevice.sendWriteRequest(writeRequest, 1)) {
        if (!reply->isFinished()) {
            connect(reply, &QModbusReply::finished, this, [reply]() {
                // 请求完成，处理结果
                if (reply->error() == QModbusDevice::NoError) {
                    // 请求成功
                    qDebug() << "Success Write!";
                } else {
                    // 请求出错，处理错误
                    qDebug() << "Error Write!";
                }
                // 删除已完成的回复
                reply->deleteLater();
            });
        } else {
            delete reply;
        }
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
    if (auto *reply = _modbusDevice.sendReadRequest(readRequest, 1)) {
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
                    qDebug() << "Success Read!" ;
                } else {
                    // 请求出错，处理错误
                    qDebug() << "Error Read!" << reply->errorString();
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
