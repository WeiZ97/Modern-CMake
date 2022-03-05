cmake_minimum_required(VERSION 3.20)
project(xyz)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/xyz-config.cmake
    INSTALL_DESTINATION share/xyz
)

add_subdirectory(XyzExecutable)
add_subdirectory(XyzLibrary)
add_subdirectory(C_XyzExecutable)


#

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xyz-config.cmake DESTINATION share/xyz)

install(
    EXPORT ${PROJECT_NAME}-target
    NAMESPACE ${PROJECT_NAME}::
    FILE ${PROJECT_NAME}-targets.cmake
    DESTINATION share/${PROJECT_NAME}
)
