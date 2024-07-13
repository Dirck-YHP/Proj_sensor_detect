#include "showwin_measureresis.h"
#include "ui_showwin_measureresis.h"

showWin_measureResis::showWin_measureResis(Resis *mea_resis, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_measureResis),
    _resis(mea_resis)
{
    ui->setupUi(this);

    //  根据用户选择设置哪些可见
    set_visible();
}

showWin_measureResis::~showWin_measureResis()
{
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

        /********************** ni9205开始采集 **********************/
        _resis->start_acquire();

        /********************** 接收电阻值并显示 **********************/
        connect(_resis, &Resis::send_ni9205_to_ui,
                this, &showWin_measureResis::slot_get_resis_and_show);

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
  *  @Sample usage:
 **************************************************************/
void showWin_measureResis::slot_get_resis_and_show(QVector<double> resis)
{

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

    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        if (selected_channel_arr.contains(ch_num)) {
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
        }
    }
}


