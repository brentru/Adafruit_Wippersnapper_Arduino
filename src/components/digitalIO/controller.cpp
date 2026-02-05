/*!
 * @file src/components/digitalIO/controller.cpp
 *
 * Controller for the digitalio.proto API
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
#include "controller.h"
#include "components/statusLED/Wippersnapper_StatusLED.h"
#include <cstdlib>
#include <cstdio>

/*!
    @brief  DigitalIOController constructor
*/
DigitalIOController::DigitalIOController() {
  _dio_model = new DigitalIOModel();
  _dio_hardware = new DigitalIOHardware();
  // Set the default maximum number of digital pins to 0
  SetMaxDigitalPins(0);
}

/*!
    @brief  DigitalIOController destructor
*/
DigitalIOController::~DigitalIOController() {
  delete _dio_model;
  delete _dio_hardware;
}

/*!
    @brief  Set the maximum number of digital pins
    @param  max_digital_pins
            The maximum number of digital pins
*/
void DigitalIOController::SetMaxDigitalPins(uint8_t max_digital_pins) {
  _max_digitalio_pins = max_digital_pins;
}

/*!
    @brief  Get the index of a digital pin
    @param  pin_name
            The pin's name (integer value).
    @return The index of the digital pin, or -1 if not found.
*/
int DigitalIOController::GetPinIdx(uint8_t pin_name) {
  for (int i = 0; i < _digitalio_pins.size(); i++) {
    if (_digitalio_pins[i].pin_name == pin_name) {
      return i;
    }
  }
  return -1;
}

/*!
    @brief  Handles a GPIOAdd message and configures the pin.
    @param  msg
            The GPIOAdd message to process.
    @return True if the pin was successfully configured, False otherwise.
*/
bool DigitalIOController::Handle_GPIOAdd(const esmp_v1_gpio_GPIOAdd *msg) {
  if (!msg) {
    WS_DEBUG_PRINTLN("[digitalio] ERROR: GPIOAdd message is null!");
    return false;
  }

  WS_DEBUG_PRINT("[digitalio] RX GPIOAdd @");
  WS_DEBUG_PRINTLN(millis());
  WS_DEBUG_PRINT("[digitalio]   pin: ");
  WS_DEBUG_PRINTLN(msg->pin_name);
  WS_DEBUG_PRINT("[digitalio]   direction: ");
  WS_DEBUG_PRINTLN(msg->direction);
  WS_DEBUG_PRINT("[digitalio]   sample_mode: ");
  WS_DEBUG_PRINTLN(msg->sample_mode);
  WS_DEBUG_PRINT("[digitalio]   poll_period_s: ");
  WS_DEBUG_PRINTLN(msg->sample_mode_poll_period);
  // Strip the D/A prefix off the pin name and convert to a uint8_t pin number
  uint8_t pin_name = atoi(msg->pin_name + 1);

  // Check if the provided pin is also the status LED pin
  if (_dio_hardware->IsStatusLEDPin(pin_name))
    ReleaseStatusPixel();

  // Deinit the pin if it's already in use
  if (GetPinIdx(pin_name) != -1)
    _dio_hardware->deinit(pin_name);

  // Attempt to configure the pin
  if (!_dio_hardware->ConfigurePin(pin_name, msg->direction)) {
    WS_DEBUG_PRINTLN(
        "[digitalio] ERROR: Pin provided an invalid protobuf direction!");
    return false;
  }

  bool current_value = _dio_hardware->GetValue(pin_name);
  // Create the digital pin and add it to the vector
  DigitalIOPin new_pin = {
      .pin_name = pin_name,
      .pin_direction = msg->direction,
      .sample_mode = msg->sample_mode,
      .pin_value = current_value,
      .pin_period = (unsigned long)(msg->sample_mode_poll_period * 1000.0f),
      .prv_pin_time = 0, // Set to 0 so timer pins trigger immediately
      .prv_pin_value = current_value};
  _digitalio_pins.push_back(new_pin);

  // Print out the pin's details
  WS_DEBUG_PRINTLN("[digitalio] Added new pin:");
  WS_DEBUG_PRINT("Pin Name: ");
  WS_DEBUG_PRINTLN(new_pin.pin_name);
  WS_DEBUG_PRINT("Period: ");
  WS_DEBUG_PRINTLN(new_pin.pin_period);
  WS_DEBUG_PRINT("Sample Mode: ");
  WS_DEBUG_PRINTLN(new_pin.sample_mode);
  WS_DEBUG_PRINT("Direction: ");
  WS_DEBUG_PRINTLN(new_pin.pin_direction);

  return true;
}

/*!
    @brief  Handles a GPIOWrite message and writes the value to hardware.
    @param  msg
            The GPIOWrite message to process.
    @return True if the pin was successfully written, False otherwise.
*/
bool DigitalIOController::Handle_GPIOWrite(const esmp_v1_gpio_GPIOWrite *msg) {
  if (!msg) {
    WS_DEBUG_PRINTLN("[digitalio] ERROR: GPIOWrite message is null!");
    return false;
  }

  WS_DEBUG_PRINT("[digitalio] RX GPIOWrite @");
  WS_DEBUG_PRINTLN(millis());
  WS_DEBUG_PRINT("[digitalio]   pin: ");
  WS_DEBUG_PRINTLN(msg->pin_name);
  WS_DEBUG_PRINT("[digitalio]   value: ");
  WS_DEBUG_PRINTLN(msg->value);

  uint8_t pin_name = atoi(msg->pin_name + 1);
  int pin_idx = GetPinIdx(pin_name);
  if (pin_idx == -1) {
    WS_DEBUG_PRINTLN(
        "[digitalio] ERROR: GPIOWrite received for unknown pin, dropping");
    return false;
  }

  DigitalIOPin &pin = _digitalio_pins[pin_idx];
  if (pin.pin_direction != esmp_v1_gpio_GPIODirection_GPIO_DIRECTION_OUTPUT) {
    WS_DEBUG_PRINTLN(
        "[digitalio] ERROR: GPIOWrite targeted a non-output pin, dropping");
    return false;
  }

  // Avoid redundant writes but still log the request
  if (pin.pin_value == msg->value) {
    WS_DEBUG_PRINTLN("[digitalio] NOTE: GPIOWrite value unchanged, skipping");
    return true;
  }

  WS_DEBUG_PRINT("[digitalio] Writing pin D");
  WS_DEBUG_PRINT(pin.pin_name);
  WS_DEBUG_PRINT(" = ");
  WS_DEBUG_PRINT(msg->value);
  WS_DEBUG_PRINT(" @");
  WS_DEBUG_PRINTLN(millis());

  _dio_hardware->SetValue(pin.pin_name, msg->value);
  WS_DEBUG_PRINT("[digitalio] WROTE pin D");
  WS_DEBUG_PRINT(pin.pin_name);
  WS_DEBUG_PRINT(" = ");
  WS_DEBUG_PRINT(msg->value);
  WS_DEBUG_PRINT(" @");
  WS_DEBUG_PRINTLN(millis());
  pin.prv_pin_value = pin.pin_value;
  pin.pin_value = msg->value;
  return true;
}

/*!
    @brief  Publishes a GPIOEvent message to the broker.
    @param  pin_name
            The pin number (no D/A prefix).
    @param  value
            The pin's current value.
    @return True if the event was published successfully, False otherwise.
*/
bool DigitalIOController::PublishGPIOEvent(uint8_t pin_name, bool value) {
  esmp_v1_gpio_GPIOEvent gpio_event = esmp_v1_gpio_GPIOEvent_init_default;
  snprintf(gpio_event.pin_name, sizeof(gpio_event.pin_name), "D%u", pin_name);
  gpio_event.value = value;

  WS_DEBUG_PRINT("[digitalio] Publishing GPIOEvent for D");
  WS_DEBUG_PRINT(pin_name);
  WS_DEBUG_PRINT(" = ");
  WS_DEBUG_PRINT(value);
  WS_DEBUG_PRINT(" @");
  WS_DEBUG_PRINTLN(millis());

  return WsV2.PublishSignalResponse(esmp_v1_SignalResponse_gpio_event_tag,
                                    &gpio_event);
}

/*!
    @brief  Updates digital input pins and publishes events as needed.
*/
void DigitalIOController::Update() {
  if (_digitalio_pins.empty()) {
    return;
  }

  unsigned long now = millis();
  for (size_t i = 0; i < _digitalio_pins.size(); i++) {
    DigitalIOPin &pin = _digitalio_pins[i];

    if (pin.pin_direction ==
            esmp_v1_gpio_GPIODirection_GPIO_DIRECTION_OUTPUT) {
      continue; // Only sample input pins
    }

    bool current_value = _dio_hardware->GetValue(pin.pin_name);

    if (pin.sample_mode ==
        esmp_v1_gpio_GPIOSampleMode_GPIO_SAMPLE_MODE_EVENT) {
      if (current_value != pin.prv_pin_value) {
        WS_DEBUG_PRINT("[digitalio] Event detected on D");
        WS_DEBUG_PRINT(pin.pin_name);
        WS_DEBUG_PRINT(" = ");
        WS_DEBUG_PRINT(current_value);
        WS_DEBUG_PRINT(" @");
        WS_DEBUG_PRINTLN(now);
        pin.prv_pin_value = current_value;
        pin.pin_value = current_value;
        PublishGPIOEvent(pin.pin_name, current_value);
      }
    } else if (pin.sample_mode ==
               esmp_v1_gpio_GPIOSampleMode_GPIO_SAMPLE_MODE_POLL) {
      if (pin.pin_period == 0) {
        continue;
      }
      if ((unsigned long)(now - pin.prv_pin_time) >= pin.pin_period) {
        pin.prv_pin_time = now;
        pin.prv_pin_value = current_value;
        pin.pin_value = current_value;
        WS_DEBUG_PRINT("[digitalio] Poll sample on D");
        WS_DEBUG_PRINT(pin.pin_name);
        WS_DEBUG_PRINT(" = ");
        WS_DEBUG_PRINT(current_value);
        WS_DEBUG_PRINT(" @");
        WS_DEBUG_PRINTLN(now);
        PublishGPIOEvent(pin.pin_name, current_value);
      }
    }
  }
}
