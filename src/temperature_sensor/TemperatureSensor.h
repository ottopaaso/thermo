#pragma once

class TemperatureSensor
{
public:
    TemperatureSensor(float temperature);

    float getTemperature() const;
    void setTemperature(float temperature);

private:
    float _temperature;
};
