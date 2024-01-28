#pragma once

#include <gmock/gmock.h>

#include "clock/IClock.h"

class MockClock : public IClock
{
public:
    MOCK_METHOD(SystemTimePoint, now, (), (const, override));
};
