/*!
 * @file src/components/digitalIO/hardware.h
 *
 * Hardware for the digitalio.proto message.
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
#ifndef WS_DIGITALIO_HARDWARE_H
#define WS_DIGITALIO_HARDWARE_H
#include "Wippersnapper_V2.h"

/*!
    @brief  Interface for interacting with hardware's digital I/O pin API.
*/
class DigitalIOHardware {
public:
  DigitalIOHardware();
  ~DigitalIOHardware();
private:
};
#endif // WS_DIGITALIO_HARDWARE_H