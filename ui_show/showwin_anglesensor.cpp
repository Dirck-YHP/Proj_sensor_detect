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

             qDebug() << "first new motor ";
        }

//        // 这个定时器的目的是数值框的显示，因为接收数据的频率很高，但是数值框显示频率没必要那么高
//        _timer_motor.setInterval(500);
//        connect(&_timer_motor, &QTimer::timeout, this, [=](){
//            // 这里接收电机返回的角度值并显示

////                if (_motor->get_dev_state() == QModbusDevice::ConnectedState) {
////                    ui->lineE_motor_angle->setText(QString::number(_motor_angle, 'f', 1));
////                }
//        });
//        _timer_motor.start();

    } else {
        // 如果不需要电机就都不可见
        ui->btn_run_stop->setVisible(false);
        ui->btn_stop_now->setVisible(false);
        ui->lineE_motor_angle->setVisible(false);
        ui->lineE_motor_circle->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
    }

    /********************** 文件保存相关 **********************/
    if (_file_save_dir != "") {
        FILE_SAVE = true;
        _data_save = new DataSave;
        _timer_savefile.setInterval(500);       // 20ms一个数据点，500ms写入到文件一次，25个点
        connect(&_timer_savefile, &QTimer::timeout, this, &showWin_angleSensor::save_data);
    } else {
        FILE_SAVE = false;
        qDebug() << "do not save file!";
    }

    /********************** qt特性配置 **********************/
    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);
}

showWin_angleSensor::~showWin_angleSensor()
{
    qDebug() << "angle window destroyed";
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
    if (_motor != nullptr) {
        delete _motor;
        qDebug() << "motor delete succeed";
    }

    if (_data_save != nullptr) {
        delete _data_save;
        qDebug() << "data_save and delete succeed!";
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

        /********************** ni9205开始采集 **********************/
        _angle_sensor->start_acquire();

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
        }

        /***************** 接收传感器发送的电压电流角度 *******************/
        connect(_angle_sensor, &AngleSensor::send_vol_cur_angle_to_ui,
                this, &showWin_angleSensor::slot_get_vol_cur_angle_and_show);


        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            QString currentDateTime = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
            QString file_name = _file_save_dir + "/" + currentDateTime + "_data.txt";
            file.setFileName(file_name);
            if (!file.open(QIODevice::Append | QIODevice::Text))    // 打开文件
                return;

            QTextStream out(&file);
            out.setCodec("UTF-8");
            out << QString("传感器类型：")  << _angle_sensor->get_label().toUtf8()
                << QString("，采集范围：") << _angle_sensor->get_range().first << "~" << _angle_sensor->get_range().second
                << QString("，采集通道：") << _angle_sensor->get_channel().toUtf8() << "\n";

            _timer_savefile.start();    // 开启定时器，开始保存数据
        }

    } else {
        ui->btn_start_finish_mea->setText("开始测量");

        /********************** 文件保存相关 **********************/
        // 保存缓冲区中残余的数据
        _timer_savefile.stop();
        qDebug() << "data_buf_size_when_close: " << save_data_buf_angle_motor.size();
        if (!save_data_buf_angle_motor.empty()) {
            QTextStream out(&file);
            out.setCodec("UTF-8");
            // 遍历数据并写入文件
            for (const SensorData& dataPoint : save_data_buf_angle_motor) {
                out << time_stamp << "," << dataPoint.value << "\n";
                time_stamp++;
            }
            qDebug() << "finish file writing last!!! ";
        }
        file.close();

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
    /****************************** 旧板 *************************************/
//    int length = angle.size();     // 每通道数据 数
//    QVector<double> x(length);
//    int point_count = ui->plot_angle->graph(0)->dataCount();

//    // 确定画图的横轴
//    for (int i = 0; i < length; i++) {
//        x[i] = i + point_count;
//    }

//    // 画图，一共条曲线
//    for (int i = 0; i < 1; i++) {
//        ui->plot_angle->graph(i)->addData(x,
//            QVector<double>(angle.begin() + i*length, angle.begin() + i*length + length), true);
//    }
//    ui->plot_angle->rescaleAxes();       // 自适应大小
//    ui->plot_angle->replot();


    /****************************** 新板 *************************************/
    // 接收到的data中数据顺序如下：
    // 供电电压、信号电压、信号电流、供电电流、角度、电池电量
    qDebug() << "处理之后的数据大小为：" << data.size();
    /*********************** 供电电压 *****************************/
    double sup_vol = data[0];
    ui->lineE_supply_voltage->setText(QString::number(sup_vol));

    /*********************** 信号电压 *****************************/
    double sig_vol = data[1];
    ui->lineE_signal_voltage->setText(QString::number(sig_vol));

    /*********************** 信号电流 *****************************/
    double sig_cur = data[2];
    ui->lineE_signal_current->setText(QString::number(sig_cur));

    /*********************** 供电电流 *****************************/
    double sup_cur = data[3];
    ui->lineE_supply_current->setText(QString::number(sup_cur));

    /*********************** 传感器角度 ***************************/
    double angle_sensor = data[4];
    /************* 角度数值框显示 **************/
    ui->lineE_sensor_angle->setText(QString::number(angle_sensor));
    /************* 角度画图 *******************/
    int length = 1;
    QVector<double> x(length);
    int point_count = ui->plot_angle->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    // 画图，一次画一个点
    ui->plot_angle->graph(0)->addData(x, QVector<double>(angle_sensor), true);
    ui->plot_angle->rescaleAxes();       // 自适应大小
    ui->plot_angle->replot();

    /*********************** 电池电量 *****************************/
    double bat = data[5];
    ui->pBar_battery->setOrientation(Qt::Horizontal);  // 水平方向
    ui->pBar_battery->setMinimum(0);                   // 最小值
    ui->pBar_battery->setMaximum(24);                   // 最大值
    ui->pBar_battery->setValue(bat);                  // 当前进度
    double dProgress = (ui->pBar_battery->value() - ui->pBar_battery->minimum()) * 100.0
                    / (ui->pBar_battery->maximum() - ui->pBar_battery->minimum());
    ui->pBar_battery->setFormat(QString::fromLocal8Bit("电池电量剩余：%1%").arg(QString::number(dProgress, 'f', 1)));
    ui->pBar_battery->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式

    /********************文件保存*********************/
    // 数据首先都放到缓冲区中
    _data_save->collectData(&save_data_buf_angle_sensor, angle_sensor);
}


/*******************************电机************************************/
/***************************************************************
  *  @brief     接收电机发送来的角度并在数值框中显示并【画图，角度2】
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::slot_get_angle(double motor_angle)
{
    _motor_angle = motor_angle;
//    qDebug() << "ui : " << _motor_angle;
    ui->lineE_motor_angle->setText(QString::number(_motor_angle));

    /********************文件保存*********************/
    // 数据首先都放到缓冲区中
    _data_save->collectData(&save_data_buf_angle_motor, motor_angle);
}

/***************************************************************
  *  @brief     接收参数配置页面电机目标角度
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_angleSensor::update_motor_tar_angle(const QString &text)
{
    _motor->set_target_angle(text);
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
        qDebug() << "UI 运行 cur id" << QThread::currentThreadId();

        // 发送配置信号
        emit signal_setConfigModbus();

    } else {
        ui->btn_run_stop->setText("运行");
        qDebug() << "UI 停止 cur id" << QThread::currentThreadId();

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
    for (const SensorData& dataPoint : save_data_buf_angle_motor) {
        out << time_stamp << "," << dataPoint.value << "\n";
        time_stamp++;
    }
    save_data_buf_angle_motor.clear();                // 清空缓冲区
}
