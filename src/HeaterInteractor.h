#pragma once

#include "Clock.h"
#include "Heater.hpp"
#include "TemperatureSensor.hpp"

#define HEATER_STATE_CHANGE_INTERVAL std::chrono::seconds(30)

class HeaterInteractor {
    public:
        HeaterInteractor(TemperatureSensor* tempSensor, Heater* heater, float targetTemperature);

        void tick();

    private:
        TemperatureSensor* _tempSensor;
        Heater* _heater;
        float _targetTemperature;
        SystemTimePoint _lastChangeTime;
};
