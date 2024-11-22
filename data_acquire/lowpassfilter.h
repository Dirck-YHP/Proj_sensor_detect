#ifndef LOWPASSFILTER_H
#define LOWPASSFILTER_H

#include <QVector>
#include <cmath>

class LowpassFilter
{
public:
    LowpassFilter(){}
    LowpassFilter(const QVector<double>& taps) : taps_(taps), buffer_(taps.size(), 0.0) {}

    // 更新滤波器输出
    double update(double input);

private:
    QVector<double> taps_;  // 滤波器系数
    QVector<double> buffer_;  // 环形缓冲区
};

// 创建一个函数，用于生成低通滤波器的系数
QVector<double> createLowpassFilter(int M, double fc, double fs);

class ExponentialMovingAverage {
public:
    ExponentialMovingAverage(double alpha = 0.2) : alpha_(alpha), initialized_(false) {}

    double update(double input) {
        if (!initialized_) {
            initialized_ = true;
            lastValue_ = input;
            return input;
        }

        double newValue = alpha_ * input + (1 - alpha_) * lastValue_;
        lastValue_ = newValue;
        return newValue;
    }

private:
    double alpha_;  // 平滑因子 (0,1]，值越大响应越快
    double lastValue_;
    bool initialized_;
};


class DeadBandFilter {
public:
    // 修改构造函数，允许同时设置threshold和alpha
    DeadBandFilter(double threshold = 0.1, double alpha = 0.15)
        : threshold_(threshold), ema_(alpha), lastOutput_(0), initialized_(false) {}

    double update(double input) {
        if (!initialized_) {
            initialized_ = true;
            lastOutput_ = input;
            return input;
        }

        // EMA滤波
        double filtered = ema_.update(input);

        // 死区判断
        if (std::abs(filtered - lastOutput_) > threshold_) {
            lastOutput_ = filtered;
        }

        return lastOutput_;
    }

private:
    double threshold_;
    ExponentialMovingAverage ema_;
    double lastOutput_;
    bool initialized_;
};
#endif // LOWPASSFILTER_H
