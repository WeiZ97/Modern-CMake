add_executable(XyzExecutable "")
target_sources(XyzExecutable PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_link_libraries(XyzExecutable XyzLibrary)
target_include_directories(XyzExecutable PRIVATE $<TARGET_PROPERTY:XyzLibrary,INTERFACE_INCLUDE_DIRECTORIES>)

set_target_properties(XyzExecutable
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