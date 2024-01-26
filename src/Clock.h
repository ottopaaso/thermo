#pragma once

#include <chrono>

using SystemTimePoint = std::chrono::time_point<std::chrono::system_clock>;

class Clock {
    public:
        Clock();
        virtual ~Clock();

        static Clock& getInstance();

        static void setInstance(Clock& instance);

        SystemTimePoint now() const;

    protected:
        virtual SystemTimePoint getNow() const;
    
    private:
        static Clock* _instance;
};

