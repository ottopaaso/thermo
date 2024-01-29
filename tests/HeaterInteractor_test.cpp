#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "mocks/MockTemperatureSensor.h"
#include "mocks/MockClock.h"

#include "heater/Heater.h"
#include "heater/HeaterInteractor.h"

#define DEFAULT_TEMPERATURE 20.0f

class HeatingSystemBehaviorTest : public ::testing::Test
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

TEST_F(HeatingSystemBehaviorTest, LimitHeaterChanges_DuringInterval)
{
    // Initial conditions: Temperature is at the default and heater should be off
    SystemTimePoint time1 = std::chrono::system_clock::now();
    EXPECT_CALL(mockClock, now())
        .WillOnce(testing::Return(time1));
    ON_CALL(mockTemperatureSensor, getTemperature())
        .WillByDefault(testing::Return(DEFAULT_TEMPERATURE));
    sut->tick();
    EXPECT_FALSE(heater->isHeating());

    // Lower the temperature and advance time, heater should remain off
    SystemTimePoint time2 = time1 + std::chrono::milliseconds(1000);
    EXPECT_CALL(mockClock, now())
        .WillOnce(testing::Return(time2));
    ON_CALL(mockTemperatureSensor, getTemperature())
        .WillByDefault(testing::Return(16.0f));
    sut->tick();
    EXPECT_FALSE(heater->isHeating());

    // Advance time further, heater should still be off
    SystemTimePoint time3 = time2 + std::chrono::milliseconds(10000);
    EXPECT_CALL(mockClock, now())
        .WillOnce(testing::Return(time3));
    sut->tick();
    EXPECT_FALSE(heater->isHeating());

    // Advance time enough for the heater to turn on
    SystemTimePoint time4 = time3 + std::chrono::milliseconds(20000);
    EXPECT_CALL(mockClock, now())
        .WillOnce(testing::Return(time4));
    sut->tick();
    EXPECT_TRUE(heater->isHeating());

    // Increase the temperature, heater should remain on
    SystemTimePoint time5 = time4 + std::chrono::milliseconds(1000);
    EXPECT_CALL(mockClock, now())
        .WillOnce(testing::Return(time5));
    ON_CALL(mockTemperatureSensor, getTemperature())
        .WillByDefault(testing::Return(23.0f));
    sut->tick();
    EXPECT_TRUE(heater->isHeating());

    // Advance time, heater should turn off
    SystemTimePoint time6 = time5 + std::chrono::milliseconds(10000);
    EXPECT_CALL(mockClock, now())
        .WillOnce(testing::Return(time6));
    sut->tick();
    EXPECT_TRUE(heater->isHeating());

    // Advance time enough for the heater to turn off
    SystemTimePoint time7 = time6 + std::chrono::milliseconds(20000);
    EXPECT_CALL(mockClock, now())
        .WillOnce(testing::Return(time7));
    sut->tick();
    EXPECT_FALSE(heater->isHeating());
}
