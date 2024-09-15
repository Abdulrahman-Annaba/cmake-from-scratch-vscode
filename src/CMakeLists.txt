add_executable(${CMAKE_PROJECT_NAME} "main.c")
# All includes used by the main application are found in the top-level include directory
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../include")
# Link library to application
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE blinky-lib)