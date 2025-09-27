cmake_minimum_required(VERSION 3.10)
project(CANSAT-FSW)

# Enable compile_commands.json generation for VS Code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(NOT DEFINED TARGET_PLATFORM)
    set(TARGET_PLATFORM "linux")
endif()

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}
)

# ==== Source Files ====
# Platform-specific sources
if(TARGET_PLATFORM STREQUAL "linux")
    file(GLOB PLATFORM_SOURCES
        platform/linux/*.cpp
        os/linux/posix_rtos.cpp
    )
elseif(TARGET_PLATFORM STREQUAL "stm32")
    file(GLOB PLATFORM_SOURCES
        platform/stm32/*.cpp
        os/stm32/freertos_rtos.cpp
    )
endif()

# Common sources
file(GLOB_RECURSE SOURCES
    main.cpp
    apps/*.cpp
    queues/*.cpp
    msg/*.cpp
    ${PLATFORM_SOURCES}
)

# ==== Executables ====
# format: add_executable(<name> <main source> <source files>)
# Main application executable
add_executable(MAIN_TEST main.cpp ${SOURCES})
# Add test executables
add_executable(rtos_task_test test/rtos_task_test.cpp os/linux/posix_rtos.cpp)
add_executable(rtos_mutex_test test/rtos_mutex_test.cpp os/linux/posix_rtos.cpp)
add_executable(rtos_semaphore_test test/rtos_semaphore_test.cpp os/linux/posix_rtos.cpp)
add_executable(rtos_countingsem_test test/rtos_countingsem_test.cpp os/linux/posix_rtos.cpp)
add_executable(rtos_queue_test test/rtos_queue_test.cpp os/linux/posix_rtos.cpp)


# ==== Link Libraries ====
# Platform-specific linking
if(TARGET_PLATFORM STREQUAL "linux")
    target_link_libraries(MAIN_TEST pthread)

    # Link RTOS test executables
    target_link_libraries(rtos_task_test pthread)
    target_link_libraries(rtos_mutex_test pthread)
    target_link_libraries(rtos_semaphore_test pthread)
    target_link_libraries(rtos_countingsem_test pthread)
    target_link_libraries(rtos_queue_test pthread)

endif()