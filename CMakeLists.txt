cmake_minimum_required(VERSION 3.20)

project(storages_shapes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(storages_shapes INTERFACE)
target_include_directories(storages_shapes INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

enable_testing()
add_subdirectory(test)
