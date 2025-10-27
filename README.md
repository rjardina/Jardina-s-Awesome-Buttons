Jab = Jardina's Awesome Buttons
Made by: Ryan Jardina ~ KF5EKB
Released under the GNU GPL v2
Version: 1

This library can take a single or group of buttons & returns the combined
value. It includes debouncing (default is 50ms), once the buttons are released
it returns the biggest value seen. I'm sure this could be used for other binary
type inputs that needs debouncing too. Uses of delay() may make this not work
at it was intended, as it's ment to be in running / cycling code.

Uses INPUT, INPUT_PULLUP and INPUT_PULLDOWN just like normal.

Jab ObjectName(INPUT_PULLUP, 2, 3, 4, 5);

First number declaired is the pin number used as the least significant bit &
goes up from there. Can include upto 8 buttons to a combined output of 255.

Public:

ObjectName.UserInput() : Returns button(s) combined value

ObjectName.LastInput : Returns last value seen
