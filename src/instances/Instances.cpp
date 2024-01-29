#include "Instances.h"

ISystem &Instances::getSystem()
{
    static System system;
    return system;
}

IClock &Instances::getClock()
{
    static Clock clock(getSystem());
    return clock;
}

ITemperatureSensor &Instances::getTemperatureSensor()
{
    static TemperatureSensor temperatureSensor(20.0f);
    return temperatureSensor;
}

IHeater &Instances::getHeater()
{
    static Heater heater;
    return heater;
}

HeaterInteractor &Instances::getHeaterInteractor()
{
    static HeaterInteractor heaterInteractor(getTemperatureSensor(), getHeater(), getClock(), 20.0f);
    return heaterInteractor;
}