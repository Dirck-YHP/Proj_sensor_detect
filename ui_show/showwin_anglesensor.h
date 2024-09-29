#ifndef SHOWWIN_ANGLESENSOR_H
#define SHOWWIN_ANGLESENSOR_H

#include <QWidget>
#include <QThreadPool>
#include <QThread>
#include <QTimer>

#include "sensors/anglesensor.h"
#include "assist_func/assist.h"
#include "devices/motor.h"

// file save
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include "functionality/datasave.h"

namespace Ui {
class showWin_angleSensor;
}

class showWin_angleSensor : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_angleSensor(QString file_save_dir,
                                 AngleSensor *angle_sensor,
                                 bool if_need_motor,
                                 QWidget *parent = nullptr);
    ~showWin_angleSensor();

private slots:
    void on_btn_ok_clicked();

    void on_btn_start_finish_mea_toggled(bool checked);

    // 接收到来自传感器的数据然后显示出来
    void slot_get_vol_cur_angle_and_show(QVector<double> angle);


    void slot_get_angle(double motor_angle);    // 接收电机发过来的角度数据
    void save_data();                           // 保存数据

    void slot_get_err(bool err);

    void on_btn_run_stop_toggled(bool checked);
    void on_btn_stop_now_clicked();

    void on_btn_angle_cali_clicked();

public slots:
    void update_motor_tar_angle(const QString &text);
    void update_motor_speed(const QString &text);
    void update_file_name(const QString &text);

signals:
    void signal_setConfigModbus();              // 点击“开始”时发送的配置信号
    void signal_closeOpenModbus();              // 点击“停止”时发送的关闭信号

    void signal_angle_cali(double cur_angle);   // 角度校准信号

    void signal_delete();

private:
    Ui::showWin_angleSensor *ui;
    AngleSensor *_angle_sensor;

    // 电机
    double last_angle_sensor = 0;         // 电机单次运行时 传感器的角度
    Motor *_motor = nullptr;
    QTimer _timer_motor;        // 显示数值框显示频率的定时器【暂时没用】
    bool _if_need_motor;        // 是否需要电机，由外界传入
    double _motor_angle = 0.0;        // 电机的角度
    bool fresh_enc = false;

    // 文件保存
    QString _file_save_dir;     // 文件保存路径，由外界传入
    QString _file_add_name;     // 用户需要的文件名标识符
    QTimer _timer_savefile;     // 文件保存的频率
    QFile file;
    DataSave *_data_save = nullptr;
    bool FILE_SAVE = false;     // 是否进行文件保存
    QVector<SensorData> save_data_buf_angle_sensor;         // 来自传感器的要保存的角度数据
    QVector<SensorData> save_data_buf_angle_motor;          // 来自电机的要保存的角度数据
    int time_stamp = 0;         // 时间戳，文件保存时的横坐标

    // 画图
    int channel_num;

    bool sig_error = false;
};

#endif // SHOWWIN_ANGLESENSOR_H
