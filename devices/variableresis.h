#ifndef VARIABLERESIS_H
#define VARIABLERESIS_H

/***************************************************************
  ************************************************************
  ****************由于也是使用9205，已结合至接近开关***************
  *************************已停用******************************
 **************************************************************/

#include <QObject>
#include <QThreadPool>
#include <QDebug>

#include "data_acquire/dataacquireai.h"

class VariableResis : public QObject
{
    Q_OBJECT
public:
    explicit VariableResis(QObject *parent = nullptr);

signals:
    // 这里需要做转化，原始电压信号——>电流——>距离，发送的是距离
    void send_ni9205_to_ui(QVector<double> data);

private slots:
    void rev_data_from_ni9205(QVector<double> data);

private:
    DataAcquireAI *data_acquire_ai;

public:
    void start_acquire();
    void stop_acquire();

};

#endif // VARIABLERESIS_H
