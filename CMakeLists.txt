cmake_minimum_required(VERSION 3.9)
project(Assignment_3)

include_directories(include
                    src)
set(SOURCE_FILES
    include/Airline.hpp
    include/Queue.hpp
    include/QueueIterators.hpp
    src/Airline.cpp
    # src/Queue.cpp
    # src/QueueIterators.cpp
    src/Test.cpp)
add_executable(Assignment_3 ${SOURCE_FILES})

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
     # -Wshadow
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
target_compile_options(Assignment_3 PUBLIC "$<$<CONFIG:DEBUG>:${FLAGS_DEBUG}>")
target_compile_options(Assignment_3 PUBLIC "$<$<CONFIG:RELEASE>:${FLAGS_RELEASE}>")
target_link_libraries(Assignment_3 "$<$<CONFIG:RELEASE>:${FLAGS_STATIC}>")
set_target_properties(Assignment_3 PROPERTIES OUTPUT_NAME "Assignment 3")
