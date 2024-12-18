#ifndef SHOWWIN_ANGLEENCODER_H
#define SHOWWIN_ANGLEENCODER_H

#include <QWidget>
#include <QDebug>
#include <QTimer>

#include "sensors/angleencoder.h"
#include "assist_func/assist.h"
#include "devices/motor.h"
#include "functionality/errorprompt.h"

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
    void slot_get_angle_and_plot(QVector<double> data,  QVector<uInt32> data2, QVector<double> data3, QVector<double> data4);

    void slot_get_err(bool err);

    void slot_get_angle(double motor_angle);    // 接收电机发过来的角度数据
    void slot_get_speed(double motor_speed);    // 接收电机发过来的速度

    void save_data();                           // 保存数据

signals:
    void signal_setConfigModbus();              // 点击“开始”时发送的配置信号
    void signal_closeOpenModbus();              // 点击“停止”时发送的关闭信号

    void signal_delete();

private:
    Ui::showWin_angleEncoder *ui;
    AngleEncoder *_angle_encoder;

    double last_angle_encoder = 0;         // 电机单次运行时 编码器的角度
    double last_angle = 0;                  // 每次接收到的编码器的角度值
    uInt32 last_A_chan = 0;
    bool fresh_enc = false;

    double B_chan = 0;          // 通道B的脉冲数（由A和角度计算得到）
    uInt32 A_chan = 0;          // 通道A的脉冲数（直接采集得到）

    // 电机
    Motor *_motor = nullptr;
    QTimer _timer_motor;        // 显示数值框显示频率的定时器【暂时没用】
    bool _if_need_motor;        // 是否需要电机，由外界传入
    double _motor_angle = 0;        // 电机的角度
    double _motor_speed = 0;

    // 文件保存
    QString _file_save_dir;     // 文件保存路径，由外界传入
    QString _file_add_name;     // 用户需要的文件名标识符
    QTimer _timer_savefile;     // 文件保存的频率
    QFile file;
    DataSave *_data_save = nullptr;
    bool FILE_SAVE = false;     // 是否进行文件保存
    QVector<SensorData> save_data_buf_angle_encoder;        // 来自编码器的要保存的角度数据
    QVector<SensorData> save_data_buf_angle_motor;          // 来自电机的要保存的角度数据
    int time_stamp = 0;         // 时间戳，文件保存时的横坐标

    bool sig_error = false;

private:
    /***************辅助********************/
    const int PLOT_9403_QUEUE_SIZE = 100;       // 滑动显示的数据长度
    QVector<QQueue<double>> plot_queue;         // 滑动显示的数据
    QVector<QVector<double>> add_data_to_queue(QVector<QVector<double>> data);      // 滑动显示处理函数
    int channel_num;                            // 后续新板子通道是定死的

    void UI_init();

public slots:
    void update_motor_tar_angle(const QString &text);
    void update_motor_speed(const QString &text);
    void update_file_name(const QString &text);
};

#endif // SHOWWIN_ANGLEENCODER_H
