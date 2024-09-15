# CMake from scratch with VScode: an opinionated example
This example is a cleaned up version of another learning project when setting up `avr-gcc` from scratch with cmake and vscode. Hopefully you find it useful

## Basic design
This is the world's most over-engineered blinky example for the arduino nano. It uses the `avr-gcc` toolchain to compile and link, and `avrdude` to flash. CMake is the build system used to drive systems like make, Ninja, etc.

Machine-specific information needed at build time is specified using environment variables, which are loaded by the `.vscode/init.sh` script that runs when an integrated terminal is opened. CMake uses these.
Information needed at build time for the application or libraries is specified using the top-level CMakeLists.txt using `target_compile_definitions`

`blinky-lib` is a library for the project.

`include` contains symlinks to library headers contained within their respective library folder. CMake then includes this folder, thus allowing one to specify the desired header file from a given library like so: `#include blinky/blinky.h`

