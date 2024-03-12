cmake_minimum_required(VERSION 3.5.0)
project(smhelper VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (Curses REQUIRED)

file(GLOB SOURCES "supermarket.cpp" "product/*.cpp" "fixture/*.cpp" "menu/*.cpp")
add_executable(smhelper ${SOURCES})

target_link_libraries(smhelper ${CURSES_LIBRARIES})
target_include_directories(smhelper PRIVATE ${CURSES_INCLUDE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
