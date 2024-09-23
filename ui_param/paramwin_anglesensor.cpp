#include "paramwin_anglesensor.h"
#include "ui_paramwin_anglesensor.h"

paramWin_angleSensor::paramWin_angleSensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_angleSensor)
{
    ui->setupUi(this);

    // ui界面
    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->label_motor->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_range->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_sensor_type->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_4mA->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_20mA->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

    ui->btn_ok->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_exit->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_load_data->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");
    ui->btn_back_mainW->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");

    ui->lineE_4mA->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->lineE_20mA->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->lineE_target_angle->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

    ui->cBox_angle_sensor_type->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->cBox_file_save->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_no_need_device->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

    // 连接电机目标角度和本地信号
    connect(ui->lineE_target_angle, &QLineEdit::textChanged,
            this, &paramWin_angleSensor::motor_target_angle_changed);

    connect(ui->lineE_file_name, &QLineEdit::textChanged,
            this, &paramWin_angleSensor::file_name);

    // 默认不保存文件
    QList<QWidget*> file_save_params;
    file_save_params << ui->label_file_name
                     << ui->lineE_file_name;
    foreach(QWidget *file_save_param, file_save_params) {
                file_save_param->setEnabled(false);
            }
}

paramWin_angleSensor::~paramWin_angleSensor()
{
    delete ui;
}

/***************************************************************
  *  @brief     确认按键
  *  @param     无
  *  @note      槽函数——弹出角位移传感器显示窗口
  *  @Sample usage:
 **************************************************************/
void paramWin_angleSensor::on_btn_ok_clicked()
{
    /********************* 获取角位移传感器的label *******************/
    angle_sensor = new AngleSensor;
    angle_sensor->set_label(ui->cBox_angle_sensor_type->currentText());     // 读取标签
    angle_sensor->set_range(ui->lineE_4mA->text(), ui->lineE_20mA->text()); // 读取量程
    angle_sensor->set_channel();

    /********************* 是否需要工装 *******************/
    if (!ui->checkBox_no_need_device->isChecked()) {
        IF_NEED_MOTOR = true;
    } else {    // 需要工装
        IF_NEED_MOTOR = false;
    }

    /********************* 显示窗口 *******************/
    show_win_angle_sensor = new showWin_angleSensor(m_file_save_dir, angle_sensor, IF_NEED_MOTOR);
    show_win_angle_sensor->show();

    // 连接参数窗口的电机目标输入和显示窗口的输出
    connect(this, &paramWin_angleSensor::motor_target_angle_changed,
            show_win_angle_sensor, &showWin_angleSensor::update_motor_tar_angle);

    // 连接参数窗口的电机速度和显示窗口的输出
    connect(this, &paramWin_angleSensor::motor_speed_changed,
            show_win_angle_sensor, &showWin_angleSensor::update_motor_speed);

    // 连接参数窗口和显示窗口的文件名
    connect(this, &paramWin_angleSensor::file_name,
            show_win_angle_sensor, &showWin_angleSensor::update_file_name);

    emit motor_target_angle_changed(ui->lineE_target_angle->text());
    emit motor_speed_changed(ui->lineE_motor_spd->text());
    emit file_name(ui->lineE_file_name->text());
}

/***************************************************************
  *  @brief     是否需要工装复选框
  *  @param     无
  *  @note      槽函数——决定电机相关控件是否可配置
  *  @Sample usage:
 **************************************************************/
void paramWin_angleSensor::on_checkBox_no_need_device_stateChanged(int arg1)
{
    QList<QWidget*> motor_params;       // 把电机相关的控件打包
    motor_params << ui->lineE_target_angle
            << ui->label_motor;

    if (arg1 == Qt::Unchecked) {    // 如果需要工装，则电机相关可配置

        foreach(QWidget *motor_param, motor_params) {
            motor_param->setEnabled(true);
        }
    } else if (arg1 == Qt::Checked) {   // 如果不需要工装，则电机参数不可配置

        foreach(QWidget *motor_param, motor_params) {
            motor_param->setEnabled(false);
        }
    }
}

/***************************************************************
  *  @brief     按键：退出
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void paramWin_angleSensor::on_btn_exit_clicked()
{
    qApp->quit();
}

/***************************************************************
  *  @brief     按键：返回主界面
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void paramWin_angleSensor::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

/***************************************************************
  *  @brief     是否保存数据
  *  @param     无
  *  @note      槽函数——改变m_file_save_dir的值
  *  @Sample usage:
 **************************************************************/
void paramWin_angleSensor::on_cBox_file_save_stateChanged(int arg1)
{
    QList<QWidget*> file_save_params;
    file_save_params << ui->label_file_name
                     << ui->lineE_file_name;

    if (arg1 == Qt::Checked) {
        m_file_save_dir = QFileDialog::getExistingDirectory(this, "Save file", "../", QFileDialog::ShowDirsOnly);
        qDebug() << m_file_save_dir;
        foreach(QWidget *file_save_param, file_save_params) {
            file_save_param->setEnabled(true);
        }
    } else if (arg1 == Qt::Unchecked) {
        m_file_save_dir = "";
        foreach(QWidget *file_save_param, file_save_params) {
            file_save_param->setEnabled(false);
        }
    }
}

/***************************************************************
  *  @brief     数据回放
  *  @param     无
  *  @note      槽函数——是否 导入历史数据
  *  @Sample usage:
 **************************************************************/
void paramWin_angleSensor::on_btn_load_data_clicked()
{
    SensorType type = SensorType::AngleSensor;
    func_win_data_review = new funcWin_DataReview(type);
    func_win_data_review->show();
}
