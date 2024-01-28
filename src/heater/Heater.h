#pragma once

class Heater
{
public:
    Heater();

    void setHeating(bool isHeating);
    bool isHeating();

private:
    bool _isHeating;
};
