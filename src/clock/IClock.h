#pragma once

#include "system/ISystem.h"

class IClock
{
public:
    virtual ~IClock() {}

    virtual SystemTimePoint now() const = 0;
};
