#ifndef HYDRAULICSTATION_H
#define HYDRAULICSTATION_H

#include <QObject>

class HydraulicStation : public QObject
{
    Q_OBJECT
public:
    explicit HydraulicStation(QObject *parent = nullptr);

signals:

};

#endif // HYDRAULICSTATION_H
