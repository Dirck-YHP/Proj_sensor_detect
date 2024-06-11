#ifndef PARAMWIN_PROXIMITYSWITCH_H
#define PARAMWIN_PROXIMITYSWITCH_H

#include <QWidget>

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

signals:
    void subWindowClosed();
private slots:
    void on_btn_exit_clicked();
    void on_btn_back_mainW_clicked();
};

#endif // PARAMWIN_PROXIMITYSWITCH_H
