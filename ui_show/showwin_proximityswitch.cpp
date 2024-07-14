#include "showwin_proximityswitch.h"
#include "ui_showwin_proximityswitch.h"

showWin_proximitySwitch::showWin_proximitySwitch(QString file_save_dir, ProximitySwitch *proxi_switch, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_proximitySwitch),
    _proxi_switch(proxi_switch),
    _file_save_dir(file_save_dir)
{
    ui->setupUi(this);

    // 根据用户选择的通道动态改变界面的label内容
    ui->label_channel->setText("通道：" + _proxi_switch->get_channel());

    /********************** 文件保存相关 **********************/
    if (_file_save_dir != "") {
        FILE_SAVE = true;
        _data_save = new DataSave;
        _timer_savefile.setInterval(500);       // 20ms一个数据点，500ms写入到文件一次，25个点
        connect(&_timer_savefile, &QTimer::timeout, this, &showWin_proximitySwitch::save_data);
    } else {
        FILE_SAVE = false;
        qDebug() << "do not save file!";
    }

    /********************** qt特性配置 **********************/
    // Set the attribute to delete the window when it is closed
    setAttribute(Qt::WA_DeleteOnClose);
}

showWin_proximitySwitch::~showWin_proximitySwitch()
{
    qDebug() << "proximity window destroyed";
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

        /************************ 滑动变阻器相关 ************************/
//        _variable_resis = new VariableResis;
//        _variable_resis->start_acquire();

//        connect(_variable_resis, &VariableResis::send_ni9205_to_ui,
//                this, &showWin_proximitySwitch::get_data_and_plot_distance);

        // 由于滑动变阻器也是通过9205采集数据计算得到距离，而全局只能存在一个数据采集类的对象
        // 所以将滑动变阻器类和接近开关类结合到一起
        // 即接近开关下发通道时在最后加上滑动变阻器对应通道
        /************************ 接近开关 + 滑动变阻器 ************************/
        _proxi_switch->start_acquire();

        // 需要一系列槽函数：供电电压、供电电流、信号电压、信号电流、是否触发、滑动变阻器距离、电池电量
        connect(_proxi_switch, &ProximitySwitch::send_ni9205_to_ui,
                this, &showWin_proximitySwitch::get_data_and_plot_pulse);

        /********************** 画图参数配置 **********************/
        ui->plot_distance->clearGraphs();
        ui->plot_distance->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->plot_distance->xAxis->setLabel("time/s");
        ui->plot_distance->yAxis->setLabel("Y");
        ui->plot_distance->yAxis->setRange(-10, 10);

        // 添加图，两个，一个画距离，一个画触发信号
        for (int i = 0; i < 2; i++) {
            ui->plot_distance->addGraph();
        }

        /********************** 文件保存相关 **********************/
        if (FILE_SAVE) {
            QString currentDateTime = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
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

            _timer_savefile.start();    // 开启定时器，开始保存数据
        }

    }else {
        ui->btn_start_finish_mea->setText("开始测量");

        /********************** 文件保存相关 **********************/
        // 保存缓冲区中残余的数据
        _timer_savefile.stop();
        qDebug() << "data_buf_size_when_close: " << save_data_buf_variaresis.size();
        if (!save_data_buf_variaresis.empty()) {
            QTextStream out(&file);
            out.setCodec("UTF-8");
            // 遍历数据并写入文件
            for (const SensorData& dataPoint : save_data_buf_variaresis) {
                out << time_stamp << "," << dataPoint.value << "\n";
                time_stamp++;
            }
            qDebug() << "finish file writing last!!! ";
        }
        file.close();

        /********************** 数据采集相关 **********************/
//        _variable_resis->stop_acquire();
        _proxi_switch->stop_acquire();
    }
}

/***************************************************************
  *  @brief     画 来自滑动变阻器的距离波形
  *  @param     无
  *  @note      槽函数
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
  *  @brief     画来自接近开关的 是否触发 的“点”
  *  @param     无
  *  @note      槽函数
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::get_data_and_plot_pulse(bool if_Pulse)
{
    // 在这里判断上升下降沿
    bool if_changed = (if_Pulse != _if_pulse);
    _if_pulse = if_Pulse;       // 保存触发状态

    /********************** 画“触发点” **********************/
    if (if_changed) {

    }

    /********************** 重复精度测量 **********************/
    if (_if_rep_mea) {      // 如果用户点击了“重复精度测量”
        if (if_changed)       // 只有“触发”的时候才记录距离
            _dis_arr.push_back(_distance);

        qDebug() << "measuring... _dis_arr's size: " << _dis_arr.size();

        if (_dis_arr.size() == REPEAT_TIMES) {      // 已经记录了10次
            auto maxIt = std::max_element(_dis_arr.begin(), _dis_arr.end());
            auto minIt = std::min_element(_dis_arr.begin(), _dis_arr.end());

            double max_dis = *maxIt;    // 最大值
            double min_dis = *minIt;    // 最小值

            // 计算平均值
            double sum = std::accumulate(_dis_arr.begin(), _dis_arr.end(), 0.0);
            double avg_dis = _dis_arr.isEmpty() ? 0.0 : sum / _dis_arr.size();

            ui->lineE_dis_max->setText(QString::number(max_dis));
            ui->lineE_dis_min->setText(QString::number(min_dis));
            ui->lineE_dis_avg->setText(QString::number(avg_dis));

            _if_rep_mea = false;        // 结束重复精度测量
            _dis_arr.clear();           // 清空
            qDebug() << "finish repeart precise measure...";
        }
    }

    /******************** 文件保存 *********************/
    // 数据首先都放到缓冲区中
    _data_save->collectData(&save_data_buf_if_pulse, if_changed);
}

/***************************************************************
  *  @brief     按键：确认
  *  @param     无
  *  @note      槽函数——删除数据保存对象
  *  @Sample usage:
 **************************************************************/
void showWin_proximitySwitch::on_btn_ok_clicked()
{
    if (_data_save != nullptr) {
        delete _data_save;
        qDebug() << "data_save and delete succeed!";
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
    qDebug() << "begin repeart precise measure...";
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
    for (const SensorData& dataPoint : save_data_buf_variaresis) {
        out << time_stamp << "," << dataPoint.value << "\n";
        time_stamp++;
    }
    save_data_buf_variaresis.clear();                // 清空缓冲区
}
