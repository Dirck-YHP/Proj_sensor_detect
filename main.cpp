#include "widget.h"
#include "mainwindow.h"

#include <QApplication>

#include "data_acquire/dataacquireai.h"
#include <QThreadPool>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<QVector<double>>("QVector<double>");      // 注册自定义类型
    qRegisterMetaType<int32>("int32");
    qRegisterMetaType<QVector<QVector<double>>>("QVector<QVector<double>>");
    qRegisterMetaType<QSerialPort::SerialPortError>("QSerialPort::SerialPortError");

//    Widget w;
//    w.show();

    mainWindow mW;
    mW.show();

//    DataAcquireAI* dataAcquire;
//    dataAcquire = new DataAcquireAI;

//    dataAcquire->get_channel("0,17,18,25,31");
//    QThreadPool::globalInstance()->start(dataAcquire);

    return a.exec();
}
