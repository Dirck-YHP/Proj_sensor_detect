#ifndef DATAEXPORT_H
#define DATAEXPORT_H

#include <QObject>

class DataExport : public QObject
{
    Q_OBJECT
public:
    explicit DataExport(QObject *parent = nullptr);

signals:

};

#endif // DATAEXPORT_H
