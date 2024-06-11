#ifndef PARAMWIN_ANGLESENSOR_H
#define PARAMWIN_ANGLESENSOR_H

#include <QWidget>

namespace Ui {
class paramWin_angleSensor;
}

class paramWin_angleSensor : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_angleSensor(QWidget *parent = nullptr);
    ~paramWin_angleSensor();

private:
    Ui::paramWin_angleSensor *ui;
};

#endif // PARAMWIN_ANGLESENSOR_H
