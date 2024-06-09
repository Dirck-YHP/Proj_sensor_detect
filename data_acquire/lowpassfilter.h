#ifndef LOWPASSFILTER_H
#define LOWPASSFILTER_H

#include <QVector>
#include <cmath>

class LowpassFilter
{
public:
    LowpassFilter(const QVector<double>& taps) : taps_(taps), buffer_(taps.size(), 0.0) {}

    // 更新滤波器输出
    double update(double input);

private:
    QVector<double> taps_;  // 滤波器系数
    QVector<double> buffer_;  // 环形缓冲区
};

// 创建一个函数，用于生成低通滤波器的系数
QVector<double> createLowpassFilter(int M, double fc, double fs);

#endif // LOWPASSFILTER_H
