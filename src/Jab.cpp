// Jab = Jardina's Awesome Buttons
// Made by Ryan Jardina ~ KF5EKB
// Released under the GNU GPL v2
// Version: 2

#include <Jab.h>

#define DebounceDelay 50

/// @brief Constructor
Jab::Jab(uint8_t InputType, uint8_t Button0, uint8_t Button1, uint8_t Button2, uint8_t Button3, uint8_t Button4, uint8_t Button5, uint8_t Button6, uint8_t Button7) {
  Button[0] = Button0; Button[1] = Button1; Button[2] = Button2; Button[3] = Button3;  // Takes pin numbers & places them in the array
  Button[4] = Button4; Button[5] = Button5; Button[6] = Button6; Button[7] = Button7;  //      "               "
  for (uint8_t i = 0; i < sizeof(Button) && Button[i] != 255; i++) {            // Loops through all buttons that were defined
    ButtonCount++;                                                              // Adds to button count
    pinMode(Button[i], InputType); }                                            // Initiate the button to receive input
    if (InputType == INPUT || InputType == INPUT_PULLDOWN) { FlipByte = 1; } }  // Default is Pullup, cause that's what I use but if others is need than this help (i think)

/// @brief Function to see if button(s) were being pressed
uint16_t Jab::UserInput(void) {
  if ((Buttons() || InputIndicator) && TimeSinceReleased < millis()) {          // Are the buttons being pressed or were they
    if (!InputIndicator) {                                                      // Were the button pressed in the recent pass
      TimeSincePressed = millis() + DebounceDelay;                              // Buttons weren't being pressed set current time plus an 8th of a second variable
      InputIndicator = 1; }                                                     // Set buttons indicator to true
    if (ButtonInputted < Buttons()) { ButtonInputted = Buttons(); }             // This is to allow botton combos + debounce 
    if (!Buttons() && TimeSincePressed < millis()) {                            // Buttons are now open again & at least an 8th of a second has passed since first pressed
      LastInput = ButtonInputted;                                               // Place buttons that were pressed into LastInput
      if (millis() > TimeSincePressed + 950) { LastInput += 256; }              // If pressed longer than a seconds add 255 to press
      InputIndicator = 0;                                                       // Resets input indicator
      ButtonInputted = 0;                                                       // Reset input
      TimeSinceReleased = millis() + DebounceDelay;                             // This is to help with debounce
      return LastInput; } }                                                     // Return what was pushed
  return 0; }                                                                   // If buttons weren't being pushed return nothing

/// @brief Function to see which button(s) are being pressed
uint8_t Jab::Buttons(void) {
  uint8_t Pressed = 0;                                                          // Place holder for buttons
  for (uint8_t i = 0; i < ButtonCount; i++) { bitWrite(Pressed, i, (FlipByte ? digitalRead(Button[i]) : !digitalRead(Button[i]))); } // Cycles through all the buttons
  return Pressed; }                                                             // Returns which button(s) are pressed
