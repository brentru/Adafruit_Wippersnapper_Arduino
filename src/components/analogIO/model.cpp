/*!
 * @file src/components/analogIO/model.cpp
 *
 * Interfaces for the analogio.proto API
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
#include "model.h"
#include <cstdio>

/*!
    @brief  AnalogIOModel constructor
*/
AnalogIOModel::AnalogIOModel() { 
  // no-op
}

/*!
    @brief  AnalogIOModel destructor
*/
AnalogIOModel::~AnalogIOModel() {

}

/*!
    @brief  Populates an AnalogInEvent payload.
    @param  event
            The event message to populate.
    @param  pin_name
            The numeric pin identifier.
    @param  value
            The latest analog value.
    @returns True if event was populated successfully.
*/
bool AnalogIOModel::PopulateAnalogInEvent(esmp_v1_analogin_AnalogInEvent *event,
                                          uint8_t pin_name,
                                          float value) {
  if (!event) {
    return false;
  }

  *event = esmp_v1_analogin_AnalogInEvent_init_default;
  snprintf(event->pin_name, sizeof(event->pin_name), "A%u", pin_name);
  event->value = value;
  return true;
}
