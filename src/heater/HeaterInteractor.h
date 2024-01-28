#pragma once

#include "clock/Clock.h"
#include "heater/Heater.h"
#include "temperature_sensor/ITemperatureSensor.h"

#define HEATER_STATE_CHANGE_INTERVAL std::chrono::seconds(30)

class HeaterInteractor
{
public:
    HeaterInteractor(ITemperatureSensor &tempSensor, IHeater &heater, IClock &clock, float targetTemperature);
    void tick();

private:
    ITemperatureSensor &_tempSensor;
    IHeater &_heater;
    IClock &_clock;
    float _targetTemperature;
    SystemTimePoint _lastChangeTime;
};
