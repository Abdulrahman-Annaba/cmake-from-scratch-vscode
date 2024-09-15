add_library(blinky-lib "include/blinky.h" "src/blinky.c")
# Set this as a private include directory to prevent `#include "blinky.h"` from being a
# valid include in applications that use this library. In other words, this is not a transitive
# include directory 
target_include_directories(blinky-lib PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")