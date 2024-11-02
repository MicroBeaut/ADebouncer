/*
  ADebouncer.cpp
  Created:  30-Jul-2023
  Author:   MicroBeaut

  MIT License
  Copyright (c) 2023 MicroBeaut
*/

#include "ADebouncer.h"

ADebouncer::ADebouncer() {
  _debounceMode = DEFAULT_DEBOUNCE_MODE;
  _debouncePeriodMicros = MS2US(DEFAULT_DEBOUNCE_PERIOD);
  _outputState = DEFAULT_INITIAL_OUTPUT;
}

void ADebouncer::setMode(DebounceMode mode, unsigned long debouncePeriod, boolean initialOutputState) {
  _debounceMode = mode;
  _debouncePeriodMicros = MS2US(debouncePeriod);
  _outputState = initialOutputState;
}

boolean ADebouncer::debounce(boolean input) {
  unsigned long currentTime = micros();
  _previousInputState = _inputState;
  _previousOutputState = _outputState;
  _inputState = input;
  if (_inputState ^ _previousInputState) {
    _debounceStartTime = currentTime;
  }
  if (_isDebouncing) {
    unsigned long elapsedTime = currentTime - _debounceStartTime;
    if (elapsedTime >= _debouncePeriodMicros) {
      _isDebouncing = false;
      _outputState = _inputState;
    }
  } else {
    if (_inputState ^ _outputState) {
      if (_debounceMode) {
        _outputState = _inputState;
      }
      _isDebouncing = true;
    }
  }
  _risingEdge = _outputState & ~_previousOutputState;
  _fallingEdge = ~_outputState & _previousOutputState;
  return _outputState;
}

boolean ADebouncer::getInputState() {
  return _inputState;
}

boolean ADebouncer::isDebouncing() {
  return _isDebouncing;
}

boolean ADebouncer::getDebouncedOutput() {
  return _outputState;
}

boolean ADebouncer::isRisingEdge() {
  return _risingEdge;
}

boolean ADebouncer::isFallingEdge() {
  return _fallingEdge;
}