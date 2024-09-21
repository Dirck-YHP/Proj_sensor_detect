#ifndef PARAMWIN_ANGLEENCODER_H
#define PARAMWIN_ANGLEENCODER_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>

#include "sensors/angleencoder.h"
#include "ui_show/showwin_angleencoder.h"
#include "ui_func/funcwin_datareview.h"

namespace Ui {
class paramWin_angleEncoder;
}

class paramWin_angleEncoder : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_angleEncoder(QWidget *parent = nullptr);
    ~paramWin_angleEncoder();

private:
    Ui::paramWin_angleEncoder *ui;
    AngleEncoder *angle_encoder;
    showWin_angleEncoder *show_win_angle_encoder;

    funcWin_DataReview *func_win_data_review;
    QString m_file_save_dir;

    bool IF_NEED_MOTOR = true;

signals:
    void subWindowClosed();

signals:
    void motor_target_angle_changed(const QString &text);
    void motor_speed_changed(const QString &text);

private slots:
    void on_btn_back_mainW_clicked();   // 返回主界面
    void on_btn_exit_clicked(); // 退出
    void on_btn_ok_clicked();   // 确认
    void on_checkBox_no_need_device_stateChanged(int arg1); // 是否需要工装
    void on_cBox_file_save_stateChanged(int arg1);
    void on_btn_load_data_clicked();
};

#endif // PARAMWIN_ANGLEENCODER_H
