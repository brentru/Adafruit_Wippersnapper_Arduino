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
#include "protos/gpio.pb.h"
#include <vector>

class Wippersnapper_V2;


class DigitalIOModel;    // Forward declaration
class DigitalIOHardware; // Forward declaration

/*!
    @brief  Represents a configured GPIO pin tracked by the controller.
*/
typedef struct {
  uint8_t pin_name;                           ///< Pin number (no D/A prefix)
  esmp_v1_gpio_GPIODirection pin_direction;   ///< Pin direction
  esmp_v1_gpio_GPIOSampleMode sample_mode;    ///< Sample mode for inputs
  bool pin_value;                             ///< Current pin value
  unsigned long pin_period;                   ///< Poll period (ms) for POLL
  unsigned long prv_pin_time;                 ///< Last poll time (ms)
  bool prv_pin_value;                         ///< Previous sampled value
} DigitalIOPin;

/*!
    @brief  Routes messages using the digitalio.proto API to the
            appropriate hardware and model classes, controls and tracks
            the state of the hardware's digital I/O pins.
*/
class DigitalIOController {
public:
  DigitalIOController();
  ~DigitalIOController();
  bool Handle_GPIOAdd(const esmp_v1_gpio_GPIOAdd *msg);
  bool Handle_GPIOWrite(const esmp_v1_gpio_GPIOWrite *msg);
  void SetMaxDigitalPins(uint8_t max_digital_pins);
  void Update();

private:
  int GetPinIdx(uint8_t pin_name);
  bool PublishGPIOEvent(uint8_t pin_name, bool value);
  DigitalIOModel *_dio_model;
  DigitalIOHardware *_dio_hardware;
  uint8_t _max_digitalio_pins;
  std::vector<DigitalIOPin> _digitalio_pins;
private:

};
extern Wippersnapper_V2 WsV2; ///< Wippersnapper V2 instance
#endif                        // WS_DIGITALIO_CONTROLLER_H
