#pragma once

class TemperatureSensor
{
public:
    TemperatureSensor(float temperature) : _temperature(temperature)
    {
    }

    float getTemperature()
    {
        return _temperature;
    }

    void setTemperature(float temperature)
    {
        _temperature = temperature;
    }

private:
    float _temperature;
};