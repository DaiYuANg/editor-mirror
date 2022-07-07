cmake_minimum_required(VERSION 3.22)
project(editor)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

include(${wxWidgets_USE_FILE})

#add_custom_command(
#        OUTPUT ${PROJECT_BINARY_DIR}/conf/
#        PRE_BUILD
#        COMMAND copy -r conf
#)
configure_file(conf/global.toml ${PROJECT_BINARY_DIR}/conf/global.toml @ONLY)
#file(COPY conf/global.toml DESTINATION ${PROJECT_BINARY_DIR}/conf/)
add_executable(main src/main.cpp src/editor.cpp src/editor.h src/frame.cpp src/frame.h)

target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})
target_include_directories(main PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(main PRIVATE tomlplusplus::tomlplusplus)
target_link_libraries(main PRIVATE unofficial::sqlite3::sqlite3)
