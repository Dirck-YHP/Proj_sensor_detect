#include "paramwin_proximityswitch.h"
#include "ui_paramwin_proximityswitch.h"

paramWin_proximitySwitch::paramWin_proximitySwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_proximitySwitch)
{
    ui->setupUi(this);

    // ui界面
    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->label_channel->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_matirial->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_using_time->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_sensing_dis->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->label_sensor_type->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

    ui->cBox_distance->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->cBox_material->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->cBox_use_time->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->cBox_prox_switch_type->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->checkBox_ch_1->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_2->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_3->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_4->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->checkBox_ch_5->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
    ui->cBox_file_save->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

    ui->btn_ok->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_exit->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_back_mainW->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_load_data->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");

    connect(ui->lineE_file_name, &QLineEdit::textChanged,
            this, &paramWin_proximitySwitch::file_name);

    // 默认不保存文件
    QList<QWidget*> file_save_params;
    file_save_params << ui->label_file_name
                     << ui->lineE_file_name;
    foreach(QWidget *file_save_param, file_save_params) {
                file_save_param->setEnabled(false);
                file_save_param->setStyleSheet("font-size: 14pt;color:rgb(46,47,48);");
            }
}

paramWin_proximitySwitch::~paramWin_proximitySwitch()
{
    delete ui;
}

/***************************************************************
  *  @brief     退出
  *  @param     无
  *  @note      槽函数——退出
  *  @Sample usage:
 **************************************************************/
void paramWin_proximitySwitch::on_btn_exit_clicked()
{
    qApp->quit();
}

/***************************************************************
  *  @brief     按键
  *  @param     无
  *  @note      槽函数——返回主界面
  *  @Sample usage:
 **************************************************************/
void paramWin_proximitySwitch::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

/***************************************************************
  *  @brief     按键“确认”
  *  @param     无
  *  @note      槽函数——打开上层ui
  *  @Sample usage:
 **************************************************************/
void paramWin_proximitySwitch::on_btn_ok_clicked()
{
    QString chl = check_channel_choosed();
    if (chl == "") {
        qDebug() << "用户选择错误";
        return;
    }

    qDebug() << "choosed: " << chl;

    _proxi_switch = new ProximitySwitch;
    _proxi_switch->set_label(ui->cBox_prox_switch_type->currentText());
    _proxi_switch->set_sensing_dis((ui->cBox_distance->currentText()));
    _proxi_switch->set_using_time(ui->cBox_use_time->currentText());
    _proxi_switch->set_sensing_matirial((ui->cBox_material->currentText()));
    _proxi_switch->set_channel(chl);

    _show_win_prox_switch = new showWin_proximitySwitch(m_file_save_dir, _proxi_switch);
    _show_win_prox_switch->show();

    // 连接参数窗口和显示窗口的文件名
    connect(this, &paramWin_proximitySwitch::file_name,
            _show_win_prox_switch, &showWin_proximitySwitch::update_file_name);
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      功能函数：检查哪些通道被选中
  *  @Sample usage:
 **************************************************************/
QString paramWin_proximitySwitch::check_channel_choosed() {
    QString channel_choosed;
    int checked_cnt = 0;
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
            checked_cnt++;
        }
    }

    // 限定只能五选一
    if (checked_cnt > 1) {
        QMessageBox::information(this, "操作", "您只能选择一个通道");
        return "";
    } else if (checked_cnt == 1) {
        return channel_choosed;
    } else {
        QMessageBox::information(this, "操作", "请选择一个通道");
        return "";
    }
}

/***************************************************************
  *  @brief     是否保存数据
  *  @param     无
  *  @note      槽函数——改变m_file_save_dir的值
  *  @Sample usage:
 **************************************************************/
void paramWin_proximitySwitch::on_cBox_file_save_stateChanged(int arg1)
{
    QList<QWidget*> file_save_params;
    file_save_params << ui->label_file_name
                     << ui->lineE_file_name;

    if (arg1 == Qt::Checked) {
        m_file_save_dir = QFileDialog::getExistingDirectory(this, "Save file", "../", QFileDialog::ShowDirsOnly);
        qDebug() << m_file_save_dir;
        foreach(QWidget *file_save_param, file_save_params) {
            file_save_param->setEnabled(true);
            file_save_param->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");
        }
    } else if (arg1 == Qt::Unchecked) {
        m_file_save_dir = "";
        foreach(QWidget *file_save_param, file_save_params) {
            file_save_param->setEnabled(false);
            file_save_param->setStyleSheet("font-size: 14pt;color:rgb(46,47,48);");
        }
    }
}

/***************************************************************
  *  @brief     数据回放
  *  @param     无
  *  @note      槽函数——是否 导入历史数据
  *  @Sample usage:
 **************************************************************/
void paramWin_proximitySwitch::on_btn_load_data_clicked()
{
    SensorType type = SensorType::ProximitySwitch;
    func_win_data_review = new funcWin_DataReview(type);
    func_win_data_review->show();
}
