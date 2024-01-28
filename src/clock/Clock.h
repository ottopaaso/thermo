#pragma once

#include "IClock.h"

#include "system/ISystem.h"

class Clock : public IClock
{
public:
    explicit Clock(ISystem &system);

    SystemTimePoint now() const override;

private:
    ISystem &_system;
};
