#include "showwin_proximityswitch.h"
#include "ui_showwin_proximityswitch.h"

showWin_proximitySwitch::showWin_proximitySwitch(ProximitySwitch *proxi_switch, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_proximitySwitch),
    _proxi_switch(proxi_switch)
{
    ui->setupUi(this);
}

showWin_proximitySwitch::~showWin_proximitySwitch()
{
    delete ui;
}

void showWin_proximitySwitch::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");

        // 滑动变阻器开始采集
        _variable_resis = new VariableResis;
        _variable_resis->start_acquire();

        // 接近开关开始采集
        _proxi_switch->start_acquire();

        // 这块放画图的初始化函数
        ui->plot_distance->clearGraphs();
        ui->plot_distance->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->plot_distance->xAxis->setLabel("time/s");
        ui->plot_distance->yAxis->setLabel("Y");
        ui->plot_distance->yAxis->setRange(-10, 10);

        // 添加图，两个，一个画距离，一个画触发信号
        ui->plot_distance->addGraph();
        ui->plot_distance->addGraph();

        // 下面是用一个槽函数来接收还是用两个，待定，因为画的曲线是滑动变阻器的距离，但是得同图标注“触发”
        connect(_proxi_switch, &ProximitySwitch::send_ni9205_to_ui,
                this, &showWin_proximitySwitch::get_data_and_plot_pulse);

        connect(_variable_resis, &VariableResis::send_ni9205_to_ui,
                this, &showWin_proximitySwitch::get_data_and_plot_distance);

    }else {
        ui->btn_start_finish_mea->setText("开始测量");

        _variable_resis->stop_acquire();
        _proxi_switch->stop_acquire();
    }
}

// 画距离波形
void showWin_proximitySwitch::get_data_and_plot_distance(QVector<double> data)
{
    _distance = data[0];        // 保存最新的数据
}

// 画“触发”点
void showWin_proximitySwitch::get_data_and_plot_pulse(bool if_Pulse)
{
    _if_pulse = if_Pulse;       // 保存触发状态

    if (_if_rep_mea) {      // 如果用户点击了“重复精度测量”
        if (if_Pulse)       // 只有“触发”的时候才记录距离
            _dis_arr.push_back(_distance);
    }
}

void showWin_proximitySwitch::on_btn_ok_clicked()
{
    this->close();
}

// 点击“重复精度测量”按钮，则开始测量十次的感应距离
// 即记录十次的触发时刻滑动变阻器的距离
void showWin_proximitySwitch::on_btn_repeat_precise_clicked()
{
    _if_rep_mea = true;

    if (_dis_arr.size() == REPEAT_TIMES) {      // 已经记录了10次
        auto maxIt = std::max_element(_dis_arr.begin(), _dis_arr.end());
        auto minIt = std::min_element(_dis_arr.begin(), _dis_arr.end());

        double max_dis = *maxIt;    // 最大值
        double min_dis = *minIt;    // 最小值

        // 计算平均值
        double sum = std::accumulate(_dis_arr.begin(), _dis_arr.end(), 0.0);
        double avg_dis = _dis_arr.isEmpty() ? 0.0 : sum / _dis_arr.size();

        ui->lineE_dis_max->setText(QString::number(max_dis));
        ui->lineE_dis_min->setText(QString::number(min_dis));
        ui->lineE_dis_avg->setText(QString::number(avg_dis));

        _if_rep_mea = false;        // 结束重复精度测量
    }
}
