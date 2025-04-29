cmake_minimum_required(VERSION 3.5)

project(neotlc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add atlc source code
file(GLOB ATLC_SRC "${CMAKE_CURRENT_SOURCE_DIR}/atlc/atlc-4.6.1/src/*.c")
file(GLOB ATLC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/atlc/include/atlc.h")
file(GLOB ATLC_CONFIG "${CMAKE_CURRENT_SOURCE_DIR}/atlc/atlc-4.6.1/config.h")

add_library(atlc STATIC
        ${ATLC_SRC}
        ${ATLC_HEADER}
        ${ATLC_CONFIG}
)

# List source files here
set(SOURCES
        src/main.cpp
        src/atlc_wrapper.h
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
