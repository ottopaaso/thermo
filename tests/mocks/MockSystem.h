#pragma once

#include <gmock/gmock.h>

#include "system/ISystem.h"

class MockSystem : public ISystem
{
public:
    MOCK_METHOD(SystemTimePoint, getCurrentDateTime, (), (const, override));
};
