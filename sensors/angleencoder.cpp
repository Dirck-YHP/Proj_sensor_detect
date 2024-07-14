#include "angleencoder.h"

AngleEncoder::AngleEncoder(QObject *parent) : QObject(parent)
{

}

/***************************************************************
  *  @brief     设置标签
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::set_label(QString label)
{
    _label = label;
}

/***************************************************************
  *  @brief     返回标签
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString AngleEncoder::get_label() const
{
    return _label;
}

/***************************************************************
  *  @brief     设置每圈脉冲数
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::set_pul_per_cir(QString pul_per_rev)
{
    _pulse_per_rev = pul_per_rev;
}

/***************************************************************
  *  @brief     返回每圈脉冲数
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString AngleEncoder::get_pul_per_cir() const
{
    return _pulse_per_rev;
}

/***************************************************************
  *  @brief     设置通道（未拆分的字符串）
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::set_channel()
{
    _channel = chToStr(CH_AE_SIGV_SIGC_A) + "," +
               chToStr(CH_AE_SIGV_SIGC_B) + "," +
               chToStr(CH_AE_SUPC);
}

/***************************************************************
  *  @brief     返回通道（未拆分的字符串）
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString AngleEncoder::get_channel() const
{
    return _channel;
}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::start_acquire()
{
    //--------------------------NI 9205--------------------------------------
    data_acquire_ai = new DataAcquireAI;

    // 供电电压(0) + 角位移编码器 A+(3) B+(5) supc(9) + 电池电量(31)
    QString channel_final = chToStr(CH_SUPV) + "," +
                            get_channel() + "," +
                            chToStr(CH_BAT);
    qDebug() << "fi: " << channel_final;

    data_acquire_ai->get_channel(channel_final);
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &AngleEncoder::rev_data_from_ni9205);

    //--------------------------NI 9403--------------------------------------
    data_acquire_di = new DataAcquireDI;
    QThreadPool::globalInstance()->start(data_acquire_di);

    connect(data_acquire_di, &DataAcquireDI::send_data,
            this, &AngleEncoder::rev_data_from_ni9403);

    //--------------------------NI 9401--------------------------------------
    data_acquire_ci = new DataAcquireCI;
    data_acquire_ci->get_pulses_per_rev(get_pul_per_cir().toUInt());

    QThreadPool::globalInstance()->start(data_acquire_ci);

    connect(data_acquire_ci, &DataAcquireCI::send_data,
            this, &AngleEncoder::rev_data_from_ni9401);
}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止三张卡的数据采集
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::stop_acquire()
{
    data_acquire_ai->stop_acquire();
    data_acquire_di->stop_acquire();
    data_acquire_ci->stop_acquire();
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理
  *  @param     无
  *  @note      根据通道判断转化成：
  *             供电电压(0) + 角位移编码器 A+(3) B+(5) supc(9) + 电池电量(31)
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::rev_data_from_ni9205(QVector<double> data)
{
    //


    emit send_ni9205_to_ui(data);
}

/***************************************************************
  *  @brief     接收ni9403的角度数据
  *  @param     无
  *  @note      后续似乎不需要做处理，直接转发就行【画脉冲图】
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::rev_data_from_ni9403(QVector<QVector<double> > data_final)
{
    emit send_ni9403_to_ui(data_final);
}

/***************************************************************
  *  @brief     接收ni9401的角度数据
  *  @param     无
  *  @note      后续似乎不需要做处理，直接转发就行【画角度图，角度1】
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::rev_data_from_ni9401(QVector<double> data)
{
    emit send_ni9401_to_ui(data);
}




