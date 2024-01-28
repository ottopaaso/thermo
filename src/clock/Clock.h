#pragma once

#include "system/ISystem.h"

class Clock
{
public:
    Clock(ISystem &system);
    SystemTimePoint now() const;

private:
    ISystem &_system;
};
