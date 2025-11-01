// Jab = Jardina's Awesome Buttons
// Made by Ryan Jardina ~ KF5EKB
// Released under the GNU GPL v2

// Takes a group of buttons & prints the combined value to serial
// Note: This example was programmed using the PI pico but all Arduino boards should work

#include <Jab.h>                                                                // Library for testing !this! example
Jab GroupOne(INPUT_PULLUP, 2, 3, 4, 5);                                         // 1st group of buttons & used pin numbers (upto 8)
Jab GroupTwo(INPUT_PULLUP, 16, 17, 18, 19, 20);                                 // 2nd            "                 "

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);                                                 // Output for Heartbeat
  Serial.println(115200); }                                                     // Start serial console

void loop() {
  digitalWrite(LED_BUILTIN, millis() >> 9 & 1);                                 // Heartbeat to see if code is cycling
  switch (GroupOne.UserInput()) {                                               // Check user's input from group's ONE buttons than goes to that case
    default: case 0: break;                                                     // Do nothing (should never happen in this example) & breaks out of the switch statement
    case 1 ... 255:                                                             // input was in the range from 1 to 255
      Serial.print("Input from Group ONE: ");                                   // Prints whats in the " "
      Serial.println(GroupOne.LastInput);                                       // Prints the input from group 1 buttons & than start a new line
      break; }                                                                  // Breaks out of the switch statement
  switch (GroupTwo.UserInput()) {                                               // Check user's input from group's TWO buttons than goes to that case
    default: case 0: break;                                                     // Do nothing (should never happen in this example) & breaks out of the switch statement
    case 1 ... 255:                                                             // Input was in the range from 1 to 255
      Serial.print("Input from Group TWO: ");                                   // Prints whats in the " "
      Serial.println(GroupTwo.LastInput);                                       // Prints the input from group 2 buttons & than start a new line
      break; } }                                                                // Breaks out of the switch statement
