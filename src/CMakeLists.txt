

file(GLOB SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        )



add_executable(map_editor ${SRCS})
target_link_libraries(map_editor
        Qt5::Gui
        Qt5::Widgets
        Qt5::Core
        Qt5::Xml
        qgis_core
        qgis_gui)