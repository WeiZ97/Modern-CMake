add_executable(XyzExecutable "")
target_sources(XyzExecutable PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_link_libraries(XyzExecutable XyzLibrary)
target_include_directories(XyzExecutable PRIVATE $<TARGET_PROPERTY:XyzLibrary,INTERFACE_INCLUDE_DIRECTORIES>)

