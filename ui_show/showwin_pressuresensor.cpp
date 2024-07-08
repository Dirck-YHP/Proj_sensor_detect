#include "showwin_pressuresensor.h"
#include "ui_showwin_pressuresensor.h"

showWin_pressureSensor::showWin_pressureSensor(QString file_save_dir, PressureSensor *pressure_sensor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_pressureSensor),
    _pressure_sensor(pressure_sensor),
    _file_save_dir(file_save_dir)
{
    ui->setupUi(this);

    // 根据用户选择的压力传感器的接入通道来决定哪些可见
    set_visiable();

    /********************** 液压站相关 **********************/
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
//            qDebug() << "serial data received nothing!";
        }
    });

    /********************** 文件保存相关 **********************/
    if (_file_save_dir != "") {
        FILE_SAVE = true;
        _data_save = new DataSave;
        _timer_savefile.setInterval(500);       // 20ms一个数据点，500ms写入到文件一次，25个点
        connect(&_timer_savefile, &QTimer::timeout, this, &showWin_pressureSensor::save_data);
    } else {
        FILE_SAVE = false;
        qDebug() << "do not save file!";
    }

    /********************** qt特性配置 **********************/
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

        /************************ 液压站相关 ************************/
        emit signal_setConfigSerialPort();
        _timer_hydrau.start();                  // 开启定时：这个是限制ui数值框显示
        connect(_hydraulic_station, &HydraulicStation::send_press_to_ui,
                this, &showWin_pressureSensor::slot_plot_press_from_hydraSta);

        /************************ 压力传感器 ************************/
//        _pressure_sensor->start_acquire();  // 开始采集
        // 先获取参数配置页面勾选了哪几个通道,这里需要注意有没有去掉电压电流的通道
//        channel_num = Assist::extractNumbers(_pressure_sensor->get_channel()).size();

//        // 建立连接
//        connect(_pressure_sensor, &PressureSensor::send_ni9205_to_ui,
//                this, &showWin_pressureSensor::slot_plot_press_from_sensor);

        /************************ 画图相关 ************************/
        ui->plot_pressure->clearGraphs();
        ui->plot_pressure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->plot_pressure->xAxis->setLabel("time/s");
        ui->plot_pressure->yAxis->setLabel("Y");
        ui->plot_pressure->yAxis->setRange(-10, 10);

        channel_num = 1;        // 暂时测试，默认为1
        // Graph数量 = 压力传感器的通道数(channel_num) + 液压站(1)
        for (int i = 0; i < 1; i++) {
            ui->plot_pressure->addGraph();
        }

        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            QString currentDateTime = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
            QString file_name = _file_save_dir + "/" + currentDateTime + "_data.txt";
            file.setFileName(file_name);
            if (!file.open(QIODevice::Append | QIODevice::Text))    // 打开文件
                return;

            QTextStream out(&file);
            out.setCodec("UTF-8");
            out << QString("采集类型：")  << _pressure_sensor->get_label().toUtf8()
                << QString("，采集范围：") << _pressure_sensor->get_range().first << "~" << _pressure_sensor->get_range().second
                << QString("，采集通道：") << _pressure_sensor->get_channel().toUtf8() << "\n";

            _timer_savefile.start();    // 开启定时器，开始保存数据
        }

    } else {
        ui->btn_start_finish_mea->setText("开始测量");

        /************************ 液压站相关 ************************/
        emit signal_closeOpen();
        _timer_hydrau.stop();

        /********************** 文件保存相关 **********************/
        _timer_savefile.stop();
        qDebug() << "data_buf_size_when_close: " << save_data_buf_hydra.size();
        if (!save_data_buf_hydra.empty()) {
            QTextStream out(&file);
            out.setCodec("UTF-8");
            // 遍历数据并写入文件
            for (const SensorData& dataPoint : save_data_buf_hydra) {
                out << time_stamp << "," << dataPoint.value << "\n";
                time_stamp++;
            }
            qDebug() << "finish file writing last!!! ";
        }
        file.close();

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

    if (_data_save != nullptr) {
        delete _data_save;
        qDebug() << "data_save and delete succeed!";
    }

    this->close();
}

/***************************************************************
  *  @brief     画来自压力传感器的压力值
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::slot_plot_press_from_sensor(QVector<double> data)
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
  *  @brief     画来自液压站的压力值
  *  @param     0708：目前data改成了size为 1
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::slot_plot_press_from_hydraSta(QVector<double> data)
{
    int length = data.size() / channel_num;     // 每通道数据 数
    QVector<double> x(length);
    int point_count = ui->plot_pressure->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    // 画图，一共channel_num条曲线
    for (int i = 0; i < channel_num; i++) {
        ui->plot_pressure->graph(i)->addData(x,
            QVector<double>(data.begin() + i*length, data.begin() + i*length + length), true);
    }
    ui->plot_pressure->rescaleAxes();       // 自适应大小
    ui->plot_pressure->replot();

    /********************文件保存*********************/
    // 数据首先都放到缓冲区中
    _data_save->collectData(&save_data_buf_hydra, data[0]);
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

/***************************************************************
  *  @brief     保存数据
  *  @param     无
  *  @note      槽函数，每500ms从缓冲区中取出数据写入一次
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::save_data()
{
    QTextStream out(&file);
    out.setCodec("UTF-8");
    // 遍历数据并写入文件
    for (const SensorData& dataPoint : save_data_buf_hydra) {
        out << time_stamp << "," << dataPoint.value << "\n";
        time_stamp++;
    }
    save_data_buf_hydra.clear();                // 清空缓冲区
}

