Jab = Jardina's Awesome Buttons<br>
Made by: Ryan Jardina ~ KF5EKB<br>
Released under the GNU GPL v2<br>
Version: 2<p>

This library can take a single or group of buttons & returns the combined
value. It includes debouncing (default is 50ms), once the buttons are released
it returns the biggest value seen. I'm sure this could be used for other binary
type inputs that needs debouncing too. Uses of delay() may make this not work
at it was intended, as it's ment to be in running / cycling code.<p>

Uses INPUT, INPUT_PULLUP and INPUT_PULLDOWN just like normal.<p>

Jab ObjectName(INPUT_PULLUP, 2, 3, 4, 5);<p>

First number declaired is the pin number used as the least significant bit &
goes up from there. Can include upto 8 buttons to a combined output of 255.<br>

Public:<p>

ObjectName.UserInput() : Returns button(s) combined value<p>

ObjectName.LastInput : Returns last value seen<p>

Holding the button(s) down longer than a seond will add 256 / 0x100 to the return value
