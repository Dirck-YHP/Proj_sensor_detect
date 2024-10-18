#include "assist.h"

Assist::Assist()
{

}

/***************************************************************
  *  @brief     提取字符串为数组
  *  @param     无
  *  @note      功能函数
  *     如：“1,2,3” ——> [1, 2, 3]
  *  @Sample usage:
 **************************************************************/
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

/***************************************************************
  *  @brief     处理数据，优化数字波形显示
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
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

/***************************************************************
  *  @brief     板子上电
  *  @param     无
  *  @note      功能函数
  *  @Sample usage:
 **************************************************************/
void Assist::board_init(bool if_open)
{
    TaskHandle taskHandleSwitch;
    DAQmxCreateTask("ASSIST", &taskHandleSwitch);

    // 这里的数字io要根据用户的选择来变动
    DAQmxCreateDOChan(taskHandleSwitch, "cDAQ1Mod2/port0/line31", "", DAQmx_Val_ChanPerLine);

    uInt8 writeArray[1];
    int32 writeSuccessNum;

    // 给0 还是 给1 是通电
    if (if_open) {
        writeArray[0] = 1;
        qDebug() << "(online)1";
    }
    else {

        qDebug() << "(offline)0";
        writeArray[0] = 0;
    }

    int error = DAQmxWriteDigitalLines(taskHandleSwitch, 1, true, -1,
                                       DAQmx_Val_GroupByChannel, writeArray, &writeSuccessNum, NULL);
    qDebug() << QString::number(error);
    DAQmxClearTask(taskHandleSwitch);
    qDebug() << "(In board)board init succeed!";
}
