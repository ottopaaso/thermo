#pragma once

#include <chrono>

// Use system specific definitions
using SystemTimePoint = std::chrono::time_point<std::chrono::system_clock>;

class ISystem
{
public:
    virtual ~ISystem() {}

    virtual SystemTimePoint getCurrentDateTime() const = 0;
};
