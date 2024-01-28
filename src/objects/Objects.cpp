#include "Objects.h"

ISystem &Objects::getSystem()
{
    static System system;
    return system;
}

Clock &Objects::getClock()
{
    static Clock clock(getSystem());
    return clock;
}

ITemperatureSensor &Objects::getTemperatureSensor()
{
    static TemperatureSensor temperatureSensor(20.0f);
    return temperatureSensor;
}

IHeater &Objects::getHeater()
{
    static Heater heater;
    return heater;
}

HeaterInteractor &Objects::getHeaterInteractor()
{
    static HeaterInteractor heaterInteractor(getTemperatureSensor(), getHeater(), getClock(), 20.0f);
    return heaterInteractor;
}