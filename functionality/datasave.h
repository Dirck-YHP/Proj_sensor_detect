#ifndef DATASAVE_H
#define DATASAVE_H

#include <QObject>

class DataSave : public QObject
{
    Q_OBJECT
public:
    explicit DataSave(QObject *parent = nullptr);

signals:

};

#endif // DATASAVE_H
