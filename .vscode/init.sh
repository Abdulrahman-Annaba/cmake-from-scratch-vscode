#!/bin/bash
source ~/.bashrc
# Tells CMake the location of the compiler binary
export CMAKE_C_COMPILER="/usr/bin/avr-gcc"
# Tells CMake which build system to use to actually build the project
export CMAKE_GENERATOR="Ninja"
# Toolchain-specific binaries for building/flashing
export OBJCOPY_PATH="/usr/bin/avr-objcopy"
export AVRSTRIP_PATH="/usr/bin/avr-strip"
export AVRDUDE_PATH="/usr/bin/avrdude"
export FLASH_PORT="/dev/ttyUSB0"