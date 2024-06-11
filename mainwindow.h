#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "ui/paramwin_anglesensor.h"
#include "ui/paramwin_angleencoder.h"
#include "ui/paramwin_proximityswitch.h"
#include "ui/paramwin_pressuresensor.h"

namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:
    void on_btn_exit_clicked();
    void on_btn_start_clicked();
    void on_btn_data_export_clicked();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
