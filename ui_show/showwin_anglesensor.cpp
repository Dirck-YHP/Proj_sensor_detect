#include "showwin_anglesensor.h"
#include "ui_showwin_anglesensor.h"

showWin_angleSensor::showWin_angleSensor(QString file_save_dir,
                                         AngleSensor *angle_sensor,
                                         bool if_need_motor,
                                         QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_angleSensor),
    _angle_sensor(angle_sensor),
    _if_need_motor(if_need_motor),
    _file_save_dir(file_save_dir)
{
    ui->setupUi(this);
    /*-------------------- UI界面 --------------------------*/
    UI_init();

    /********************** 电机相关 **********************/
    // 是否需要电机
    if (_if_need_motor) {
        ui->btn_run_stop->setVisible(true);     // 设置为可见
        ui->btn_stop_now->setVisible(true);

        if (_motor == nullptr) {
            _motor = new Motor;

            // 用户点击“运行”之后会发送这个配置信号 给电机
            connect(this, &showWin_angleSensor::signal_setConfigModbus,
                    _motor, &Motor::get_config_signal);
            // 用户点击“停止”之后会发送这个关闭信号 给电机
            connect(this, &showWin_angleSensor::signal_closeOpenModbus,
                    _motor, &Motor::get_close_signal);

            // 接收电机发送的角度数据，数值框+画图显示
            connect(_motor, &Motor::send_angle_to_ui,
                    this, &showWin_angleSensor::slot_get_angle);

            // 用户点击“角度校准”之后会发送这个信号 给电机
            connect(this, &showWin_angleSensor::signal_angle_cali,
                    _motor, &Motor::slot_get_angle_cali);

             qDebug() << "(In Win)first new motor ";
        }

    } else {
        if (_motor == nullptr) {
            _motor = new Motor;
        }
        // 如果不需要电机就都不可见
        ui->btn_run_stop->setVisible(false);
        ui->btn_stop_now->setVisible(false);
        ui->lineE_motor_angle->setVisible(false);
        ui->lineE_motor_circle->setVisible(false);
        ui->label_motor_angle->setVisible(false);
        ui->label_motor_circle->setVisible(false);
    }

    /********************** 文件保存相关 **********************/
    if (_file_save_dir != "") {
        FILE_SAVE = true;
        _data_save = new DataSave;
        _timer_savefile.setInterval(500);       // 20ms一个数据点，500ms写入到文件一次，25个点
        connect(&_timer_savefile, &QTimer::timeout, this, &showWin_angleSensor::save_data);
    } else {
        FILE_SAVE = false;
        qDebug() << "(In Win)do not save file!";
    }

    /********************** 画图参数配置 **********************/
    ui->plot_angle->clearGraphs();
    ui->plot_angle->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_angle->xAxis->setLabel("time/s");
    ui->plot_angle->yAxis->setLabel("Y");
    ui->plot_angle->yAxis->setRange(-10, 10);

    channel_num = 2;
    // Graph数量 = 角位移传感器角度(1) + 电机(1)
    for (int i = 0; i < channel_num; i++) {
        ui->plot_angle->addGraph();
        ui->plot_angle->graph(i)->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256)));
    }

    /********************** qt特性配置 **********************/
    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);

    /***************** 接收传感器发送的电压电流角度 *******************/
    connect(_angle_sensor, &AngleSensor::send_vol_cur_angle_to_ui,
            this, &showWin_angleSensor::slot_get_vol_cur_angle_and_show);

    /********************** 对象析构 **********************/
    connect(this, &showWin_angleSensor::signal_delete,
            _angle_sensor, &AngleSensor::slot_acq_delete);

    /********************** 错误检测 **********************/
    connect(_angle_sensor, &AngleSensor::sig_err_to_ui,
            this, &showWin_angleSensor::slot_get_err);
}

void showWin_angleSensor::UI_init()
{
    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->label_cali->setStyleSheet("min-width:32px;min-height:32px;max-width:32px;max-height:32px;border-radius:16px");
    ui->label_ang->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_bat->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_angle_err->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_motor_angle->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_motor_circle->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_sensor_angle->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_angle_err_per->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_signal_current->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_signal_voltage->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_supply_current->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_supply_voltage->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");

    ui->btn_ok->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_run_stop->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");
    ui->btn_start_finish_mea->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_stop_now->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");
    ui->btn_angle_cali->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");

    ui->lineE_angle_err->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_motor_angle->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_motor_circle->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_sensor_angle->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_angle_err_per->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_signal_current->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_signal_voltage->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_supply_current->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_supply_voltage->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
}

showWin_angleSensor::~showWin_angleSensor()
{
    emit signal_delete();
    qDebug() << "(In Win)angle window destroyed";
    qDebug() << "------------------------";

    delete ui;
}

/***************************************************************
  *  @brief     ok键按下
  *  @param     无
  *  @note      槽函数——删除motor对象
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::on_btn_ok_clicked()
{
    _angle_sensor->stop_acquire();

    if (_motor != nullptr) {
        delete _motor;
        qDebug() << "(In Win)motor delete succeed";
    }

    if (_data_save != nullptr) {
        delete _data_save;
        qDebug() << "(In Win)data_save and delete succeed!";
    }

    this->close();
}

/***************************************************************
  *  @brief     这里目前只涉及画图？
  *  @param     无
  *  @note      槽函数——开始测量/结束测量键
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");
        Assist::board_init(true);

        // 清零
        last_angle_sensor = 0.0;
        sig_error = false;

        /********************** ni9205开始采集 **********************/
        _angle_sensor->start_acquire();

        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            QString currentDateTime = "AS_" + _file_add_name + "_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
            QString file_name = _file_save_dir + "/" + currentDateTime + "_data.txt";

            qDebug() << "(In Win)fileName: " <<file_name;
            file.setFileName(file_name);
            if (!file.open(QIODevice::Append | QIODevice::Text))    // 打开文件
                return;

            QTextStream out(&file);
            out.setCodec("UTF-8");
            out << QString("传感器类型：")  << _angle_sensor->get_label().toUtf8()
                << QString("，采集范围：") << _angle_sensor->get_range().first << "~" << _angle_sensor->get_range().second
                << QString("，采集通道：") << _angle_sensor->get_channel().toUtf8() << "\n";
            out << QString("x") << QString("  传感器") << QString(" 电机") << "\n";

            _timer_savefile.start();    // 开启定时器，开始保存数据
        }

    } else {
        ui->btn_start_finish_mea->setText("开始测量");

        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            // 保存缓冲区中残余的数据
            _timer_savefile.stop();
            qDebug() << "data_buf_size_when_close: "
                     << save_data_buf_angle_sensor.size()
                     << save_data_buf_angle_motor.size();

            if (!save_data_buf_angle_motor.empty()) {
                QTextStream out(&file);
                out.setCodec("UTF-8");
                // 遍历数据并写入文件
                for (int i = 0; i < save_data_buf_angle_sensor.size(); i++) {
                    out << time_stamp << ":  "
                        << save_data_buf_angle_sensor[i].value << "    "
                        << save_data_buf_angle_motor[i].value << "\n";
                    time_stamp++;
                }

//                for (const SensorData& dataPoint : save_data_buf_angle_motor) {
//                    out << time_stamp << "," << dataPoint.value << "\n";
//                    time_stamp++;
//                }
                qDebug() << "finish file writing last!!! ";
            }
            file.close();
        }

        /********************** 数据采集相关 **********************/
        _angle_sensor->stop_acquire();
    }
}

/***************************************************************
  *  @brief     接收传感器的角度1 并画图
  *  @param     无
  *  @note      槽函数——数值框+画图
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::slot_get_vol_cur_angle_and_show(QVector<double> data)
{
    /****************************** 新板 *************************************/
    // 接收到的data中数据顺序如下：
    // 供电电压、信号电压、信号电流、供电电流、角度、电池电量
//    qDebug() << "(In Win)处理之后的数据大小为：" << data.size();
    const int DIGIT = 1;
    /*********************** 供电电压 *****************************/
    double sup_vol = data[0];
    ui->lineE_supply_voltage->setText(QString::number(sup_vol, 'f', DIGIT) + "V");

    /*********************** 信号电压 *****************************/
    double sig_vol = data[1];
    ui->lineE_signal_voltage->setText(QString::number(sig_vol, 'f', DIGIT) + "V");

    /*********************** 信号电流 *****************************/
    double sig_cur = data[2];
    // 补偿
    ui->lineE_signal_current->setText(QString::number(sig_cur, 'f', DIGIT) + "mA");

    /*********************** 供电电流 *****************************/
    double sup_cur = data[3];
    ui->lineE_supply_current->setText(QString::number(sup_cur, 'f', DIGIT) + "mA");

    /*********************** 传感器角度 ***************************/
    double angle_sensor;
    angle_sensor = data[4] - last_angle_sensor;
    // 累计角度
    // qDebug() << temp_angle << " " << data[4] << "   " << acc_cnt;

    // if (abs(temp_angle - data[4]) < THREAD_ANGLE) {
    //     angle_sensor = data[4] - last_angle_sensor + acc_cnt*360;
    //     temp_abs_angle = angle_sensor;
    // }else {
    //     angle_sensor = temp_abs_angle;
    // }
    // // 如果读取的角度值突变很大（大于范围的一半）
    // if (temp_angle - data[4] > THREAD_ANGLE && (temp_angle - ZERO_ANGLE) * (data[4] - ZERO_ANGLE) < 0) {  // 正向
    //     acc_cnt++;
    // }else if (temp_angle - data[4] < -THREAD_ANGLE && (temp_angle - ZERO_ANGLE) * (data[4] - ZERO_ANGLE) < 0) {    // 反向
    //     acc_cnt--;
    // }

    // angle_sensor += acc_cnt*360;
    // 每次电机重新运行时候，数据需要清零
    if (fresh_enc) {
        angle_sensor = 0.0;
        last_angle_sensor = data[4];
        fresh_enc = false;
        acc_cnt = 0;
    }

    /******************************/
    if (ui->btn_angle_cali->isChecked()) {
        if (abs(sig_cur - 12) < 0.1) {
            ui->label_cali->setStyleSheet("background:rgb(244,211,111);min-width:32px;min-height:32px;max-width:32px;max-height:32px;border-radius:16px");
            qDebug() << "=====================";
        }else {
            ui->label_cali->setStyleSheet("background:rgb(0,0,0);min-width:32px;min-height:32px;max-width:32px;max-height:32px;border-radius:16px");
        }
    }else {
        ui->label_cali->setStyleSheet("background:rgb(0,0,0);min-width:32px;min-height:32px;max-width:32px;max-height:32px;border-radius:16px");
    }

    /************* 角度数值框显示 **************/
    ui->lineE_sensor_angle->setText(QString::number(angle_sensor, 'f', DIGIT) + "°");

    temp_angle = data[4];


    /*********************** 电机角度 ***************************/
    /************* 电机转动圈数显示 ************/
    double cur_turn = _motor_angle / 360;

    ui->lineE_motor_circle->setText(QString::number(cur_turn, 'f', DIGIT) + "圈");

    /************** 角度数值框显示 ************/
    ui->lineE_motor_angle->setText(QString::number(_motor_angle, 'f', DIGIT) + "°");

    /************** 角度误差和百分比数值框显示 ************/
    double err_ang = abs(angle_sensor - _motor_angle);
    ui->lineE_angle_err->setText(QString::number(err_ang, 'f', DIGIT));
    double err_per = err_ang / angle_sensor * 100;
    ui->lineE_angle_err_per->setText(QString::number(err_per, 'f', DIGIT) + "%");

    /*********************** 角度画图 ***************************/
    int length = 1;
    QVector<double> x(length);
    int point_count = ui->plot_angle->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    // 画图，一次画一个点
    QVector<double> y1 = {angle_sensor};
    QVector<double> y2 = {_motor_angle};

    ui->plot_angle->graph(0)->addData(x, y1, true);
    ui->plot_angle->graph(1)->addData(x, y2, true);

    ui->plot_angle->rescaleAxes();       // 自适应大小
    ui->plot_angle->replot();

    /*********************** 电池电量 *****************************/
    double bat = data[5];
    ui->pBar_battery->setOrientation(Qt::Horizontal);  // 水平方向
    ui->pBar_battery->setMinimum(0);                   // 最小值
    ui->pBar_battery->setMaximum(25);                   // 最大值
    double dProgress = (bat - ui->pBar_battery->minimum()) * 100.0
                    / (ui->pBar_battery->maximum() - ui->pBar_battery->minimum());
    // 定义电量档位
    double batteryLevel;
    if (dProgress <= 25.0) {
        batteryLevel = 25.0;  // 第一档：25%
    } else if (dProgress <= 50.0) {
        batteryLevel = 50.0;  // 第二档：50%
    } else if (dProgress <= 75.0) {
        batteryLevel = 75.0;  // 第三档：75%
    } else {
        batteryLevel = 100.0; // 第四档：100%
    }

    ui->pBar_battery->setValue(batteryLevel);                  // 当前进度
    ui->pBar_battery->setFormat(QString::fromLocal8Bit("bat left: %1%").arg(QString::number(batteryLevel, 'f', 1)));
    ui->pBar_battery->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式

    /********************文件保存*********************/
    // 数据首先都放到缓冲区中
    if (FILE_SAVE) {
        _data_save->collectData(&save_data_buf_angle_sensor, angle_sensor);
        _data_save->collectData(&save_data_buf_angle_motor, _motor_angle);
    }
}


/*******************************电机************************************/
/***************************************************************
  *  @brief     按键：“角度校准”
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
// void showWin_angleSensor::on_btn_angle_cali_clicked()
// {
//     // double cur_angle = ui->lineE_angle_cali->text().toDouble();
//     // emit signal_angle_cali(cur_angle);
//     qDebug() << "(In Win)校准信号已发送！";
// }

/***************************************************************
  *  @brief     接收电机发送来的角度并在数值框中显示并【画图，角度2】
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::slot_get_angle(double motor_angle)
{
    _motor_angle = motor_angle;
}

/***************************************************************
  *  @brief     接收参数配置页面电机目标角度
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::update_motor_tar_angle(const QString &text)
{
    double angle = text.toDouble() * 360;

    _motor->set_target_angle(QString::number(angle));
}

/***************************************************************
  *  @brief     接收参数配置页面电机速度
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::update_motor_speed(const QString &text)
{
    qDebug() << "(In Win)spd: " << text;
    _motor->set_speed(text);
}

void showWin_angleSensor::update_file_name(const QString &text)
{
    _file_add_name = text;
    qDebug() << "(In Win)file_name: " << _file_add_name;
}

/***************************************************************
  *  @brief     按键：电机“运行”/“停止”
  *  @param     无
  *  @note      槽函数——“运行”时发送配置信号，即启动；“停止”时发送关闭信号，即停止
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::on_btn_run_stop_toggled(bool checked)
{
    if (checked) {
        ui->btn_run_stop->setText("停止");
        qDebug() << "(In Win)UI 运行 cur id" << QThread::currentThreadId();

        fresh_enc = true;

        // 发送配置信号
        emit signal_setConfigModbus();

    } else {
        ui->btn_run_stop->setText("运行");
        qDebug() << "(In Win)UI 停止 cur id" << QThread::currentThreadId();

        // 发送关闭信号
        emit signal_closeOpenModbus();
    }
}

/***************************************************************
  *  @brief     按键：电机“立即停止”
  *  @param     无
  *  @note      目前急停还没加“电机失能”，嘻嘻
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::on_btn_stop_now_clicked()
{
//    _motor->disable_motor();

    ui->btn_run_stop->setChecked(false);

    Assist::board_init(false);
}

/*******************************文件保存************************************/
/***************************************************************
  *  @brief     保存数据
  *  @param     无
  *  @note      槽函数，每500ms从缓冲区中取出数据写入一次【目前只有电机的角度】
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::save_data()
{
    QTextStream out(&file);
    out.setCodec("UTF-8");
    // 遍历数据并写入文件
    qDebug() << "(In W_file_save)size: " << save_data_buf_angle_sensor.size()
             << " " << save_data_buf_angle_motor.size();
    for (int i = 0; i < save_data_buf_angle_sensor.size(); i++) {
        out << time_stamp << ":  "
            << save_data_buf_angle_sensor[i].value << "    "
            << save_data_buf_angle_motor[i].value << "\n";
        time_stamp++;
    }

    save_data_buf_angle_sensor.clear();        // 清空缓冲区
    save_data_buf_angle_motor.clear();
}

/***************************************************************
  *  @brief     处理数据采集类的错误信号，给用户一个弹窗
  *  @param     无
  *  @note      槽函数——接收错误信号
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::slot_get_err(bool err)
{
    qDebug() << "(In Win)get err!——" << err;

    if (!sig_error) {
        sig_error = true;

        ErrorPrompt e_pmt;
        e_pmt.showError(ErrorType::NetworkError);
    }
}

void showWin_angleSensor::on_btn_angle_cali_toggled(bool checked)
{
    if (checked) {

    }
}

