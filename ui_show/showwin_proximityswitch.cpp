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

        // 添加图，一个就行，电压电流已经不需要画图了hhh
        ui->plot_distance->addGraph();

        // 下面是用一个槽函数来接收还是用两个，待定，因为画的曲线是滑动变阻器的距离，但是得同图标注“触发”
        connect(_proxi_switch, &ProximitySwitch::send_ni9205_to_ui,
                this, &showWin_proximitySwitch::get_data_and_plot_9205);
//        connect(_variable_resis, &VariableResis::send_ni9205_to_ui,
//                this, &showWin_proximitySwitch)

    }else {
        ui->btn_start_finish_mea->setText("开始测量");

        _variable_resis->stop_acquire();
        _proxi_switch->stop_acquire();
    }
}

void showWin_proximitySwitch::get_data_and_plot_9205(QVector<double> data)
{

}
