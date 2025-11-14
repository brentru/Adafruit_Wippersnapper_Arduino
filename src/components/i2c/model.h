/*!
 * @file src/components/i2c/model.h
 *
 * Provides high-level interfaces for messages within i2c.proto and
 * i2c_output.proto.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Copyright (c) Brent Rubell 2025 for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */
#ifndef WS_I2C_MODEL_H
#define WS_I2C_MODEL_H
#include "Wippersnapper_V2.h"
#include <Adafruit_Sensor.h>
#define MAX_DEVICE_EVENTS                                                      \
  15 ///< Maximum number of SensorEvents within I2cDeviceEvent
#define MAX_I2C_SCAN_DEVICES 120 ///< Maximum number of devices found on the bus

/*!
    @brief  Provides an interface for creating, encoding, and parsing
            messages from i2c.proto.
*/
class I2cModel {
public:
  I2cModel();
  ~I2cModel();

private:

};

#endif // WS_I2C_MODEL_H