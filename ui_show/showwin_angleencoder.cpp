#include "showwin_angleencoder.h"
#include "ui_showwin_angleencoder.h"

showWin_angleEncoder::showWin_angleEncoder(AngleEncoder *angle_encoder,
                                           bool if_need_motor,
                                           QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_angleEncoder),
    _angle_encoder(angle_encoder),
    _if_need_motor(if_need_motor)
{
    // 通过队列让初始化波形展示为滑动，初始化为6个通道
    plot_queue = QVector<QQueue<double>>(6);

    ui->setupUi(this);

    // 是否需要电机
    if (_if_need_motor) {
        ui->btn_run_stop->setVisible(true);
        ui->btn_stop_now->setVisible(true);

        if (_motor == nullptr) {
            _motor = new Motor;

            // 用户点击“运行”之后会发送这个配置信号 给电机
            connect(this, &showWin_angleEncoder::signal_setConfigModbus,
                    _motor, &Motor::get_config_signal);
            // 用户点击“停止”之后会发送这个关闭信号 给电机
            connect(this, &showWin_angleEncoder::signal_closeOpenModbus,
                    _motor, &Motor::get_close_signal);

            // 电机将接收到的数据发送到ui
            connect(_motor, &Motor::send_angle_to_ui,
                    this, &showWin_angleEncoder::slot_get_angle);

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
        ui->btn_run_stop->setVisible(false);
        ui->btn_stop_now->setVisible(false);
        ui->lineE_motor_angle->setVisible(false);
        ui->lineE_motor_circle->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
    }

    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);
}

showWin_angleEncoder::~showWin_angleEncoder()
{
    qDebug() << "encoder window destroyed";
    qDebug() << "------------------------";

    delete ui;
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      槽函数——ok键按下
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::on_btn_ok_clicked()
{
    if (_motor != nullptr) {
        delete _motor;
        qDebug() << "motor delete succeed";
    }

    this->close();
}

/***************************************************************
  *  @brief     这里目前只涉及画图？
  *  @param     无
  *  @note      槽函数——开始测量/结束测量键
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");

        _angle_encoder->start_acquire();

        // 开始画图，先测试，不考虑下面的控件命名
        // ---------------- ni 9205 -----------------
            // 获取通道数，用来画图
        channel_num = Assist::extractNumbers(_angle_encoder->get_channel()).size();
        ui->plot_angle->clearGraphs();
        ui->plot_angle->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->plot_angle->xAxis->setLabel("time/s");
        ui->plot_angle->yAxis->setLabel("Y");
        ui->plot_angle->yAxis->setRange(-10, 10);

        for (int i = 0; i < channel_num; i++) {
            ui->plot_angle->addGraph();
        }

        connect(_angle_encoder, &AngleEncoder::send_ni9205_to_ui,
                this, &showWin_angleEncoder::get_data_and_plot_9205);

       // ---------------- ni 9403 -----------------
        ui->plot_current->clearGraphs();
        ui->plot_current->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->plot_current->xAxis->setLabel("time/s");
        ui->plot_current->yAxis->setLabel("Y");
        ui->plot_current->yAxis->setRange(-1, 3);

        for (int i = 0; i < 6; i++) {
            ui->plot_current->addGraph();
        }

        connect(_angle_encoder, &AngleEncoder::send_ni9403_to_ui,
                this, &showWin_angleEncoder::get_data_and_plot_9403);

        // ---------------- ni 9401 -----------------
        connect(_angle_encoder, &AngleEncoder::send_ni9401_to_ui,
                this, &showWin_angleEncoder::get_data_and_plot_9401);

    } else {
        ui->btn_start_finish_mea->setText("开始测量");

        _angle_encoder->stop_acquire();
    }
}

/***************************************************************
  *  @brief     接收9205的数据并plot
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::get_data_and_plot_9205(QVector<double> data)
{
    int length = data.size() / channel_num;     // 每通道数据 数
    QVector<double> x(length);
    int point_count = ui->plot_angle->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    // 画图，一共channel_num条曲线
    for (int i = 0; i < channel_num; i++) {
        ui->plot_angle->graph(i)->addData(x,
            QVector<double>(data.begin() + i*length, data.begin() + i*length + length), true);
    }
    ui->plot_angle->rescaleAxes();       // 自适应大小
    ui->plot_angle->replot();
}

/***************************************************************
  *  @brief     接收9403的数据并plot
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::get_data_and_plot_9403(QVector<QVector<double> > data)
{
    data = add_data_to_queue(data);     // 设置队列，让波形固定范围滑动

    int length = data[0].size();

    QVector<double> x(length);
//    int point_count = ui->plot_ni_9403->graph(0)->dataCount() / 2;

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i;
    }

    // 画图，一共画 data.size() 条曲线
    for (int i = 0; i < data.size(); i++) {
        QPair<QVector<double>, QVector<double>> x_and_y;
        x_and_y = Assist::make_di_plot_better(x, data[i], i);

        ui->plot_current->graph(i)->setData(x_and_y.first, x_and_y.second, true);
    }
    ui->plot_current->rescaleAxes();       // 自适应大小
    ui->plot_current->replot();
}

/***************************************************************
  *  @brief     接收9401的数据并在数值框中显示
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::get_data_and_plot_9401(QVector<double> data)
{
    QString content = QString::number(data[0]) + "°";

    ui->lineE_encoder_angle->setText(content);
}

/***************************************************************
  *  @brief     接收电机发送来的角度并在数值框中显示
  *  @param     无
  *  @note      槽函数——
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::slot_get_angle(double motor_angle)
{
    _motor_angle = motor_angle;
//    qDebug() << "ui : " << _motor_angle;
    ui->lineE_motor_angle->setText(QString::number(_motor_angle));
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
  *  @brief     接收参数配置页面电机目标角度
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::update_motor_tar_angle(const QString &text)
{
    _motor->set_target_angle(text);
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      槽函数——电机“运行”/“停止”
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::on_btn_run_stop_toggled(bool checked)
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
  *  @brief
  *  @param     无
  *  @note      槽函数——电机“立即停止”键
  *  @Sample usage:
 **************************************************************/
void showWin_angleEncoder::on_btn_stop_now_clicked()
{
//    _motor->disable_motor();

    ui->btn_run_stop->setChecked(false);
}
