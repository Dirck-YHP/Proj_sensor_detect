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
            file_process_angle_e();
            break;

        case SensorType::AngleSensor:           // 处理角度传感器
            file_process_angle_s();
            break;

        case SensorType::ProximitySwitch:       // 处理接近开关
            file_process_proxi();
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

            // 第二行是提示信息：暂不处理
            QString second_line = in.readLine();
//          qDebug() << second_line;

            // 从第三行开始读取数据
            QVector<double> xData;
            QVector<QVector<double>> yData(6);

            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList data = line.split(":", QString::SkipEmptyParts);
                if (data.size() == 2) {
                    QStringList yParts = data.at(1).split(" ", QString::SkipEmptyParts);
                    y_channel_num = yParts.size();
                    if (yParts.size() >= 2) {
                        xData.append(data[0].toDouble());
                        for (int k = 0; k < yParts.size(); k++) {
                            yData[k].append(yParts[k].toDouble());
                        }
                    }
                }
            }
            file.close();

            qDebug() << "channel_num[ +hydra(1) ]: " << y_channel_num;
            qDebug() << "finish reading data, size: "
                     << xData.size();
            for (int i = 0; i < y_channel_num; i++) {
                qDebug() << "y_size:" << yData[i].size();
            }

            // 画图
            ui->custom_plot->clearGraphs();
            ui->custom_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
            ui->custom_plot->xAxis->setLabel("time/s");
            ui->custom_plot->yAxis->setLabel("Y");
            ui->custom_plot->yAxis->setRange(-10, 10);

            // Graph数量 = 压力传感器的通道数(channel_num) + 液压站(1)
            for (int i = 0; i < y_channel_num; i++) {
                ui->custom_plot->addGraph();
                ui->custom_plot->graph(i)->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256)));
            }

            for (int i = 0; i < y_channel_num; i++) {
                ui->custom_plot->graph(i)->addData(xData, yData[i], true);
            }
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

/***************************************************************
  *  @brief     处理角位移编码器的文件
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataReview::file_process_angle_e()
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
                if (part.startsWith("传感器类型：")) {
                    type = part.mid(6); // 去掉前缀"传感器类型："
                } else if (part.startsWith("编码器每圈脉冲数：")) {
                    range = part.mid(9); // 去掉前缀"编码器每圈脉冲数："
                } else if (part.startsWith("采集通道：")) {
                    acqChannels = part.mid(5);
                }
            }

            // 显示标签信息
            QString str = "传感器类型：" + type +
                         " 编码器每圈脉冲数：" + range +
                         " 采集通道：" + acqChannels;
            ui->lineE_labels->setText(str);

            // 第二行是提示信息：暂不处理
            QString second_line = in.readLine();
//            qDebug() << second_line;

            // 从第三行开始读取数据
            QVector<double> xData;
            QVector<double> yData1;
            QVector<double> yData2;

            while (!in.atEnd()) {
                QString line = in.readLine();
//                qDebug() << line;
                QStringList data = line.split(":", QString::SkipEmptyParts);
                if (data.size() == 2) {
                    QStringList yParts = data.at(1).split(" ", QString::SkipEmptyParts);
                    if (yParts.size() >= 2) {
                        xData.append(data[0].toDouble());
                        yData1.append(yParts[0].toDouble());
                        yData2.append(yParts[1].toDouble());
                    }
                }
            }
            file.close();

            qDebug() << "finish reading data, size: "
                     << xData.size() << " "
                     << yData1.size() << " "
                     << yData2.size();
            // 画图
            ui->custom_plot->clearGraphs();
            ui->custom_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
            ui->custom_plot->xAxis->setLabel("time/s");
            ui->custom_plot->yAxis->setLabel("Y");
            ui->custom_plot->yAxis->setRange(-10, 10);

            // Graph数量 = 角位移编码器角度(1) + 电机角度(1)
            for (int i = 0; i < 2; i++) {
                ui->custom_plot->addGraph();
                ui->custom_plot->graph(i)->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256)));
            }

            ui->custom_plot->graph(0)->addData(xData, yData1, true);
            ui->custom_plot->graph(1)->addData(xData, yData2, true);
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

/***************************************************************
  *  @brief     处理角位移传感器的文件
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataReview::file_process_angle_s()
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
                if (part.startsWith("传感器类型：")) {
                    type = part.mid(6); // 去掉前缀"传感器类型："
                } else if (part.startsWith("采集范围：")) {
                    range = part.mid(5); // 去掉前缀"采集范围："
                } else if (part.startsWith("采集通道：")) {
                    acqChannels = part.mid(5);
                }
            }

            // 显示标签信息
            QString str = "传感器类型：" + type +
                         " 采集范围：" + range +
                         " 采集通道：" + acqChannels;
            ui->lineE_labels->setText(str);

            // 第二行是提示信息：暂不处理
            QString second_line = in.readLine();
//            qDebug() << second_line;

            // 从第三行开始读取数据
            QVector<double> xData;
            QVector<double> yData1;
            QVector<double> yData2;

            while (!in.atEnd()) {
                QString line = in.readLine();
//                qDebug() << line;
                QStringList data = line.split(":", QString::SkipEmptyParts);
                if (data.size() == 2) {
                    QStringList yParts = data.at(1).split(" ", QString::SkipEmptyParts);
                    if (yParts.size() >= 2) {
                        xData.append(data[0].toDouble());
                        yData1.append(yParts[0].toDouble());
                        yData2.append(yParts[1].toDouble());
                    }
                }
            }
            file.close();

            qDebug() << "finish reading data, size: "
                     << xData.size() << " "
                     << yData1.size() << " "
                     << yData2.size();
            // 画图
            ui->custom_plot->clearGraphs();
            ui->custom_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
            ui->custom_plot->xAxis->setLabel("time/s");
            ui->custom_plot->yAxis->setLabel("Y");
            ui->custom_plot->yAxis->setRange(-10, 10);

            // Graph数量 = 角位移编码器角度(1) + 电机角度(1)
            for (int i = 0; i < 2; i++) {
                ui->custom_plot->addGraph();
                ui->custom_plot->graph(i)->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256)));
            }

            ui->custom_plot->graph(0)->addData(xData, yData1, true);
            ui->custom_plot->graph(1)->addData(xData, yData2, true);
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

/***************************************************************
  *  @brief     处理接近开关的文件
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void funcWin_DataReview::file_process_proxi()
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
            QString type, using_time, sensing_matirial, sensing_dis, acqChannels;

            foreach (const QString &part, headerParts) {
                if (part.startsWith("传感器类型：")) {
                    type = part.mid(6);
                } else if (part.startsWith("使用时间：")) {
                    using_time = part.mid(5);
                } else if (part.startsWith("感应材料：")) {
                    sensing_matirial = part.mid(5);
                } else if (part.startsWith("感应距离：")) {
                    sensing_dis = part.mid(5);
                } else if (part.startsWith("采集通道：")) {
                    acqChannels = part.mid(5);
                }
            }

            // 显示标签信息
            QString str = "传感器类型：" + type +
                         " 使用时间：" + using_time +
                         " 感应材料：" + sensing_matirial +
                         " 感应距离：" + sensing_dis +
                         " 采集通道：" + acqChannels;
            ui->lineE_labels->setText(str);

            // 第二行是提示信息：暂不处理
            QString second_line = in.readLine();
//            qDebug() << second_line;

            // 从第三行开始读取数据
            QVector<double> xData;
            QVector<double> yData1;
            QVector<double> yData2;

            while (!in.atEnd()) {
                QString line = in.readLine();
//                qDebug() << line;
                QStringList data = line.split(":", QString::SkipEmptyParts);
                if (data.size() == 2) {
                    QStringList yParts = data.at(1).split(" ", QString::SkipEmptyParts);
                    if (yParts.size() >= 2) {
                        xData.append(data[0].toDouble());
                        yData1.append(yParts[0].toDouble());
                        yData2.append(yParts[1].toDouble());
                    }
                }
            }
            file.close();

            qDebug() << "finish reading data, size: "
                     << xData.size() << " "
                     << yData1.size() << " "
                     << yData2.size();
            // 画图
            ui->custom_plot->clearGraphs();
            ui->custom_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
            ui->custom_plot->xAxis->setLabel("time/s");
            ui->custom_plot->yAxis->setLabel("Y");
            ui->custom_plot->yAxis->setRange(-10, 10);

            // Graph数量 = 2
            ui->custom_plot->addGraph();
            ui->custom_plot->addGraph();

            //

            // 根据y2判断是否画“触发”
            for (int i = 0; i < yData1.size(); i++) {
                QVector<double> x = {xData[i]};
                QVector<double> y = {yData1[i]};
                ui->custom_plot->graph(0)->addData(x, y, true);
            }

            ui->custom_plot->graph(0)->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256)));
            ui->custom_plot->graph(1)->setPen(QPen(QColor(255, 0, 0)));

            for (int i = 0; i < yData2.size(); i++) {
                QVector<double> x = {xData[i]};
                QVector<double> y = {yData1[i]};
                if (yData2[i]) {
                    ui->custom_plot->graph(1)->setLineStyle(QCPGraph::LineStyle::lsNone);
                    ui->custom_plot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
                    ui->custom_plot->graph(1)->addData(x, y, true);
                }
            }

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
