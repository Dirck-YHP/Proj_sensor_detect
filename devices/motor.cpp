#include "motor.h"

Motor::Motor(QObject *parent) : QObject(parent)
{
    if (_modbus == nullptr) {
        _modbus = new Modbus;
        qDebug() << "fisrt new modbus succeed";
    }
}

Motor::~Motor()
{
    if (_modbus != nullptr) {
        qDebug() << "delete modus succeed";
        delete _modbus;
    }
}

void Motor::set_target_angle(QString motor_target_angle)
{
    _input_angle = motor_target_angle;      // 测试代码，后面删
    _modbus->get_input_angle(motor_target_angle);
}

QString Motor::get_target_angle() const
{
    return _input_angle;
}

void Motor::build_connection()
{
    _modbus->build_connecttion();
}

void Motor::break_connection()
{
    _modbus->break_connection();
}

void Motor::enable_motor()
{
    _modbus->enable_motor();
}

void Motor::disable_motor()
{
    _modbus->disable_motor();
}

void Motor::run_motor()
{
    _modbus->run_motor();
}

void Motor::stop_motor()
{
    _modbus->stop_motor();
}

void Motor::angle_cili()
{
    _modbus->angle_cali();
}

QModbusDevice::State Motor::get_dev_state()
{
    return _modbus->put_modbusdevice_state();
}

int Motor::get_read_num() const
{
    return _modbus->put_read_num();
}
