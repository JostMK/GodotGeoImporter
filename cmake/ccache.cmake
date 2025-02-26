# See: https://crascit.com/2016/04/09/using-ccache-with-cmake/
find_program(CCACHE_PROGRAM ccache)

if (CCACHE_PROGRAM)
    # get version information
    execute_process(
            COMMAND "${CCACHE_PROGRAM}" --version
            OUTPUT_VARIABLE CCACHE_VERSION
    )
    string(REGEX MATCH "[^\r\n]*" CCACHE_VERSION ${CCACHE_VERSION})

    message(STATUS "Using ccache: ${CCACHE_PROGRAM} (${CCACHE_VERSION})")

    # See: https://github.com/ccache/ccache/wiki/MS-Visual-Studio
    if (MSVC)
        message(STATUS "Configuring ccache for MSVC")
        file(COPY_FILE
                ${CCACHE_PROGRAM} ${CMAKE_BINARY_DIR}/cl.exe
                ONLY_IF_DIFFERENT)

        # By default Visual Studio generators will use /Zi which is not compatible
        # with ccache, so tell Visual Studio to use /Z7 instead.
        message(STATUS "Setting MSVC debug information format to 'Embedded'")
        set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")

        set(CMAKE_VS_GLOBALS
                "CLToolExe=cl.exe"
                "CLToolPath=${CMAKE_BINARY_DIR}"
                "UseMultiToolTask=true"
                "DebugInformationFormat=OldStyle"
        )
    endif ()

    # Turn on ccache for all targets
    set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
    set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")

    unset(CCACHE_VERSION)
endif ()
