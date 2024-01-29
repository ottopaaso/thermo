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
    // Define different time points
    SystemTimePoint time1 = std::chrono::system_clock::now();
    SystemTimePoint time2 = time1 + std::chrono::milliseconds(1000);
    SystemTimePoint time3 = time2 + std::chrono::milliseconds(10000);
    SystemTimePoint time4 = time3 + std::chrono::milliseconds(20000);
    SystemTimePoint time5 = time4 + std::chrono::milliseconds(1000);
    SystemTimePoint time6 = time5 + std::chrono::milliseconds(10000);
    SystemTimePoint time7 = time6 + std::chrono::milliseconds(20000);

    // Set up the return values for successive calls
    EXPECT_CALL(mockClock, now())
        .WillOnce(testing::Return(time1))
        .WillOnce(testing::Return(time2))
        .WillOnce(testing::Return(time3))
        .WillOnce(testing::Return(time4))
        .WillOnce(testing::Return(time5))
        .WillOnce(testing::Return(time6))
        .WillOnce(testing::Return(time7))
        .WillRepeatedly(testing::Return(time7)); // Default return after all specified times

    // Initial conditions: Temperature is at the default and heater should be off
    ON_CALL(mockTemperatureSensor, getTemperature())
        .WillByDefault(testing::Return(DEFAULT_TEMPERATURE));
    sut->tick();
    EXPECT_FALSE(heater->isHeating());

    // Lower the temperature and advance time, heater should remain off
    ON_CALL(mockTemperatureSensor, getTemperature())
        .WillByDefault(testing::Return(16.0f));
    sut->tick();
    EXPECT_FALSE(heater->isHeating());

    // Advance time further, heater should still be off
    sut->tick();
    EXPECT_FALSE(heater->isHeating());

    // Advance time enough for the heater to turn on
    sut->tick();
    EXPECT_TRUE(heater->isHeating());

    // Increase the temperature, heater should remain on
    ON_CALL(mockTemperatureSensor, getTemperature())
        .WillByDefault(testing::Return(23.0f));
    sut->tick();
    EXPECT_TRUE(heater->isHeating());

    // Advance time, heater should turn off
    sut->tick();
    EXPECT_TRUE(heater->isHeating());

    // Advance time enough for the heater to turn off
    sut->tick();
    EXPECT_FALSE(heater->isHeating());
}
