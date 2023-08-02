#include "ADebouncer.h"

#define buttonPin 2         // Define the button input pin.
#define debouncePeroid 10   // Define the debounce period in milliseconds

ADebouncer debouncer;       // Declare debouncer variable.

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);               // Set the button mode as input pullup.
  pinMode(LED_BUILTIN, OUTPUT);                   // Set the LED_BUILTIN mode as output.
  debouncer.mode(DELAYED, debouncePeroid, HIGH);  // Set the debounce mode as delayed mode and debounce period as 10 ms, with the initial output in a HIGH state.
}

void loop() {
  bool buttonState = debouncer.debounce(digitalRead(buttonPin));  // Save the debounced of the button state.
  digitalWrite(LED_BUILTIN, buttonState);                         // Update LED_BUILTIN with the button state.
}