cmake_minimum_required(VERSION 3.14)

project(neotlc LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# GSL
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSL REQUIRED gsl)

# Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# ATLC source files
file(GLOB ATLC_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/atlc/atlc-4.6.1/src/*.c
)

add_library(atlc STATIC ${ATLC_SOURCES})

target_include_directories(atlc PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/atlc/include
        ${CMAKE_CURRENT_SOURCE_DIR}/atlc/atlc-4.6.1
        ${CMAKE_CURRENT_SOURCE_DIR}/atlc/atlc-4.6.1/src
        ${GSL_INCLUDE_DIRS}
)

target_link_libraries(atlc PUBLIC ${GSL_LINK_LIBRARIES})

# Executable
add_executable(neotlc
        src/main.cpp
        src/atlc_wrapper.h
)

target_include_directories(neotlc PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(neotlc
        atlc
        Qt5::Core
        Qt5::Widgets
)
