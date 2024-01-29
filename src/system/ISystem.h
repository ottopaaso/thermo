#pragma once

#include "SystemTimePoint.h"

class ISystem
{
public:
    virtual ~ISystem() {}

    virtual SystemTimePoint getCurrentDateTime() const = 0;
};
