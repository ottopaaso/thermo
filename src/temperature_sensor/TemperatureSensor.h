#pragma once

#include "ITemperatureSensor.h"

class TemperatureSensor : public ITemperatureSensor
{
public:
    TemperatureSensor(float temperature);

    float getTemperature() const override;
    void setTemperature(float temperature) override;

private:
    float _temperature;
};
