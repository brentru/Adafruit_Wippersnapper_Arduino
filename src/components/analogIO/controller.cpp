/*!
 * @file src/components/analogIO/controller.cpp
 *
 * Controller for the analogio.proto API
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Copyright (c) Brent Rubell 2024-2025 for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */
#include "controller.h"
#include <cstdlib>

namespace {

/*!
    @brief  Resolves an Ax index to the board's hardware pin constant.
    @param  analog_pin_name
            The numeric analog pin index from Ax (for example, 0 for A0).
    @param  hardware_pin
            Output pointer to resolved hardware pin.
    @return True if the mapping exists on this board.
*/
bool ResolveAnalogHardwarePin(uint8_t analog_pin_name, uint8_t *hardware_pin) {
  if (!hardware_pin) {
    return false;
  }

#if defined(ARDUINO_ARCH_ESP32)
  switch (analog_pin_name) {
  case 0:
    *hardware_pin = A0;
    return true;
  case 1:
    *hardware_pin = A1;
    return true;
  case 2:
    *hardware_pin = A2;
    return true;
  case 3:
    *hardware_pin = A3;
    return true;
  case 4:
    *hardware_pin = A4;
    return true;
  case 5:
    *hardware_pin = A5;
    return true;
  default:
    break;
  }
#else
  // Non-ESP32 boards commonly expose analog inputs as numeric aliases.
  *hardware_pin = analog_pin_name;
  return true;
#endif
  return false;
}

/*!
    @brief  Parses a pin label and resolves hardware pin.
    @param  pin_label
            Pin string from protobuf, expected as Ax or Dx.
    @param  logical_pin_name
            Parsed numeric pin name (x).
    @param  hardware_pin
            Resolved hardware pin used by Arduino APIs.
    @return True if parsing and resolution succeeded.
*/
bool ParseAndResolvePin(const char *pin_label, uint8_t *logical_pin_name,
                        uint8_t *hardware_pin) {
  if (!pin_label || !logical_pin_name || !hardware_pin || pin_label[0] == '\0' ||
      pin_label[1] == '\0') {
    return false;
  }

  uint8_t pin_name = atoi(pin_label + 1);
  *logical_pin_name = pin_name;

  if (pin_label[0] == 'D' || pin_label[0] == 'd') {
    *hardware_pin = pin_name;
    return true;
  }

  if (pin_label[0] == 'A' || pin_label[0] == 'a') {
    if (ResolveAnalogHardwarePin(pin_name, hardware_pin)) {
      return true;
    }
    // Fallback instead of hard-failing add/remove on unknown Ax mapping.
    *hardware_pin = pin_name;
    return true;
  }

  return false;
}

} // namespace

/*!
    @brief  AnalogIO controller constructor
*/
AnalogIOController::AnalogIOController() {
  _aio_model = new AnalogIOModel();
  _aio_hardware = new AnalogIOHardware();
}

/*!
    @brief  AnalogIO controller destructor
*/
AnalogIOController::~AnalogIOController() {
  delete _aio_model;
  delete _aio_hardware;
}

/*!
    @brief  Gets the index of an analog pin.
    @param  pin_name
            The pin number (no D/A prefix).
    @return Index of the pin in the vector, or -1 if not found.
*/
int AnalogIOController::GetPinIdx(uint8_t pin_name) {
  for (int i = 0; i < _analogio_pins.size(); i++) {
    if (_analogio_pins[i].pin_name == pin_name) {
      return i;
    }
  }
  return -1;
}

/*!
    @brief  Gets the index of an analog pin by hardware pin number.
    @param  hardware_pin
            The board pin used for analogRead/pinMode.
    @return Index of the pin in the vector, or -1 if not found.
*/
int AnalogIOController::GetPinIdxByHardwarePin(uint8_t hardware_pin) {
  for (int i = 0; i < _analogio_pins.size(); i++) {
    if (_analogio_pins[i].hardware_pin == hardware_pin) {
      return i;
    }
  }
  return -1;
}

/*!
    @brief  Handles an AnalogInAdd message and configures the pin.
    @param  msg
            The AnalogInAdd message.
    @return True if the pin was configured successfully.
*/
bool AnalogIOController::Handle_AnalogInAdd(
    const esmp_v1_analogin_AnalogInAdd *msg) {
  if (!msg) {
    WS_DEBUG_PRINTLN("[analogio] ERROR: AnalogInAdd message is null!");
    return false;
  }

  WS_DEBUG_PRINT("[analogio] RX AnalogInAdd @");
  WS_DEBUG_PRINTLN(millis());
  WS_DEBUG_PRINT("[analogio]   pin: ");
  WS_DEBUG_PRINTLN(msg->pin_name);
  WS_DEBUG_PRINT("[analogio]   poll_period_s: ");
  WS_DEBUG_PRINTLN(msg->sample_mode_poll_period);

  uint8_t pin_name = 0;
  uint8_t hardware_pin = 0;
  if (!ParseAndResolvePin(msg->pin_name, &pin_name, &hardware_pin)) {
    WS_DEBUG_PRINTLN("[analogio] ERROR: Invalid analog pin name!");
    return false;
  }

  int pin_idx = GetPinIdx(pin_name);
  if (pin_idx == -1) {
    pin_idx = GetPinIdxByHardwarePin(hardware_pin);
  }
  if (pin_idx != -1) {
    _aio_hardware->deinit(_analogio_pins[pin_idx].hardware_pin);
    _analogio_pins.erase(_analogio_pins.begin() + pin_idx);
  }

  if (!_aio_hardware->ConfigurePin(hardware_pin)) {
    WS_DEBUG_PRINTLN("[analogio] ERROR: Failed to configure analog pin!");
    return false;
  }

  unsigned long poll_period_ms =
      (unsigned long)(msg->sample_mode_poll_period * 1000.0f);
  if (poll_period_ms == 0) {
    poll_period_ms = 1;
  }

  AnalogIOPin new_pin = {
      .pin_name = pin_name,
      .hardware_pin = hardware_pin,
      .pin_period = poll_period_ms,
      .prv_pin_time = 0,
      .pin_value = 0,
      .prv_pin_value = 0,
      .has_sampled = false};
  _analogio_pins.push_back(new_pin);

  WS_DEBUG_PRINTLN("[analogio] Added new pin:");
  WS_DEBUG_PRINT("Pin Name: ");
  WS_DEBUG_PRINTLN(new_pin.pin_name);
  WS_DEBUG_PRINT("Hardware Pin: ");
  WS_DEBUG_PRINTLN(new_pin.hardware_pin);
  WS_DEBUG_PRINT("Period: ");
  WS_DEBUG_PRINTLN((double)new_pin.pin_period);

  return true;
}

/*!
    @brief  Handles an AnalogInRemove message and deinitializes the pin.
    @param  msg
            The AnalogInRemove message.
    @return True if the pin was removed.
*/
bool AnalogIOController::Handle_AnalogInRemove(
    const esmp_v1_analogin_AnalogInRemove *msg) {
  if (!msg) {
    WS_DEBUG_PRINTLN("[analogio] ERROR: AnalogInRemove message is null!");
    return false;
  }

  WS_DEBUG_PRINT("[analogio] RX AnalogInRemove @");
  WS_DEBUG_PRINTLN(millis());
  WS_DEBUG_PRINT("[analogio]   pin: ");
  WS_DEBUG_PRINTLN(msg->pin_name);

  uint8_t pin_name = 0;
  uint8_t hardware_pin = 0;
  if (!ParseAndResolvePin(msg->pin_name, &pin_name, &hardware_pin)) {
    WS_DEBUG_PRINTLN("[analogio] ERROR: Invalid analog pin name!");
    return false;
  }

  int pin_idx = GetPinIdx(pin_name);
  if (pin_idx == -1) {
    pin_idx = GetPinIdxByHardwarePin(hardware_pin);
  }
  if (pin_idx == -1) {
    WS_DEBUG_PRINT("[analogio] NOTE: AnalogInRemove pin not found (logical A");
    WS_DEBUG_PRINT(pin_name);
    WS_DEBUG_PRINT(", hardware ");
    WS_DEBUG_PRINT(hardware_pin);
    WS_DEBUG_PRINTLN("), ignoring");
    return true;
  }

  _aio_hardware->deinit(_analogio_pins[pin_idx].hardware_pin);
  _analogio_pins.erase(_analogio_pins.begin() + pin_idx);
  WS_DEBUG_PRINT("[analogio] Removed pin A");
  WS_DEBUG_PRINTLN(pin_name);
  return true;
}

/*!
    @brief  Publishes an AnalogInEvent to the broker.
    @param  pin_name
            The numeric pin identifier.
    @param  value
            The latest analog value.
    @return True if event was published.
*/
bool AnalogIOController::PublishAnalogInEvent(uint8_t pin_name, float value) {
  esmp_v1_analogin_AnalogInEvent analog_event =
      esmp_v1_analogin_AnalogInEvent_init_default;
  if (!_aio_model->PopulateAnalogInEvent(&analog_event, pin_name, value)) {
    return false;
  }

  WS_DEBUG_PRINT("[analogio] Publishing AnalogInEvent for A");
  WS_DEBUG_PRINT(pin_name);
  WS_DEBUG_PRINT(" = ");
  WS_DEBUG_PRINTLN(value);

  return WsV2.PublishSignalResponse(esmp_v1_SignalResponse_analog_in_event_tag,
                                    &analog_event);
}

/*!
    @brief  Updates analog pins and publishes samples at each timer interval.
*/
void AnalogIOController::Update() {
  if (_analogio_pins.empty()) {
    return;
  }

  unsigned long now = millis();
  for (size_t i = 0; i < _analogio_pins.size(); i++) {
    AnalogIOPin &pin = _analogio_pins[i];
    if ((unsigned long)(now - pin.prv_pin_time) < pin.pin_period) {
      continue;
    }

    pin.prv_pin_time = now;
    float current_value = _aio_hardware->GetValue(pin.hardware_pin);
    pin.pin_value = current_value;
    pin.prv_pin_value = current_value;
    pin.has_sampled = true;
    PublishAnalogInEvent(pin.pin_name, current_value);
  }
}
