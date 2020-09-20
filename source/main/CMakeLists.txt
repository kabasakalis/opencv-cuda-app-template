#
# External dependencies
#


#
# Executable name and options
#

# Target name
set(target opencvapp)
set(DATA_FOLDER "data")

# Exit here if required dependencies are not met
message(STATUS "Main ${target}")


#
# Sources
#

set(sources
        main.cpp
        )


# Build executable
add_executable(${target}
        MACOSX_BUNDLE
        ${sources}
        )

# Create namespaced alias
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})


#
# Project options
#

set_target_properties(${target}
        PROPERTIES
        ${DEFAULT_PROJECT_OPTIONS}
        FOLDER "${IDE_FOLDER}"
        )

#
# Include directories
#
target_include_directories(${target}
        PRIVATE
        ${DEFAULT_INCLUDE_DIRECTORIES}
        ${PROJECT_BINARY_DIR}/source/include
        ${OpenCV_INCLUDE_DIRS}
        PUBLIC
        )


#
# Libraries
#

target_link_libraries(${target}
        PRIVATE
        ${DEFAULT_LIBRARIES}
        ${META_PROJECT_NAME}::baselib
        ${META_PROJECT_NAME}::fiblib
        ${OpenCV_LIBRARIES}
        )

#
# Compile definitions
#

target_compile_definitions(${target}
        PRIVATE
        ${DEFAULT_COMPILE_DEFINITIONS}
        )


#
# Compile options
#

target_compile_options(${target}
        PRIVATE
        ${DEFAULT_COMPILE_OPTIONS}
        )


#
# Linker options
#

target_link_libraries(${target}
        PRIVATE
        ${DEFAULT_LINKER_OPTIONS}
        )


#
# Target Health
#

perform_health_checks(
        ${target}
        ${sources}
)


# Copy data folder in build folder
add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/../../${DATA_FOLDER}
        $<TARGET_FILE_DIR:${target}>/${DATA_FOLDER}
        )

#
# Deployment
#

# Executable
install(TARGETS ${target}
        RUNTIME DESTINATION ${INSTALL_BIN} COMPONENT examples
        BUNDLE DESTINATION ${INSTALL_BIN} COMPONENT examples
        )
