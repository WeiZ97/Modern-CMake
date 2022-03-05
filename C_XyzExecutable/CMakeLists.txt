add_executable(C_XyzExecutable "")
target_sources(C_XyzExecutable PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/main.c")

target_link_libraries(C_XyzExecutable XyzLibrary)
target_include_directories(C_XyzExecutable PRIVATE $<TARGET_PROPERTY:XyzLibrary,INTERFACE_INCLUDE_DIRECTORIES>)

