#include "paramwin_angleencoder.h"
#include "ui_paramwin_angleencoder.h"

paramWin_angleEncoder::paramWin_angleEncoder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_angleEncoder)
{
    ui->setupUi(this);

    // 连接电机目标角度和本地信号
    connect(ui->lineE_target_angle, &QLineEdit::textChanged,
            this, &paramWin_angleEncoder::motor_target_angle_changed);
}

paramWin_angleEncoder::~paramWin_angleEncoder()
{
    delete ui;
}

void paramWin_angleEncoder::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

void paramWin_angleEncoder::on_btn_exit_clicked()
{
    qApp->quit();
}

void paramWin_angleEncoder::on_btn_ok_clicked()
{
    angle_encoder = new AngleEncoder;
    angle_encoder->set_label(ui->cBox_angle_sensor_type->currentText());
    angle_encoder->set_pul_per_cir(ui->lineE_pulse_per_cir->text());
    angle_encoder->set_channel(ui->lineE_channel->text());

    if (ui->checkBox_measure_resis->isChecked()) {  // 如果选中了测电阻，则弹出测电阻的窗口
        show_win_measure_r = new showWin_measureResis;
        show_win_measure_r->show();
    } else {
        if (!ui->checkBox_no_need_device->isChecked()) {    // 不需要工装
            IF_NEED_MOTOR = true;

        } else {    // 需要工装
            IF_NEED_MOTOR = false;
        }
        show_win_angle_encoder = new showWin_angleEncoder(angle_encoder, IF_NEED_MOTOR);
        show_win_angle_encoder->show();

        // 连接参数窗口的电机目标输入和显示窗口的输出
        connect(this, &paramWin_angleEncoder::motor_target_angle_changed,
                show_win_angle_encoder, &showWin_angleEncoder::update_motor_tar_angle);
    }
}

void paramWin_angleEncoder::on_checkBox_measure_resis_stateChanged(int arg1)
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

void paramWin_angleEncoder::on_checkBox_no_need_device_stateChanged(int arg1)
{
    QList<QWidget*> motor_params;       // 把电机相关的控件打包
    motor_params << ui->lineE_target_angle
            << ui->label_6
            << ui->btn_build_connect
            << ui->btn_break_connect
            << ui->btn_run_stop
            << ui->btn_stop_now;

    if (arg1 == Qt::Unchecked) {    // 如果需要工装，则电机相关可配置
        ui->checkBox_measure_resis->setEnabled(true);

        foreach(QWidget *motor_param, motor_params) {
            motor_param->setEnabled(true);
        }
    } else if (arg1 == Qt::Checked) {   // 如果不需要工装，则电机参数不可配置
        ui->checkBox_measure_resis->setEnabled(false);

        foreach(QWidget *motor_param, motor_params) {
            motor_param->setEnabled(false);
        }
    }
}
