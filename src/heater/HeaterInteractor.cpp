#include "HeaterInteractor.h"

HeaterInteractor::HeaterInteractor(ITemperatureSensor &tempSensor, Heater &heater, Clock &clock, float targetTemperature) : _tempSensor(tempSensor),
                                                                                                                            _heater(heater),
                                                                                                                            _clock(clock),
                                                                                                                            _targetTemperature(targetTemperature)
{
    _lastChangeTime = _clock.now();
}

void HeaterInteractor::tick()
{
    const auto now = _clock.now();
    if (now - _lastChangeTime < HEATER_STATE_CHANGE_INTERVAL)
    {
        return;
    }

    float currentTemperature = _tempSensor.getTemperature();
    _heater.setHeating(currentTemperature < _targetTemperature);
    _lastChangeTime = now;
}
