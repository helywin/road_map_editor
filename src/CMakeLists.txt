project(roadmapeditorplugin)
file(GLOB SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
        )
add_library(${PROJECT_NAME} MODULE
        ${SRCS})

generate_qrc(RoadMapEditor ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Xml
        ${QGIS_CORE_LIBRARY}
        ${QGIS_GUI_LIBRARY})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${QGIS_INCLUDE_DIR})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${QGIS_PLUGIN_DIR}
        LIBRARY DESTINATION ${QGIS_PLUGIN_DIR}
        )

add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE_OUTPUT_PATH}/libroadmapeditorplugin.so /home/jiang/qgis_plugin
        )