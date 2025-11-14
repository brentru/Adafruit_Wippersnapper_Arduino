/*!
 * @file src/components/register/model.cpp
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
#include "model.h"

/*!
    @brief  RegisterModel constructor
*/
RegisterModel::RegisterModel() {
  memset(&_RegisterAdd, 0, sizeof(_RegisterAdd));
  memset(&_RegisterAdded, 0, sizeof(_RegisterAdded));
  memset(_device_identifier, 0, sizeof(_device_identifier));
  _pin_cnt_digital = 0;
  _pin_cnt_analog = 0;
}

/*!
    @brief  RegisterModel destructor
*/
RegisterModel::~RegisterModel() {
  memset(&_RegisterAdd, 0, sizeof(_RegisterAdd));
  memset(&_RegisterAdded, 0, sizeof(_RegisterAdded));
  memset(_device_identifier, 0, sizeof(_device_identifier));
}

/*!
    @brief  Fills and creates a RegisterAdd message
    @param  device_identifier
            Device's unique identifier.
*/
void RegisterModel::CreateRegisterAddRequest(const char *device_identifier) {
  strncpy(_device_identifier, device_identifier, sizeof(_device_identifier) - 1);
  _device_identifier[sizeof(_device_identifier) - 1] = '\0';
  
  // Set up the callback for encoding the device_identifier
  _RegisterAdd.device_identifier.funcs.encode = &encode_device_identifier_callback;
  _RegisterAdd.device_identifier.arg = _device_identifier;
}

/*!
    @brief  Encodes a RegisterAdd message
    @returns True if the message was successfully encoded,
             False otherwise.
*/
bool RegisterModel::EncodeRegisterAddRequest() {
  // Obtain size of the message
  size_t registerAddRequestSz;
  if (!pb_get_encoded_size(&registerAddRequestSz,
                           register_v1_gpio_RegisterAdd_fields,
                           &_RegisterAdd))
    return false;

  // Create a buffer for holding the message
  uint8_t buf[registerAddRequestSz];

  // Create a stream that will write to buf
  pb_ostream_t msg_stream = pb_ostream_from_buffer(buf, sizeof(buf));

  // Encode the message
  return pb_encode(&msg_stream, register_v1_gpio_RegisterAdd_fields, &_RegisterAdd);
}

/*!
    @brief  Decodes a RegisterAdded message
    @param  stream
            Incoming data stream from buffer.
    @returns True if the message was successfully decoded,
             False otherwise.
*/
bool RegisterModel::DecodeRegisterAddedResponse(pb_istream_t *stream) {
  memset(&_RegisterAdded, 0, sizeof(_RegisterAdded));
  memset(_device_identifier, 0, sizeof(_device_identifier));
  
  // Set up the callback for decoding the device_identifier
  _RegisterAdded.device_identifier.funcs.decode = &decode_device_identifier_callback;
  _RegisterAdded.device_identifier.arg = _device_identifier;
  
  return pb_decode(stream, register_v1_gpio_RegisterAdded_fields, &_RegisterAdded);
}

/*!
    @brief  Parses the fields of a RegisterAdded message.
*/
void RegisterModel::ParseRegisterAddedResponse() {
  _pin_cnt_digital = _RegisterAdded.pin_cnt_digital;
  _pin_cnt_analog = _RegisterAdded.pin_cnt_analog;
}

/*!
    @brief  Gets the RegisterAdd message
    @returns RegisterAdd message.
*/
register_v1_gpio_RegisterAdd *RegisterModel::getRegisterAddRequest() {
  return &_RegisterAdd;
}

/*!
    @brief  Gets the device identifier from the response
    @returns Device identifier string.
*/
const char *RegisterModel::getDeviceIdentifier() {
  return _device_identifier;
}

/*!
    @brief  Gets the digital pin count from the response
    @returns Number of digital pins.
*/
uint32_t RegisterModel::getDigitalPinCount() {
  return _pin_cnt_digital;
}

/*!
    @brief  Gets the analog pin count from the response
    @returns Number of analog pins.
*/
uint32_t RegisterModel::getAnalogPinCount() {
  return _pin_cnt_analog;
}

/*!
    @brief  Callback function for encoding device_identifier string
    @param  stream
            Output stream.
    @param  field
            Field being encoded.
    @param  arg
            Pointer to the string data.
    @returns True if encoding was successful.
*/
bool RegisterModel::encode_device_identifier_callback(pb_ostream_t *stream,
                                                     const pb_field_t *field,
                                                     void *const *arg) {
  const char *str = (const char *)*arg;
  if (!pb_encode_tag_for_field(stream, field))
    return false;
  
  return pb_encode_string(stream, (uint8_t *)str, strlen(str));
}

/*!
    @brief  Callback function for decoding device_identifier string
    @param  stream
            Input stream.
    @param  field
            Field being decoded.
    @param  arg
            Pointer to store the string data.
    @returns True if decoding was successful.
*/
bool RegisterModel::decode_device_identifier_callback(pb_istream_t *stream,
                                                     const pb_field_t *field,
                                                     void **arg) {
  char *dest = (char *)*arg;
  size_t max_size = 128; // Match the buffer size in the class
  
  if (stream->bytes_left > max_size - 1)
    return false;
  
  if (!pb_read(stream, (uint8_t *)dest, stream->bytes_left))
    return false;
  
  dest[stream->bytes_left] = '\0';
  return true;
}