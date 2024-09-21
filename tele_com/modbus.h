#ifndef MODBUS_H
#define MODBUS_H

#include <QObject>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QVariant>
#include <QDebug>
#include <QThread>
#include <QSerialPortInfo>

class Modbus : public QObject
{
    Q_OBJECT
public:
    Modbus(QObject *parent = nullptr);

public:
    int put_read_num();     // 将协议读到的值传出去
    QModbusDevice::State put_modbusdevice_state();      // 将电机当前状态传出去

    void get_input_angle(QString input_angle);  // 获取用户输入角度
    void get_input_spd(QString input_spd);      // 获取用户输入速度
    void build_connecttion();   // 建立连接
    void enable_motor();        // 电机使能
    void run_motor();           // 电机运行

    void disable_motor();       // 电机失能
    void break_connection();    // 断开连接

    void stop_motor();          // 急停

    void angle_cali();          // 角度校准：设置电机当前位置

    QModbusRtuSerialMaster *get_modbus_dev();
private:
    void write_run(int address, int count, int parameter);      // 往地址写
    void read(int address, int count);                          // 从地址读
    void readSpeed(int address, int count);

    void read_Data();
    void read_speed();  // 读取当前电机运行速度

    bool checkPortAvailability(const QString &portName);
private:
    double _input_angle;
    double _input_spd;
    bool _angle_calibration = false;

    bool BEGIN_READ = false;

    QModbusRtuSerialMaster *_modbusDevice = nullptr;
    QTimer *timer_modbus;

    const QString COM = "COM3";

    int _read_num = 0;                  // 读到的值
    double _read_speed = 0.0;

    double _angle_cali;
public slots:
    void slot_modbus_init();            // 初始化——创定时器
    void slot_modbus_delete();

    void slot_configModbus();
    void slot_closeOpneModbus();

    void slot_get_angle_cali(double angle_cali);

signals:
    void send_data(int data);
    void send_spd(int spd);
};

#endif // MODBUS_H
