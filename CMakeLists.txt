cmake_minimum_required(VERSION 3.9)
project(Assignment_1)

include_directories(include)
set(SOURCE_FILES
        include/Date.hpp
        src/Date.cpp
        src/Test.cpp)
add_executable(Assignment_1 ${SOURCE_FILES})

list(APPEND FLAGS_WARN
        -Wall
        -Wextra
        -Wfloat-equal
        -Wundef
        -Wcast-align
        -Wwrite-strings
        -Wlogical-op
        -Wmissing-declarations
        -Wredundant-decls
        -Wshadow
        -Woverloaded-virtual)
list(APPEND FLAGS_STATIC
        -static-libgcc
        -static-libstdc++
        -static)
list(APPEND FLAGS_DEBUG
        ${FLAGS_WARN}
        -ggdb
        -g3)
list(APPEND FLAGS_RELEASE
        ${FLAGS_WARN}
        -o2
        -DNDEBUG)

set(CMAKE_CXX_STANDARD 17)
target_compile_options(Assignment_1 PUBLIC "$<$<CONFIG:DEBUG>:${FLAGS_DEBUG}>")
target_compile_options(Assignment_1 PUBLIC "$<$<CONFIG:RELEASE>:${FLAGS_RELEASE}>")
target_link_libraries(Assignment_1 "$<$<CONFIG:RELEASE>:${FLAGS_STATIC}>")
set_target_properties(Assignment_1 PROPERTIES OUTPUT_NAME "Assignment 1")
