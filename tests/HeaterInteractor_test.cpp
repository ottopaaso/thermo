#include "gtest/gtest.h"

class TemperatureSensor {
    public:
        TemperatureSensor() : _temperature(19.0f) {
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


class HeaterInteractor {
    public:
        TemperatureSensor* _tempSensor;
        Heater* _heater;
        float _targetTemperature;

        HeaterInteractor(TemperatureSensor* tempSensor, Heater* heater, float targetTemperature) :
            _targetTemperature(targetTemperature),
            _heater(heater),
            _tempSensor(tempSensor) {
                
            }

        void tick() {
            float currentTemperature = _tempSensor->getTemperature();
            _heater->setHeating(currentTemperature < _targetTemperature);
        }
};


TEST(HeaterControllerTest, TurnHeaterOn)
{
    auto tempSensor = TemperatureSensor();
    auto heater = Heater();
    auto sut = HeaterInteractor(&tempSensor, &heater, 20.0f);
    EXPECT_EQ(heater.isHeating(), false);

    sut.tick();
    EXPECT_EQ(heater.isHeating(), true);
    tempSensor.setTemperature(25.0f);

    sut.tick();
    EXPECT_EQ(heater.isHeating(), false);
}

