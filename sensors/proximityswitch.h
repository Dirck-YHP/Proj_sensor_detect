#ifndef PROXIMITYSWITCH_H
#define PROXIMITYSWITCH_H

#include <QObject>

class ProximitySwitch : public QObject
{
    Q_OBJECT
public:
    explicit ProximitySwitch(QObject *parent = nullptr);
};

#endif // PROXIMITYSWITCH_H
