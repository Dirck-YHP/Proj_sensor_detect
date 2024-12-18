#include "showwin_measureresis.h"
#include "ui_showwin_measureresis.h"

showWin_measureResis::showWin_measureResis(Resis *mea_resis, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_measureResis),
    _resis(mea_resis)
{
    ui->setupUi(this);

    /*-------------------- UI界面 --------------------------*/
    UI_init();


    //  根据用户选择设置哪些可见
    set_visible();

    /********************** 接收电阻值并显示 **********************/
    connect(_resis, &Resis::send_resis_to_ui,
            this, &showWin_measureResis::slot_get_resis_and_show);

    /********************** 对象析构 **********************/
    connect(this, &showWin_measureResis::signal_delete,
            mea_resis, &Resis::slot_acq_delete);

    connect(this, &showWin_measureResis::signal_change_resis,
            mea_resis, &Resis::slot_get_r_idx);
}

void showWin_measureResis::UI_init()
{
    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->label_bat->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_ch1->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_ch2->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_ch3->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_ch4->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_ch5->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_resis->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");

    ui->btn_ok->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_start_finish_mea->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");

    ui->lineE_show_resis_1->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_show_resis_2->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_show_resis_3->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_show_resis_4->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_show_resis_5->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
}

showWin_measureResis::~showWin_measureResis()
{
    emit signal_delete();
    qDebug() << "(In Win)angle window destroyed";
    qDebug() << "------------------------";

    delete ui;
}

/***************************************************************
  *  @brief     ok键按下
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_measureResis::on_btn_ok_clicked()
{
    _resis->stop_acquire();

    this->close();
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      槽函数——开始测量/结束测量键
  *  @Sample usage:
 **************************************************************/
void showWin_measureResis::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");
        Assist::board_init(true);

        /********************** ni9205开始采集 **********************/
        _resis->start_acquire();

    } else {
        ui->btn_start_finish_mea->setText("开始测量");

        /********************** 数据采集相关 **********************/
        _resis->stop_acquire();
    }
}

/***************************************************************
  *  @brief     接收电阻值 并在数值框中显示
  *  @param     无
  *  @note      槽函数——数值框
  *          电阻 * (len - 1)、电池电量
  *  @Sample usage:
 **************************************************************/
void showWin_measureResis::slot_get_resis_and_show(QVector<double> data)
{
    /****************************** 新板 *************************************/
    // 接收到的data中数据顺序如下：
    // 电阻 * (len - 1)、电池电量
    int total_len = data.size();
//    qDebug() << "(In Win)处理之后的数据大小为：" << total_len;

    /*********************** 电阻数值框显示 *************************/
    QString selected_channel_str = _resis->get_channel();
    QVector<int> selected_channel_arr  = Assist::extractNumbers(selected_channel_str);

    int start_idx = 0;
    const int DIGIT = 1;

    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        if (selected_channel_arr.contains(15 - ch_num)) {
            QString lineE_name = "lineE_show_resis_" + QString::number(ch_num);
            QLineEdit *lineE = this->findChild<QLineEdit*>(lineE_name);

            if (data[start_idx] < 1000)
                lineE->setText(QString::number(data[start_idx], 'f', DIGIT) + "Ω");
            else if (data[start_idx] < 1000000) {
                double show_r = data[start_idx] / 1000;
                lineE->setText(QString::number(show_r, 'f', DIGIT) + "KΩ");
            }
            else {
                double show_r = data[start_idx] / 1000000;
                lineE->setText(QString::number(show_r, 'f', DIGIT) + "MΩ");
            }

            start_idx++;
        }
    }

    /*********************** 电池电量 *****************************/
    double bat = data[total_len - 1];
    ui->pBar_battery->setOrientation(Qt::Horizontal);  // 水平方向
    ui->pBar_battery->setMinimum(0);                   // 最小值
    ui->pBar_battery->setMaximum(25);                   // 最大值
    double dProgress = (bat - ui->pBar_battery->minimum()) * 100.0
                    / (ui->pBar_battery->maximum() - ui->pBar_battery->minimum());
    // 定义电量档位
    int batteryLevel;
    if (dProgress <= 25.0) {
        batteryLevel = 25;  // 第一档：25%
    } else if (dProgress <= 50.0) {
        batteryLevel = 50;  // 第二档：50%
    } else if (dProgress <= 75.0) {
        batteryLevel = 75;  // 第三档：75%
    } else {
        batteryLevel = 100; // 第四档：100%
    }

    ui->pBar_battery->setValue(batteryLevel);                  // 当前进度
    ui->pBar_battery->setFormat(QString::fromLocal8Bit("bat left: %1%").arg(QString::number(batteryLevel, 'f', 1)));
    ui->pBar_battery->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式
}

/***************************************************************
  *  @brief     根据用户的通道选择结果决定对应通道的可见
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void showWin_measureResis::set_visible()
{
    QString selected_channel_str = _resis->get_channel();
    QVector<int> selected_channel_arr  = Assist::extractNumbers(selected_channel_str);

    qDebug() << "(In Win)" << selected_channel_arr;
    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        if (selected_channel_arr.contains(15 - ch_num)) {
            QString lineEdit_name = "lineE_show_resis_" + QString::number(ch_num);
            QLineEdit *lineEdit = this->findChild<QLineEdit*>(lineEdit_name);
            lineEdit->setEnabled(true);

            QString label_name = "label_ch" + QString::number(ch_num);
            QLabel *label = this->findChild<QLabel*>(label_name);
            label->setEnabled(true);
        } else {
            QString lineEdit_name = "lineE_show_resis_" + QString::number(ch_num);
            QLineEdit *lineEdit = this->findChild<QLineEdit*>(lineEdit_name);
            lineEdit->setEnabled(false);

            QString label_name = "label_ch" + QString::number(ch_num);
            QLabel *label = this->findChild<QLabel*>(label_name);
            label->setEnabled(false);
            label->setStyleSheet("color:rgb(254,254,254);");
        }
    }
}

void showWin_measureResis::on_comboBox_currentIndexChanged(int index)
{
    emit signal_change_resis(index);
}

