#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "ui_param/paramwin_anglesensor.h"
#include "ui_param/paramwin_angleencoder.h"
#include "ui_param/paramwin_proximityswitch.h"
#include "ui_param/paramwin_pressuresensor.h"
#include "ui_param/paramwin_mea_resis.h"

#include "ui_func/funcwin_dataexport.h"

#include "assist_func/assist.h"

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

    void showMainWindow();

    void on_btn_AS_clicked();

    void on_btn_AE_clicked();

    void on_btn_PxS_clicked();

    void on_btn_PS_clicked();

    void on_btn_Resis_clicked();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
