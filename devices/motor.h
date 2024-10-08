#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include <QThread>
#include <QDebug>

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

    void set_speed(QString motor_spd);

    void build_connection();        // 建立连接
    void break_connection();        // 断开连接

    void enable_motor();            // 电机使能
    void disable_motor();           // 电机失能

    void run_motor();               // 电机运行

    void stop_motor();              // 急停
    void angle_cili();              // 角度校准

    QModbusRtuSerialMaster *get_modbus_dev();

    QModbusDevice::State get_dev_state();   // 获取电机当前状态
private:
    // 线程相关变量
    Modbus *modbus_com;
    QThread *thread_modbus;
    // end

    QString _input_angle;

private slots:
    void rev_data_from_modbus(int data);
    void rev_spd_from_modbus(int data);

public slots:
    void get_config_signal();
    void get_close_signal();

    void slot_get_angle_cali(double angle_cali);

signals:
    void signal_set_config_modbus();
    void signal_close_modbus();

    void send_angle_to_ui(double angle);
    void send_spd_to_ui(double spd);

    void signal_delete();

    void signal_angle_cali(double angle_cali);
};

#endif // MOTOR_H
