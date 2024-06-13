#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include <QObject>

class PressureSensor : public QObject
{
    Q_OBJECT
public:
    explicit PressureSensor(QObject *parent = nullptr);

signals:

};

#endif // PRESSURESENSOR_H
