/*!
 * @file model.h
 *
 * Hardware implementation for the ds18x20.proto message.
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
#ifndef WS_DS18X20_HARDWARE_H
#define WS_DS18X20_HARDWARE_H
#include "Wippersnapper_V2.h"

#include "OneWireNg_CurrentPlatform.h"
#include "drivers/DSTherm.h"
#include "utils/Placeholder.h"

/**************************************************************************/
/*!
    @brief  Interface for interacting with the's DallasTemp
            and OneWire APIs.
*/
/**************************************************************************/
class DS18X20Hardware {
public:
  DS18X20Hardware(uint8_t onewire_pin);
  ~DS18X20Hardware();
  void setResolution(int resolution);

private:
  // NOTE: We are going to try definining a vector of DS18X20Hardware objects
  // iwthin the controller so instead of a struct, these are all assigned to
  // this class
  Placeholder<OneWireNg_CurrentPlatform> _ow; ///< OneWire bus object
  DSTherm _drv_therm;                         ///< DS18X20 driver object
  DSTherm::Resolution _resolution; ///< Resolution of the DS18X20 sensor
  // From the PB model
  uint8_t onewire_pin; ///< Pin utilized by the OneWire bus, used for addressing
  float _period;       ///< The desired period to read the sensor, in seconds
  float _prv_period;   ///< Last time the sensor was polled, in seconds
  pb_size_t
      _sensor_types_count; ///< Number of sensor types to read from the sensor
  wippersnapper_sensor_SensorType
      _sensor_types[2]; ///< DS sensor type(s) to read from the sensor
};
#endif // WS_DS18X20_HARDWARE_H