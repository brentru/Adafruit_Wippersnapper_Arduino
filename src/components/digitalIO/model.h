/*!
 * @file src/components/digitalIO/model.h
 *
 * Model for the digitalio.proto message.
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
#ifndef WS_DIGITALIO_MODEL_H
#define WS_DIGITALIO_MODEL_H
#include "Wippersnapper_V2.h"

/*!
    @brief  Provides an interface for creating, encoding, and parsing
            messages from digitalio.proto.
*/
class DigitalIOModel {
public:
  DigitalIOModel();
  ~DigitalIOModel();
private:
};
#endif // WS_DIGITALIO_MODEL_H