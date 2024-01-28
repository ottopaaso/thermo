#pragma once

#include "system/System.h"
#include "clock/Clock.h"
#include "temperature_sensor/TemperatureSensor.h"
#include "heater/Heater.h"
#include "heater/HeaterInteractor.h"

class Objects
{
public:
    static ISystem &getSystem();
    static Clock &getClock();
    static ITemperatureSensor &getTemperatureSensor();
    static IHeater &getHeater();
    static HeaterInteractor &getHeaterInteractor();
};