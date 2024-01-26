#include "gtest/gtest.h"

#include "Clock.h"

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

class TemperatureSensor {
    public:
        TemperatureSensor(float temperature) : _temperature(temperature) {
        }

        float getTemperature() {
            return _temperature;
        }

        void setTemperature(float temperature) {
            _temperature = temperature;
        }

    private:
        float _temperature;
};

class Heater {
    public:
        Heater() : _isHeating(false) {
        }

        void setHeating(bool isHeating) {
            _isHeating = isHeating;
        }

        bool isHeating() {
            return _isHeating;
        }

    private:
        bool _isHeating = false;
};

#define HEATER_STATE_CHANGE_INTERVAL std::chrono::seconds(30)

class HeaterInteractor {
    public:
        TemperatureSensor* _tempSensor;
        Heater* _heater;
        float _targetTemperature;
        SystemTimePoint _lastChangeTime;

        HeaterInteractor(TemperatureSensor* tempSensor, Heater* heater, float targetTemperature) :
            _targetTemperature(targetTemperature),
            _heater(heater),
            _tempSensor(tempSensor) {
                _lastChangeTime = Clock::getInstance().now();
        }

        void tick() {
            const auto now = Clock::getInstance().now();
            if (now - _lastChangeTime < HEATER_STATE_CHANGE_INTERVAL) {
                return;
            }

            float currentTemperature = _tempSensor->getTemperature();
            _heater->setHeating(currentTemperature < _targetTemperature);
            _lastChangeTime = now;
        }
};


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

