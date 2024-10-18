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

    /********************** 接收电阻值并显示 **********************/
    connect(_resis, &Resis::send_resis_to_ui,
            this, &showWin_measureResis::slot_get_resis_and_show);

    /********************** 对象析构 **********************/
    connect(this, &showWin_measureResis::signal_delete,
            mea_resis, &Resis::slot_acq_delete);
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

    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        if (selected_channel_arr.contains(ch_num + 9)) {
            QString lineE_name = "lineE_show_resis_" + QString::number(ch_num);
            QLineEdit *lineE = this->findChild<QLineEdit*>(lineE_name);
            lineE->setText(QString::number(data[start_idx]));

            start_idx++;
        }
    }

    /*********************** 电池电量 *****************************/
    double bat = data[total_len - 1];
    ui->pBar_battery->setOrientation(Qt::Horizontal);  // 水平方向
    ui->pBar_battery->setMinimum(0);                   // 最小值
    ui->pBar_battery->setMaximum(24);                   // 最大值
    ui->pBar_battery->setValue(bat);                  // 当前进度
    double dProgress = (ui->pBar_battery->value() - ui->pBar_battery->minimum()) * 100.0
                    / (ui->pBar_battery->maximum() - ui->pBar_battery->minimum());
    ui->pBar_battery->setFormat(QString::fromLocal8Bit("bat left: %1%").arg(QString::number(dProgress, 'f', 1)));
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

    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        if (selected_channel_arr.contains(ch_num + 9)) {
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
