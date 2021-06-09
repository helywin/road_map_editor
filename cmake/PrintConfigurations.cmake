function(print_configurations)
    message("===configurations===")
#    message(STATUS "Windows API version is ${CMAKE_VS_WINDOWS_TARGET_PLATFORM_VERSION}")
    cmake_print_variables(
            CMAKE_VS_PLATFORM_TOOLSET
            CMAKE_SYSTEM_VERSION
            CMAKE_VS_WINDOWS_TARGET_PLATFORM_VERSION
    )
endfunction()