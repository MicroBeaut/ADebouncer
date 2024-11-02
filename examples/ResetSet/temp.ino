/*
  This code initializes a delayed debounce mode, debounces the button input signal,
  and updates the state of the built-in LED accordingly.
*/
 
#include "ADebouncer.h"
 
#define BUTTON_INPUT_PIN 2        // Pin for the button input.
#define DEBOUNCE_PERIOD_MS 10      // Debounce period in milliseconds.
 
ADebouncer buttonDebouncer;       // Create a debouncer instance.
 
void setup() {
  pinMode(BUTTON_INPUT_PIN, INPUT_PULLUP);            // Set the button input pin as input with pull-up.
  pinMode(LED_BUILTIN, OUTPUT);                       // Set the built-in LED pin as output.
  buttonDebouncer.setMode(DELAYED, DEBOUNCE_PERIOD_MS, HIGH);  // Set debounce mode to delayed with a 10ms period, starting with a HIGH output.
}
 
void loop() {
  bool debouncedButtonState = buttonDebouncer.debounce(digitalRead(BUTTON_INPUT_PIN));  // Get the debounced button state.
  digitalWrite(LED_BUILTIN, debouncedButtonState);                                   // Update the built-in LED with the debounced button state.
}