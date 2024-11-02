/*
  Description: Debounces the input signals from the set and reset buttons and updates the state of LED_BUILTIN accordingly.
*/

#include "ADebouncer.h"

#define SET_PIN          12       // Define the set input pin.
#define RESET_PIN        11       // Define the reset input pin.
#define DEBOUNCE_PERIOD_MS  1000  // Define the debounce period in milliseconds

ADebouncer setButton;       // Declare set debouncer variable.
ADebouncer resetButton;     // Declare reset debouncer variable.
bool state;                 // Declare state variable for ResetSet.

void setup() {
  pinMode(SET_PIN, INPUT_PULLUP);   // Set the button mode as input pullup.
  pinMode(RESET_PIN, INPUT_PULLUP); // Set the button mode as input pullup.
  pinMode(LED_BUILTIN, OUTPUT);     // Set the LED_BUILTIN mode as output.
  setButton.setMode(DELAYED, DEBOUNCE_PERIOD_MS, HIGH);    // Set the debounce mode as delayed mode and debounce period, with the initial output in a HIGH state.
  resetButton.setMode(INSTANT, DEBOUNCE_PERIOD_MS, HIGH);  // Set the debounce mode as instant mode and debounce period, with the initial output in a HIGH state.
  state = LOW;                                          // Initial state in a LOW state.
}

void loop() {
  // Debounce input of the set button state.
  setButton.debounce(digitalRead(SET_PIN));
  // Debounce input of the reset button state.
  resetButton.debounce(digitalRead(RESET_PIN));

  // Update the state based on set and reset button outputs.
  state = (state | !setButton.getDebouncedOutput()) & resetButton.getDebouncedOutput();
  // Update LED_BUILTIN with the state.
  digitalWrite(LED_BUILTIN, state);
}