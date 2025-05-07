cmake_minimum_required(VERSION 3.14)

project(neotlc VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# GSL
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSL REQUIRED gsl)

# Qt
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

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
qt_add_executable(neotlc
        src/main.cpp
        src/atlc_wrapper.h
        src/window.cpp
        src/window.h
)

target_include_directories(neotlc PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(neotlc PUBLIC
        atlc
        Qt6::Core
        Qt6::Widgets
)

set_target_properties(neotlc PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin
)
