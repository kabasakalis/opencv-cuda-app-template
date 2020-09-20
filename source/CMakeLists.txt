# Configuration for all sub-projects

# Generate version-header
configure_file(version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME}/${META_PROJECT_NAME}-version.h @ONLY)


# Sub-projects

# Project Libraries
set(IDE_FOLDER "")
add_subdirectory(baselib)
add_subdirectory(fiblib)


# Main
set(IDE_FOLDER "Main")
add_subdirectory(main)

# Tests
if (OPTION_BUILD_TESTS AND NOT MINGW)
    set(IDE_FOLDER "Tests")
    add_subdirectory(tests)
endif ()


# Deployment

# Deploy generated headers
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME} DESTINATION include COMPONENT dev)
