#include "paramwin_anglesensor.h"
#include "ui_paramwin_anglesensor.h"

paramWin_angleSensor::paramWin_angleSensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_angleSensor)
{
    ui->setupUi(this);
}

paramWin_angleSensor::~paramWin_angleSensor()
{
    delete ui;
}

void paramWin_angleSensor::on_btn_ok_clicked()
{
    angle_sensor = new AngleSensor;
    angle_sensor->set_label(ui->cBox_angle_sensor_type->currentText());     // 读取标签
    angle_sensor->set_range(ui->lineE_4mA->text(), ui->lineE_20mA->text()); // 读取量程
    angle_sensor->set_channel(ui->lineE_channel->text());


    if (!ui->checkBox_no_need_device->isChecked()) {    // 不需要工装

    } else {    // 需要工装

    }

    show_win_angle_sensor = new showWin_angleSensor(angle_sensor);
    show_win_angle_sensor->show();

}

void paramWin_angleSensor::on_checkBox_measure_resis_stateChanged(int arg1)
{
    QList<QWidget*> motor_params;       // 把电机相关的控件打包
    motor_params << ui->lineE_target_angle
            << ui->label_6
            << ui->btn_build_connect
            << ui->btn_break_connect
            << ui->btn_run_stop
            << ui->btn_stop_now;

    if (arg1 == Qt::Checked) {      // 如果测电阻，则工装及电机不可用
        ui->checkBox_no_need_device->setEnabled(false);

        foreach(QWidget *motor_param, motor_params) {
            motor_param->setEnabled(false);
        }
    } else if (arg1 == Qt::Unchecked) { // 如果不测电阻，则可用
        ui->checkBox_no_need_device->setEnabled(true);

        foreach(QWidget *motor_param, motor_params) {
            motor_param->setEnabled(true);
        }
    }
}

void paramWin_angleSensor::on_checkBox_no_need_device_stateChanged(int arg1)
{
    QList<QWidget*> motor_params;       // 把电机相关的控件打包
    motor_params << ui->lineE_target_angle
            << ui->label_6
            << ui->btn_build_connect
            << ui->btn_break_connect
            << ui->btn_run_stop
            << ui->btn_stop_now;

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

void paramWin_angleSensor::on_btn_exit_clicked()
{
    qApp->quit();
}

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
    if (arg1 == Qt::Checked) {
        m_file_save_dir = QFileDialog::getExistingDirectory(this, "Save file", "../", QFileDialog::ShowDirsOnly);
        qDebug() << m_file_save_dir;
    } else if (arg1 == Qt::Unchecked) {
        m_file_save_dir = "";
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
