#include "showwin_pressuresensor.h"
#include "ui_showwin_pressuresensor.h"

showWin_pressureSensor::showWin_pressureSensor(PressureSensor *pressure_sensor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_pressureSensor),
    _pressure_sensor(pressure_sensor)
{
    ui->setupUi(this);

    // 根据用户选择的压力传感器的接入通道来决定哪些可见
    set_visiable();

    // 初始化液压站
    if (_hydraulic_station == nullptr) {
        _hydraulic_station = new HydraulicStation;

        // 用户点击“开始测量”之后会发送这个配置信号给 液压站
        connect(this, &showWin_pressureSensor::signal_setConfigSerialPort,
                _hydraulic_station, &HydraulicStation::get_config_signal);
        // 用户点击“结束测量”之后会发送这个关闭信号给 液压站
        connect(this, &showWin_pressureSensor::signal_closeOpen,
                _hydraulic_station, &HydraulicStation::get_close_signal);

        qDebug() << "first new HydraulicStation and build conn";
    }

    // 这个定时器的目的是数值框的显示，因为接收数据频率很高，但是数值框没必要那么高
    _timer_hydrau.setInterval(500);
    connect(&_timer_hydrau, &QTimer::timeout, this, [=](){
        QString msg = _hydraulic_station->get_msg();    // 接收液压站的返回的压力值
        if (msg != "") {    // 如果不为空
            ui->textBrowser->append(msg);       // 暂时先单纯打印出来，后续要画波形
            ui->lineE_hydra_val->setText(msg);
        } else {    // 如果是空的话，则提示用户接收到的数据有问题
            qDebug() << "serial data received nothing!";
        }
    });

    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);
}

showWin_pressureSensor::~showWin_pressureSensor()
{
    qDebug() << "pressure window destroyed";
    delete ui;
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      槽函数——“开始测量”/“结束测量”
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");
        emit signal_setConfigSerialPort();
        _timer_hydrau.start();      // 开启定时

//        _pressure_sensor->start_acquire();  // 开始采集

        // 先获取参数配置页面勾选了哪几个通道,这里需要注意有没有去掉电压电流的通道
//        channel_num = Assist::extractNumbers(_pressure_sensor->get_channel()).size();

        // 根据通道数来确定要画多少个波形
//        ui->plot_pressure->clearGraphs();
//        ui->plot_pressure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
//        ui->plot_pressure->xAxis->setLabel("time/s");
//        ui->plot_pressure->yAxis->setLabel("Y");
//        ui->plot_pressure->yAxis->setRange(-10, 10);

//        for (int i = 0; i < channel_num; i++) {
//            ui->plot_pressure->addGraph();
//        }

//        // 建立连接
//        connect(_pressure_sensor, &PressureSensor::send_ni9205_to_ui,
//                this, &showWin_pressureSensor::get_data_and_plot_pressure);

    } else {
        ui->btn_start_finish_mea->setText("开始测量");
        emit signal_closeOpen();
        _timer_hydrau.stop();      // 开启定时

//        _pressure_sensor->stop_acquire();   // 停止采集
    }
}

/***************************************************************
  *  @brief     删除液压站对象
  *  @param     无
  *  @note      槽函数——“确认”
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::on_btn_ok_clicked()
{
    if (_hydraulic_station != nullptr) {
        delete _hydraulic_station;
        qDebug() << "HydraulicStation and delete succeed!";
    }

    this->close();
}

/***************************************************************
  *  @brief     画压力值
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::get_data_and_plot_pressure(QVector<double> data)
{

}

/***************************************************************
  *  @brief     检查参数配置页面的用户通道选择结果是否传过来
  *  @param     无
  *  @note      测试函数——待删
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::on_pushButton_clicked()
{
    ui->textBrowser->append(_pressure_sensor->get_channel());
}

/***************************************************************
  *  @brief     根据用户的通道选择结果决定对应通道的可见
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::set_visiable()
{
    QString selected_channel_str = _pressure_sensor->get_channel();
    QVector<int> selected_channel_arr  = Assist::extractNumbers(selected_channel_str);

//    qDebug() << selected_channel_arr;

    for (int ch_num = 1; ch_num <= 6; ch_num++) {
        if (selected_channel_arr.contains(ch_num)) {
            QString baseName = "lineE_"; // 基础名称
            setLineEditsForRowEnable(baseName + "pres_val", ch_num, true);
            setLineEditsForRowEnable(baseName + "signal_current", ch_num, true);
            setLineEditsForRowEnable(baseName + "signal_voltage", ch_num, true);
            setLineEditsForRowEnable(baseName + "supply_current", ch_num, true);
            setLineEditsForRowEnable(baseName + "supply_voltage", ch_num, true);
            QString label_name = "label_ch" + QString::number(ch_num);
            QLabel *label = this->findChild<QLabel*>(label_name);
            label->setEnabled(true);
        } else {
            QString baseName = "lineE_"; // 基础名称
            setLineEditsForRowEnable(baseName + "pres_val", ch_num, false);
            setLineEditsForRowEnable(baseName + "signal_current", ch_num, false);
            setLineEditsForRowEnable(baseName + "signal_voltage", ch_num, false);
            setLineEditsForRowEnable(baseName + "supply_current", ch_num, false);
            setLineEditsForRowEnable(baseName + "supply_voltage", ch_num, false);
            QString label_name = "label_ch" + QString::number(ch_num);
            QLabel *label = this->findChild<QLabel*>(label_name);
            label->setEnabled(false);
        }
    }
}

/***************************************************************
  *  @brief     处理groupbox
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::setLineEditsForRowEnable(const QString &baseName, int ch_num, bool isEnable)
{
    QString objectName = baseName + "_" + QString::number(ch_num);
    QLineEdit *lineEdit = ui->gridGroupBox->findChild<QLineEdit*>(objectName);

    if (lineEdit) {
        lineEdit->setEnabled(isEnable); // 设置为可见
    } else {
        qDebug() << "LineEdit not found:" << objectName;
    }
}

