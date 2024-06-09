#ifndef ASSIST_H
#define ASSIST_H

#include <QVector>
#include <QStringList>
#include <QRegExp>

class Assist
{
public:
    Assist();

public:
    static QVector<int> extractNumbers(const QString &input);
    static QPair<QVector<double>, QVector<double>> make_di_plot_better(const QVector<double> &x,
                                                                const QVector<double> &y, int index);
};

#endif // ASSIST_H
