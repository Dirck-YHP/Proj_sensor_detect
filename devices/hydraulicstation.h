#ifndef HYDRAULICSTATION_H
#define HYDRAULICSTATION_H

#include <QObject>

#include "tele_com/serialportcom.h"

class HydraulicStation : public QObject
{
    Q_OBJECT
public:
    explicit HydraulicStation(QObject *parent = nullptr);

private:
    SerialPortCom *serial_port_com;

signals:

};

#endif // HYDRAULICSTATION_H
