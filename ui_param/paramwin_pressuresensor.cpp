#include "paramwin_pressuresensor.h"
#include "ui_paramwin_pressuresensor.h"

paramWin_pressureSensor::paramWin_pressureSensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_pressureSensor)
{
    ui->setupUi(this);

    // ui界面
    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
//    ui->label_4mA->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_20mA->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_range->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_channel->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_sensor_type->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

    ui->cBox_pressure_sensor_type->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->cBox_file_save->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_1->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_2->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_3->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_4->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_5->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

//    ui->lineE_4mA->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->lineE_20mA->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

    ui->btn_ok->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_exit->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_back_mainW->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_load_data->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");
}

paramWin_pressureSensor::~paramWin_pressureSensor()
{
    delete ui;
}

/***************************************************************
  *  @brief     按键
  *  @param     无
  *  @note      槽函数——返回主界面
  *  @Sample usage:
 **************************************************************/
void paramWin_pressureSensor::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

/***************************************************************
  *  @brief     退出
  *  @param     无
  *  @note      槽函数——退出
  *  @Sample usage:
 **************************************************************/
void paramWin_pressureSensor::on_btn_exit_clicked()
{
    qApp->quit();
}

/***************************************************************
  *  @brief     按键“确认”
  *  @param     无
  *  @note      槽函数——打开上层ui
  *  @Sample usage:
 **************************************************************/
void paramWin_pressureSensor::on_btn_ok_clicked()
{
    _pressure_sensor = new PressureSensor;
    _pressure_sensor->set_label(ui->cBox_pressure_sensor_type->currentText());
    _pressure_sensor->set_range(range_4mA, ui->lineE_20mA->text());
    _pressure_sensor->set_channel(check_channel_choosed());

    show_win_press_sensor = new showWin_pressureSensor(m_file_save_dir, _pressure_sensor);
    show_win_press_sensor->show();
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      功能函数：检查哪些通道被选中
  *  @Sample usage:
 **************************************************************/
QString paramWin_pressureSensor::check_channel_choosed() {
    QString channel_choosed;
    // 从 1 到 5 循环检查每一路
    for (int i = 1; i <= 5; ++i) {
        // 构建每个 QCheckBox 的 objectName
        QString checkBoxName = QString("checkBox_ch_%1").arg(i);

        // 使用 findChild 查找对应的 QCheckBox
        QCheckBox *checkBox = ui->gridGroupBox->findChild<QCheckBox*>(checkBoxName);

        // 检查 QCheckBox 是否存在以及是否被勾选
        if (checkBox && checkBox->isChecked()) {
            if (!channel_choosed.isEmpty()) {
                channel_choosed.append(",");
            }
            // 将通道编号添加到字符串中
            channel_choosed.append(QString::number(i));
            // channel_choosed.append(电压+电流)
        }
    }
    return channel_choosed;
}

/***************************************************************
  *  @brief     是否保存数据
  *  @param     无
  *  @note      槽函数——改变m_file_save_dir的值
  *  @Sample usage:
 **************************************************************/
void paramWin_pressureSensor::on_cBox_file_save_stateChanged(int arg1)
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
void paramWin_pressureSensor::on_btn_load_data_clicked()
{
    SensorType type = SensorType::PressureSensor;
    func_win_data_review = new funcWin_DataReview(type);
    func_win_data_review->show();
}
