# SPDX-License-Identifier: Unlicense

target_sources( ${PROJECT_NAME}
    PRIVATE
        gdexample.h
        gdexample.cpp
        register_types.cpp
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
