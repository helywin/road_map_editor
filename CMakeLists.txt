cmake_minimum_required(VERSION 3.19)
project(map_editor)

find_package(Qt5 COMPONENTS REQUIRED Core Widgets Gui Xml)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)