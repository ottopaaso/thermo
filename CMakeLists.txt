cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find GTest package
find_package(GTest REQUIRED)

# Add the main executable
add_executable(MyProject main.cpp)

# Add the source files to the executable
target_sources(MyProject PRIVATE
    src/myfile.cpp
)

# Add the include directories for the main executable
target_include_directories(MyProject PRIVATE
    include
    src
)

# Add the test executable
add_executable(MyProjectTests tests/myfile_test.cpp)

# Add the source files for tests
target_sources(MyProjectTests PRIVATE
    tests/myfile_test.cpp
)

# Link Google Test to the test executable
target_link_libraries(MyProjectTests PRIVATE
    GTest::GTest
    GTest::Main
)

# Add include directories for tests
target_include_directories(MyProjectTests PRIVATE
    ${CMAKE_SOURCE_DIR}/include  # Assuming 'include' is at the top level of your project
)

# Add the include directories for both main executable and tests
target_include_directories(MyProject PRIVATE
    include
    src
)

# Add a test target
enable_testing()
add_test(NAME MyProjectTests COMMAND MyProjectTests)
