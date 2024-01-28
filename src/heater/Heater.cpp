#include "Heater.h"

Heater::Heater() : _isHeating(false)
{
}

void Heater::setHeating(bool isHeating)
{
    _isHeating = isHeating;
}

bool Heater::isHeating() const
{
    return _isHeating;
}