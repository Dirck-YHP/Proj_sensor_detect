#include "funcwin_datareview.h"
#include "ui_funcwin_datareview.h"

funcWin_DataReview::funcWin_DataReview(SensorType sensor_type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::funcWin_DataReview),
    _sensor_type(sensor_type)
{
    ui->setupUi(this);

}

funcWin_DataReview::~funcWin_DataReview()
{
    delete ui;
}

/***************************************************************
  *  @brief     确认键按下
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataReview::on_btn_ok_clicked()
{
    this->close();
}

/***************************************************************
  *  @brief     选择文件
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataReview::on_btn_choose_file_clicked()
{
    switch (_sensor_type) {
        case SensorType::AngleEncoder:          // 处理角度编码器
            break;
        case SensorType::AngleSensor:           // 处理角度传感器
            break;
        case SensorType::ProximitySwitch:       // 处理接近开关
            break;
        case SensorType::PressureSensor:        // 处理压力传感器
            file_process_press();
            break;
    }
}

/***************************************************************
  *  @brief     处理压力传感器的文件
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataReview::file_process_press()
{
    QString filePath = QFileDialog::getOpenFileName(this, "选择文件", "../", "所有文件 (*);;文本文件 (*.txt)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            in.setCodec("UTF-8");

            // 读取第一行作为标签信息
            QString headerLine = in.readLine();
            // 解析标签信息
            QStringList headerParts = headerLine.split("，", QString::SkipEmptyParts);
            QString type;
            QString range;
            QString acqChannels;

            foreach (const QString &part, headerParts) {
                if (part.startsWith("采集类型：")) {
                    type = part.mid(5); // 去掉前缀"采集类型："
                } else if (part.startsWith("采集范围：")) {
                    range = part.mid(5); // 去掉前缀"采集范围："，并保留"~"符号
                } else if (part.startsWith("采集通道：")) {
                    acqChannels = part.mid(5);
                }
            }

            // 显示标签信息
            QString str = "采集类型：" + type +
                         " 采集范围：" + range +
                         " 采集通道：" + acqChannels;
            ui->lineE_labels->setText(str);

            // 从第二行开始读取数据
            QVector<double> xData;
            QVector<double> yData1;
            QVector<double> yData2;

            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList data = line.split(",", QString::SkipEmptyParts);
                if (data.size() >= 2) {
                    // 这里假设第一列是时间戳，第二列和第三列是数据点
                    // 根据实际情况调整解析逻辑
                    xData.append(data[0].toDouble());
                    yData1.append(data[1].toDouble());
//                    yData2.append(data[2].toDouble());
                }
            }
            file.close();

            qDebug() << "finish reading data, size: "
                     << xData.size() << " "
                     << yData1.size() << " ";
//                     << yData2.size();
            // 画图
            ui->custom_plot->clearGraphs();
            ui->custom_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
            ui->custom_plot->xAxis->setLabel("time/s");
            ui->custom_plot->yAxis->setLabel("Y");
            ui->custom_plot->yAxis->setRange(-10, 10);

            // Graph数量 = 压力传感器的通道数(channel_num) + 液压站(1)，暂时为1
            for (int i = 0; i < 1; i++) {
                ui->custom_plot->addGraph();
            }

            ui->custom_plot->graph(0)->addData(xData, yData1, true);
            ui->custom_plot->rescaleAxes();       // 自适应大小
            ui->custom_plot->replot();

        } else {
            QMessageBox::warning(this, "错误", "无法打开文件: " + filePath);
        }

        QMessageBox::information(this, "操作", "文件导入成功");
    } else {
        // 用户取消了选择
        QMessageBox::information(this, "操作", "您取消了文件选择");
    }
}
