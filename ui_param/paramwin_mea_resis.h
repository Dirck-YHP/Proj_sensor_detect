#ifndef PARAMWIN_MEA_RESIS_H
#define PARAMWIN_MEA_RESIS_H

#include <QWidget>
#include "sensors/resis.h"
#include "ui_show/showwin_measureresis.h"

namespace Ui {
class paramWin_mea_resis;
}

class paramWin_mea_resis : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_mea_resis(QWidget *parent = nullptr);
    ~paramWin_mea_resis();

private slots:
    void on_btn_back_mainW_clicked();
    void on_btn_exit_clicked();
    void on_btn_ok_clicked();

signals:
    void subWindowClosed();

private:
    Ui::paramWin_mea_resis *ui;
    Resis *_resis;
    showWin_measureResis *show_win_measure_r;

private:
    QString check_channel_choosed();
};

#endif // PARAMWIN_MEA_RESIS_H
