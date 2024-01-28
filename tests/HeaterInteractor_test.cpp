#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "mocks/MockSystem.h"
#include "mocks/MockTemperatureSensor.h"
#include "mocks/MockHeater.h"
#include "mocks/MockClock.h"

#include "heater/HeaterInteractor.h"

class HeaterInteractorTest : public ::testing::Test
{
protected:
    MockTemperatureSensor mockTemperatureSensor;
    MockHeater mockHeater;
    MockClock mockClock;
    std::unique_ptr<HeaterInteractor> sut;

    void SetUp() override
    {
        sut = std::make_unique<HeaterInteractor>(mockTemperatureSensor, mockHeater, mockClock, 20.0f);
    }
};

TEST_F(HeaterInteractorTest, DoesNotHeatInitially)
{
    // Setup expectations and actions on the mock objects
    // Call methods on `sut` and assert outcomes
    sut->tick();
    // Replace 'heater.isHeating()' with the appropriate method to check the heating status
    // EXPECT_EQ(heater.isHeating(), false);
}

TEST_F(HeaterInteractorTest, RemainsOffWithLowTemperatureShortInterval)
{
    // Setup mockTemperatureSensor to return 16.0f
    // Setup mockClock to advance time by 1000 milliseconds
    // Setup expectations on mockHeater
    // Call sut->tick() and assert expectations
}

TEST_F(HeaterInteractorTest, RemainsOffWithLowTemperatureLongInterval)
{
    // Setup mockTemperatureSensor to return 16.0f
    // Setup mockClock to advance time by 10000 milliseconds
    // Setup expectations on mockHeater
    // Call sut->tick() and assert expectations
}

TEST_F(HeaterInteractorTest, TurnsOnAfterLongInterval)
{
    // Setup mockTemperatureSensor to return 16.0f
    // Setup mockClock to advance time by 20000 milliseconds
    // Setup expectations on mockHeater
    // Call sut->tick() and assert expectations
}

TEST_F(HeaterInteractorTest, RemainsOnWithHighTemperatureShortInterval)
{
    // Setup mockTemperatureSensor to return 23.0f
    // Setup mockClock to advance time by 1000 milliseconds
    // Setup expectations on mockHeater
    // Call sut->tick() and assert expectations
}

// Additional tests...
