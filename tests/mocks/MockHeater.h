#pragma once

#include <gmock/gmock.h>

#include "heater/IHeater.h"

class MockHeater : public IHeater
{
public:
    MOCK_METHOD(void, setHeating, (bool isHeating), (override));
    MOCK_METHOD(bool, isHeating, (), (const, override));
};
