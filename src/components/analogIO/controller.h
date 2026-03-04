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
#include "protos/analogin.pb.h"
#include <vector>

class Wippersnapper_V2; ///< Forward declaration
class AnalogIOModel;    ///< Forward declaration
class AnalogIOHardware; ///< Forward declaration

/*!
    @brief  Represents a configured analog pin tracked by the controller.
*/
typedef struct {
  uint8_t pin_name;            ///< Pin number (no D/A prefix)
  uint8_t hardware_pin;        ///< Resolved hardware pin for analogRead/pinMode
  unsigned long pin_period;    ///< Sample period in milliseconds
  unsigned long prv_pin_time;  ///< Last sample time in milliseconds
  float pin_value;             ///< Most recent sampled value
  float prv_pin_value;         ///< Previous sampled value
  bool has_sampled;            ///< True if at least one sample has been taken
} AnalogIOPin;

/*!
    @brief  Routes messages using the analogio.proto API to the
            appropriate hardware and model classes, controls and tracks
            the state of the hardware's digital I/O pins.
*/
class AnalogIOController {
public:
  AnalogIOController();
  ~AnalogIOController();
  bool Handle_AnalogInAdd(const esmp_v1_analogin_AnalogInAdd *msg);
  bool Handle_AnalogInRemove(const esmp_v1_analogin_AnalogInRemove *msg);
  void Update();

private:
  int GetPinIdx(uint8_t pin_name);
  int GetPinIdxByHardwarePin(uint8_t hardware_pin);
  bool PublishAnalogInEvent(uint8_t pin_name, float value);
  AnalogIOModel *_aio_model;
  AnalogIOHardware *_aio_hardware;
  std::vector<AnalogIOPin> _analogio_pins;
};
extern Wippersnapper_V2 WsV2; ///< Wippersnapper V2 instance
#endif                        // WS_ANALOGIO_CONTROLLER_H
