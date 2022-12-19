cmake_minimum_required(VERSION 3.5)

set (FAMILY rp2040)
set (PICO_BOARD pico)

include(${CMAKE_CURRENT_SOURCE_DIR}/tinyusb-master/hw/bsp/family_support.cmake)

# gets PROJECT name for the example (e.g. <BOARD>-<DIR_NAME>)
family_get_project_name(PROJECT ${CMAKE_CURRENT_LIST_DIR})

project(${PROJECT})

# Checks this example is valid for the family and initializes the project
family_initialize_project(${PROJECT} ${CMAKE_CURRENT_LIST_DIR})

add_executable(${PROJECT})

target_link_libraries(${PROJECT} PUBLIC
        pico_stdlib
        pico_multicore
        hardware_i2c
)

# Example source
target_sources(${PROJECT} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/keyboard/usb_descriptors.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/keyboard/keyboard.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/oled/oled.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/encoder/encoder.c
        )

# Example include
target_include_directories(${PROJECT} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

# Configure compilation flags and libraries for the example... see the corresponding function
# in hw/bsp/FAMILY/family.cmake for details.
family_configure_device_example(${PROJECT})