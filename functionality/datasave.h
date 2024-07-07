#ifndef DATASAVE_H
#define DATASAVE_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

class DataSave : public QObject
{
    Q_OBJECT
public:
    explicit DataSave(QObject *parent = nullptr);

private:
    QFile file;

public:
    void dataSave(QString dir, QString acqType, QString acqChannel);
signals:

};

#endif // DATASAVE_H
