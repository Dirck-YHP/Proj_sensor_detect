#ifndef SHOWWIN_PROXIMITYSWITCH_H
#define SHOWWIN_PROXIMITYSWITCH_H

#include <QWidget>
#include <QTimer>

#include "sensors/proximityswitch.h"
//#include "devices/variableresis.h"        // 已停用

// file save
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include "functionality/datasave.h"

namespace Ui {
class showWin_proximitySwitch;
}

class showWin_proximitySwitch : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_proximitySwitch(QString file_save_dir, ProximitySwitch *proxi_switch, QWidget *parent = nullptr);
    ~showWin_proximitySwitch();

private slots:
    void on_btn_start_finish_mea_toggled(bool checked);

    // 测试用，接收到来自传感器的数据然后显示出来
    void get_data_and_plot_distance(QVector<double> data);
    void slot_get_vol_cur_pul_dis_and_show(QVector<double> data);

    void on_btn_ok_clicked();

    void on_btn_repeat_precise_clicked();   // 进行重复精度测量
    void save_data();

public slots:
    void update_file_name(const QString &text);

private:
    int tmp_num = 100;

    Ui::showWin_proximitySwitch *ui;
    ProximitySwitch *_proxi_switch;
//    VariableResis *_variable_resis;

    int REPEAT_TIMES = 10;          // 重复测量次数
    bool _if_rep_mea = false;       // 是否开始重复测量
    QVector<double> _dis_arr;

    double _distance;               // 距离
    bool _if_pulse = false;         // 是否触发
    QVector<double> pulse_dis;

    // 文件保存
    QString _file_save_dir;
    QString _file_add_name;     // 用户需要的文件名标识符
    QTimer _timer_savefile;
    QFile file;
    DataSave *_data_save = nullptr;
    bool FILE_SAVE = false;
    QVector<SensorData> save_data_buf_variaresis;        // 来自滑动变阻器的要保存的数据
    QVector<SensorData> save_data_buf_if_pulse;          // 来自接近开关的要保存的数据
    int time_stamp = 0;

signals:
    void signal_delete();
};

#endif // SHOWWIN_PROXIMITYSWITCH_H
