#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(float temperature) : _temperature(temperature)
{
}

float TemperatureSensor::getTemperature() const
{
    return _temperature;
}

void TemperatureSensor::setTemperature(float temperature)
{
    _temperature = temperature;
}