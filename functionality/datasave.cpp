#include "datasave.h"

DataSave::DataSave(QObject *parent) : QObject(parent)
{

}

void DataSave::dataSave(QString dir, QString acqType, QString acqChannel)
{
//    QString currentDateTime = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
//    QString file_name = dir + "/" + currentDateTime + "_data.csv";
//    file.setFileName(file_name);
//    if (!file.open(QIODevice::Append | QIODevice::Text))
//        return;

//    QTextStream out(&file);
//    out.setCodec("UTF-8");
//    out << QString("采集类型：") << acqType.toUtf8()
//        << QString("，采集通道：") << acqChannel.toUtf8() << "\n";
}
