/*!
 * @file src/components/analogIO/controller.h
 *
 * Controller for the AnalogIO API
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
#ifndef WS_ANALOGIO_CONTROLLER_H
#define WS_ANALOGIO_CONTROLLER_H
#include "Wippersnapper_V2.h"
#include "hardware.h"
#include "model.h"

class Wippersnapper_V2; ///< Forward declaration
class AnalogIOModel;    ///< Forward declaration
class AnalogIOHardware; ///< Forward declaration


/*!
    @brief  Routes messages using the analogio.proto API to the
            appropriate hardware and model classes, controls and tracks
            the state of the hardware's digital I/O pins.
*/
class AnalogIOController {
public:
  AnalogIOController();
  ~AnalogIOController();
private:
};
extern Wippersnapper_V2 WsV2; ///< Wippersnapper V2 instance
#endif                        // WS_ANALOGIO_CONTROLLER_H