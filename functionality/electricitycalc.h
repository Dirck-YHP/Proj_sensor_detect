#ifndef ELECTRICITYCALC_H
#define ELECTRICITYCALC_H

#include <QObject>

class ElectricityCalc : public QObject
{
    Q_OBJECT
public:
    explicit ElectricityCalc(QObject *parent = nullptr);

signals:

};

#endif // ELECTRICITYCALC_H
