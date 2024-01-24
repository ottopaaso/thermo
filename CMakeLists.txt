cmake_minimum_required(VERSION 3.10)

project(Thermo)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find GTest package
find_package(GTest REQUIRED)

# Add the main executable
add_executable(Thermo main.cpp)

# Add the source files to the executable
target_sources(Thermo PRIVATE
    src/myfile.cpp
)

# Add the include directories for the main executable
target_include_directories(Thermo PRIVATE
    src
)

# Add the test executable
add_executable(ThermoTests
    tests/myfile_test.cpp
    src/myfile.cpp
)

# Add the source files for tests
target_sources(ThermoTests PRIVATE
    tests/myfile_test.cpp
)

# Link Google Test to the test executable
target_link_libraries(ThermoTests PRIVATE
    GTest::GTest
    GTest::Main
)

# Add include directories for tests
target_include_directories(ThermoTests PRIVATE
    ${CMAKE_SOURCE_DIR}/src  # Assuming 'include' is at the top level of your project
)

# Add the include directories for both main executable and tests
target_include_directories(Thermo PRIVATE
    src
)

# Add a test target
enable_testing()
add_test(NAME ThermoTests COMMAND ThermoTests)
