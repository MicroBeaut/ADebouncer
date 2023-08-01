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

#define ADEBOUNCER_VERSION "1.0.0"
#define ADEBOUNCER_AUTHOR "MicroBeaut"

enum debounce_t : boolean {DELAYED, INSTANT};

#define DEFAULT_DEBOUNCE_PERIOD 10        // Default debounce Period in milliseconds
#define DEFAULT_DEBOUNCE_MODE   DELAYED   // Default debounce mode
#define DEFAULT_INITIAL_OUTPUT  true      // Default initial output

#ifndef MS2US
#define MS2US(ms) (ms*1000UL)
#endif  // MS2US

class ADebouncer {
  private:
    unsigned char _instant: 1;
    unsigned char _debouncing: 1;

    unsigned char _input: 1;
    unsigned char _prevInput: 1;

    unsigned char _output: 1;
    unsigned char _prevOutput: 1;

    unsigned char _rising: 1;
    unsigned char _falling: 1;

    unsigned long _debouncePeriod;
    unsigned long _debounceStartTime;

  public:
    ADebouncer();
    void mode(debounce_t instant, unsigned long debouncePeriod = DEFAULT_DEBOUNCE_PERIOD, boolean initOutput = DEFAULT_INITIAL_OUTPUT);
    boolean debounce(boolean input);
    boolean input();
    boolean debouncing();
    boolean debounced();
    boolean rising();
    boolean falling();
};

#endif  // ADEBOUNCER_H