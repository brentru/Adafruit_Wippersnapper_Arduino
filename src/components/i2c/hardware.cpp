/*!
 * @file src/components/i2c/hardware.cpp
 *
 * Hardware implementation for the i2c.proto API
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
#include "hardware.h"

/*!
    @brief  Default I2C bus hardware class constructor
*/
I2cHardware::I2cHardware() {

}

/*!
    @brief  I2C hardware class constructor for an alternative bus.
    @param    sda
                The desired SDA pin.
    @param    scl
                The desired SCL pin.
*/
I2cHardware::I2cHardware(const char *sda, const char *scl) {

}

/*!
    @brief  I2C hardware class destructor
*/
I2cHardware::~I2cHardware() {  }
