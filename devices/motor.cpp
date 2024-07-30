#include "motor.h"

Motor::Motor(QObject *parent) : QObject(parent)
{
    // 线程  参数
    modbus_com = new Modbus();
    thread_modbus = new QThread;
    qDebug() << "(In motor)fisrt new modbus";

    modbus_com->moveToThread(thread_modbus);
    // 回收
    connect(modbus_com, &QObject::destroyed, thread_modbus, &QThread::quit);

    connect(this, &Motor::signal_delete, modbus_com, &Modbus::slot_modbus_delete);
    connect(thread_modbus, &QThread::finished, modbus_com, &Modbus::deleteLater);
    connect(thread_modbus, &QThread::finished, thread_modbus, &QThread::deleteLater);

    // modbus配置初始化
    connect(thread_modbus, &QThread::started, modbus_com, &Modbus::slot_modbus_init);

    // 启动线程
    thread_modbus->start();

    // 接收来自ui界面的开始测量信号时，发送信号给modbus，触发其配置槽函数
    connect(this, &Motor::signal_set_config_modbus,
            modbus_com, &Modbus::slot_configModbus);

    // 接收来自ui界面的关闭测量信号，发送信号给modbus，触发其关闭槽函数
    connect(this, &Motor::signal_close_modbus,
            modbus_com, &Modbus::slot_closeOpneModbus);

    // 接收到来自ui界面的角度校准信号，发送信号给modbus，进行角度校准
    connect(this, &Motor::signal_angle_cali,
            modbus_com, &Modbus::slot_get_angle_cali);

    // 接收Modbus发送的数据信号，Motor这里转换成角度
    connect(modbus_com, &Modbus::send_data, this, &Motor::rev_data_from_modbus);
}

/***************************************************************
  *  @brief     析构
  *  @param     无
  *  @note      这里发送信号来断开电机的连接
  *  @Sample usage:
 **************************************************************/
Motor::~Motor()
{
    emit signal_delete();
}

/***************************************************************
  *  @brief     设置电机目标角度
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::set_target_angle(QString motor_target_angle)
{
    _input_angle = motor_target_angle;                  // 测试代码，后面删
    modbus_com->get_input_angle(motor_target_angle);
}

/***************************************************************
  *  @brief     暂没用到——待删
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
QString Motor::get_target_angle() const
{
    return _input_angle;
}

/***************************************************************
  *  @brief     暂没用到——待删
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::build_connection()
{
    modbus_com->build_connecttion();
}

/***************************************************************
  *  @brief     暂没用到——待删
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::break_connection()
{
    modbus_com->break_connection();
}

/***************************************************************
  *  @brief     电机使能
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::enable_motor()
{
    modbus_com->enable_motor();
}

/***************************************************************
  *  @brief     电机失能
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::disable_motor()
{
    modbus_com->disable_motor();
}

/***************************************************************
  *  @brief     电机运行
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::run_motor()
{
    modbus_com->run_motor();
}

/***************************************************************
  *  @brief     电机停止
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::stop_motor()
{
    modbus_com->stop_motor();
}

/***************************************************************
  *  @brief     电机角度校准
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::angle_cili()
{
    modbus_com->angle_cali();
}

/***************************************************************
  *  @brief     暂没用到——待删。返回_modbusDev对象
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
QModbusRtuSerialMaster *Motor::get_modbus_dev()
{
    return modbus_com->get_modbus_dev();
}

/***************************************************************
  *  @brief     暂没用到——待删。返回电机连接状态
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
QModbusDevice::State Motor::get_dev_state()
{
    return modbus_com->put_modbusdevice_state();
}

/***************************************************************
  *  @brief     暂没用到——待删
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
int Motor::get_read_num() const
{
    return modbus_com->put_read_num();
}

/***************************************************************
  *  @brief     接收modbus发送来的数据，转换成角度，发信号给ui
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void Motor::rev_data_from_modbus(int data)
{
    double motor_read_num = (double)data;
    double angle = motor_read_num * 360 / 12800;

    emit send_angle_to_ui(angle);
}

/***************************************************************
  *  @brief     接收ui的配置信号并发送配置信号给modbus类
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::get_config_signal()
{
    qDebug() << "(In motor)收到界面的配置信号";
    emit signal_set_config_modbus();
}

/***************************************************************
  *  @brief     接收ui的关闭信号并发送关闭信号给modbus类
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::get_close_signal()
{
    qDebug() << "(In motor)收到界面的关闭信号";
    emit signal_close_modbus();
}

/***************************************************************
  *  @brief     接收ui的角度校准信号并把目标角度发送给modbus
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void Motor::slot_get_angle_cali(double angle_cali)
{
    qDebug() << "(In motor)收到校准角度：" << angle_cali;
    emit signal_angle_cali(angle_cali);
}
