/*!
 * @file src/components/digitalIO/controller.h
 *
 * Controller for the digitalio API
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
#ifndef WS_DIGITALIO_CONTROLLER_H
#define WS_DIGITALIO_CONTROLLER_H
#include "Wippersnapper_V2.h"
#include "hardware.h"
#include "model.h"

class Wippersnapper_V2;


class DigitalIOModel;    // Forward declaration
class DigitalIOHardware; // Forward declaration

/*!
    @brief  Routes messages using the digitalio.proto API to the
            appropriate hardware and model classes, controls and tracks
            the state of the hardware's digital I/O pins.
*/
class DigitalIOController {
public:
  DigitalIOController();
  ~DigitalIOController();
private:

};
extern Wippersnapper_V2 WsV2; ///< Wippersnapper V2 instance
#endif                        // WS_DIGITALIO_CONTROLLER_H