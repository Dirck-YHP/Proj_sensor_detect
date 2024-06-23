#ifndef SHOWWIN_ANGLEENCODER_H
#define SHOWWIN_ANGLEENCODER_H

#include <QWidget>
#include <QDebug>
#include <QTimer>

#include "sensors/angleencoder.h"
#include "assist_func/assist.h"
#include "devices/motor.h"

namespace Ui {
class showWin_angleEncoder;
}

class showWin_angleEncoder : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_angleEncoder(AngleEncoder *angle_encoder,
                                  bool if_need_motor,
                                  QWidget *parent = nullptr);
    ~showWin_angleEncoder();

private slots:
    void on_btn_ok_clicked();
    void on_btn_start_finish_mea_toggled(bool checked);
    void on_btn_run_stop_toggled(bool checked);
    void on_btn_stop_now_clicked();

    // 测试用，接收到来自传感器的数据然后显示出来
    void get_data_and_plot_9205(QVector<double> data);
    void get_data_and_plot_9403(QVector<QVector<double>> data);
    void get_data_and_plot_9401(QVector<double> data);

    void get_angle(double motor_angle);

private:
    Ui::showWin_angleEncoder *ui;
    AngleEncoder *_angle_encoder;

    Motor *_motor = nullptr;
    QTimer _timer_motor;
    bool _if_need_motor;

    double _motor_angle;      // 电机的角度

private:
    /***************辅助********************/
    const int PLOT_9403_QUEUE_SIZE = 100;
    QVector<QQueue<double>> plot_queue;
    QVector<QVector<double>> add_data_to_queue(QVector<QVector<double>> data);
    int channel_num;    // 测试用，后续新板子不需要这个变量，通道是定死的

public slots:
    void update_motor_tar_angle(const QString &text);
};

#endif // SHOWWIN_ANGLEENCODER_H
