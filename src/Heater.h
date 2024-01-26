#pragma once

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
