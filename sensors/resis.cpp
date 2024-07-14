#include "resis.h"

Resis::Resis(QObject *parent) : QObject(parent)
{

}

/***************************************************************
  *  @brief     设置通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void Resis::set_channel(QString channel)
{
    qDebug() << "way choosed: " << channel;
    QVector<int> selected_channel_arr  = Assist::extractNumbers(channel);

    _channel = "";
    bool isFirst = true; // 用于判断是否是第一个元素，避免在字符串开头添加逗号

    for (int i = 1; i <= 5; ++i) {
        if (selected_channel_arr.contains(i)) {
            if (!isFirst) {
                _channel.append(",");
            }

            if (i == 1) _channel.append(chToStr(CH_R_1));
            if (i == 2) _channel.append(chToStr(CH_R_2));
            if (i == 3) _channel.append(chToStr(CH_R_3));
            if (i == 4) _channel.append(chToStr(CH_R_4));
            if (i == 5) _channel.append(chToStr(CH_R_5));

            isFirst = false;
        }
    }
}

/***************************************************************
  *  @brief     返回通道
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
QString Resis::get_channel() const
{
    return _channel;
}

/***************************************************************
  *  @brief     开始进行数据采集
  *  @param     无
  *  @note      构造数据采集类的对象，接收数据采集类传过来的数据并进行处理
  *  @Sample usage:
 **************************************************************/
void Resis::start_acquire()
{
    data_acquire_ai = new DataAcquireAI;

    // 电阻：(10),...,(14) + 电池电量(31)
    QString channel_final = get_channel() + "," +
                            chToStr(CH_BAT);
    qDebug() << "fi: " << channel_final;

    data_acquire_ai->get_channel(channel_final);
    QThreadPool::globalInstance()->start(data_acquire_ai);

    connect(data_acquire_ai, &DataAcquireAI::send_data,
            this, &Resis::rev_data_from_ni9205);
}

/***************************************************************
  *  @brief     停止进行数据采集
  *  @param     无
  *  @note      停止9205的数据采集
  *  @Sample usage:
 **************************************************************/
void Resis::stop_acquire()
{
    data_acquire_ai->stop_acquire();
}

/***************************************************************
  *  @brief     接收ni9205的数据并处理（涉及多路转换）
  *  @param     无
  *  @note      根据选择的通道分别转化成:
  *             电压并计算出电阻然后送给上层
  *             电阻：(10),...,(14) + 电池电量(31)
  *  @Sample usage:
 **************************************************************/
void Resis::rev_data_from_ni9205(QVector<double> data)
{
    // 目前还没做转化，直接发送原始数据
    emit send_ni9205_to_ui(data);
}
