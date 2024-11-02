/*
  ADebouncer.h
  Created:  30-Jul-2023
  Author:   MicroBeaut

  MIT License
  Copyright (c) 2023 MicroBeaut
*/

#ifndef ADEBOUNCER_H
#define ADEBOUNCER_H

#include <Arduino.h>

#define ADEBOUNCER_VERSION "1.2.0"
#define ADEBOUNCER_AUTHOR "MicroBeaut"

enum DebounceMode : boolean {DELAYED, INSTANT};

#define DEFAULT_DEBOUNCE_PERIOD 10        // Default debounce period in milliseconds
#define DEFAULT_DEBOUNCE_MODE   DebounceMode::DELAYED   // Default debounce mode
#define DEFAULT_INITIAL_OUTPUT  true      // Default initial output

#ifndef MS2US
#define MS2US(ms) (ms * 1000UL)
#endif  // MS2US

class ADebouncer {
  private:
    unsigned char _debounceMode: 1;
    unsigned char _isDebouncing: 1;

    unsigned char _inputState: 1;
    unsigned char _previousInputState: 1;

    unsigned char _outputState: 1;
    unsigned char _previousOutputState: 1;

    unsigned char _risingEdge: 1;
    unsigned char _fallingEdge: 1;

    unsigned long _debouncePeriodMicros;
    unsigned long _debounceStartTime;

  public:
    ADebouncer();
    void setMode(DebounceMode mode, unsigned long debouncePeriod = DEFAULT_DEBOUNCE_PERIOD, boolean initialOutputState = DEFAULT_INITIAL_OUTPUT);
    boolean debounce(boolean inputState);
    boolean getInputState();
    boolean isDebouncing();
    boolean getDebouncedOutput();
    boolean isRisingEdge();
    boolean isFallingEdge();
};

#endif  // ADEBOUNCER_H