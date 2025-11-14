/*!
 * @file src/components/register/model.h
 *
 * Model for the ESMP register proto API.
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
#ifndef WS_REGISTER_MODEL_H
#define WS_REGISTER_MODEL_H
#include "Wippersnapper_V2.h"

/*!
    @brief  Provides an interface for creating, encoding, and parsing
            messages from register.proto.
*/
class RegisterModel {
public:
  RegisterModel();
  ~RegisterModel();
  // Request Message
  void CreateRegisterAddRequest(const char *device_identifier);
  bool EncodeRegisterAddRequest();
  register_v1_gpio_RegisterAdd *getRegisterAddRequest();
  // Response Message
  bool DecodeRegisterAddedResponse(pb_istream_t *stream);
  void ParseRegisterAddedResponse();
  const char *getDeviceIdentifier();
  uint32_t getDigitalPinCount();
  uint32_t getAnalogPinCount();
  
  // Callbacks for nanopb
  static bool encode_device_identifier_callback(pb_ostream_t *stream,
                                                const pb_field_t *field,
                                                void *const *arg);
  static bool decode_device_identifier_callback(pb_istream_t *stream,
                                                const pb_field_t *field,
                                                void **arg);

private:
  register_v1_gpio_RegisterAdd _RegisterAdd;
  register_v1_gpio_RegisterAdded _RegisterAdded;
  char _device_identifier[128]; // Buffer for device identifier
  uint32_t _pin_cnt_digital;
  uint32_t _pin_cnt_analog;
};
#endif // WS_REGISTER_MODEL_H