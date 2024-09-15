#ifndef BLINKY_LIB_H
#define BLINKY_LIB_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/// @brief Initializes the built in LED on the arduino nano
void initialize_led();

/// @brief Turns on the built in LED on the arduino nano
void turn_on_led();

/// @brief Turns off the built in LED on the arduino nano
void turn_off_led();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BLINKY_LIB_H */