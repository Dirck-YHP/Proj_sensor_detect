#ifndef PARAMWIN_ANGLEENCODER_H
#define PARAMWIN_ANGLEENCODER_H

#include <QWidget>
#include "sensors/angleencoder.h"
#include "ui_show/showwin_measureresis.h"
#include "ui_show/showwin_angleencoder.h"

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
    showWin_measureResis *show_win_measure_r;
    showWin_angleEncoder *show_win_angle_encoder;

signals:
    void subWindowClosed();
private slots:
    void on_btn_back_mainW_clicked();
    void on_btn_exit_clicked();
    void on_btn_ok_clicked();
    void on_checkBox_measure_resis_stateChanged(int arg1);
    void on_checkBox_no_need_device_stateChanged(int arg1);
};

#endif // PARAMWIN_ANGLEENCODER_H
