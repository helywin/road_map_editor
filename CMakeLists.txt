cmake_minimum_required(VERSION 3.10)
project(road_map_editor)

set(QGIS_PLUGIN_DIR /usr/lib/qgis/plugins)
list(APPEND CMAKE_MODULE_PATH "/usr/share/qgis")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(GenerateQrc)

find_package(Qt5 COMPONENTS Core Gui Widgets Xml)
find_package(QGIS )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -fvisibility-inlines-hidden")

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message("=== Debug Mode ===")
    set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/debug)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/debug)
    add_definitions(-DDEBUG) # 加此宏是为了激活代码里面有的#ifdef DEBUG宏
elseif (CMAKE_BUILD_TYPE MATCHES Release) #CMAKE_BUILD_TYPE MATCHES Release
    message("=== Release Mode ===")
    set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/release)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release)
    # 屏蔽Qt警告和调试
    add_definitions(-DQT_NO_DEBUG)
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
    add_definitions(-DQT_DEPRECATED_WARNINGS)
endif ()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_subdirectory(src)