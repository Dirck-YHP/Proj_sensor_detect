#include "motor.h"

Motor::Motor(QObject *parent) : QObject(parent)
{
    // 线程  begin
    modbus_com = new Modbus();
    thread_modbus = new QThread;
    qDebug() << "fisrt new modbus";

    modbus_com->moveToThread(thread_modbus);
    // 回收
    connect(thread_modbus, &QThread::finished, modbus_com, &Modbus::deleteLater);
    connect(thread_modbus, &QThread::finished, thread_modbus, &QThread::deleteLater);
    connect(modbus_com, SIGNAL(destroyed(QObject*)), thread_modbus, SLOT(quit()));

    // modbus配置初始化
    connect(thread_modbus, &QThread::started, modbus_com, &Modbus::slot_modbus_init);

    // 启动线程
    thread_modbus->start();

    // 接收来自ui界面的开始测量信号，触发 modbus的配置
    connect(this, &Motor::signal_set_config_modbus,
            modbus_com, &Modbus::slot_configModbus);

    // 接收来自ui界面的关闭测量信号，触发 串口关闭
    connect(this, &Motor::signal_close_modbus,
            modbus_com, &Modbus::slot_closeOpneModbus);

    // 接收Modbus发送的数据，Motor这里来进行处理
    connect(modbus_com, &Modbus::send_data, this, &Motor::rev_data_from_modbus);
}

Motor::~Motor()
{
}

void Motor::set_target_angle(QString motor_target_angle)
{
    _input_angle = motor_target_angle;      // 测试代码，后面删
    modbus_com->get_input_angle(motor_target_angle);
}

QString Motor::get_target_angle() const
{
    return _input_angle;
}

void Motor::build_connection()
{
    modbus_com->build_connecttion();
}

void Motor::break_connection()
{
    modbus_com->break_connection();
}

void Motor::enable_motor()
{
    modbus_com->enable_motor();
}

void Motor::disable_motor()
{
    modbus_com->disable_motor();
}

void Motor::run_motor()
{
    modbus_com->run_motor();
}

void Motor::stop_motor()
{
    modbus_com->stop_motor();
}

void Motor::angle_cili()
{
    modbus_com->angle_cali();
}

QModbusRtuSerialMaster *Motor::get_modbus_dev()
{
    return modbus_com->get_modbus_dev();
}

QModbusDevice::State Motor::get_dev_state()
{
    return modbus_com->put_modbusdevice_state();
}

int Motor::get_read_num() const
{
    return modbus_com->put_read_num();
}

void Motor::rev_data_from_modbus(int data)
{
    double motor_read_num = (double)data;
    double angle = motor_read_num * 360 / 12800;

//    qDebug() << "in Motor-angle is :" << angle;
    emit send_angle_to_ui(angle);
}

/***************************************************************
  *  @brief     接收界面的配置信号并发送配置信号给modbus类
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::get_config_signal()
{
    qDebug() << "收到界面的配置信号";
    emit signal_set_config_modbus();
}

/***************************************************************
  *  @brief     接收界面的关闭信号并发送关闭信号给modbus类
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::get_close_signal()
{
    qDebug() << "收到界面的关闭信号";
    emit signal_close_modbus();
}
