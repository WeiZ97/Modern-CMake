file(GLOB XyzSources "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp")

add_library(XyzLibrary SHARED  "")



target_sources(XyzLibrary
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/IXyz.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/SXyz.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/CXyz.cpp")

target_include_directories(XyzLibrary
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/headers>
        $<INSTALL_INTERFACE:headers>)


set_target_properties(XyzLibrary
    PROPERTIES
        DEBUG_POSTFIX "_d"
        OUTPUT_NAME "Xyz"
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

install(
    TARGETS XyzLibrary
    EXPORT ${PROJECT_NAME}-target
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/CXyz.h
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/SXyz.h   
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/IXyz.h
    DESTINATION 
        include        
)