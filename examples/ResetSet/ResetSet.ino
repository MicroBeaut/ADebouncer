#include "ADebouncer.h"

#define setPin          12    // Define the set input pin.
#define resetPin        11    // Define the reset input pin.
#define debouncePeroid  1000  // Define the debounce period in milliseconds

ADebouncer setButton;       // Declare set debouncer variable.
ADebouncer resetButton;     // Declare reset debouncer variable.
bool state;                 // Declare state variable for ResetSet.

void setup() {
  pinMode(setPin, INPUT_PULLUP);                    // Set the button mode as input pullup.
  pinMode(resetPin, INPUT_PULLUP);                  // Set the button mode as input pullup.
  pinMode(LED_BUILTIN, OUTPUT);                     // Set the LED_BUILTIN mode as output.
  setButton.mode(DELAYED, debouncePeroid, HIGH);    // Set the debounce mode as delayed mode and debounce period, with the initial output in a HIGH state.
  resetButton.mode(INSTANT, debouncePeroid, HIGH);  // Set the debounce mode as instant mode and debounce period, with the initial output in a HIGH state.
  state = LOW;                                      // Initial state in a LOW state.
}

void loop() {
  setButton.debounce(digitalRead(setPin));                              // Debounce input of the set button state.
  resetButton.debounce(digitalRead(resetPin));                          // Debounce input of the reset button state.
  state = (state | !setButton.debounced()) & resetButton.debounced();   // Reset and Set the state
  digitalWrite(LED_BUILTIN, state);                                     // Update LED_BUILTIN with the state.
}