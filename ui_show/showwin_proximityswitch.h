#ifndef SHOWWIN_PROXIMITYSWITCH_H
#define SHOWWIN_PROXIMITYSWITCH_H

#include <QWidget>
#include "sensors/proximityswitch.h"

namespace Ui {
class showWin_proximitySwitch;
}

class showWin_proximitySwitch : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_proximitySwitch(ProximitySwitch *proxi_switch, QWidget *parent = nullptr);
    ~showWin_proximitySwitch();

private:
    Ui::showWin_proximitySwitch *ui;
    ProximitySwitch *_proxi_switch;
};

#endif // SHOWWIN_PROXIMITYSWITCH_H
