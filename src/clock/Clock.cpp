#include "Clock.h"

Clock::Clock(ISystem &system) : _system(system) {}

SystemTimePoint Clock::now() const
{
    return _system.getCurrentDateTime();
}
