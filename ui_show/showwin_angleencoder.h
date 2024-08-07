#ifndef SHOWWIN_ANGLEENCODER_H
#define SHOWWIN_ANGLEENCODER_H

#include <QWidget>
#include <QDebug>
#include <QTimer>

#include "sensors/angleencoder.h"
#include "assist_func/assist.h"
#include "devices/motor.h"

// file save
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include "functionality/datasave.h"

namespace Ui {
class showWin_angleEncoder;
}

class showWin_angleEncoder : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_angleEncoder(QString file_save_dir,
                                  AngleEncoder *angle_encoder,
                                  bool if_need_motor,
                                  QWidget *parent = nullptr);
    ~showWin_angleEncoder();

private slots:
    void on_btn_ok_clicked();
    void on_btn_start_finish_mea_toggled(bool checked);
    void on_btn_run_stop_toggled(bool checked);
    void on_btn_stop_now_clicked();

    // 接收到来自传感器的数据然后显示出来
    void slot_get_vol_cur_and_show(QVector<double> data);          // 后续需要换名字，编码器9205只有电压电流且不画图
    void slot_get_pulse_and_plot(QVector<QVector<double>> data); // 后续需要换名字，编码器9403画脉冲图
    void slot_get_angle_and_plot(QVector<double> data);          // 后续需要换名字，编码器9401同电机一起画图

    void slot_get_angle(double motor_angle);    // 接收电机发过来的角度数据

    void save_data();                           // 保存数据

signals:
    void signal_setConfigModbus();              // 点击“开始”时发送的配置信号
    void signal_closeOpenModbus();              // 点击“停止”时发送的关闭信号

    void signal_delete();

private:
    Ui::showWin_angleEncoder *ui;
    AngleEncoder *_angle_encoder;

    double absolute_angle_encoder = 0;     // 编码器角度绝对值
    double last_angle_encoder = 0;         // 编码器上次角度

    // 电机
    Motor *_motor = nullptr;
    QTimer _timer_motor;        // 显示数值框显示频率的定时器【暂时没用】
    bool _if_need_motor;        // 是否需要电机，由外界传入
    double _motor_angle = 0;        // 电机的角度
    int totalTurns = 0;
    int last_turn = 0;
    bool fresh_turn = false;    // 重新开始

    // 文件保存
    QString _file_save_dir;     // 文件保存路径，由外界传入
    QTimer _timer_savefile;     // 文件保存的频率
    QFile file;
    DataSave *_data_save = nullptr;
    bool FILE_SAVE = false;     // 是否进行文件保存
    QVector<SensorData> save_data_buf_angle_encoder;        // 来自编码器的要保存的角度数据
    QVector<SensorData> save_data_buf_angle_motor;          // 来自电机的要保存的角度数据
    int time_stamp = 0;         // 时间戳，文件保存时的横坐标

private:
    /***************辅助********************/
    const int PLOT_9403_QUEUE_SIZE = 100;       // 滑动显示的数据长度
    QVector<QQueue<double>> plot_queue;         // 滑动显示的数据
    QVector<QVector<double>> add_data_to_queue(QVector<QVector<double>> data);      // 滑动显示处理函数
    int channel_num;                            // 后续新板子通道是定死的

public slots:
    void update_motor_tar_angle(const QString &text);
};

#endif // SHOWWIN_ANGLEENCODER_H
