#ifndef HYDRAULICSTATION_H
#define HYDRAULICSTATION_H

#include <QObject>
#include <QDebug>
#include <QThread>

#include "tele_com/serialportcom.h"

class HydraulicStation : public QObject
{
    Q_OBJECT
public:
    explicit HydraulicStation(QObject *parent = nullptr);
    ~HydraulicStation();

private:
    // 线程相关变量
    QThread *thread_serial_port;
    SerialPortCom *serial_port_com;
    // end

    QString _hydrau_value;

    const QString SEND_MSG = "001100";      // 发送给液压站的命令，固定的

    int _tik_num = 0;
    int _pre_tik_num = 0;

public:
    void build_connection();
    void break_connection();
    void send_msg();
    QString get_msg();

public slots:
    void get_serial_data(QString rev_data);

    void get_config_signal();
    void get_close_signal();

signals:
    void signal_set_config_serial_port();
    void signal_close_seriao_port();
};

#endif // HYDRAULICSTATION_H
