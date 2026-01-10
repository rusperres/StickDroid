# Minimum CMake version required
cmake_minimum_required(VERSION 3.16)

# Include ESP-IDF build system
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Minimal build: only main component + dependencies
idf_build_set_property(MINIMAL_BUILD ON)

# Project name
project(stick_droid)


