#pragma once

class ITemperatureSensor
{
public:
    virtual ~ITemperatureSensor() {}

    virtual float getTemperature() const = 0;
    virtual void setTemperature(float temperature) = 0;
};
