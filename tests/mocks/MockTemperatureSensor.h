#pragma once

#include <gmock/gmock.h>

#include "temperature_sensor/ITemperatureSensor.h"

class MockTemperatureSensor : public ITemperatureSensor
{
public:
    MOCK_METHOD(float, getTemperature, (), (const, override));
    MOCK_METHOD(void, setTemperature, (float temperature), (override));
};
