#include "showwin_proximityswitch.h"
#include "ui_showwin_proximityswitch.h"

showWin_proximitySwitch::showWin_proximitySwitch(QString file_save_dir, ProximitySwitch *proxi_switch, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_proximitySwitch),
    _proxi_switch(proxi_switch),
    _file_save_dir(file_save_dir)
{
    ui->setupUi(this);

    /*-------------------- UI界面 --------------------------*/
    UI_init();


    /********************** 文件保存相关 **********************/
    if (_file_save_dir != "") {
        FILE_SAVE = true;
        _data_save = new DataSave;
        _timer_savefile.setInterval(500);       // 20ms一个数据点，500ms写入到文件一次，25个点
        connect(&_timer_savefile, &QTimer::timeout, this, &showWin_proximitySwitch::save_data);
    } else {
        FILE_SAVE = false;
        qDebug() << "(In Win)do not save file!";
    }

    /********************** qt特性配置 **********************/
    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);

    /********************** 画图参数配置 **********************/
    ui->plot_distance->clearGraphs();
    ui->plot_distance->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_distance->xAxis->setLabel("time/s");
    ui->plot_distance->yAxis->setLabel("Y");
    ui->plot_distance->yAxis->setRange(-10, 10);

    // 添加图 画距离 和 画触发信号
    // 一张图就够了，根据是否触发判断当前这个点要不要画的特殊一点
    for (int i = 0; i < 2; i++) {
        ui->plot_distance->addGraph();
    }
    ui->plot_distance->graph(0)->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256)));
    ui->plot_distance->graph(1)->setPen(QPen(QColor(255, 0, 0)));

    /********************** 9205相关 **********************/
    connect(_proxi_switch, &ProximitySwitch::send_vol_cur_pul_dis_to_ui,
            this, &showWin_proximitySwitch::slot_get_vol_cur_pul_dis_and_show);

    /********************** 对象析构 **********************/
    connect(this, &showWin_proximitySwitch::signal_delete,
            _proxi_switch, &ProximitySwitch::slot_acq_delete);

    /********************** 错误检测 **********************/
    connect(_proxi_switch, &ProximitySwitch::sig_err_to_ui,
            this, &showWin_proximitySwitch::slot_get_err);
}

void showWin_proximitySwitch::UI_init()
{
    ui->label->setStyleSheet("font:bold 18pt Arial;color:rgb(130,194,204);background-color:rgb(105,105,105);");
    ui->label_bat->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_dis->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_dis_avg->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_dis_max->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_dis_min->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_sensing_dis->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_signal_current->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_signal_voltage->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_supply_current->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");
    ui->label_supply_voltage->setStyleSheet("font-size: 14pt;color:rgb(67,67,67);");

    ui->btn_ok->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_start_finish_mea->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(84,80,107);");
    ui->btn_repeat_precise->setStyleSheet("font-size: 14pt;color:rgb(254,254,254);background-color:rgb(146,189,108);");
}

showWin_proximitySwitch::~showWin_proximitySwitch()
{
    emit signal_delete();
    qDebug() << "(In Win)proximity window destroyed";
    delete ui;
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      槽函数——“开始测量”/“结束测量”
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::on_btn_start_finish_mea_toggled(bool checked)
{
    if (checked) {
        ui->btn_start_finish_mea->setText("结束测量");
        Assist::board_init(true);

        /************************ 接近开关 + 滑动变阻器 ************************/
        // 由于滑动变阻器也是通过9205采集数据计算得到距离，而全局只能存在一个数据采集类的对象
        // 所以将滑动变阻器类和接近开关类结合到一起
        // 即 接近开关下发通道时在最后加上滑动变阻器对应通道

        _proxi_switch->start_acquire();

        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            QString currentDateTime = "PxS_" + _file_add_name + "_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
            QString file_name = _file_save_dir + "/" + currentDateTime + "_data.txt";
            file.setFileName(file_name);
            if (!file.open(QIODevice::Append | QIODevice::Text))    // 打开文件
                return;

            QTextStream out(&file);
            out.setCodec("UTF-8");
            out << QString("传感器类型：") << _proxi_switch->get_label().toUtf8()
                << QString("，使用时间：") << _proxi_switch->get_using_time()
                << QString("，感应材料：") << _proxi_switch->get_sensing_matirial()
                << QString("，感应距离：") << _proxi_switch->get_sensing_dis()
                << QString("，采集通道：") << _proxi_switch->get_channel().toUtf8() << "\n";
            out << QString("x") << QString("  距离") << QString(" 是否触发") << "\n";

            _timer_savefile.start();    // 开启定时器，开始保存数据
        }

    }else {
        ui->btn_start_finish_mea->setText("开始测量");

        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            // 保存缓冲区中残余的数据
            _timer_savefile.stop();
            qDebug() << "data_buf_size_when_close: "
                     << save_data_buf_variaresis.size()
                     << save_data_buf_if_pulse.size();

            if (!save_data_buf_variaresis.empty()) {
                QTextStream out(&file);
                out.setCodec("UTF-8");
                // 遍历数据并写入文件
                for (int i = 0; i < save_data_buf_variaresis.size(); i++) {
                    out << time_stamp << ":  "
                        << save_data_buf_variaresis[i].value << "    "
                        << save_data_buf_if_pulse[i].value << "\n";
                    time_stamp++;
                }

                qDebug() << "finish file writing last!!! ";
            }
            file.close();
        }

        /********************** 数据采集相关 **********************/
        _proxi_switch->stop_acquire();
    }
}

/***************************************************************
  *  @brief     画 来自滑动变阻器的距离波形
  *  @param     无
  *  @note      槽函数——暂没用到！！！！
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::get_data_and_plot_distance(QVector<double> data)
{
    _distance = data[0];

    int length = data.size();     // 每通道数据 数
    QVector<double> x(length);
    int point_count = ui->plot_distance->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    // 画图，一条曲线
    for (int i = 0; i < 1; i++) {
        ui->plot_distance->graph(i)->addData(x,
            QVector<double>(data.begin() + i*length, data.begin() + i*length + length), true);
    }
    ui->plot_distance->rescaleAxes();       // 自适应大小
    ui->plot_distance->replot();

    /********************文件保存*********************/
    // 数据首先都放到缓冲区中
    _data_save->collectData(&save_data_buf_variaresis, _distance);
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      槽函数：
  *         供电电压、信号电压、信号电流、供电电流、是否触发、滑动变阻器距离、电池电量
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::slot_get_vol_cur_pul_dis_and_show(QVector<double> data)
{
    const int DIGIT = 1;
    /*********************** 供电电压 ************************/
    double sup_vol = data[0];
    ui->lineE_supply_voltage->setText(QString::number(sup_vol, 'f', DIGIT) + "V");

    /*********************** 信号电压 ************************/
    double sig_vol = data[1];
    ui->lineE_signal_voltage->setText(QString::number(sig_vol / 5.1 * 25.1, 'f', DIGIT) + "V");

    /*********************** 信号电流 ************************/
    double sig_cur = data[2];
    ui->lineE_signal_current->setText(QString::number(sig_cur, 'f', DIGIT) + "mA");

    /*********************** 供电电流 ************************/
    double sup_cur = data[3];
    ui->lineE_supply_current->setText(QString::number(sup_cur, 'f', DIGIT) + "mA");

    /*********************** 是否触发 ************************/
    bool if_Pulse = data[4];
    // 在这里判断上升下降沿
    bool if_changed = (if_Pulse != _if_pulse);
    _if_pulse = if_Pulse;       // 保存触发状态

    /********************* 滑动变阻器距离 **********************/
    _distance = data[5];
    /*************** 画距离 ****************/
    int length = 1;
    QVector<double> x(length);
    int point_count = ui->plot_distance->graph(0)->dataCount();

    // 确定画图的横轴
    for (int i = 0; i < length; i++) {
        x[i] = i + point_count;
    }

    /*************** 画 “触发点” ****************/
    if (if_changed) {
        QVector<double> y_pulse = {_distance};

        ui->plot_distance->graph(1)->setLineStyle(QCPGraph::LineStyle::lsNone);
        ui->plot_distance->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
        ui->plot_distance->graph(1)->addData(x, y_pulse, true);
        qDebug() << "---- YES ----";
    } else {

    }

    // 画图，一次画一个点
    QVector<double> y = {_distance};

    ui->plot_distance->graph(0)->addData(x, y, true);
    ui->plot_distance->rescaleAxes();       // 自适应大小
    ui->plot_distance->replot();

    /*************** 数值框显示 ****************/
    ui->lineE_sensing_dis->setText(QString::number(_distance, 'f', 1) + "mm");

    /********************** 重复精度测量 **********************/

    if (_if_rep_mea) {      // 如果用户点击了“重复精度测量”
        if (if_changed) {   // 只有“触发”的时候才记录距离
           _dis_arr.push_back(_distance);
            qDebug() << "(In Win)dis: " << _distance;
            // _dis_arr.push_back(tmp_num);
        }

//        qDebug() << "(In Win)measuring... _dis_arr's size: " << _dis_arr.size();

        if (_dis_arr.size() == REPEAT_TIMES) {      // 已经记录了10次
            auto maxIt = std::max_element(_dis_arr.begin(), _dis_arr.end());
            auto minIt = std::min_element(_dis_arr.begin(), _dis_arr.end());

            double max_dis = *maxIt;    // 最大值
            double min_dis = *minIt;    // 最小值

            // 计算平均值
            double sum = std::accumulate(_dis_arr.begin(), _dis_arr.end(), 0.0);
            double avg_dis = _dis_arr.isEmpty() ? 0.0 : sum / _dis_arr.size();

            ui->lineE_dis_max->setText(QString::number(max_dis, 'f', DIGIT));
            ui->lineE_dis_min->setText(QString::number(min_dis, 'f', DIGIT));
            ui->lineE_dis_avg->setText(QString::number(avg_dis, 'f', DIGIT));

            _if_rep_mea = false;        // 结束重复精度测量
            _dis_arr.clear();           // 清空
            qDebug() << "(In Win)finish repeart precise measure...";
        }
    }

    /*********************** 电池电量 ************************/
    double bat = data[6];
    ui->pBar_battery->setOrientation(Qt::Horizontal);  // 水平方向
    ui->pBar_battery->setMinimum(0);                   // 最小值
    ui->pBar_battery->setMaximum(25);                   // 最大值
    double dProgress = (bat - ui->pBar_battery->minimum()) * 100.0
                    / (ui->pBar_battery->maximum() - ui->pBar_battery->minimum());
    // 定义电量档位
    int batteryLevel;
    if (dProgress <= 25.0) {
        batteryLevel = 25;  // 第一档：25%
    } else if (dProgress <= 50.0) {
        batteryLevel = 50;  // 第二档：50%
    } else if (dProgress <= 75.0) {
        batteryLevel = 75;  // 第三档：75%
    } else {
        batteryLevel = 100; // 第四档：100%
    }

    ui->pBar_battery->setValue(batteryLevel);                  // 当前进度
    ui->pBar_battery->setFormat(QString::fromLocal8Bit("bat left: %1%").arg(QString::number(batteryLevel, 'f', 1)));
    ui->pBar_battery->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式

    /******************** 文件保存 *********************/
    if (FILE_SAVE) {
        // 数据首先都放到缓冲区中
        _data_save->collectData(&save_data_buf_if_pulse, if_changed);
        _data_save->collectData(&save_data_buf_variaresis, _distance);
    }

}

/***************************************************************
  *  @brief     按键：确认
  *  @param     无
  *  @note      槽函数——删除数据保存对象
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::on_btn_ok_clicked()
{
    _proxi_switch->stop_acquire();

    if (_data_save != nullptr) {
        delete _data_save;
        qDebug() << "(In Win)data_save and delete succeed!";
    }

    this->close();
}

/***************************************************************
  *  @brief     按键：重复精度测量
  *  @param     无
  *  @note      槽函数——开始测量十次的感应距离，即记录十次的触发时刻滑动变阻器的距离
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::on_btn_repeat_precise_clicked()
{
    _if_rep_mea = true;
    qDebug() << "(In Win)begin repeart precise measure...";
}

/***************************************************************
  *  @brief     保存数据
  *  @param     无
  *  @note      槽函数，每500ms从缓冲区中取出数据写入一次
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::save_data()
{
    QTextStream out(&file);
    out.setCodec("UTF-8");
    // 遍历数据并写入文件
    qDebug() << "(In W_file_save)size: " << save_data_buf_variaresis.size()
             << " " << save_data_buf_if_pulse.size();
    for (int i = 0; i < save_data_buf_variaresis.size(); i++) {
        out << time_stamp << ":  "
            << save_data_buf_variaresis[i].value << "    "
            << save_data_buf_if_pulse[i].value << "\n";
        time_stamp++;
    }

    save_data_buf_variaresis.clear();                // 清空缓冲区
    save_data_buf_if_pulse.clear();
}

/***************************************************************
  *  @brief     处理数据采集类的错误信号，给用户一个弹窗
  *  @param     无
  *  @note      槽函数——接收错误信号
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::slot_get_err(bool err)
{
    qDebug() << "(In Win)get err!——" << err;

    if (!sig_error) {
        sig_error = true;

        ErrorPrompt e_pmt;
        e_pmt.showError(ErrorType::NetworkError);
    }
}

void showWin_proximitySwitch::update_file_name(const QString &text)
{
    _file_add_name = text;
    qDebug() << "(In Win)file_name: " << _file_add_name;
}
