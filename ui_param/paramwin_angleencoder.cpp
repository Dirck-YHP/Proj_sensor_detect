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

/***************************************************************
  *  @brief     按键——返回主窗口
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void paramWin_angleEncoder::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

/***************************************************************
  *  @brief     软件退出
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void paramWin_angleEncoder::on_btn_exit_clicked()
{
    qApp->quit();
}

/***************************************************************
  *  @brief     确认按键
  *  @param     无
  *  @note      槽函数——弹出角位移编码器显示窗口
  *  @Sample usage:
 **************************************************************/
void paramWin_angleEncoder::on_btn_ok_clicked()
{
    /********************* 获取角位移编码器的label *******************/
    angle_encoder = new AngleEncoder;
    angle_encoder->set_label(ui->cBox_angle_sensor_type->currentText());
    angle_encoder->set_pul_per_cir(ui->lineE_pulse_per_cir->text());
    angle_encoder->set_channel(ui->lineE_channel->text());

    /********************* 是否需要工装 *******************/
    if (!ui->checkBox_no_need_device->isChecked()) {
        IF_NEED_MOTOR = true;
    } else {    // 需要工装
        IF_NEED_MOTOR = false;
    }

    /********************* 显示窗口 *******************/
    show_win_angle_encoder = new showWin_angleEncoder(angle_encoder, IF_NEED_MOTOR);
    show_win_angle_encoder->show();

    // 连接参数窗口的电机目标输入和显示窗口的输出
    connect(this, &paramWin_angleEncoder::motor_target_angle_changed,
            show_win_angle_encoder, &showWin_angleEncoder::update_motor_tar_angle);

}

/***************************************************************
  *  @brief     是否需要工装复选框
  *  @param     无
  *  @note      槽函数——决定电机相关控件是否可配置
  *  @Sample usage:
 **************************************************************/
void paramWin_angleEncoder::on_checkBox_no_need_device_stateChanged(int arg1)
{
    QList<QWidget*> motor_params;       // 把电机相关的控件打包
    motor_params << ui->lineE_target_angle
            << ui->label_6;

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
  *  @brief     是否保存数据
  *  @param     无
  *  @note      槽函数——改变m_file_save_dir的值
  *  @Sample usage:
 **************************************************************/
void paramWin_angleEncoder::on_cBox_file_save_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
        m_file_save_dir = QFileDialog::getExistingDirectory(this, "Save file", "../", QFileDialog::ShowDirsOnly);
        qDebug() << m_file_save_dir;
    } else if (arg1 == Qt::Unchecked) {
        m_file_save_dir = "";
    }
}
