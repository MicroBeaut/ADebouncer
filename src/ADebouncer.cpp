/*
  ADebouncer.cpp
  Created:  30-Jul-2023
  Author:   MicroBeaut

  MIT License
  Copyright (c) 2023 MicroBeaut
*/

#include "ADebouncer.h"

ADebouncer::ADebouncer() {
  _instant = DEFAULT_DEBOUNCE_MODE;
  _debouncePeriod = MS2US(DEFAULT_DEBOUNCE_PERIOD);
  _output = DEFAULT_INITIAL_OUTPUT;
}

void ADebouncer::mode(debounce_t instant, unsigned long debouncePeriod, boolean initOutput) {
  _instant = instant;
  _debouncePeriod = MS2US(debouncePeriod);
  _output = initOutput;
}

boolean ADebouncer::debounce(boolean input) {
  unsigned long currentTime = micros();
  _prevInput = _input;
  _prevOutput = _output;
  _input = input;
  if (_input != _prevInput) _debounceStartTime = currentTime;
  if (_debouncing) {
    unsigned long elapsedTime = currentTime - _debounceStartTime;
    if (elapsedTime >= _debouncePeriod) {
      _debouncing = false;
      _output = _input;
    }
  } else {
    if (_input != _output) {
      if (_instant == INSTANT) _output = _input;
      _debouncing = true;
    }
  }
  _rising = _output & !_prevOutput;
  _falling = !_output & _prevOutput;
  return _output;
}

boolean ADebouncer::input() {
  return _input;
}

boolean ADebouncer::debouncing() {
  return _debouncing;
}

boolean ADebouncer::debounced() {
  return _output;
}

boolean ADebouncer::rising() {
  return _rising;
}

boolean ADebouncer::falling() {
  return _falling;
}