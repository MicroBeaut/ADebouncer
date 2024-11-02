/*
  This example sets up a debouncer for a set button and a reset button to control the state.
  - Declare a debouncer for the set button with delayed mode for debouncing.
  - Declare a debouncer for the reset button with instant mode for debouncing.

  Both set and reset buttons have a debounce period set to 1 second.
  - To set the state, press the set button for 1 second.
  - To reset the state, press the reset button for an instant reset.

  The LED_BUILTIN will reflect the state value.
*/

#include "ADebouncer.h"

#define BUTTON_INPUT_PIN 12     // Define the button input pin.
#define DEBOUNCE_PERIOD_MS 10   // Define the debounce period in milliseconds

ADebouncer buttonDebouncer;       // Declare debouncer variable.
bool state;                       // Declare state variable.

void setup() {
  pinMode(BUTTON_INPUT_PIN, INPUT_PULLUP);                      // Set the button mode as input pullup.
  pinMode(LED_BUILTIN, OUTPUT);                                 // Set the LED_BUILTIN mode as output.
  buttonDebouncer.setMode(DELAYED, DEBOUNCE_PERIOD_MS, HIGH);   // Set the debounce mode as delayed mode and debounce period, with the initial output in a HIGH state.
  state = HIGH;                                                 // Initial state is set to HIGH.
}

void loop() {
  buttonDebouncer.debounce(digitalRead(BUTTON_INPUT_PIN));  // Debounce input of the button state.
  if (buttonDebouncer.isFallingEdge()) state = !state;      // Toggle state of the state variable.
  digitalWrite(LED_BUILTIN, state);                         // Update LED_BUILTIN with the state.
}