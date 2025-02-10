include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/UndistortConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(EXPORT UndistortTargets
    FILE UndistortTargets.cmake
    NAMESPACE Undistort::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Undistort
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/UndistortConfigVersion.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/UndistortConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Undistort
)
