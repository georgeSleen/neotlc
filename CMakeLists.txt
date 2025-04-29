cmake_minimum_required(VERSION 3.5)

project(neotlc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Enable automatic MOC, UIC, RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# List your source files here
set(SOURCES
        src/main.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Qt5 libraries
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
