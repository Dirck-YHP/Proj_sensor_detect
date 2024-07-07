#ifndef SHOWWIN_PRESSURESENSOR_H
#define SHOWWIN_PRESSURESENSOR_H

#include <QWidget>
#include <QTimer>

#include "sensors/pressuresensor.h"
#include "devices/hydraulicstation.h"
#include "assist_func/assist.h"

// file save
#include <QFile>
#include <QDateTime>
#include <QTextStream>

namespace Ui {
class showWin_pressureSensor;
}

class showWin_pressureSensor : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_pressureSensor(QString file_save_dir, PressureSensor *pressure_sensor, QWidget *parent = nullptr);
    ~showWin_pressureSensor();

private slots:
    void on_btn_start_finish_mea_toggled(bool checked);
    void on_btn_ok_clicked();

    // 测试用，接收到来自传感器的数据然后显示出来
    void get_data_and_plot_pressure(QVector<double> data);
    void on_pushButton_clicked();

signals:
    void signal_setConfigSerialPort();
    void signal_closeOpen();

private:
    Ui::showWin_pressureSensor *ui;
    PressureSensor *_pressure_sensor;
    HydraulicStation *_hydraulic_station = nullptr;

    int channel_num;

    QTimer _timer_hydrau;

    // 文件保存
    QString _file_save_dir;
    QTimer _timer_savefile;
    QFile file;

private:
    void set_visiable();
    void setLineEditsForRowEnable(const QString &baseName, int ch_num, bool isEnable);
    void save_data();
};

#endif // SHOWWIN_PRESSURESENSOR_H
