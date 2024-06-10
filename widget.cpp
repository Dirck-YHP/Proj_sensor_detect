#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    modbus = new Modbus;
    modbus->build_connecttion();                // 建立连接

    // 通过队列让初始化波形展示为滑动，初始化为6个通道
    plot_queue = QVector<QQueue<double>>(6);

    // 设置定时器：每500ms显示一次电机当前角度值
    timer_modbus.setInterval(200);
    connect(&timer_modbus, &QTimer::timeout, this, [=](){
        // 如果电机处于连接状态，则读取值
        // 这个条件待测，可能需要加上一个bool变量作为条件，放在按键触发事件里变为有效
        if (modbus->put_modbusdevice_state() == QModbusDevice::ConnectedState) {
            double modbus_read_num = (double)modbus->put_read_num();
            ui->textB_modbus->setText(QString::number(modbus_read_num * 360 / 12800, 'f', 1));
        }
//        qDebug() << modbus->put_modbusdevice_state();
    });
    timer_modbus.start();


}

Widget::~Widget()
{
    delete ui;
}


// 接收到NI9205发送来的数据后开始处理
void Widget::get_data_and_plot_9205(QVector<double> data)
{
    int length = data.size() / channel_num;     // 每通道数据 数
    QVector<double> x(length);
    int point_count = ui->plot_ni_9205->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    // 画图，一共channel_num条曲线
    for (int i = 0; i < channel_num; i++) {
        ui->plot_ni_9205->graph(i)->addData(x,
            QVector<double>(data.begin() + i*length, data.begin() + i*length + length), true);
    }
    ui->plot_ni_9205->rescaleAxes();       // 自适应大小
    ui->plot_ni_9205->replot();
}

// 接收到NI9403发送来的数据后开始处理
void Widget::get_data_and_plot_9403(QVector<QVector<double>> data)
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

        ui->plot_ni_9403->graph(i)->setData(x_and_y.first, x_and_y.second, true);
    }
    ui->plot_ni_9403->rescaleAxes();       // 自适应大小
    ui->plot_ni_9403->replot();
}

// 接收到NI9401发送来的数据后开始处理
void Widget::get_data_and_plot_9401(QVector<double> data)
{
    QString content = "正向：" + QString::number(data[0]);
    //  + " 反向：" + QString::number(data[1])
    ui->textB_ni_9401->setText(content);
}

// 屏幕点击“开始测量”按钮后触发
void Widget::on_btn_startAcquire_toggled(bool checked)
{
    if (checked) {      // 开始测量
        ui->btn_startAcquire->setText("结束测量");

        // -----------------------NI 9205----------------------------
        QString channel = ui->Edit_channel->text();     // 获取用户在ui输入哪些通道

        channel_num = Assist::extractNumbers(channel).size();   // 将输入的通道str转成vec
        data_acquire_ai = new DataAcquireAI;
        data_acquire_ai->get_channel(channel);
        QThreadPool::globalInstance()->start(data_acquire_ai);  // 丢到线程池开始run
        // 图像相关初始化
        ui->plot_ni_9205->clearGraphs();
        ui->plot_ni_9205->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->plot_ni_9205->xAxis->setLabel("time/s");
        ui->plot_ni_9205->yAxis->setLabel("Y");
        ui->plot_ni_9205->yAxis->setRange(-10, 10);

        for (int i = 0; i < channel_num; i++) {
            ui->plot_ni_9205->addGraph();
        }

        // 连接信号与槽，不同线程之间的通信
        connect(data_acquire_ai, &DataAcquireAI::send_data, this, &Widget::get_data_and_plot_9205);

        // -----------------------NI 9403----------------------------
        data_acquire_di = new DataAcquireDI;
        QThreadPool::globalInstance()->start(data_acquire_di);  // 丢到线程池开始run
        // 图像相关初始化
        ui->plot_ni_9403->clearGraphs();
        ui->plot_ni_9403->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->plot_ni_9403->xAxis->setLabel("time/s");
        ui->plot_ni_9403->yAxis->setLabel("Y");
        ui->plot_ni_9403->yAxis->setRange(-1, 3);

        for (int i = 0; i < data_acquire_di->CHANNEL_NUM; i++) {
            ui->plot_ni_9403->addGraph();
        }

        // 连接信号与槽，不同线程之间的通信
        connect(data_acquire_di, &DataAcquireDI::send_data, this, &Widget::get_data_and_plot_9403);

        // -----------------------NI 9401----------------------------
        QString pulse_per_rev = ui->Edit_pul_per_rev->text();       // 获取用户在ui输入的每圈脉冲数
        data_acquire_ci = new DataAcquireCI;
        data_acquire_ci->get_pulses_per_rev(pulse_per_rev.toUInt());
        QThreadPool::globalInstance()->start(data_acquire_ci);      // 丢到线程池开始run

        // 连接信号与槽，不同线程之间的通信
        connect(data_acquire_ci, &DataAcquireCI::send_data, this, &Widget::get_data_and_plot_9401);

    } else {            // 结束测量
        ui->btn_startAcquire->setText("开始测量");
        data_acquire_ai->stop_acquire();
        data_acquire_di->stop_acquire();
        data_acquire_ci->stop_acquire();
    }
}

// 画图数据处理
// 将二维数组限制在一个queue里，然后转成二维数组再传出去
QVector<QVector<double>> Widget::add_data_to_queue(QVector<QVector<double> > data)
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



void Widget::on_btn_run_stop_toggled(bool checked)
{
    if (checked) {      // 点击“运行”：这里进行 电机连接 + 电机使能
        ui->btn_run_stop->setText("停止");

        QString input_angel = ui->Edit_target_angle->text();    // 获取目标角度

        modbus->get_input_angle(input_angel);       // 将目标角度传给modbus内部变量
//        modbus->build_connecttion();                // 建立连接
        modbus->enable_motor();                     // 电机使能
        modbus->run_motor();                        // 电机运行

    } else {            // 点击“停止”：这里进行 电机失能 + 断开连接
        ui->btn_run_stop->setText("运行");

        modbus->stop_motor();
//        QThread::msleep(50);
//        modbus->break_connection();                 // 断开连接[!!!!!!!!这里有问题 待测]
    }
}



void Widget::on_btn_stop_now_clicked()
{
    if (modbus != NULL) {
        modbus->stop_motor();
        modbus->disable_motor();
        ui->btn_run_stop->setChecked(false);
    }
}

void Widget::on_btn_angle_cali_clicked()
{
    if (modbus != NULL) {
//        modbus->get_input_angle(QString::number(1000));       // 将目标角度传给modbus内部变量
//        modbus->enable_motor();                     // 电机使能
//        modbus->run_motor();                        // 电机运行

        modbus->angle_cali();

        double modbus_read_num = (double)modbus->put_read_num();
        ui->textB_angle_cali->setText("初始角度: "+ QString::number(modbus_read_num * 360 / 12800, 'f', 1));
    }
}

void Widget::on_btn_break_connect_clicked()
{
    modbus->break_connection();                 // 断开连接
}

void Widget::on_btn_build_connect_clicked()
{
    modbus->build_connecttion();                // 建立连接
}
