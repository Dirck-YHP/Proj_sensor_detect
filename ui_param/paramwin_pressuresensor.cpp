#include "paramwin_pressuresensor.h"
#include "ui_paramwin_pressuresensor.h"

paramWin_pressureSensor::paramWin_pressureSensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_pressureSensor)
{
    ui->setupUi(this);
}

paramWin_pressureSensor::~paramWin_pressureSensor()
{
    delete ui;
}

void paramWin_pressureSensor::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

void paramWin_pressureSensor::on_btn_exit_clicked()
{
    qApp->quit();
}

void paramWin_pressureSensor::on_btn_ok_clicked()
{
    _pressure_sensor = new PressureSensor;
    _pressure_sensor->set_label(ui->cBox_pressure_sensor_type->currentText());
    _pressure_sensor->set_range(ui->lineE_4mA->text(), ui->lineE_20mA->text());
    _pressure_sensor->set_channel(check_channel_choosed());


    show_win_press_sensor = new showWin_pressureSensor(m_file_save_dir, _pressure_sensor);
    show_win_press_sensor->show();

}

void paramWin_pressureSensor::on_checkBox_measure_r_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {      // 如果测电阻，则工装及电机不可用
        ui->gridGroupBox->setEnabled(false);
        ui->label_7->setEnabled(false);

    } else if (arg1 == Qt::Unchecked) { // 如果不测电阻，则可用
        ui->gridGroupBox->setEnabled(true);
        ui->label_7->setEnabled(true);
    }
}

QString paramWin_pressureSensor::check_channel_choosed() {
    QString channel_choosed;
    // 从 1 到 6 循环检查每个通道
    for (int i = 1; i <= 6; ++i) {
        // 构建每个 QCheckBox 的 objectName
        QString checkBoxName = QString("checkBox_ch_%1").arg(i);

        // 使用 findChild 查找对应的 QCheckBox
        QCheckBox *checkBox = ui->gridGroupBox->findChild<QCheckBox*>(checkBoxName);

        // 检查 QCheckBox 是否存在以及是否被勾选
        if (checkBox && checkBox->isChecked()) {
            if (!channel_choosed.isEmpty()) {
                channel_choosed.append(",");
            }
            // 将通道编号添加到字符串中
            channel_choosed.append(QString::number(i));
            // channel_choosed.append(电压+电流)
        }
    }
    return channel_choosed;
}


void paramWin_pressureSensor::on_cBox_file_save_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
        m_file_save_dir = QFileDialog::getExistingDirectory(this, "Save file", "../", QFileDialog::ShowDirsOnly);
        qDebug() << m_file_save_dir;
    } else if (arg1 == Qt::Unchecked) {
        m_file_save_dir = "";
    }
}
