#include "paramwin_mea_resis.h"
#include "ui_paramwin_mea_resis.h"

paramWin_mea_resis::paramWin_mea_resis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_mea_resis)
{
    ui->setupUi(this);

    // ui界面
    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->label_channel->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);");

    ui->checkBox_ch_1->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->checkBox_ch_2->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->checkBox_ch_3->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->checkBox_ch_4->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->checkBox_ch_5->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");

    ui->btn_ok->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_exit->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_back_mainW->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
}

paramWin_mea_resis::~paramWin_mea_resis()
{
    delete ui;
}

/***************************************************************
  *  @brief     按键
  *  @param     无
  *  @note      槽函数——返回主界面
  *  @Sample usage:
 **************************************************************/
void paramWin_mea_resis::on_btn_back_mainW_clicked()
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
void paramWin_mea_resis::on_btn_exit_clicked()
{
    qApp->quit();
}

/***************************************************************
  *  @brief     按键“确认”
  *  @param     无
  *  @note      槽函数——打开上层ui
  *  @Sample usage:
 **************************************************************/
void paramWin_mea_resis::on_btn_ok_clicked()
{
    _resis = new Resis;
    _resis->set_channel(check_channel_choosed());

    show_win_measure_r = new showWin_measureResis(_resis);
    show_win_measure_r->show();
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      功能函数：检查哪些通道被选中
  *  @Sample usage:
 **************************************************************/
QString paramWin_mea_resis::check_channel_choosed() {
    QString channel_choosed;
    // 从 1 到 5 循环检查每个通道
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
