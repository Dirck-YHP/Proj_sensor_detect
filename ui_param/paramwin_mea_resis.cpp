#include "paramwin_mea_resis.h"
#include "ui_paramwin_mea_resis.h"

paramWin_mea_resis::paramWin_mea_resis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_mea_resis)
{
    ui->setupUi(this);
}

paramWin_mea_resis::~paramWin_mea_resis()
{
    delete ui;
}

void paramWin_mea_resis::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

void paramWin_mea_resis::on_btn_exit_clicked()
{
    qApp->quit();
}

void paramWin_mea_resis::on_btn_ok_clicked()
{
    Resis *_resis = new Resis;
    _resis->set_channel(check_channel_choosed());

    show_win_measure_r = new showWin_measureResis(_resis);
    show_win_measure_r->show();
}

QString paramWin_mea_resis::check_channel_choosed() {
    QString channel_choosed;
    // 从 1 到 6 循环检查每个通道
    for (int i = 1; i <= 6; ++i) {
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
