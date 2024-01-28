#pragma once

#include "IHeater.h"

class Heater : public IHeater
{
public:
    Heater();

    void setHeating(bool isHeating) override;
    bool isHeating() const override;

private:
    bool _isHeating;
};