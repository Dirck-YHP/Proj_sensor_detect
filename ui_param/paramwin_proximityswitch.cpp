#include "paramwin_proximityswitch.h"
#include "ui_paramwin_proximityswitch.h"

paramWin_proximitySwitch::paramWin_proximitySwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paramWin_proximitySwitch)
{
    ui->setupUi(this);
}

paramWin_proximitySwitch::~paramWin_proximitySwitch()
{
    delete ui;
}

void paramWin_proximitySwitch::on_btn_exit_clicked()
{
    qApp->quit();
}

void paramWin_proximitySwitch::on_btn_back_mainW_clicked()
{
    emit subWindowClosed();
    this->close();
}

void paramWin_proximitySwitch::on_btn_ok_clicked()
{
    _proxi_switch = new ProximitySwitch;
    _proxi_switch->set_label(ui->cBox_prox_switch_type->currentText());
    _proxi_switch->set_sensing_dis((ui->cBox_distance->currentText()));
    _proxi_switch->set_using_time(ui->cBox_use_time->currentText());
    _proxi_switch->set_sensing_matirial((ui->cBox_material->currentText()));

    _show_win_prox_switch = new showWin_proximitySwitch(_proxi_switch);
    _show_win_prox_switch->show();

}

/***************************************************************
  *  @brief     是否保存数据
  *  @param     无
  *  @note      槽函数——改变m_file_save_dir的值
  *  @Sample usage:
 **************************************************************/
void paramWin_proximitySwitch::on_cBox_file_save_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
        m_file_save_dir = QFileDialog::getExistingDirectory(this, "Save file", "../", QFileDialog::ShowDirsOnly);
        qDebug() << m_file_save_dir;
    } else if (arg1 == Qt::Unchecked) {
        m_file_save_dir = "";
    }
}

/***************************************************************
  *  @brief     数据回放
  *  @param     无
  *  @note      槽函数——是否 导入历史数据
  *  @Sample usage:
 **************************************************************/
void paramWin_proximitySwitch::on_btn_load_data_clicked()
{
    SensorType type = SensorType::ProximitySwitch;
    func_win_data_review = new funcWin_DataReview(type);
    func_win_data_review->show();
}
