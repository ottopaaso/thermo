#pragma once

#include "clock/Clock.h"
#include "heater/Heater.h"
#include "temperature_sensor/ITemperatureSensor.h"

#define HEATER_STATE_CHANGE_INTERVAL std::chrono::seconds(30)

class HeaterInteractor
{
public:
    HeaterInteractor(ITemperatureSensor &tempSensor, Heater &heater, Clock &clock, float targetTemperature);
    void tick();

private:
    ITemperatureSensor &_tempSensor;
    Heater &_heater;
    Clock &_clock;
    float _targetTemperature;
    SystemTimePoint _lastChangeTime;
};
