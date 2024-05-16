SET(PROJ_NAME VirtualComputer)
project(${PROJ_NAME})

set(CMAKE_C_STANDARD                99)
set(CMAKE_CXX_STANDARD              14)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_C_EXTENSIONS              OFF)
set(CMAKE_CXX_EXTENSIONS            OFF)

find_package(cxxopts CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(${PROJ_NAME} main.cpp)

target_link_libraries(${PROJ_NAME} PRIVATE spdlog::spdlog)
