#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>

class Motor : public QObject
{
    Q_OBJECT
public:
    explicit Motor(QObject *parent = nullptr);

signals:

};

#endif // MOTOR_H
