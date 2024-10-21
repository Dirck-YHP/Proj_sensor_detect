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
#include "functionality/datasave.h"

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
    void slot_plot_press_from_sensor(QVector<double> data);

    void slot_plot_press_from_hydraSta(QVector<double> data);
    void save_data();

    void slot_get_err(bool err);

public slots:
    void update_file_name(const QString &text);

signals:
    void signal_setConfigSerialPort();
    void signal_closeOpen();

    void signal_delete();

private:
    Ui::showWin_pressureSensor *ui;
    PressureSensor *_pressure_sensor;
    HydraulicStation *_hydraulic_station = nullptr;

    int channel_num;

    QTimer _timer_hydrau;

    // 液压站
    double _pressure = 0;

    // 文件保存
    QString _file_save_dir;
    QString _file_add_name;     // 用户需要的文件名标识符
    QTimer _timer_savefile;
    QFile file;
    DataSave *_data_save = nullptr;
    bool FILE_SAVE = false;
    QVector<SensorData> save_data_buf_hydra;        // 来自液压站的要保存的数据
    QVector<QVector<SensorData>> save_data_buf_sensor;       // 来自传感器的要保存的数据
    int time_stamp = 0;

    QVector<double> err_save;   // 保存误差值，用来画图

    bool sig_error = false;

    void UI_init();

private:
    void set_visiable();
    void setLineEditsForRowEnable(const QString &baseName, int ch_num, bool isEnable);

    void show_vol_cur_press(QVector<double> data);
    void setLineEditsForRowValue(const QString &baseName, int ch_num, double data);

};

#endif // SHOWWIN_PRESSURESENSOR_H
