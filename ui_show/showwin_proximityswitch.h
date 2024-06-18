#ifndef SHOWWIN_PROXIMITYSWITCH_H
#define SHOWWIN_PROXIMITYSWITCH_H

#include <QWidget>
#include "sensors/proximityswitch.h"
#include "devices/variableresis.h"

namespace Ui {
class showWin_proximitySwitch;
}

class showWin_proximitySwitch : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_proximitySwitch(ProximitySwitch *proxi_switch, QWidget *parent = nullptr);
    ~showWin_proximitySwitch();

private slots:
    void on_btn_start_finish_mea_toggled(bool checked);

    // 测试用，接收到来自传感器的数据然后显示出来
    void get_data_and_plot_9205(QVector<double> data);

public:
    // 需要一个转化函数，根据读到的电压值判断是否“接触”

private:
    Ui::showWin_proximitySwitch *ui;
    ProximitySwitch *_proxi_switch;
    VariableResis *_variable_resis;
};

#endif // SHOWWIN_PROXIMITYSWITCH_H
