add_executable(C_XyzExecutable "")
target_sources(C_XyzExecutable PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/main.c")

target_link_libraries(C_XyzExecutable XyzLibrary)
target_include_directories(C_XyzExecutable PRIVATE $<TARGET_PROPERTY:XyzLibrary,INTERFACE_INCLUDE_DIRECTORIES>)

set_target_properties(C_XyzExecutable
    PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY            ${PROJECT_BINARY_DIR}/bin
            RUNTIME_OUTPUT_DIRECTORY_DEBUG      ${PROJECT_BINARY_DIR}/bin
            RUNTIME_OUTPUT_DIRECTORY_RELEASE    ${PROJECT_BINARY_DIR}/bin
            LIBRARY_OUTPUT_DIRECTORY            ${PROJECT_BINARY_DIR}/lib
            LIBRARY_OUTPUT_DIRECTORY_DEBUG      ${PROJECT_BINARY_DIR}/lib
            LIBRARY_OUTPUT_DIRECTORY_RELEASE    ${PROJECT_BINARY_DIR}/lib
            ARCHIVE_OUTPUT_DIRECTORY            ${PROJECT_BINARY_DIR}/lib
            ARCHIVE_OUTPUT_DIRECTORY_DEBUG      ${PROJECT_BINARY_DIR}/lib
            ARCHIVE_OUTPUT_DIRECTORY_RELEASE    ${PROJECT_BINARY_DIR}/lib
        
    )