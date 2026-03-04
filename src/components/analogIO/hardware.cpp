/*!
 * @file src/components/analogIO/hardware.cpp
 *
 * Hardware interface for the analogio.proto API
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Copyright (c) Brent Rubell 2024 for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */
#include "hardware.h"

/*!
    @brief  AnalogIO hardware constructor
*/
AnalogIOHardware::AnalogIOHardware() {
  // no-op
}

/*!
    @brief  AnalogIO hardware destructor
*/
AnalogIOHardware::~AnalogIOHardware() {}

/*!
    @brief  Configures an analog input pin.
    @param  pin_name
            The pin's numeric name.
    @return True if the pin was configured.
*/
bool AnalogIOHardware::ConfigurePin(uint8_t pin_name) {
  pinMode(pin_name, INPUT);
  return true;
}

/*!
    @brief  Deinitializes an analog input pin.
    @param  pin_name
            The pin to deinitialize.
*/
void AnalogIOHardware::deinit(uint8_t pin_name) {
  pinMode(pin_name, INPUT);
}

/*!
    @brief  Reads the current value of an analog pin.
    @param  pin_name
            The pin's numeric name.
    @return The analog reading as a float.
*/
float AnalogIOHardware::GetValue(uint8_t pin_name) {
  return (float)analogRead(pin_name);
}
