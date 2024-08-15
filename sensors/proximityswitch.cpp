﻿#include "proximityswitch.h"

ProximitySwitch::ProximitySwitch(QObject *parent) : QObject(parent)
{
    if (data_acquire_ai == nullptr) {
        data_acquire_ai = new DataAcquireAI;
        qDebug() << "(In PxS)new acq_ai succeed";
    }

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &ProximitySwitch::rev_data_from_ni9205);
}

/***************************************************************
  *  @brief     设置标签
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::set_label(QString label)
{
    _label = label;
}

/***************************************************************
  *  @brief     返回标签
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString ProximitySwitch::get_label() const
{
    return _label;
}

/***************************************************************
  *  @brief     设置感应距离
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::set_sensing_dis(QString sensing_dis)
{
    _sensing_distance = sensing_dis;
}

/***************************************************************
  *  @brief     返回感应距离
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString ProximitySwitch::get_sensing_dis() const
{
    return _sensing_distance;
}

/***************************************************************
  *  @brief     设置使用时间
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::set_using_time(QString using_time)
{
    _using_time = using_time;
}

/***************************************************************
  *  @brief     返回使用时间
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString ProximitySwitch::get_using_time() const
{
    return _using_time;
}

/***************************************************************
  *  @brief     设置感应材料
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::set_sensing_matirial(QString sensing_matirial)
{
    _sensing_matirial = sensing_matirial;
}

/***************************************************************
  *  @brief     返回感应材料
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString ProximitySwitch::get_sensing_matirial() const
{
    return _sensing_matirial;
}

/***************************************************************
  *  @brief     设置通道：这里需要将用户选择的路 转换成 通道
  *  @param     无
  *  @note      功能函数：在这里做映射
  *             将用户在ui选择的 路1~5 映射为 实际物理通道
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::set_channel(QString channel)
{
    if (channel == "1") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_1) + "," + chToStr(CH_PS_SUPC_1);
    } else if (channel == "2") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_2) + "," + chToStr(CH_PS_SUPC_2);
    } else if (channel == "3") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_3) + "," + chToStr(CH_PS_SUPC_3);
    } else if (channel == "4") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_4) + "," + chToStr(CH_PS_SUPC_4);
    } else if (channel == "5") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_5) + "," + chToStr(CH_PS_SUPC_5);
    }
}

/***************************************************************
  *  @brief     返回通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString ProximitySwitch::get_channel() const
{
    return _channel;
}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
double choose_min_max(int channel)
{
    double U = 0.0;
    switch (channel) {
    case 0:     // 0 供电电压
    case 1:     // 1 角位移传感器信号电压、信号电流、角度值
        U = 10;
        break;
    case 2:     // 2 角位移传感器供电电流
        U = 0.2;
        break;
    case 3:     // 3~8 角位移编码器信号电压、信号电流
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        U = 10;
        break;
    case 9:     // 9 角位移编码器供电电流
        U = 0.2;
        break;
    case 10:    // 10~14 测电阻
    case 11:
    case 12:
    case 13:
    case 14:
        U = 5.0;
        break;
    case 15:    // 15~24 接近开关
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
        U = 10;
        break;
    case 25:    // 25 滑动变阻器距离
        U = 5.0;
        break;
    case 26:    // 26~30 压力传感器信号电压、信号电流、压力值
    case 27:
    case 28:
    case 29:
    case 30:

    case 31:
        U = 10;
        break;
    }

    return U;
}

void ProximitySwitch::start_acquire()
{
    //--------------------------NI 9205--------------------------------------
    qDebug() << "(In PxS)id:" << QThread::currentThreadId();

    // 供电电压：(0) + 接近开关通道：(15,16),...,(23,24) + 滑动变阻器：(25) + 电池电量：(31)
    channel_final = chToStr(CH_SUPV) + "," +
                            get_channel() + "," +
                            chToStr(CH_VR_DIS) + "," +
                            chToStr(CH_BAT);

    data_acquire_ai->get_channel(channel_final);
#if 0
    // ----以下是尝试代码----
    connect(this, &ProximitySwitch::startDataAcq, data_acquire_ai, &DataAcquireAI::init);

    DAQmxCreateTask("Data Acquire Task", &tk);
    QVector<int> idx = Assist::extractNumbers(channel_final);
    idx = QVector<int>{17};
    qDebug() << "(In PxS)idx: " << idx;

    for (int i = 0; i < idx.size(); i++) {
        double U = choose_min_max(idx[i]);
        qDebug() << "(In PxS)U: " << U;

        QString physicalChannel = "cDAQ2Mod3/ai" + QString::number(idx[i]);
        DAQmxCreateAIVoltageChan(tk, physicalChannel.toUtf8(), "",
                                 DAQmx_Val_RSE, -U, U, DAQmx_Val_Volts, NULL);
        DAQmxCfgSampClkTiming(tk, NULL, 1000.0, DAQmx_Val_Rising, DAQmx_Val_ContSamps, 1000);

    }
    DAQmxStartTask(tk);

    emit startDataAcq(tk);
    // ---- END ----
#endif
    QThreadPool::globalInstance()->start(data_acquire_ai);

}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止9205的数据采集
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理（涉及多路转换）
  *  @param     无
  *  @note      根据通道判断转化成：
  *             供电电压：(0) + 接近开关通道：(15,16),...,(23,24) + 滑动变阻器：(25) + 电池电量：(31)
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::rev_data_from_ni9205(QVector<double> data)
{
    // 判断channel_final的size和data的size是否一致，根据channel_final的顺序取数据
//    qDebug() << "(In PxS)通道size: " << Assist::extractNumbers(channel_final).size() << " 接收数据size: " << data.size();
    if (data.size() != Assist::extractNumbers(channel_final).size()) {
        qDebug() << "(In PxS)通道和接收数据的size不一致！";
        return;
    }

    // 供电电压
    double sup_vol = data[0];

    // 信号电压、信号电流、是否触发
    double sig_vol = data[1];
    double sig_cur = sig_vol / 5100;
    double if_pulse = (sig_vol > THREAD_VOL_TO_PUL) ? 1 : 0;

//    qDebug() << "(In PxS)if_pulse" << if_pulse;

    // 供电电流
    double sup_cur = data[2] / 5000;

    // 滑动变阻器计算距离
    double cur = data[3] / 1;
    double distance_var = map_from_cur_to_varDis(cur);

    // 电池电量
    double bat = data[4] * 3;

    // 组合成一个vector发出去，data中数据顺序如下：
    // 供电电压、信号电压、信号电流、供电电流、是否触发、滑动变阻器距离、电池电量
    QVector<double> data_after_process = {sup_vol,
                                         sig_vol, sig_cur,
                                         sup_cur,
                                         if_pulse, distance_var,
                                         bat};

#if 0
    double sup_vol = data[0];
    QVector<double> data_after_process = {sup_vol};
#endif
    emit send_vol_cur_pul_dis_to_ui(data_after_process);
}

/***************************************************************
  *  @brief     在win中connect，窗口关闭，删除对象
  *  @param     无
  *  @note      槽函数——负责删除对象
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::slot_acq_delete()
{
    qDebug() << "(In PxS)get delete sig";

    if (data_acquire_ai != nullptr) {
        delete data_acquire_ai;
        qDebug() << "(In PxS)delete acq_ai succeed!!!!!!!!!!";
    }
}

/***************************************************************
  *  @brief
  *  @param     无
  *  @note      功能函数：实现电流到滑动变阻器距离的映射(暂时还没补充映射)
  *  @Sample usage:
 **************************************************************/
double ProximitySwitch::map_from_cur_to_varDis(double current)
{
    return current;
}
