cmake_minimum_required(VERSION 3.22)
project(editor)

set(CMAKE_CXX_STANDARD 14)

#todo add custom command to generate tree.md
#tree -f -a -I '*svn|*node_module*|*tmp*|*.git|*.idea|*cmake-*|*vcpkg_*' > tree
#add_custom_command(TARGET ./tree.md
#        COMMAND tree -f -a -I '*svn|*node_module*|*tmp*|.git' > tree.md
#        )
add_custom_command(
        OUTPUT "./tree"
        COMMAND "tree -f -a -I '*svn|*node_module*|*tmp*|.git' > tree.md"
)

#dep
find_package(wxWidgets REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

include(${wxWidgets_USE_FILE})

#auto update config
configure_file(conf/global.toml ${PROJECT_BINARY_DIR}/conf/global.toml @ONLY)

add_executable(main src/main.cpp src/editor.cpp src/editor.h src/frame.cpp src/frame.h src/layout.cpp src/layout.h)

#target
target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})
target_include_directories(main PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(main PRIVATE tomlplusplus::tomlplusplus)
target_link_libraries(main PRIVATE unofficial::sqlite3::sqlite3)
