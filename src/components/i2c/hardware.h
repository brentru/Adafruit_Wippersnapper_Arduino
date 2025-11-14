/*!
 * @file src/components/i2c/hardware.h
 *
 * Hardware driver for the i2c API
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
#ifndef WS_I2C_HARDWARE_H
#define WS_I2C_HARDWARE_H
#include "Wippersnapper_V2.h"


/*!
    @brief  Interfaces with the I2C bus via the Arduino "Wire" API.
*/
class I2cHardware {
public:
  I2cHardware();
  I2cHardware(const char *sda, const char *scl);
  ~I2cHardware();

private:

};
#endif // WS_I2C_HARDWARE_H