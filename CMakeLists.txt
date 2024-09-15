cmake_minimum_required(VERSION 3.12)

set(CMAKE_SYSTEM_NAME Generic)
set(AVRSTRIP $ENV{AVRSTRIP_PATH})
set(OBJCOPY $ENV{OBJCOPY_PATH})
set(AVRDUDE $ENV{AVRDUDE_PATH})

project(blinky-example VERSION 0.1.0 LANGUAGES C CXX ASM)
set(CMAKE_C_COMPILER $ENV{CMAKE_C_COMPILER})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Set the MCU architecture flag for the compiler
set(MCU "atmega328p")
set(PROG_TYPE "arduino")
set(CMAKE_C_FLAGS "-mmcu=${MCU} -std=gnu99 -O3 -Wall -Wextra")
# Add library subdirectories first, then main application src
add_subdirectory(blinky-lib)
add_subdirectory(src)
# Add compile definitions for whatever needs them
# This project just needs F_CPU defined for the main application
target_compile_definitions(blinky-example PRIVATE F_CPU=16000000UL)
# Specify the binary name
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")
# Specify build targets
# The "ALL" specifier tells CMake to run that build step for any build target
add_custom_target(strip ALL     ${AVRSTRIP} "src/${PROJECT_NAME}.elf" DEPENDS ${PROJECT_NAME})
add_custom_target(hex   ALL     ${OBJCOPY} -R .eeprom -O ihex "src/${PROJECT_NAME}.elf" "src/${PROJECT_NAME}.hex" DEPENDS strip)
add_custom_target(flash ${AVRDUDE} -c ${PROG_TYPE} -D -p ${MCU} -P $ENV{FLASH_PORT} -U flash:w:src/${PROJECT_NAME}.hex DEPENDS hex)
