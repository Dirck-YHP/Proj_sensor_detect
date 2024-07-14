#include "proximityswitch.h"

ProximitySwitch::ProximitySwitch(QObject *parent) : QObject(parent)
{

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
void ProximitySwitch::start_acquire()
{
    //--------------------------NI 9205--------------------------------------
    data_acquire_ai = new DataAcquireAI;

    // 供电电压：(0) + 接近开关通道：(15,16),...,(23,24) + 滑动变阻器：(25) + 电池电量：(31)
    QString channel_final = chToStr(CH_SUPV) + "," +
                            get_channel() + "," +
                            chToStr(CH_VR_DIS) + "," +
                            chToStr(CH_BAT);

    data_acquire_ai->get_channel(channel_final);
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &ProximitySwitch::rev_data_from_ni9205);
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
    // 目前还没做转化，直接发送原始数据
    data[0]++;
    emit send_ni9205_to_ui(true);
}
