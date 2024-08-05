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

        qDebug() << "(In Win)first new HydraulicStation and build conn";
    }

    // 这个定时器的目的是数值框的显示，因为接收数据频率很高，但是数值框没必要那么高
    _timer_hydrau.setInterval(500);
    connect(&_timer_hydrau, &QTimer::timeout, this, [=](){
        QString msg = _hydraulic_station->get_msg();    // 接收液压站的返回的压力值
        if (msg != "") {    // 如果不为空
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
        qDebug() << "(In Win)do not save file!";
    }

    /********************** qt特性配置 **********************/
    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);

    /********************** 画图参数配置 **********************/
    ui->plot_pressure->clearGraphs();
    ui->plot_pressure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_pressure->xAxis->setLabel("time/s");
    ui->plot_pressure->yAxis->setLabel("Y");
    ui->plot_pressure->yAxis->setRange(-10, 10);

//        channel_num = Assist::extractNumbers(_pressure_sensor->get_channel()).size();
//        qDebug() << "(In Win)pre_channel_choosed: " << channel_num;
//        // Graph数量 = 选择的压力传感器个数(channel_num) + 液压站(1)
    channel_num = 2;
    for (int i = 0; i < channel_num; i++) {
        ui->plot_pressure->addGraph();
    }

    /********************** 液压站相关 **********************/
    connect(_hydraulic_station, &HydraulicStation::send_press_to_ui,
            this, &showWin_pressureSensor::slot_plot_press_from_hydraSta);

    /******************** 压力传感器相关 *********************/
    connect(_pressure_sensor, &PressureSensor::send_vol_cur_pres_to_ui,
            this, &showWin_pressureSensor::slot_plot_press_from_sensor);

    /********************** 对象析构 **********************/
    connect(this, &showWin_pressureSensor::signal_delete,
            _pressure_sensor, &PressureSensor::slot_acq_delete);
}

showWin_pressureSensor::~showWin_pressureSensor()
{
    emit signal_delete();
    qDebug() << "(In Win)pressure window destroyed";
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
        emit signal_setConfigSerialPort();      // 发送配置信号
        _timer_hydrau.start();                  // 开启定时：这个是限制ui数值框显示
//        connect(_hydraulic_station, &HydraulicStation::send_press_to_ui,
//                this, &showWin_pressureSensor::slot_plot_press_from_hydraSta);

        /************************ 压力传感器 ************************/
//        _pressure_sensor->start_acquire();      // 开始采集

//        connect(_pressure_sensor, &PressureSensor::send_vol_cur_pres_to_ui,
//                this, &showWin_pressureSensor::slot_plot_press_from_sensor);

//        /********************** 画图参数配置 **********************/
//        ui->plot_pressure->clearGraphs();
//        ui->plot_pressure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
//        ui->plot_pressure->xAxis->setLabel("time/s");
//        ui->plot_pressure->yAxis->setLabel("Y");
//        ui->plot_pressure->yAxis->setRange(-10, 10);

////        channel_num = Assist::extractNumbers(_pressure_sensor->get_channel()).size();
////        qDebug() << "(In Win)pre_channel_choosed: " << channel_num;
////        // Graph数量 = 选择的压力传感器个数(channel_num) + 液压站(1)
//        channel_num = 2;
//        for (int i = 0; i < channel_num; i++) {
//            ui->plot_pressure->addGraph();
//        }

        /********************** 文件保存相关 **********************/
        // 压力传感器的缓冲区大小根据用户选择的通道先确定
        save_data_buf_sensor.resize(channel_num);   // 这里是不是channel_num待定

        if (FILE_SAVE) {
            QString currentDateTime = "PS_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
            QString file_name = _file_save_dir + "/" + currentDateTime + "_data.txt";
            file.setFileName(file_name);
            if (!file.open(QIODevice::Append | QIODevice::Text))    // 打开文件
                return;

            QTextStream out(&file);
            out.setCodec("UTF-8");
            out << QString("传感器类型：")  << _pressure_sensor->get_label().toUtf8()
                << QString("，采集范围：") << _pressure_sensor->get_range().first << "~" << _pressure_sensor->get_range().second
                << QString("，采集通道：") << _pressure_sensor->get_channel().toUtf8() << "\n";
            out << QString("x") << QString("  传感器") << QString(" 液压站") << "\n";

            _timer_savefile.start();    // 开启定时器，开始保存数据
        }

    } else {
        ui->btn_start_finish_mea->setText("开始测量");

        /************************ 液压站相关 ************************/
        emit signal_closeOpen();
        _timer_hydrau.stop();

        /********************** 文件保存相关 **********************/
        // 保存缓冲区中残余的数据
        if (FILE_SAVE) {
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
        }

        /*********************** 压力传感器相关 **********************/
//        _pressure_sensor->stop_acquire();   // 停止采集
    }
}

/***************************************************************
  *  @brief     按键：确认
  *  @param     无
  *  @note      槽函数——删除液压站对象及数据保存对象
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::on_btn_ok_clicked()
{
    if (_hydraulic_station != nullptr) {
        delete _hydraulic_station;
        qDebug() << "(In Win)HydraulicStation and delete succeed!";
    }

    if (_data_save != nullptr) {
        delete _data_save;
        qDebug() << "(In Win)data_save and delete succeed!";
    }

    this->close();
}

/***************************************************************
  *  @brief     画来自压力传感器的压力值
  *  @param     无
  *  @note      槽函数:
  *          供电电压、(信号电压、信号电流、压力) * (len - 1)、电池电量
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::slot_plot_press_from_sensor(QVector<double> data)
{
    /****************************** 新板 *************************************/
    // 接收到的data中数据顺序如下：
    // 供电电压、(信号电压、信号电流、压力) * (len - 1)、电池电量
    int total_len = data.size();
    qDebug() << "(In Win)处理之后的数据大小为：" << total_len;

    /*********************** 数值框显示 *****************************/
    show_vol_cur_press(data);

    /*********************** 液压站相关 *****************************/
    /******************** 压力数值框显示 *********************/
    ui->lineE_hydra_val->setText(QString::number(_pressure) + "Pa.?");

    /*********************** 压力值画图 ****************************/
    // 根据用户选择确定通道然后画图
    int length = 1;
    QVector<double> x(length);
    int point_count = ui->plot_pressure->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    // 画图，一次画一个点
    for (int i = 0; i < (total_len - 2)/ 3; i++) {
        QVector<double> y = {data[3 + 3 * i]};
        ui->plot_pressure->graph(i)->addData(x, y, true);

        /*********************** 文件保存 *****************************/
        if (FILE_SAVE) {
            _data_save->collectData(&save_data_buf_sensor[i], data[3 + 3 * i]);
        }
    }

    // 液压站压力画图
    QVector<double> y_hy = {_pressure};
    ui->plot_pressure->graph(channel_num - 1)->addData(x, y_hy, true);

    ui->plot_pressure->rescaleAxes();       // 自适应大小
    ui->plot_pressure->replot();

    /*********************** 文件保存 *****************************/
    if (FILE_SAVE) {
        _data_save->collectData(&save_data_buf_hydra, _pressure);
    }

    /*********************** 电池电量 *****************************/
    double bat = data[total_len - 1];
    ui->pBar_battery->setOrientation(Qt::Horizontal);  // 水平方向
    ui->pBar_battery->setMinimum(0);                   // 最小值
    ui->pBar_battery->setMaximum(24);                   // 最大值
    ui->pBar_battery->setValue(bat);                  // 当前进度
    double dProgress = (ui->pBar_battery->value() - ui->pBar_battery->minimum()) * 100.0
                    / (ui->pBar_battery->maximum() - ui->pBar_battery->minimum());
    ui->pBar_battery->setFormat(QString::fromLocal8Bit("电池电量剩余：%1%").arg(QString::number(dProgress, 'f', 1)));
    ui->pBar_battery->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式
}

/***************************************************************
  *  @brief     画来自液压站的压力值
  *
  *  @param     0708：目前data改成了size为 1
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::slot_plot_press_from_hydraSta(QVector<double> data)
{
    _pressure = data[0];

//    /******************** 压力数值框显示 *********************/
//    ui->lineE_hydra_val->setText(QString::number(_pressure) + "Pa.?");

//    /********************* 压力画图 **********************/
//    int length = 1;
//    QVector<double> x(length);
//    int point_count = ui->plot_pressure->graph(1)->dataCount();

//    // 确定画图的横轴
//    for (int i = 0; i < length; i++) {
//        x[i] = i + point_count;
//    }

//    // 画图，一次画一个点
//    QVector<double> y = {_pressure};
//    ui->plot_pressure->graph(1)->addData(x, y, true);

//    ui->plot_pressure->rescaleAxes();       // 自适应大小
//    ui->plot_pressure->replot();

//    /********************文件保存*********************/
//    // 数据首先都放到缓冲区中
//    if (FILE_SAVE) {
//        _data_save->collectData(&save_data_buf_hydra, data[0]);
//    }
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

    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        if (selected_channel_arr.contains(ch_num + 25)) {
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
  *  @brief     各个参数数值框显示
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::show_vol_cur_press(QVector<double> data)
{
    QString selected_channel_str = _pressure_sensor->get_channel();
    QVector<int> selected_channel_arr  = Assist::extractNumbers(selected_channel_str);

    int start_idx = 0;
    int len = selected_channel_arr.size();

    for (int ch_num = 1; ch_num <= 5; ch_num++) {
        if (selected_channel_arr.contains(ch_num + 25)) {
            QString baseName = "lineE_"; // 基础名称
            // 供电电压、(信号电压、信号电流、压力) * (len - 1)、电池电量
            /*********************** 供电电压 *****************************/
            double sup_vol = data[0];
            setLineEditsForRowValue(baseName + "supply_voltage", ch_num, sup_vol);

            /*********************** 信号电压 *****************************/
            double sig_vol = data[1 + start_idx * len];
            setLineEditsForRowValue(baseName + "signal_voltage", ch_num, sig_vol);

            /*********************** 信号电流 *****************************/
            double sig_cur = data[2 + start_idx * len];
            setLineEditsForRowValue(baseName + "signal_current", ch_num, sig_cur);

            /*********************** 供电电流 *****************************/
            double sup_cur = data[2 + start_idx * len];
            setLineEditsForRowValue(baseName + "supply_current", ch_num, sup_cur);

            /*********************** 压力值 *****************************/
            double pressure = data[3 + start_idx * len];
            setLineEditsForRowValue(baseName + "pres_val", ch_num, pressure);

            start_idx++;
        }
    }
}

/***************************************************************
  *  @brief     处理groupbox
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void showWin_pressureSensor::setLineEditsForRowValue(const QString &baseName, int ch_num, double value)
{
    QString objectName = baseName + "_" + QString::number(ch_num);
    QLineEdit *lineEdit = ui->gridGroupBox->findChild<QLineEdit*>(objectName);

    if (lineEdit) {
        lineEdit->setText(QString::number(value));
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

