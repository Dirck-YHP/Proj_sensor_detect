#ifndef PARAMWIN_PROXIMITYSWITCH_H
#define PARAMWIN_PROXIMITYSWITCH_H

#include <QWidget>
#include <QMessageBox>

#include "sensors/proximityswitch.h"
#include "ui_show/showwin_proximityswitch.h"
#include "ui_func/funcwin_datareview.h"

namespace Ui {
class paramWin_proximitySwitch;
}

class paramWin_proximitySwitch : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_proximitySwitch(QWidget *parent = nullptr);
    ~paramWin_proximitySwitch();

    QString check_channel_choosed();

private:
    Ui::paramWin_proximitySwitch *ui;
    ProximitySwitch *_proxi_switch;
    showWin_proximitySwitch *_show_win_prox_switch;

    funcWin_DataReview *func_win_data_review;
    QString m_file_save_dir;

signals:
    void subWindowClosed();
    void file_name(const QString &text);

private slots:
    void on_btn_exit_clicked();
    void on_btn_back_mainW_clicked();
    void on_btn_ok_clicked();
    void on_cBox_file_save_stateChanged(int arg1);
    void on_btn_load_data_clicked();
};

#endif // PARAMWIN_PROXIMITYSWITCH_H
