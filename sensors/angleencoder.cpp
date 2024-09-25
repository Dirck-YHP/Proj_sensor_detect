#include "angleencoder.h"

AngleEncoder::AngleEncoder(QObject *parent) : QObject(parent)
{
    if (data_acquire_ai == nullptr) {
        data_acquire_ai = new DataAcquireAI;
        qDebug() << "(In AE)new acq_ai succeed";
    }

    if (data_acquire_di == nullptr) {
        data_acquire_di = new DataAcquireDI;
        qDebug() << "(In AE)new acq_di succeed";
    }

    if (data_acquire_ci == nullptr) {
        data_acquire_ci = new DataAcquireCI;
        qDebug() << "(In AE)new acq_ci succeed";
    }

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &AngleEncoder::rev_data_from_ni9205);

    connect(data_acquire_di, &DataAcquireDI::send_data,
            this, &AngleEncoder::rev_data_from_ni9403);

    connect(data_acquire_ci, &DataAcquireCI::send_data,
            this, &AngleEncoder::rev_data_from_ni9401);
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
//    data_acquire_ai = new DataAcquireAI;

    // 供电电压(0) + 角位移编码器 A+(3) B+(5) supc(9) + 电池电量(31)
    channel_final = chToStr(CH_SUPV) + "," +
                            get_channel() + "," +
                            chToStr(CH_BAT);
    qDebug() << "(In AE)fi: " << channel_final;

    data_acquire_ai->get_channel(channel_final);
    QThreadPool::globalInstance()->start(data_acquire_ai);

//    connect(data_acquire_ai, &DataAcquireAI::send_data,
//            this, &AngleEncoder::rev_data_from_ni9205);

    //--------------------------NI 9403--------------------------------------
//    data_acquire_di = new DataAcquireDI;
    QThreadPool::globalInstance()->start(data_acquire_di);

//    connect(data_acquire_di, &DataAcquireDI::send_data,
//            this, &AngleEncoder::rev_data_from_ni9403);

    //--------------------------NI 9401--------------------------------------
//    data_acquire_ci = new DataAcquireCI;
    data_acquire_ci->get_pulses_per_rev(get_pul_per_cir().toUInt());

    QThreadPool::globalInstance()->start(data_acquire_ci);

//    connect(data_acquire_ci, &DataAcquireCI::send_data,
//            this, &AngleEncoder::rev_data_from_ni9401);
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
  *             供电电压(0) + 角位移编码器 A+(3) B+(5) + supc(9) + 电池电量(31)
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::rev_data_from_ni9205(QVector<double> data)
{
    // 判断channel_final的size和data的size是否一致，根据channel_final的顺序取数据
//    qDebug() << "(In AE)通道size: " << Assist::extractNumbers(channel_final).size()
//             << " 接收数据size: " << data.size();
    if (data.size() != Assist::extractNumbers(channel_final).size()) {
        qDebug() << "in AE:通道和接收数据的size不一致！";
        return;
    }

    // 供电电压：
    double sup_vol = data[0];

    // 信号电压A+
    // 信号电流A+ = 信号电压A+ / 5kΩ
    double sig_vol_A = data[1] / 5.1 * 25.1;
    double sig_cur_A = sig_vol_A / 5100;

    // 信号电压B+
    // 信号电流A+ = 信号电压A+ / 5kΩ
    double sig_vol_B = data[2] / 5.1 * 25.1;
    double sig_cur_B = sig_vol_B / 5100;

    // 供电电流 = 电压 / 电阻(1Ω)
    double sup_cur = data[3] / 1;

    // 电池电量
    double bat = data[4] * 3;

    // 组合成一个vector发出去，data中数据顺序如下：
    // 供电电压、A项信号电压、A项信号电流、B项信号电压、B项信号电流、供电电流、电池电量
    QVector<double> data_after_process = {sup_vol,
                                          sig_vol_A, sig_cur_A,
                                          sig_vol_B, sig_cur_B,
                                          sup_cur, bat};
    // 发送
    emit send_vol_cur_to_ui(data_after_process);
}

/***************************************************************
  *  @brief     接收ni9403的角度数据
  *  @param     无
  *  @note      后续似乎不需要做处理，直接转发就行【画脉冲图】
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::rev_data_from_ni9403(QVector<QVector<double> > data_final)
{
    emit send_pulse_to_ui(data_final);
}

/***************************************************************
  *  @brief     接收ni9401的角度数据
  *  @param     无
  *  @note      这里是0~360°，需要上传绝对角度【画角度图，角度1】
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::rev_data_from_ni9401(QVector<double> data, QVector<uInt32> data2, QVector<uInt32> data3)
{
//    qDebug() << "(In AE)angle: " << data;
    emit send_angle_to_ui(data, data2, data3);
}

/***************************************************************
  *  @brief     在win中connect，窗口关闭，删除对象
  *  @param     无
  *  @note      槽函数——负责删除对象
  *  @Sample usage:
 **************************************************************/
void AngleEncoder::slot_acq_delete()
{
    qDebug() << "(In AE)get delete sig";

    if (data_acquire_ai != nullptr) {
        delete data_acquire_ai;
        qDebug() << "(In AE)delete acq_ai succeed!!!!!!!!!!";
    }

    if (data_acquire_di != nullptr) {
        delete data_acquire_di;
        qDebug() << "(In AE)delete acq_di succeed!!!!!!!!!!";
    }

    if (data_acquire_ci != nullptr) {
        delete data_acquire_ci;
        qDebug() << "(In AE)delete acq_ci succeed!!!!!!!!!!";
    }
}
