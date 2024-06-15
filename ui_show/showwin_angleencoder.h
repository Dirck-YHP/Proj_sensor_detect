#ifndef SHOWWIN_ANGLEENCODER_H
#define SHOWWIN_ANGLEENCODER_H

#include <QWidget>
#include <QDebug>

#include "sensors/angleencoder.h"
#include "assist_func/assist.h"

namespace Ui {
class showWin_angleEncoder;
}

class showWin_angleEncoder : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_angleEncoder(AngleEncoder *angle_encoder, QWidget *parent = nullptr);
    ~showWin_angleEncoder();

private slots:
    void on_btn_test_clicked();

    void on_btn_ok_clicked();

    void on_btn_start_finish_mea_toggled(bool checked);

    // 测试用
    void get_data_and_plot_9205(QVector<double> data);
    void get_data_and_plot_9403(QVector<QVector<double>> data);
    void get_data_and_plot_9401(QVector<double> data);

private:
    Ui::showWin_angleEncoder *ui;
    AngleEncoder *_angle_encoder;

private:
    QVector<QVector<double>> add_data_to_queue(QVector<QVector<double>> data);

private:
    /***************辅助********************/
    const int PLOT_9403_QUEUE_SIZE = 100;
    QVector<QQueue<double>> plot_queue;
    int channel_num;    // 测试用，后续新板子不需要这个变量，通道是定死的
};

#endif // SHOWWIN_ANGLEENCODER_H
