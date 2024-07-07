#include "datasave.h"

DataSave::DataSave(QObject *parent) : QObject(parent)
{

}

void DataSave::collectData(QVector<SensorData> *dataBuffer, double dataValue)
{
    SensorData sensorData;
    sensorData.timestamp++;
    sensorData.value = dataValue;

    dataBuffer->push_back(sensorData);
}

