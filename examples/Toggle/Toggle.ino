/*
  This example is designed to have a set button and a reset button to Reset-Set the state.
  - Declare debouncer for the set button. set the debounce as a delayed mode
  - Declare debouncer for the reset button. Set the debounce as an instant mode

  Both set and reset buttons have the same debounce period. in this example, will be set to debounce period for 1 second,
  - To set the state, press the set button for 1 second.
  - To reset the state, the state will be instantly reset after pressing the reset button.

  The LED_BUILTIN will be updated with the state value.
*/

#include "ADebouncer.h"

#define buttonPin 12        // Define the button input pin.
#define debouncePeroid 10   // Define the debounce period in milliseconds

ADebouncer debouncer;       // Declare debouncer variable.
bool state;                 // Declare state variable.

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);               // Set the button mode as input pullup.
  pinMode(LED_BUILTIN, OUTPUT);                   // Set the LED_BUILTIN mode as output.
  debouncer.mode(DELAYED, debouncePeroid, HIGH);  // Set the debounce mode as delayed mode and debounce period, with the initial output in a HIGH state.
  state = HIGH;                                   // Initial state in a HIGH state.
}

void loop() {
  debouncer.debounce(digitalRead(buttonPin));   // Debounce input of the button state.
  if (debouncer.falling()) state = !state;      // Toggle state of the state variable.
  digitalWrite(LED_BUILTIN, state);             // Update LED_BUILTIN with the state.
}