#include "gtest/gtest.h"

#include "Clock.h"
#include "Heater.hpp"
#include "HeaterInteractor.h"
#include "TemperatureSensor.hpp"

class ClockMock : public Clock {
    public:
        ClockMock(SystemTimePoint now) : _now(now) {
        }

        virtual ~ClockMock() {
        }

        void advance(std::chrono::milliseconds duration) {
            _now = _now + duration;
        }

    protected:
        SystemTimePoint getNow() const override {
            return _now;
        }
    
    private:
        SystemTimePoint _now;
};

ClockMock clockMock = ClockMock(std::chrono::system_clock::now());

TEST(HeaterInteractorTest, LimitHeaterChanges_DuringInterval)
{
    Clock::setInstance(clockMock);
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
}

