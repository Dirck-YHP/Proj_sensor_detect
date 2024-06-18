#ifndef VARIABLERESIS_H
#define VARIABLERESIS_H

#include <QObject>
#include <QThreadPool>
#include <QDebug>

#include "data_acquire/dataacquireai.h"

class VariableResis : public QObject
{
    Q_OBJECT
public:
    explicit VariableResis(QObject *parent = nullptr);

signals:
    void send_ni9205_to_ui(QVector<double> data);

private slots:
    void rev_data_from_ni9205(QVector<double> data);

private:
    DataAcquireAI *data_acquire_ai;

public:
    void start_acquire();
    void stop_acquire();

};

#endif // VARIABLERESIS_H
