#ifndef HYDRAULICSTATION_H
#define HYDRAULICSTATION_H

#include <QObject>
#include <QDebug>

#include "tele_com/serialportcom.h"

class HydraulicStation : public QObject
{
    Q_OBJECT
public:
    explicit HydraulicStation(QObject *parent = nullptr);
    ~HydraulicStation();

private:
    SerialPortCom *serial_port_com = nullptr;
    QString _hydrau_value;

    const QString SEND_MSG = "001100";      // 发送给液压站的命令，固定的

public:
    void build_connection();
    void break_connection();
    void send_msg();
    QString get_msg();

private slots:
    void get_serial_data();

signals:

};

#endif // HYDRAULICSTATION_H
