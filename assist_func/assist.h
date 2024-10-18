#ifndef ASSIST_H
#define ASSIST_H

#include <QVector>
#include <QStringList>
#include <QRegExp>
#include <QDebug>

#include "data_acquire/dataacquireai.h"

class Assist
{
public:
    Assist();

public:
    static QVector<int> extractNumbers(const QString &input);
    static QPair<QVector<double>, QVector<double>> make_di_plot_better(const QVector<double> &x,
                                                                const QVector<double> &y, int index);
    static void board_init(bool if_open);
};

#endif // ASSIST_H
