#include "showwin_angleencoder.h"
#include "ui_showwin_angleencoder.h"

showWin_angleEncoder::showWin_angleEncoder(QString file_save_dir,
                                           AngleEncoder *angle_encoder,
                                           bool if_need_motor,
                                           QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_angleEncoder),
    _angle_encoder(angle_encoder),
    _if_need_motor(if_need_motor),
    _file_save_dir(file_save_dir)
{
    // 通过队列让初始化波形展示为滑动，初始化为6个通道
    plot_queue = QVector<QQueue<double>>(6);

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
            connect(this, &showWin_angleEncoder::signal_setConfigModbus,
                    _motor, &Motor::get_config_signal);
            // 用户点击“停止”之后会发送这个关闭信号 给电机
            connect(this, &showWin_angleEncoder::signal_closeOpenModbus,
                    _motor, &Motor::get_close_signal);

            // 接收电机发送的角度数据，数值框+画图显示
            connect(_motor, &Motor::send_angle_to_ui,
                    this, &showWin_angleEncoder::slot_get_angle);

            connect(_motor, &Motor::send_spd_to_ui,
                    this, &showWin_angleEncoder::slot_get_speed);

             qDebug() << "(In win)first new motor ";
        }

    } else {
        // 如果不需要电机就都不可见
        if (_motor == nullptr) {
            _motor = new Motor;
        }
        ui->btn_run_stop->setVisible(false);
        ui->btn_stop_now->setVisible(false);
        ui->lineE_motor_angle->setVisible(false);
        ui->lineE_motor_circle->setVisible(false);
        ui->lineE_motor_speed->setVisible(false);
        ui->label_motor_angle->setVisible(false);
        ui->label_motor_speed->setVisible(false);
        ui->label_motor_circle->setVisible(false);
    }

    /********************** 文件保存相关 **********************/
    if (_file_save_dir != "") {
        FILE_SAVE = true;
        _data_save = new DataSave;
        _timer_savefile.setInterval(500);       // 20ms一个数据点，500ms写入到文件一次，25个点
        connect(&_timer_savefile, &QTimer::timeout, this, &showWin_angleEncoder::save_data);
    } else {
        FILE_SAVE = false;
        qDebug() << "(In win)do not save file!";
    }

    /********************** qt特性配置 **********************/
    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);

    /********************** 角度图参数配置 **********************/
    ui->plot_angle->clearGraphs();
    ui->plot_angle->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_angle->xAxis->setLabel("time/s");
    ui->plot_angle->yAxis->setLabel("Y");
    ui->plot_angle->yAxis->setRange(-10, 10);

    // 两条曲线：一条是编码器角度，另一条是电机角度
    for (int i = 0; i < 2; i++) {
        ui->plot_angle->addGraph();
        ui->plot_angle->graph(i)->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256)));
    }

    /********************** 脉冲图参数配置 **********************/
    ui->plot_impulse->clearGraphs();
    ui->plot_impulse->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_impulse->xAxis->setLabel("time/s");
    ui->plot_impulse->yAxis->setLabel("Y");
    ui->plot_impulse->yAxis->setRange(-1, 3);

    for (int i = 0; i < 6; i++) {
        ui->plot_impulse->addGraph();
        ui->plot_impulse->graph(i)->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256)));
    }

    /********************** ni 9205相关 **********************/
    connect(_angle_encoder, &AngleEncoder::send_vol_cur_to_ui,
            this, &showWin_angleEncoder::slot_get_vol_cur_and_show);

    /********************** ni 9403相关 **********************/
    connect(_angle_encoder, &AngleEncoder::send_pulse_to_ui,
            this, &showWin_angleEncoder::slot_get_pulse_and_plot);

    /********************** ni 9401相关 **********************/
    connect(_angle_encoder, &AngleEncoder::send_angle_to_ui,
            this, &showWin_angleEncoder::slot_get_angle_and_plot);

    /********************** 对象析构 **********************/
    connect(this, &showWin_angleEncoder::signal_delete,
            _angle_encoder, &AngleEncoder::slot_acq_delete);

    /********************** 错误检测 **********************/
    connect(_angle_encoder, &AngleEncoder::sig_err_to_ui,
            this, &showWin_angleEncoder::slot_get_err);
}

showWin_angleEncoder::~showWin_angleEncoder()
{
    emit signal_delete();
    qDebug() << "(In win)encoder window destroyed";
    qDebug() << "------------------------";

    delete ui;
}

void showWin_angleEncoder::UI_init()
{
    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->label_bat->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    // ui->label_period->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_err_per->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_enc_angle->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_enc_A_pulse->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_enc_B_pulse->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_motor_angle->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_motor_speed->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_motor_circle->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    // ui->label_two_edge_sep->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_supply_current->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_supply_voltage->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_signal_current_A->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_signal_current_B->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_signal_voltage_A->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_signal_voltage_B->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");

    ui->btn_ok->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_run_stop->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");
    ui->btn_start_finish_mea->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_stop_now->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");

    // ui->lineE_two_edge_sep->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_motor_angle->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_motor_speed->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_motor_circle->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_encoder_angle->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_phase_err_per->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_supply_current->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_supply_voltage->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_encoder_A_pulse->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_encoder_B_pulse->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_signal_current_A->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_signal_current_B->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_signal_voltage_A->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");
    ui->lineE_signal_voltage_B->setStyleSheet("font-size: 14pt;color:rgb(0,0,0);");

}

/***************************************************************
  *  @brief     ok键按下
  *  @param     无
  *  @note      槽函数——删除motor对象
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::on_btn_ok_clicked()
{
    _angle_encoder->stop_acquire();     // 停止采集

    if (_motor != nullptr) {
        delete _motor;
        qDebug() << "(In win)motor delete succeed";
    }

    if (_data_save != nullptr) {
        delete _data_save;
        qDebug() << "(In win)data_save and delete succeed!";
    }

    this->close();
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      槽函数——开始测量/结束测量键
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");
        Assist::board_init(true);

        // 清零
        last_angle_encoder = 0.0;
        B_chan = 0;
        last_angle = 0;
        sig_error = false;

        /********************** 三张卡开始采集 **********************/
        _angle_encoder->start_acquire();

        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            QString currentDateTime = "AE_" + _file_add_name + "_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
            QString file_name = _file_save_dir + "/" + currentDateTime + "_data.txt";

            qDebug() << "(In Win)fileName: " <<file_name;
            file.setFileName(file_name);
            if (!file.open(QIODevice::Append | QIODevice::Text))    // 打开文件
                return;

            QTextStream out(&file);
            out.setCodec("UTF-8");
            out << QString("传感器类型：")  << _angle_encoder->get_label().toUtf8()
                << QString("，编码器每圈脉冲数：") << _angle_encoder->get_pul_per_cir().toUtf8()
                << QString("，采集通道：") << _angle_encoder->get_channel().toUtf8() << "\n";
            out << QString("x") << QString("  编码器") << QString(" 电机") << "\n";

            _timer_savefile.start();    // 开启定时器，开始保存数据
        }

    } else {
        ui->btn_start_finish_mea->setText("开始测量");

        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            // 保存缓冲区中残余的数据
            _timer_savefile.stop();
            qDebug() << "(In win)data_buf_size_when_close: "
                     // << save_data_buf_angle_encoder.size()
                     << save_data_buf_angle_motor.size();

            if (!save_data_buf_angle_motor.empty()) {
                QTextStream out(&file);
                out.setCodec("UTF-8");
                // 遍历数据并写入文件
                for (int i = 0; i < save_data_buf_angle_encoder.size(); i++) {
                    out << time_stamp << ":  "
                        << save_data_buf_angle_encoder[i].value << "    "
                        << save_data_buf_angle_motor[i].value << "\n";
                    time_stamp++;
                }

                qDebug() << "(In win)finish file writing last!!! ";
            }
            file.close();
        }

        /********************** 数据采集相关 **********************/
        _angle_encoder->stop_acquire();     // 停止采集
    }
}

/***************************************************************
  *  @brief     接收编码器的电压电流数据并在数值框中显示
  *  @param     无
  *  @note      槽函数——接收编码器类发送的供电/信号回路的电压、电流，后续无需画图，只需数值框
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::slot_get_vol_cur_and_show(QVector<double> data)
{
    /****************************** 新板 *************************************/
    // 接收到的data中数据顺序如下：
    // 供电电压、A项信号电压、A项信号电流、B项信号电压、B项信号电流、供电电流、电池电量
    const int DIGIT = 1;
    /*********************** 供电电压 *****************************/
    double sup_vol = data[0] * 3;
    ui->lineE_supply_voltage->setText(QString::number(sup_vol, 'f', DIGIT) + "V");

    /*********************** A项信号电压 *****************************/
    double sig_vol_A = data[1];
    ui->lineE_signal_voltage_A->setText(QString::number(sig_vol_A, 'f', DIGIT) + "V");

    /*********************** A项信号电流 *****************************/
    double sig_cur_A = data[2] * 1000;
    ui->lineE_signal_current_A->setText(QString::number(sig_cur_A, 'f', DIGIT) + "mA");

    /*********************** B项信号电压 *****************************/
    double sig_vol_B = data[3];
    ui->lineE_signal_voltage_B->setText(QString::number(sig_vol_B, 'f', DIGIT) + "V");

    /*********************** B项信号电流 *****************************/
    double sig_cur_B = data[4] * 1000;
    ui->lineE_signal_current_B->setText(QString::number(sig_cur_B, 'f', DIGIT) + "mA");

    /*********************** 供电电流 *****************************/
    double sup_cur = data[5] * 1000;
    ui->lineE_supply_current->setText(QString::number(sup_cur, 'f', DIGIT) + "mA");

    /*********************** 电池电量 *****************************/
    double bat = data[6];
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

}

/***************************************************************
  *  @brief     接收编码器类的脉冲信号数据并画图
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::slot_get_pulse_and_plot(QVector<QVector<double> > data)
{
    data = add_data_to_queue(data);     // 设置队列，让波形固定范围滑动

    int length = data[0].size();

    QVector<double> x(length);

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i;
    }

    // 画图，一共画 data.size() 条曲线
    for (int i = 0; i < data.size(); i++) {
        QPair<QVector<double>, QVector<double>> x_and_y;
        x_and_y = Assist::make_di_plot_better(x, data[i], i);

        ui->plot_impulse->graph(i)->setData(x_and_y.first, x_and_y.second, true);
    }
    ui->plot_impulse->rescaleAxes();       // 自适应大小
    ui->plot_impulse->replot();
}

/***************************************************************
  *  @brief     接收编码器的角度数据并在数值框中显示，同时和电机一起画图
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::slot_get_angle_and_plot(QVector<double> data, QVector<uInt32> data2, QVector<double> data3, QVector<double> data4)
{
    /*************************** 编码器 *****************************/
    /**************** 显示编码器角度累计值 ******************/
    double angle = data[0] - last_angle_encoder;    // Last_angle_encoder表示的是每次电机重新运行时上一次的角度
    // 脉冲增量 = 角度增量的绝对值 / 360° * 每圈脉冲数
    double incre_pulse = abs(angle - last_angle) / 360 * _angle_encoder->get_pul_per_cir().toDouble();

    // A B相脉冲数
    A_chan = data2[0] - last_A_chan;
    B_chan += incre_pulse;

    // 周期 和 上升沿间隔
    static double period = 0, two_edge_sep = 0;

    if (data3.size())
        period = data3[0];
    if (data4.size())
        two_edge_sep = data4[0];

    // 每次电机重新运行时候，数据需要清零
    if (fresh_enc) {
        angle = 0.0;
        A_chan = 0;
        B_chan = 0;
        last_angle = 0;
        last_angle_encoder = data[0];
        last_A_chan = data2[0];
        fresh_enc = false;
    }

    /***************** 编码器角度数值框显示 ******************/
    ui->lineE_encoder_angle->setText(QString::number(angle) + "°");

    /***************** 编码器A B相上升沿数值框显示 ******************/
    ui->lineE_encoder_A_pulse->setText(QString::number(A_chan));

    uInt32 _B_chan = 0;
    if (angle - last_angle >= 0) {
        _B_chan = (B_chan - (uInt32)B_chan >= 0.5 ? ((uInt32)B_chan + 1) : (uInt32)B_chan);
    } else {
        _B_chan = (B_chan - (uInt32)B_chan >= 0.25 ? ((uInt32)B_chan + 1) : (uInt32)B_chan);
    }
    ui->lineE_encoder_B_pulse->setText(QString::number(_B_chan));

    /***************** 编码器A B相周期和上升沿间隔值框显示 ******************/
    // ui->lineE_period->setText(QString::number(period));
    // ui->lineE_two_edge_sep->setText(QString::number(two_edge_sep));

    double per_phase = two_edge_sep / period * 100;
    ui->lineE_phase_err_per->setText(QString::number(per_phase, 'f', 1) + "%");

    // 保存当前角度，计算角度增量时需要
    last_angle = angle;

    /*************************** 电机 *****************************/
    /******************** 电机转动圈数显示 *********************/
    double cur_turn = _motor_angle / 360;

    ui->lineE_motor_circle->setText(QString::number(qRound(cur_turn * 10.0) / 10.0));

    /******************** 角度数值框显示 *********************/
//    ui->lineE_motor_angle->setText(QString::number(qRound(_motor_angle * 10.0) / 10.0));

    /************************* 角度画图 ***************************/
    int length = 1;
    QVector<double> x(length);
    int point_count = ui->plot_angle->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    // 画图，一次画一个点
    QVector<double> y1 = {angle};
    QVector<double> y2 = {_motor_angle};

    ui->plot_angle->graph(0)->addData(x, y1, true);
    ui->plot_angle->graph(1)->addData(x, y2, true);

    ui->plot_angle->rescaleAxes();       // 自适应大小
    ui->plot_angle->replot();

    /************************* 文件保存 ***************************/
    if (FILE_SAVE) {
        // 数据首先都放到缓冲区中
        _data_save->collectData(&save_data_buf_angle_encoder, angle);
        _data_save->collectData(&save_data_buf_angle_motor, _motor_angle);
    }
}

/***************************************************************
  *  @brief     处理数据采集类的错误信号，给用户一个弹窗
  *  @param     无
  *  @note      槽函数——接收错误信号
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::slot_get_err(bool err)
{
    qDebug() << "(In Win)get err!——" << err;

    if (!sig_error) {
        sig_error = true;

        ErrorPrompt e_pmt;
        e_pmt.showError(ErrorType::NetworkError);
    }
}

/***************************************************************
  *  @brief     将二维数组限制在一个queue里，然后转成二维数组再传出去
  *  @param     无
  *  @note      功能函数——画图数据处理
  *  @Sample usage:
 **************************************************************/
QVector<QVector<double>> showWin_angleEncoder::add_data_to_queue(QVector<QVector<double> > data)
{
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            if (plot_queue[i].size() >= PLOT_9403_QUEUE_SIZE) {
                plot_queue[i].dequeue();
            }
            plot_queue[i].enqueue(data[i][j]);
        }
    }

    QVector<QVector<double>> data_after_queue(plot_queue.size(), QVector<double>(plot_queue[0].size()));
    for (int i = 0; i < plot_queue.size(); i++) {
        for (int j = 0; j < plot_queue[0].size(); j++) {
            data_after_queue[i][j] = plot_queue[i].at(j);
        }
    }

    return data_after_queue;
}

/*******************************电机************************************/
/***************************************************************
  *  @brief     接收电机发送来的角度并在数值框中显示并【画图，角度2】
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::slot_get_angle(double motor_angle)
{
    _motor_angle = motor_angle;
    ui->lineE_motor_angle->setText(QString::number(qRound(motor_angle * 10.0) / 10.0));
}

/***************************************************************
  *  @brief     接收电机发送来的电机当前速度并在数值框中显示
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::slot_get_speed(double motor_speed)
{
    _motor_speed = motor_speed;
    ui->lineE_motor_speed->setText(QString::number(qRound(motor_speed * 10.0) / 10.0));
}

/***************************************************************
  *  @brief     接收参数配置页面电机目标角度
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::update_motor_tar_angle(const QString &text)
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
void showWin_angleEncoder::update_motor_speed(const QString &text)
{
    qDebug() << "(In Win)spd: " << text;
    _motor->set_speed(text);
}

/***************************************************************
  *  @brief     文件名中添加用户自定义标识
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::update_file_name(const QString &text)
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
void showWin_angleEncoder::on_btn_run_stop_toggled(bool checked)
{
    if (checked) {
        ui->btn_run_stop->setText("停止");
        qDebug() << "(In win)UI 运行 cur id" << QThread::currentThreadId();

        fresh_enc = true;

        // 发送配置信号
        emit signal_setConfigModbus();

    } else {
        ui->btn_run_stop->setText("运行");

        qDebug() << "(In win)UI 停止 cur id" << QThread::currentThreadId();

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
void showWin_angleEncoder::on_btn_stop_now_clicked()
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
void showWin_angleEncoder::save_data()
{
    QTextStream out(&file);
    out.setCodec("UTF-8");
    // 遍历数据并写入文件
    qDebug() << "(In W_file_save)size: " << save_data_buf_angle_encoder.size()
             << " " << save_data_buf_angle_motor.size();
    for (int i = 0; i < save_data_buf_angle_encoder.size(); i++) {
        out << time_stamp << ":  "
            << save_data_buf_angle_encoder[i].value << "    "
            << save_data_buf_angle_motor[i].value << "\n";
        time_stamp++;
    }

    save_data_buf_angle_encoder.clear();        // 清空缓冲区
    save_data_buf_angle_motor.clear();
}
