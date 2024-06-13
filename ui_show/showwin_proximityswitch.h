#ifndef SHOWWIN_PROXIMITYSWITCH_H
#define SHOWWIN_PROXIMITYSWITCH_H

#include <QWidget>

namespace Ui {
class showWin_proximitySwitch;
}

class showWin_proximitySwitch : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_proximitySwitch(QWidget *parent = nullptr);
    ~showWin_proximitySwitch();

private:
    Ui::showWin_proximitySwitch *ui;
};

#endif // SHOWWIN_PROXIMITYSWITCH_H
