cmake_minimum_required(VERSION 3.22)
project(editor)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)

include(${wxWidgets_USE_FILE})

add_executable(editor src/main.cpp)

target_link_libraries(editor PRIVATE ${wxWidgets_LIBRARIES})
target_include_directories(editor PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(editor PRIVATE tomlplusplus::tomlplusplus)
