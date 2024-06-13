#ifndef SHOWWIN_PRESSURESENSOR_H
#define SHOWWIN_PRESSURESENSOR_H

#include <QWidget>

namespace Ui {
class showWin_pressureSensor;
}

class showWin_pressureSensor : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_pressureSensor(QWidget *parent = nullptr);
    ~showWin_pressureSensor();

private:
    Ui::showWin_pressureSensor *ui;
};

#endif // SHOWWIN_PRESSURESENSOR_H
