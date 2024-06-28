#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "ui_param/paramwin_anglesensor.h"
#include "ui_param/paramwin_angleencoder.h"
#include "ui_param/paramwin_proximityswitch.h"
#include "ui_param/paramwin_pressuresensor.h"


#include "ui_func/funcwin_dataexport.h"

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

    void showMainWindow();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
