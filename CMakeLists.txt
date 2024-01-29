cmake_minimum_required(VERSION 3.14)

project(Thermo)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Google Test
include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
FetchContent_MakeAvailable(googletest)

# Add a library with your source files
add_library(Thermolib
    src/instances/Instances.cpp
    src/system/System.cpp
    src/clock/Clock.cpp
    src/heater/Heater.cpp
    src/heater/HeaterInteractor.cpp
    src/temperature_sensor/TemperatureSensor.cpp
)

# Add the main executable
add_executable(Thermo main.cpp)
target_link_libraries(Thermo PRIVATE Thermolib)

# Enable testing
enable_testing()

# Add the test executable
add_executable(ThermoTests
    tests/HeaterInteractor_test.cpp
)
target_link_libraries(ThermoTests PRIVATE Thermolib gtest_main gmock)

# Include directories
target_include_directories(Thermolib PUBLIC src)
target_include_directories(Thermo PRIVATE src)
target_include_directories(ThermoTests PRIVATE src)

# Include the GoogleTest module
include(GoogleTest)

# Discover and register tests
gtest_discover_tests(ThermoTests)
