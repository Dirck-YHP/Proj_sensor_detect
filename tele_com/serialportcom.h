#ifndef SERIALPORTCOM_H
#define SERIALPORTCOM_H

#include <QObject>

class SerialPortCom : public QObject
{
    Q_OBJECT
public:
    SerialPortCom(QObject *parent = nullptr);
};

#endif // SERIALPORTCOM_H
