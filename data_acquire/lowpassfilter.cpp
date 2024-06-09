#include "lowpassfilter.h"


double LowpassFilter::update(double input)
{
    // 将新的输入添加到环形缓冲区中
    buffer_.insert(buffer_.begin(), input);
    buffer_.pop_back();

    // 计算输出值
    double output = 0.0;
    for (int i = 0; i < taps_.size(); ++i) {
          output += taps_[i] * buffer_[i];
    }
    return output;
}

QVector<double> createLowpassFilter(int M, double fc, double fs)
{
    QVector<double> h(M + 1);
    for (int n = 0; n <= M; ++n) {
        if (n == M / 2) {
            h[n] = 2.0 * fc / fs;
        }
        else {
            h[n] = sin(2.0 * M_PI * fc * (n - M / 2.0) / fs) / (M_PI * (n - M / 2.0));
        }
        h[n] *= 0.54 - 0.46 * cos(2.0 * M_PI * n / M);
    }
    return h;
}
