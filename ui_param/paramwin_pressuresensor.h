#ifndef PARAMWIN_PRESSURESENSOR_H
#define PARAMWIN_PRESSURESENSOR_H

#include <QWidget>

namespace Ui {
class paramWin_pressureSensor;
}

class paramWin_pressureSensor : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_pressureSensor(QWidget *parent = nullptr);
    ~paramWin_pressureSensor();

private:
    Ui::paramWin_pressureSensor *ui;

signals:
    void subWindowClosed();
private slots:
    void on_btn_back_mainW_clicked();
    void on_btn_exit_clicked();
};

#endif // PARAMWIN_PRESSURESENSOR_H
