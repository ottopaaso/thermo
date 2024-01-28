#pragma once

class IHeater
{
public:
    virtual ~IHeater() {}

    virtual void setHeating(bool isHeating) = 0;
    virtual bool isHeating() const = 0;
};
