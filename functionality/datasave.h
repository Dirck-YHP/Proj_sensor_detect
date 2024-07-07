#ifndef DATASAVE_H
#define DATASAVE_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

struct SensorData {
    qint64 timestamp = 0;       // 使用 qint64 存储时间戳
    double value;           // 假设传感器数据是 double 类型
};

class DataSave : public QObject
{
    Q_OBJECT
public:
    explicit DataSave(QObject *parent = nullptr);

private:
    QFile file;

public:
    void collectData(QVector<SensorData> *dataBuffer, double dataValue);

signals:

};

#endif // DATASAVE_H
