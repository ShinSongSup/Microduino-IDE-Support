/* Arduino SdFat Library
 * Copyright (C) 2010 by William Greiman
 *
 * This file is part of the Arduino SdFat Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Arduino SdFat Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
// Warning this file was generated by a program.
#ifndef Sd2PinMap_h
#define Sd2PinMap_h
#include <avr/io.h>

#include <Arduino.h>

// Two Wire (aka I2C) ports
uint8_t const SDA_PIN = SDA;
uint8_t const SCL_PIN = SCL;

// SPI port
uint8_t const SS_PIN = SS;
uint8_t const MOSI_PIN = MOSI;
uint8_t const MISO_PIN = MISO;
uint8_t const SCK_PIN = SCK;

uint8_t badPinNumber(void)
  __attribute__((error("Pin number is too large or not a constant")));

static inline __attribute__((always_inline))
  uint8_t getPinMode(uint8_t pin) {
  if (__builtin_constant_p(pin) && pin < NUM_DIGITAL_PINS) {
    return *portModeRegister(digitalPinToPort(pin)) & digitalPinToBitMask(pin);
  } else {
    return badPinNumber();
  }
}
static inline __attribute__((always_inline))
  void setPinMode(uint8_t pin, uint8_t mode) {
  if (__builtin_constant_p(pin) && pin < NUM_DIGITAL_PINS) {
    if (mode) {
      *portModeRegister(digitalPinToPort(pin)) |= digitalPinToBitMask(pin);
    } else {
      *portModeRegister(digitalPinToPort(pin)) &= ~digitalPinToBitMask(pin);
    }
  } else {
    badPinNumber();
  }
}
static inline __attribute__((always_inline))
  uint8_t fastDigitalRead(uint8_t pin) {
  if (__builtin_constant_p(pin) && pin < NUM_DIGITAL_PINS) {
    return *portInputRegister(digitalPinToPort(pin)) & digitalPinToBitMask(pin);
  } else {
    return badPinNumber();
  }
}
static inline __attribute__((always_inline))
  void fastDigitalWrite(uint8_t pin, uint8_t value) {
  if (__builtin_constant_p(pin) && pin < NUM_DIGITAL_PINS) {
    if (value) {
      *portOutputRegister(digitalPinToPort(pin)) |= digitalPinToBitMask(pin);
    } else {
      *portOutputRegister(digitalPinToPort(pin)) &= ~digitalPinToBitMask(pin);
    }
  } else {
    badPinNumber();
  }
}
#endif  // Sd2PinMap_h
