file(GLOB XyzSources "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp")

add_library(XyzLibrary SHARED  "")

target_sources(XyzLibrary
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/IXyz.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/SXyz.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/CXyz.cpp")

target_include_directories(XyzLibrary
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/headers)


set_target_properties(XyzLibrary
    PROPERTIES
        DEBUG_POSTFIX "_d"
        OUTPUT_NAME "Xyz"
        PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/headers/XyzLibrary.h
        
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

target_compile_definitions(XyzLibrary
    PUBLIC
    $<$<BOOL:${WIN32}>:
        # for windows
        PLATFORM_WINDOWS
    >
    INTERFACE
    $<$<BOOL:${msvc_cxx}>:
        # for msvc c++
        __cplusplus
    >
    INTERFACE
    $<$<COMPILE_LANG_AND_ID:CXX,GNU>:
        #for gcc c++
        __cplusplus
    >

    PRIVATE 
        XYZLIBRARY_EXPORTS
        __cplusplus
)

