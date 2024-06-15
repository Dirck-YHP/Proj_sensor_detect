#include "showwin_angleencoder.h"
#include "ui_showwin_angleencoder.h"

showWin_angleEncoder::showWin_angleEncoder(AngleEncoder *angle_encoder, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_angleEncoder),
    _angle_encoder(angle_encoder)
{
    // 通过队列让初始化波形展示为滑动，初始化为6个通道
    plot_queue = QVector<QQueue<double>>(6);

    ui->setupUi(this);
}

showWin_angleEncoder::~showWin_angleEncoder()
{
    delete ui;
}

void showWin_angleEncoder::on_btn_test_clicked()
{
    ui->textB_test->append(_angle_encoder->get_label());
    ui->textB_test->append("   hahaha   ");
    ui->textB_test->append(_angle_encoder->get_pul_per_cir());
}

void showWin_angleEncoder::on_btn_ok_clicked()
{
    this->close();
}


void showWin_angleEncoder::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
//        qDebug() << "now btn pressed";
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

//        qDebug() << QString::number(channel_num);

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

void showWin_angleEncoder::get_data_and_plot_9401(QVector<double> data)
{
    QString content = "正向：" + QString::number(data[0]);

    ui->textB_ni_9401->setText(content);
}

// 画图数据处理
// 将二维数组限制在一个queue里，然后转成二维数组再传出去
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

















