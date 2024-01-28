#include "System.h"

SystemTimePoint System::getCurrentDateTime() const
{
    return std::chrono::system_clock::now();
}