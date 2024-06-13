#ifndef ANGLEENCODER_H
#define ANGLEENCODER_H

#include <QObject>

class AngleEncoder : public QObject
{
    Q_OBJECT
public:
    explicit AngleEncoder(QObject *parent = nullptr);

signals:

};

#endif // ANGLEENCODER_H
