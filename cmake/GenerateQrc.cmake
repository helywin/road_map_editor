include_guard()
function(generate_qrc QRC_NAME QRC_TARGET)
    set(RES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)
    if (NOT EXISTS ${RES_DIR})
        file(MAKE_DIRECTORY ${RES_DIR})
    endif ()
    if (NOT EXISTS ${RES_DIR}/css)
        file(MAKE_DIRECTORY ${RES_DIR}/css)
    endif ()
    if (NOT EXISTS ${RES_DIR}/icon)
        file(MAKE_DIRECTORY ${RES_DIR}/icon)
    endif ()
    file(GLOB FILES_AND_DIRS_LIST LIST_DIRECTORIES true ${RES_DIR}/*)
    set(QRC_FILE ${RES_DIR}/${QRC_NAME}.qrc)
    # if exists file module_name.qrc.lock, this function will not modify or update qrc file any more
    if (NOT EXISTS ${QRC_FILE}.lock)
        file(REMOVE ${QRC_FILE})
        file(WRITE ${QRC_FILE} "<RCC version=\"1.0\">\n")
        foreach (ITEM ${FILES_AND_DIRS_LIST})
            if (IS_DIRECTORY ${ITEM})
                get_filename_component(DIR ${ITEM} NAME)
                # only support prefix '/'
                file(GLOB FILE_LIST ${ITEM}/*)
                if (FILE_LIST STREQUAL "")
                    continue()
                endif ()
                file(APPEND ${QRC_FILE} "    <qresource prefix=\"/\">\n")
                foreach (FILE_FULL ${FILE_LIST})
                    get_filename_component(FILE ${FILE_FULL} NAME)
                    file(APPEND ${QRC_FILE} "        <file>${DIR}/${FILE}</file>\n")
                endforeach ()
                file(APPEND ${QRC_FILE} "    </qresource>\n")
            endif ()
        endforeach ()
        file(APPEND ${QRC_FILE} "</RCC>\n")
    endif ()
    target_sources(${QRC_TARGET} PRIVATE ${QRC_FILE})
endfunction()