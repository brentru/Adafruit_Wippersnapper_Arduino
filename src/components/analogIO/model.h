/*!
 * @file src/components/analogIO/model.h
 *
 * Model interface for the analogio.proto message.
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
#ifndef WS_ANALOGIO_MODEL_H
#define WS_ANALOGIO_MODEL_H
#include "Wippersnapper_V2.h"
#include "protos/analogin.pb.h"

/*!
    @brief  Provides an interface for creating, encoding, and parsing
            messages from analogio.proto.
*/
class AnalogIOModel {
public:
  AnalogIOModel();
  ~AnalogIOModel();
  bool PopulateAnalogInEvent(esmp_v1_analogin_AnalogInEvent *event,
                             uint8_t pin_name,
                             float value);

private:

};
#endif // WS_DIGITALIO_MODEL_H
