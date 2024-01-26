#include "HeaterInteractor.h"

HeaterInteractor::HeaterInteractor(TemperatureSensor* tempSensor, Heater* heater, float targetTemperature) :
    _targetTemperature(targetTemperature),
    _heater(heater),
    _tempSensor(tempSensor) {
        _lastChangeTime = Clock::getInstance().now();
}


void HeaterInteractor::tick() {
    const auto now = Clock::getInstance().now();
    if (now - _lastChangeTime < HEATER_STATE_CHANGE_INTERVAL) {
        return;
    }

    float currentTemperature = _tempSensor->getTemperature();
    _heater->setHeating(currentTemperature < _targetTemperature);
    _lastChangeTime = now;
}
