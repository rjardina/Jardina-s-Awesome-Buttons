// Jab = Jardina's Awesome Buttons
// Made by Ryan Jardina ~ KF5EKB
// Released under the GNU GPL v2
// Version 1

#ifndef JAB_H
#define JAB_H

#include "Arduino.h"

class Jab {
public:
  /// @brief Constructor
  Jab(uint8_t InputType=INPUT_PULLUP, uint8_t Button0=255, uint8_t Button1=255, uint8_t Button2=255, uint8_t Button3=255, uint8_t Button4=255, uint8_t Button5=255, uint8_t Button6=255, uint8_t Button7=255);

  /// @brief Returns the users input
  uint8_t UserInput(void);

  /// @brief Returns the last input
  uint8_t LastInput;

private:
  /// @brief Sees if any buttons are being pressed
  uint8_t Buttons(void);

  /// @brief Array of Pins/Buttons
  uint8_t Button[8];

  /// @brief Tells if input has been received
  bool InputIndicator;

  /// @brief Time since pressed + debounce delay
  long TimeSincePressed;

  /// @brief Time since release + debounce delay
  long TimeSinceReleased;

  /// @brief Holds the Button(s)
  uint8_t ButtonInputted;

  /// @brief Number of pins or buttons being used
  uint8_t ButtonCount;

  /// @brief Bit to see if the inputs are normally high or low
  bool FlipByte;
};

#endif // JAB_H
