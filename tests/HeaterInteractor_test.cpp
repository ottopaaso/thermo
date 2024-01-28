#include "gtest/gtest.h"

#include "clock/Clock.h"
#include "heater/Heater.h"
#include "heater/HeaterInteractor.h"
#include "temperature_sensor/TemperatureSensor.h"

TEST(HeaterInteractorTest, LimitHeaterChanges_DuringInterval)
{
    /*
    auto tempSensor = TemperatureSensor(20.0f);
    auto heater = Heater();
    auto sut = HeaterInteractor(&tempSensor, &heater, 19.0f);
    sut.tick();
    EXPECT_EQ(heater.isHeating(), false);

    tempSensor.setTemperature(16.0f);
    clockMock.advance(std::chrono::milliseconds(1000));
    sut.tick();
    EXPECT_EQ(heater.isHeating(), false);

    clockMock.advance(std::chrono::milliseconds(10000));
    sut.tick();
    EXPECT_EQ(heater.isHeating(), false);

    clockMock.advance(std::chrono::milliseconds(20000));
    sut.tick();
    EXPECT_EQ(heater.isHeating(), true);

    tempSensor.setTemperature(23.0f);
    clockMock.advance(std::chrono::milliseconds(1000));
    sut.tick();
    EXPECT_EQ(heater.isHeating(), true);

    clockMock.advance(std::chrono::milliseconds(10000));
    sut.tick();
    EXPECT_EQ(heater.isHeating(), true);

    clockMock.advance(std::chrono::milliseconds(20000));
    sut.tick();
    EXPECT_EQ(heater.isHeating(), false);
    */
}
