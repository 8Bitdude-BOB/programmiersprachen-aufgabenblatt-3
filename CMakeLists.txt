# CMake is the build system we use to compile our C++ projects.
# It reads this file (CMakeLists.txt) and generates platform-specific
# build files (Makefiles on Linux/macOS, Visual Studio projects on Windows).
#
# To learn more about CMake, see: https://cmake.org/cmake/help/latest/guide/tutorial/

# ---------------------------------------------------------------------------
# Every CMakeLists.txt starts with these two commands:
#   cmake_minimum_required - the oldest CMake version that can build this project
#   project                - gives the project a name (shown in IDEs like Visual Studio)
# ---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.20)
project(Aufgabenblatt3)

# ---------------------------------------------------------------------------
# C++ standard configuration
#   CMAKE_CXX_STANDARD          - which C++ version to use (we use C++20)
#   CMAKE_CXX_STANDARD_REQUIRED - fail if the compiler does not support C++20
# ---------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------------------------
# Doctest setup
#   We use the doctest library for unit testing (https://github.com/doctest/doctest).
#   It is a single header file located in external/doctest/doctest.h.
#   include_directories() tells the compiler where to find it so that
#   #include <doctest.h> works in our source files.
# ---------------------------------------------------------------------------
set(DOCTEST_DIRECTORY doctest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/${DOCTEST_DIRECTORY})

# ---------------------------------------------------------------------------
# Testing
#   enable_testing() activates CMake's test runner (ctest).
#   Individual tests are registered with add_test() in source/CMakeLists.txt.
#   After building, you can run all tests with:  ctest --build-config Release
# ---------------------------------------------------------------------------
enable_testing()

# ---------------------------------------------------------------------------
# Subdirectories
#   add_subdirectory() tells CMake to also process the CMakeLists.txt
#   in the given folder. Our source code lives in the source/ directory.
# ---------------------------------------------------------------------------
add_subdirectory(source)
