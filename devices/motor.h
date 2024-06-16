#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include "tele_com/modbus.h"

class Motor : public QObject
{
    Q_OBJECT
public:
    explicit Motor(QObject *parent = nullptr);
    ~Motor();

public:
    void set_target_angle(QString motor_target_angle);
    QString get_target_angle() const;

    void build_connection();        // 建立连接
    void break_connection();        // 断开连接

    void enable_motor();            // 电机使能
    void disable_motor();           // 电机失能

    void run_motor();               // 电机运行

    void stop_motor();              // 急停
    void angle_cili();              // 角度校准

    QModbusDevice::State get_dev_state();   // 获取电机当前状态
    int get_read_num() const;             // 获取协议读到的值

    bool IF_MOTOR = false;

private:
    Modbus *_modbus = nullptr;

    QString _input_angle;


};

#endif // MOTOR_H
