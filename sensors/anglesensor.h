#ifndef ANGLESENSOR_H
#define ANGLESENSOR_H

#include <QObject>

class AngleSensor : public QObject
{
    Q_OBJECT
public:
    explicit AngleSensor(QObject *parent = nullptr);

private:
    QString _label;
    QPair<int, int> _range;

public:
    void set_label(QString label);
    QString get_label() const;

    void set_range(QString angle_4mA, QString angle_20mA);
    QPair<int, int> get_range() const;

signals:

};

#endif // ANGLESENSOR_H
