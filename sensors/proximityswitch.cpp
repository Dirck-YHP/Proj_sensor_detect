﻿#include "proximityswitch.h"

ProximitySwitch::ProximitySwitch(QObject *parent) : QObject(parent)
{
    if (data_acquire_ai == nullptr) {
        data_acquire_ai = new DataAcquireAI;
        // qDebug() << "(In PxS)new acq_ai succeed";
    }

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &ProximitySwitch::rev_data_from_ni9205);

    // 接收错误信号
    connect(data_acquire_ai, &DataAcquireAI::sig_err,
            this, &ProximitySwitch::slot_get_err);
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
    /*  这里由于硬件连线问题，映射顺序做个调换
        用户选择的 1   映射到   实际的 5
        用户选择的 2   映射到   实际的 4
        ...
        以此类推
    */
    if (channel == "1") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_5) + "," + chToStr(CH_PS_SUPC_5);
    } else if (channel == "2") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_4) + "," + chToStr(CH_PS_SUPC_4);
    } else if (channel == "3") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_3) + "," + chToStr(CH_PS_SUPC_3);
    } else if (channel == "4") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_2) + "," + chToStr(CH_PS_SUPC_2);
    } else if (channel == "5") {
        _channel = chToStr(CH_PS_SIGV_SIGC_PUL_1) + "," + chToStr(CH_PS_SUPC_1);
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
void ProximitySwitch::start_acquire()
{
    //--------------------------NI 9205--------------------------------------
    // 供电电压：(0) + 接近开关通道：(15,16),...,(23,24) + 滑动变阻器：(25) + 电池电量：(31)
    channel_final = chToStr(CH_SUPV) + "," +
                            get_channel() + "," +
                            chToStr(CH_VR_DIS) + "," +
                            chToStr(CH_BAT);

    // qDebug() << "fi: " << channel_final;
    data_acquire_ai->get_channel(channel_final);

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
        // qDebug() << "(In PxS)通道和接收数据的size不一致！";
        return;
    }

    // 供电电压
    double sup_vol = data[0] * 3;

    // 信号电压、信号电流、是否触发
    double sig_vol = data[1];
    sig_vol = sig_vol * 0.9954 - 0.0406;

    double sig_cur = sig_vol / 5100 * 1000;
    sig_cur = 0.9969 * sig_cur - 0.0022;

    double if_pulse = (sig_vol > THREAD_VOL_TO_PUL) ? 1 : 0;

//    qDebug() << "(In PxS)if_pulse" << if_pulse;

    // 供电电流
    double sup_cur = data[2] / 1 * 1000;
    sup_cur = 0.9795 * sup_cur + 0.9399;
    // qDebug() << "(Pxs)sup_cur: " << sup_cur;

    // 滑动变阻器计算距离
    double cur = data[3] / 1 * 1000;
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

    emit send_vol_cur_pul_dis_to_ui(data_after_process);
}

/***************************************************************
  *  @brief     接收底层错误信号
  *  @param     无
  *  @note
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::slot_get_err(bool err)
{
    // qDebug() << "(In PxS)get err sig!!";
    emit sig_err_to_ui(err);
}

/***************************************************************
  *  @brief     在win中connect，窗口关闭，删除对象
  *  @param     无
  *  @note      槽函数——负责删除对象
  *  @Sample usage:
 **************************************************************/
void ProximitySwitch::slot_acq_delete()
{
    // qDebug() << "(In PxS)get delete sig";

    if (data_acquire_ai != nullptr) {
        delete data_acquire_ai;
        // qDebug() << "(In PxS)delete acq_ai succeed!!!!!!!!!!";
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
    // 电流补偿
    // qDebug() << current;
    current = current * 0.9856 + 0.0955;
    qDebug() << current;

    double dis = (current - 4) * (_range.second - _range.first) / (20 -4) + _range.first;

    return dis;
}
