#include "assist.h"

Assist::Assist()
{

}


QVector<int> Assist::extractNumbers(const QString &input) {
    QVector<int> numbers;
    QRegExp pattern("，|,"); // 正则表达式，匹配中文逗号或英文逗号
    QStringList stringNumbers = input.split(pattern);

    foreach (const QString &strNum, stringNumbers) {
        // 将分割得到的字符串尝试转换为整数
        bool ok;
        int number = strNum.toInt(&ok);
        if (ok) { // 如果转换成功
            numbers.append(number);
        } else {
            // 转换失败的处理，例如打印错误信息或抛出异常
        }
    }
    return numbers;
}


// 辅助函数，用来对数据处理，使得数字波形显示的很好
QPair<QVector<double>, QVector<double>> Assist::make_di_plot_better(const QVector<double> &x,
                                                                  const QVector<double> &y, int index)
{
    QVector<double> x_ret, y_ret;
    for(int i = 0; i < x.size(); i++){
        x_ret.append(x[i]);
        y_ret.append(y[i] + 2 * index);
        x_ret.append((x[i] + 1));
        y_ret.append(y[i] + 2 * index);
    }
    return {x_ret, y_ret};
}
