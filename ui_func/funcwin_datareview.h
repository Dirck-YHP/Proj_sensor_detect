#ifndef FUNCWIN_DATAREVIEW_H
#define FUNCWIN_DATAREVIEW_H

#include <QWidget>
#include <QFileDialog>

enum class SensorType {
    AngleEncoder,
    AngleSensor,
    ProximitySwitch,
    PressureSensor
};

namespace Ui {
class funcWin_DataReview;
}

class funcWin_DataReview : public QWidget
{
    Q_OBJECT

public:
    explicit funcWin_DataReview(SensorType sensor_type, QWidget *parent = nullptr);
    ~funcWin_DataReview();

private slots:
    void on_btn_ok_clicked();

    void on_btn_choose_file_clicked();

private:
    Ui::funcWin_DataReview *ui;
    SensorType _sensor_type;

    void file_process_press();          // 压力传感器
    void file_process_angle_e();        // 角位移编码器
    void file_process_angle_s();        // 角位移传感器
    void file_process_proxi();          // 接近开关

private:
    int y_channel_num;
};

#endif // FUNCWIN_DATAREVIEW_H
