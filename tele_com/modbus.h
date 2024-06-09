#ifndef MODBUS_H
#define MODBUS_H

#include <QObject>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QVariant>
#include <QDebug>

class Modbus : public QObject
{
    Q_OBJECT
public:
    Modbus(QObject *parent = nullptr);

public:
    int put_read_num();     // 将协议读到的值传出去
    QModbusDevice::State put_modbusdevice_state();      // 将电机当前状态传出去

    void get_input_angle(QString input_angle);  // 获取用户输入角度
    void build_connecttion();   // 建立连接
    void enable_motor();        // 电机使能
    void run_motor();           // 电机运行

    void disable_motor();       // 电机失能
    void break_connection();    // 断开连接

    void stop_motor();          // 急停

    void angle_cali(double cali_angle);          // 角度校准：设置电机当前位置
private:
    void write(int address, int count, int parameter);      // 往地址写
    void read(int address, int count);                      // 从地址读

private:
    double _input_angle;
//    bool _angle_calibration = false;

    QModbusRtuSerialMaster _modbusDevice;
    QTimer _timer;
    int _read_num = 0;       // 读到的值
};

#endif // MODBUS_H
