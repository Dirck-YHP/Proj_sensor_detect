#ifndef PARAMWIN_PROXIMITYSWITCH_H
#define PARAMWIN_PROXIMITYSWITCH_H

#include <QWidget>

#include "sensors/proximityswitch.h"
#include "ui_show/showwin_proximityswitch.h"

namespace Ui {
class paramWin_proximitySwitch;
}

class paramWin_proximitySwitch : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_proximitySwitch(QWidget *parent = nullptr);
    ~paramWin_proximitySwitch();

private:
    Ui::paramWin_proximitySwitch *ui;
    ProximitySwitch *_proxi_switch;
    showWin_proximitySwitch *_show_win_prox_switch;

signals:
    void subWindowClosed();

private slots:
    void on_btn_exit_clicked();
    void on_btn_back_mainW_clicked();
    void on_btn_ok_clicked();
};

#endif // PARAMWIN_PROXIMITYSWITCH_H
