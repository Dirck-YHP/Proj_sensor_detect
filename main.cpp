#include "widget.h"
#include "mainwindow.h"

#include <QApplication>

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
    mW.setStyleSheet("background-color:rgb(67,67,67);");
    mW.show();

    return a.exec();
}
