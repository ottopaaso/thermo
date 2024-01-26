#include "Clock.h"

#include <iostream>


Clock::Clock() {
}

Clock::~Clock() {
    if (_instance) {
        _instance = nullptr;
        delete _instance;
    }
}

Clock* Clock::_instance = nullptr;

Clock& Clock::getInstance() {
    if (!_instance) {
        _instance = new Clock();
    }
    return *_instance;
}

void Clock::setInstance(Clock& instance) {
    if (_instance) {
        delete _instance;
    }

    _instance = &instance;
}

SystemTimePoint Clock::now() const {
    return _instance->getNow();
}

SystemTimePoint Clock::getNow() const {
    return std::chrono::system_clock::now();
}

