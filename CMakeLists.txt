SET(PROJ_NAME virtual-machine)
cmake_minimum_required(VERSION 3.25)
project(${PROJ_NAME})

include(${CMAKE_SOURCE_DIR}/cmake/config.cmake)

# set(CMAKE_C_STANDARD                14)
set(CMAKE_CXX_STANDARD              17)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_C_EXTENSIONS              OFF)
set(CMAKE_CXX_EXTENSIONS            OFF)

if (USE_GTEST)
    enable_testing()
    find_package(GTest CONFIG REQUIRED)
endif()

find_package(cxxopts CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/inc)

if (NOT USE_GTEST)
    add_executable(${PROJ_NAME} src/main.cpp
                                src/system/memory.cpp
                                src/args/parser.cpp
                                src/isa/fundamental/delegate.cpp)
else()
    add_library(${PROJ_NAME} src/args/parser.cpp)
    include(${CMAKE_SOURCE_DIR}/cmake/tests/args.cmake)
endif()

target_link_libraries(${PROJ_NAME} PRIVATE spdlog::spdlog)
target_link_libraries(${PROJ_NAME} PRIVATE cxxopts::cxxopts)
