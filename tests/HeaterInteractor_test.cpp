#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "mocks/MockTemperatureSensor.h"
#include "mocks/MockClock.h"

#include "heater/Heater.h"
#include "heater/HeaterInteractor.h"

#define DEFAULT_TEMPERATURE 20.0f

class HeaterInteractorTest : public ::testing::Test
{
protected:
    MockTemperatureSensor mockTemperatureSensor;
    MockClock mockClock;

    std::unique_ptr<Heater> heater;
    std::unique_ptr<HeaterInteractor> sut;

    void SetUp() override
    {
        heater = std::make_unique<Heater>();
        sut = std::make_unique<HeaterInteractor>(mockTemperatureSensor, *heater, mockClock, DEFAULT_TEMPERATURE);
    }
};

TEST_F(HeaterInteractorTest, DoesNotHeatInitially)
{
    ON_CALL(mockTemperatureSensor, getTemperature())
        .WillByDefault(testing::Return(DEFAULT_TEMPERATURE));

    sut->tick();

    EXPECT_FALSE(heater->isHeating());
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
