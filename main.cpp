#include "widget.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<QVector<double>>("QVector<double>");      // 注册自定义类型
    qRegisterMetaType<int32>("int32");
    qRegisterMetaType<QVector<QVector<double>>>("QVector<QVector<double>>");

//    Widget w;
//    w.show();
    mainWindow mW;
    mW.show();

    return a.exec();
}
