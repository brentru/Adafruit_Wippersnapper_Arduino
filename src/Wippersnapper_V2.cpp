/*!
 * @file Wippersnapper_v2.cpp
 *
 * @mainpage Adafruit Wippersnapper Wrapper
 *
 * @section intro_sec Introduction
 *
 * This is the documentation for Adafruit's Wippersnapper wrapper for the
 * Arduino platform.  It is designed specifically to work with the
 * Adafruit IO+ Wippersnapper IoT platform.
 *
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * @section dependencies Dependencies
 *
 * This library depends on <a
 * href="https://github.com/adafruit/Adafruit_Sensor"> Adafruit_Sensor</a> being
 * present on your system. Please make sure you have installed the latest
 * version before using this library.
 *
 * @section author Author
 *
 * Copyright (c) Brent Rubell 2020-2025 for Adafruit Industries.
 *
 * @section license License
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "Wippersnapper_V2.h"

Wippersnapper_V2 WsV2;

Wippersnapper_V2::Wippersnapper_V2() {
  // TODO: Scope out how much of this we can remove
  // and what should be here (if we are wrong!)
  _mqttV2 = 0; // MQTT Client object

  // Reserved MQTT Topics
  _topicError = 0;
  _topicThrottle = 0;
  _subscribeError = 0;
  _subscribeThrottle = 0;

  // Initialize model classes
  //WsV2.sensorModel = new SensorModel();
  WsV2.register_model = new RegisterModel();

  // Initialize controller classes
  WsV2.digital_io_controller = new DigitalIOController();
  WsV2.analogio_controller = new AnalogIOController();
  //WsV2._i2c_controller = new I2cController();
};

/*!
    @brief    Wippersnapper_V2 destructor
*/
Wippersnapper_V2::~Wippersnapper_V2() {}

/*!
    @brief    Provisions a WipperSnapper device with its network
              configuration and Adafruit IO credentials.
*/
void Wippersnapper_V2::provision() {
  // Obtain device's MAC address
  getMacAddr();

  // Initialize the status LED for signaling FS errors
  initStatusLED();

// Initialize the filesystem
#ifdef USE_TINYUSB
  _fileSystemV2 = new Wippersnapper_FS();
#elif defined(USE_LITTLEFS)
  _littleFSV2 = new WipperSnapper_LittleFS();
#endif

#ifdef USE_TINYUSB
  _fileSystemV2->parseSecrets();
#elif defined(USE_LITTLEFS)
  _littleFSV2->parseSecrets();
#else
  check_valid_ssid(); // non-fs-backed, sets global credentials within network
                      // iface
#endif
  // Set the status pixel's brightness
  setStatusLEDBrightness(WsV2._configV2.status_pixel_brightness);
  // Set device's wireless credentials
  set_ssid_pass();

}

/*!
    @brief    Disconnects from Adafruit IO+ Wippersnapper_V2.
*/
void Wippersnapper_V2::disconnect() { _disconnect(); }

// Concrete class definition for abstract classes

/*!
    @brief    Connects to wireless network.
*/
void Wippersnapper_V2::_connect() {
  WS_DEBUG_PRINTLN("Wippersnapper_V2::_connect()");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
}

/*!
    @brief    Disconnect Wippersnapper MQTT session and network.
*/
void Wippersnapper_V2::_disconnect() {
  WS_DEBUG_PRINTLN("WIppersnapper_V2::_disconnect");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
}

/*!
    @brief    Sets the network interface's unique identifer, typically the
              MAC address.
*/
void Wippersnapper_V2::getMacAddr() {
  WS_DEBUG_PRINTLN("Wippersnapper_V2::getMacAddr");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
}

/*!
    @brief    Gets the network's RSSI.
    @return   int32_t RSSI value, 0 to 255, in dB
*/
int32_t Wippersnapper_V2::getRSSI() {
  WS_DEBUG_PRINTLN("Wiippersnapper_V2::getRSSI");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
  return 0;
}

/*!
    @brief    Sets up the MQTT client session.
    @param    clientID
              A unique client identifier string.
*/
void Wippersnapper_V2::setupMQTTClient(const char * /*clientID*/) {
  WS_DEBUG_PRINTLN("Wippersnapper_V2::setupMQTTClient");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
}

/*!
    @brief    Returns the network's connection status
    @returns  Network status as ws_status_t.
*/
ws_status_t Wippersnapper_V2::networkStatus() {
  WS_DEBUG_PRINTLN("Wippersnapper_V2::networkStatus");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
  return WS_IDLE;
}

/*!
    @brief    Sets the device's wireless network credentials.
    @param    ssid
              Your wireless network's SSID
    @param    ssidPassword
              Your wireless network's password.
*/
void Wippersnapper_V2::set_ssid_pass(const char * /*ssid*/,
                                     const char * /*ssidPassword*/) {
  WS_DEBUG_PRINTLN("Wippersnapper_V2::set_ssid_pass");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
}

/*!
    @brief    Sets the device's wireless network credentials from the
              secrets.json configuration file.
*/
void Wippersnapper_V2::set_ssid_pass() {
  WS_DEBUG_PRINTLN("Wippersnapper_V2::set_ssid_pass");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
}

/*!
@brief   Performs a scan of local WiFi networks.
@returns True if `_network_ssid` is found, False otherwise.
*/
bool Wippersnapper_V2::check_valid_ssid() {
  WS_DEBUG_PRINTLN("Wippersnapper_V2::check_valid_ssid");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
  return false;
}

/*!
    @brief    Configures the device's Adafruit IO credentials. This method
              should be used only if filesystem-backed provisioning is
              not avaliable.
*/
void Wippersnapper_V2::set_user_key() {
  WS_DEBUG_PRINTLN("Wippersnapper_V2::set_user_key");
  WS_DEBUG_PRINTLN("ERROR: Please define a network interface!");
}

/*!
    @brief    Creates, fills, encodes and publishes a checkin request
              message to the broker.
    @returns  True if the Checkin request message published successfully,
              False otherwise.
*/
bool Wippersnapper_V2::CreateRegisterRequest() {
  WS_DEBUG_PRINT("Creating the Register message with UID: ");
  WS_DEBUG_PRINTLN(WsV2.sUIDV2);
  WsV2.register_model->CreateRegisterAddRequest(WsV2.sUIDV2);
  WS_DEBUG_PRINTLN("Created!");

  WS_DEBUG_PRINT("Encoding the Register message...");
  if (!WsV2.register_model->EncodeRegisterAddRequest())
    return false;
  WS_DEBUG_PRINTLN("Encoded!");

  WS_DEBUG_PRINT("Publishing Register Request...");
  if (!PublishSignalResponse(esmp_v1_SignalRequest_register_add_tag, WsV2.register_model->getRegisterAddRequest()))
    return false;
  WS_DEBUG_PRINTLN("Published!");

  return true;
}

/*!
    @brief    Handles a Register Response message and initializes the
              device's GPIO classes.
    @param    stream
              Incoming data stream from buffer.
    @returns  True if Register Response decoded and parsed successfully,
              False otherwise.
*/
bool handleRegisterResponse(pb_istream_t *stream) {
  // Decode the Register Response message
  if (!WsV2.register_model->DecodeRegisterAddedResponse(stream)) {
    WS_DEBUG_PRINTLN("ERROR: Unable to decode Register Response message");
    return false;
  }

  // Parse the response message
  WsV2.register_model->ParseRegisterAddedResponse();

  // Configure GPIO classes based on register response message
  // TODO! Add these back!
  // WsV2.digital_io_controller->SetMaxDigitalPins(WsV2.register_model->getDigitalPinCount());

  //WsV2.analogio_controller->SetRefVoltage(3.3);
  // WsV2.analogio_controller->SetTotalAnalogPins(WsV2.register_model->getAnalogPinCount());

  // set glob flag so we don't keep the polling loop open
  WsV2.got_register_response = true;
  return true;
}

/*!
    @brief    Handles a GPIOAdd message from the broker.
    @param    stream
              Incoming data stream from buffer.
    @returns  True if GPIOAdd decoded and processed successfully,
              False otherwise.
*/
bool handleGPIOAdd(pb_istream_t *stream) {
  esmp_v1_gpio_GPIOAdd gpio_add = esmp_v1_gpio_GPIOAdd_init_default;
  if (!ws_pb_decode(stream, esmp_v1_gpio_GPIOAdd_fields, &gpio_add)) {
    WS_DEBUG_PRINTLN("[digitalio] ERROR: Unable to decode GPIOAdd message!");
    return false;
  }

  if (!WsV2.digital_io_controller->Handle_GPIOAdd(&gpio_add)) {
    WS_DEBUG_PRINTLN("[digitalio] ERROR: Unable to handle GPIOAdd message!");
    return false;
  }

  return true;
}

/*!
    @brief    Handles a GPIOWrite message from the broker.
    @param    stream
              Incoming data stream from buffer.
    @returns  True if GPIOWrite decoded and processed successfully,
              False otherwise.
*/
bool handleGPIOWrite(pb_istream_t *stream) {
  esmp_v1_gpio_GPIOWrite gpio_write = esmp_v1_gpio_GPIOWrite_init_default;
  if (!ws_pb_decode(stream, esmp_v1_gpio_GPIOWrite_fields, &gpio_write)) {
    WS_DEBUG_PRINTLN("[digitalio] ERROR: Unable to decode GPIOWrite message!");
    return false;
  }

  if (!WsV2.digital_io_controller->Handle_GPIOWrite(&gpio_write)) {
    WS_DEBUG_PRINTLN("[digitalio] ERROR: Unable to handle GPIOWrite message!");
    return false;
  }

  return true;
}

// Decoders //

/*!
    @brief    Decodes a BrokerToDevice message and executes the asscoiated
   callback.
    @param    stream
              Incoming data stream from buffer.
    @param    field
              Protobuf message's tag type.
    @param    arg
              Optional arguments from decoder calling function.
    @returns  True if decoded and executed successfully, False otherwise.
*/
bool cbDecodeBrokerToDevice(pb_istream_t *stream, const pb_field_t *field,
                            void **arg) {
  (void)arg; // marking unused parameters to avoid compiler warning

  switch (field->tag) {
  case esmp_v1_SignalRequest_register_add_tag:
    WS_DEBUG_PRINTLN("-> Register Add Request");
    if (!handleRegisterResponse(stream)) {
      return false;
    }
    WS_DEBUG_PRINTLN("Handled!");
    break;
  case esmp_v1_SignalRequest_gpio_add_tag:
    WS_DEBUG_PRINT("[digitalio] -> GPIO Add @");
    WS_DEBUG_PRINTLN(millis());
    if (!handleGPIOAdd(stream)) {
      return false;
    }
    WS_DEBUG_PRINTLN("Handled!");
    break;
  case esmp_v1_SignalRequest_gpio_write_tag:
    WS_DEBUG_PRINT("[digitalio] -> GPIO Write @");
    WS_DEBUG_PRINTLN(millis());
    if (!handleGPIOWrite(stream)) {
      return false;
    }
    WS_DEBUG_PRINTLN("Handled!");
    break;
  default:
    WS_DEBUG_PRINTLN("ERROR: BrokerToDevice message type not found!");
    return false;
  }
  // once this is returned, pb_dec_submessage()
  // decodes the submessage contents.
  return true;
}

/*!
    @brief    Called when client receives a message published across the
                Adafruit IO MQTT /ws-b2d/ "signal topic".
    @param    data
                Data (payload) from MQTT broker.
    @param    len
                Length of data received from MQTT broker.
*/
void cbBrokerToDevice(char *data, uint16_t len) {
  WS_DEBUG_PRINTLN("=> New SignalRequest message!");

  esmp_v1_SignalRequest msg_signal_req =  esmp_v1_SignalRequest_init_default;

  msg_signal_req.cb_payload.funcs.decode = cbDecodeBrokerToDevice;

  // Decode msg_signal
  WS_DEBUG_PRINTLN("Creating input stream...");
  pb_istream_t istream = pb_istream_from_buffer((uint8_t *)data, len);
  WS_DEBUG_PRINTLN("Decoding SignalRequest message...");
  if (!pb_decode(&istream, esmp_v1_SignalRequest_fields, &msg_signal_req)) {
    WS_DEBUG_PRINTLN("ERROR: Unable to decode SignalRequest message!");
    return;
  }
  WS_DEBUG_PRINTLN("Decoded SignalRequest message!");
}

/*!
    @brief    Attempts to generate unique device identifier.
    @returns  True if device identifier generated successfully,
              False otherwise.
*/
bool Wippersnapper_V2::generateDeviceUID() {
  // Generate device unique identifier
  // Set machine_name
  WsV2._boardIdV2 = BOARD_ID;
  // Move the top 3 bytes from the UID
  for (int i = 5; i > 2; i--) {
    WsV2._macAddrV2[6 - 1 - i] = WsV2._macAddrV2[i];
  }
  snprintf(WsV2.sUIDV2, sizeof(WsV2.sUIDV2), "%02d%02d%02d", WsV2._macAddrV2[0],
           WsV2._macAddrV2[1], WsV2._macAddrV2[2]);
  // Conversion to match integer UID sent by createMsgCheckinRequest()
  itoa(atoi(WsV2.sUIDV2), WsV2.sUIDV2, 10);

  // Calculate the length of device and UID strings
  WS_DEBUG_PRINTLN("Calculating device UID length...");
  size_t lenBoardId = strlen(WsV2._boardIdV2);
  size_t lenUID = strlen(WsV2.sUIDV2);
  size_t lenIOWipper = strlen("io-wipper-");
  size_t lenDeviceUID = lenBoardId + lenUID + lenIOWipper + 1;

  // Attempt to allocate memory for the _device_uid
  WS_DEBUG_PRINTLN("Allocating memory for device UID");
#ifdef USE_PSRAM
  _device_uidV2 = (char *)ps_malloc(sizeof(char) * lenDeviceUID);
#else
  _device_uidV2 = (char *)malloc(sizeof(char) * lenDeviceUID);
#endif

  // Check if memory allocation was successful
  if (_device_uidV2 == NULL) {
    WS_DEBUG_PRINTLN("ERROR: Unable to create device uid, Malloc failure");
    return false;
  }

  // Create the device identifier
  snprintf(_device_uidV2, lenDeviceUID, "io-wipper-%s%s", WsV2._boardIdV2,
           WsV2.sUIDV2);
  WS_DEBUG_PRINT("Device UID: ");
  WS_DEBUG_PRINTLN(_device_uidV2);

  return true;
}

/*!
    @brief    Generates device-specific Wippersnapper control topics and
              subscribes to them.
    @returns  True if memory for control topics allocated successfully,
                False otherwise.
*/
bool Wippersnapper_V2::generateMQTTTopics() {
  WS_DEBUG_PRINTLN("Pre-calculating topic lengths...");
  // Calculate length of strings that are are dynamic within the secrets file
  size_t lenUser = strlen(WsV2._configV2.aio_user);
  size_t lenBoardId = strlen(_device_uidV2);
  // Calculate length of static strings
  size_t lenTopicX2x = strlen("/ws-x2x/");
  size_t lenTopicErrorStr = strlen("/errors/");
  size_t lenTopicThrottleStr = strlen("/throttle/");
  // Calculate length of complete topic strings
  // NOTE: We are using "+2" to account for the null terminator and the "/" at
  // the end of the topic
  size_t lenTopicB2d = lenUser + lenTopicX2x + lenBoardId + 2;
  size_t lenTopicD2b = lenUser + lenTopicX2x + lenBoardId + 2;
  size_t lenTopicError = lenUser + lenTopicErrorStr + 2;
  size_t lenTopicThrottle = lenUser + lenTopicThrottleStr + 2;

  // Attempt to allocate memory for the broker-to-device topic
#ifdef USE_PSRAM
  WsV2._topicB2d = (char *)ps_malloc(sizeof(char) * lenTopicB2d);
#else
  WsV2._topicB2d = (char *)malloc(sizeof(char) * lenTopicB2d);
#endif
  // Check if memory allocation was successful
  if (WsV2._topicB2d == NULL)
    return false;
  // Build the broker-to-device topic
  snprintf(WsV2._topicB2d, lenTopicB2d, "%s/ws-b2d/%s/",
           WsV2._configV2.aio_user, _device_uidV2);
  WS_DEBUG_PRINT("Broker-to-device topic: ");
  WS_DEBUG_PRINTLN(WsV2._topicB2d);
  // Subscribe to broker-to-device topic
  _subscribeB2d = new Adafruit_MQTT_Subscribe(WsV2._mqttV2, WsV2._topicB2d, 1);
  WsV2._mqttV2->subscribe(_subscribeB2d);
  _subscribeB2d->setCallback(cbBrokerToDevice);

  // Create global device to broker topic
  // Attempt to allocate memory for the broker-to-device topic
#ifdef USE_PSRAM
  WsV2._topicD2b = (char *)ps_malloc(sizeof(char) * lenTopicD2b);
#else
  WsV2._topicD2b = (char *)malloc(sizeof(char) * lenTopicD2b);
#endif
  // Check if memory allocation was successful
  if (WsV2._topicD2b == NULL)
    return false;
  // Build the broker-to-device topic
  snprintf(WsV2._topicD2b, lenTopicD2b, "%s/ws-d2b/%s/",
           WsV2._configV2.aio_user, _device_uidV2);
  WS_DEBUG_PRINT("Device-to-broker topic: ");
  WS_DEBUG_PRINTLN(WsV2._topicD2b);

  return true;
}

/*!
    @brief    Writes an error message to the serial and the filesystem,
                blinks WS_LED_STATUS_ERROR_RUNTIME pattern and hangs.
    @param    error
              The error message to write to the serial and filesystem.
*/
void Wippersnapper_V2::errorWriteHangV2(const char* error) {
  // Print error
  WS_DEBUG_PRINTLN(error);
#ifdef USE_TINYUSB
  _fileSystemV2->writeToBootOut(error);
  TinyUSBDevice.attach();
  delay(500);
#endif
  // Signal and hang forever
  while (1) {
    WS_DEBUG_PRINTLN("ERROR: Halted execution");
    WS_DEBUG_PRINTLN(error);
    WsV2.feedWDTV2();
    statusLEDBlink(WS_LED_STATUS_ERROR_RUNTIME);
    delay(1000);
  }
}

/*!
    @brief    Checks network and MQTT connectivity. Handles network
              re-connection and mqtt re-establishment.
*/
void Wippersnapper_V2::runNetFSMV2() {
  WsV2.feedWDTV2();
  // Initial state
  fsm_net_t fsmNetwork;
  fsmNetwork = FSM_NET_CHECK_MQTT;
  int maxAttempts;
  while (fsmNetwork != FSM_NET_CONNECTED) {
    switch (fsmNetwork) {
    case FSM_NET_CHECK_MQTT:
      if (WsV2._mqttV2->connected()) {
        // WS_DEBUG_PRINTLN("Connected to Adafruit IO!");
        fsmNetwork = FSM_NET_CONNECTED;
        return;
      }
      fsmNetwork = FSM_NET_CHECK_NETWORK;
      break;
    case FSM_NET_CHECK_NETWORK:
      if (networkStatus() == WS_NET_CONNECTED) {
        WS_DEBUG_PRINTLN("Connected to WiFi!");
        fsmNetwork = FSM_NET_ESTABLISH_MQTT;
        break;
      }
      fsmNetwork = FSM_NET_ESTABLISH_NETWORK;
      break;
    case FSM_NET_ESTABLISH_NETWORK:
      WS_DEBUG_PRINTLN("Establishing network connection...");
      WS_PRINTER.flush();
      // Perform a WiFi scan and check if SSID within
      // secrets.json is within the scanned SSIDs
      WS_DEBUG_PRINT("Performing a WiFi scan for SSID...");
      if (!check_valid_ssid()) {
        haltErrorV2("ERROR: Unable to find WiFi network, rebooting soon...",
                    WS_LED_STATUS_WIFI_CONNECTING);
      }
      // Attempt to connect to wireless network
      maxAttempts = 5;
      while (maxAttempts > 0) {
        // blink before we connect
        statusLEDBlink(WS_LED_STATUS_WIFI_CONNECTING);
        feedWDTV2();
        // attempt to connect
        WS_DEBUG_PRINT("Connecting to WiFi (attempt #");
        WS_DEBUG_PRINT(5 - maxAttempts);
        WS_DEBUG_PRINTLN(")");
        WS_PRINTER.flush();
        feedWDTV2();
        _connect();
        feedWDTV2();
        // did we connect?
        if (networkStatus() == WS_NET_CONNECTED)
          break;
        maxAttempts--;
      }
      // Validate connection
      if (networkStatus() != WS_NET_CONNECTED) {
        WS_DEBUG_PRINTLN("ERROR: Unable to connect to WiFi!");
        haltErrorV2("ERROR: Unable to connect to WiFi, rebooting soon...",
                    WS_LED_STATUS_WIFI_CONNECTING);
      }

      fsmNetwork = FSM_NET_CHECK_NETWORK;
      break;
    case FSM_NET_ESTABLISH_MQTT:
      WsV2._mqttV2->setKeepAliveInterval(WS_KEEPALIVE_INTERVAL_MS / 1000);
      // Attempt to connect
      maxAttempts = 5;
      while (maxAttempts > 0) {
        WS_DEBUG_PRINT("Connecting to AIO MQTT (attempt #");
        WS_DEBUG_PRINT(5 - maxAttempts);
        WS_DEBUG_PRINTLN(")");
        WS_PRINTER.flush();
        WS_DEBUG_PRINT("WiFi Status: ");
        WS_DEBUG_PRINTLN(networkStatus());
        WS_PRINTER.flush();
        feedWDTV2();
        statusLEDBlink(WS_LED_STATUS_MQTT_CONNECTING);
        feedWDTV2();
        int8_t mqttRC = WsV2._mqttV2->connect();
        feedWDTV2();
        if (mqttRC == WS_MQTT_CONNECTED) {
          fsmNetwork = FSM_NET_CHECK_MQTT;
          break;
        }
        WS_DEBUG_PRINT("MQTT Connection Error: ");
        WS_DEBUG_PRINTLN(mqttRC);
        WS_DEBUG_PRINTLN(WsV2._mqttV2->connectErrorString(mqttRC));
        WS_DEBUG_PRINTLN(
            "Unable to connect to Adafruit IO MQTT, retrying in 3 seconds...");
        delay(3000);
        maxAttempts--;
      }
      if (fsmNetwork != FSM_NET_CHECK_MQTT) {
        haltErrorV2(
            "ERROR: Unable to connect to Adafruit.IO MQTT, rebooting soon...",
            WS_LED_STATUS_MQTT_CONNECTING);
      }
      break;
    default:
      break;
    }
  }
}

/*!
    @brief    Prints an error to the serial and halts the hardware until
              the WDT bites.
    @param    error
              The desired error to print to serial.
    @param    ledStatusColor
              The desired color to blink.
    @param    reboot
              If true, the device will reboot after the WDT bites.
              If false, the device will not allow the WDT to bite and
              instead hang indefinitely, holding the WIPPER drive open
*/
void Wippersnapper_V2::haltErrorV2(const char* error, ws_led_status_t ledStatusColor,
                                   bool reboot) {
  WS_DEBUG_PRINT("ERROR ");
  if (reboot) {
    WS_DEBUG_PRINT("[RESET]: ");
  } else {
    WS_DEBUG_PRINT("[HANG]: ");
  }
  WS_DEBUG_PRINTLN(error);
  statusLEDSolid(ledStatusColor);
  for (;;) {
    if (!reboot) {
      WsV2.feedWDTV2(); // Feed the WDT indefinitely to hold the WIPPER drive
                        // open
    } else {
// Let the WDT fail out and reset!
#ifndef ARDUINO_ARCH_ESP8266
      delay(1000);
#else
      // Calls to delay() and yield() feed the ESP8266's
      // hardware and software watchdog timers, delayMicroseconds does not.
      delayMicroseconds(1000000);
#endif
    }
  }
}

/*!
    @brief    Publishes a signal message to the broker.
    @param    which_payload
              The type of signal payload to publish.
    @param    payload
              The payload to publish.
    @returns  True if the signal message published successfully,
              False otherwise.
*/
bool Wippersnapper_V2::PublishSignalResponse(pb_size_t which_payload, void *payload) {

#ifdef DEBUG_PROFILE
  unsigned long total_start_time = micros();
#endif

  size_t szMessageBuf;
  esmp_v1_SignalResponse msg_signal_response = esmp_v1_SignalResponse_init_default;

  // Fill generic signal payload with the payload from the args.
  WS_DEBUG_PRINT("Payload Type: ");
  switch (which_payload) {
  case esmp_v1_SignalResponse_register_added_tag:
    WS_DEBUG_PRINTLN("RegisterAdd");
    msg_signal_response.which_payload = esmp_v1_SignalResponse_register_added_tag;
    msg_signal_response.payload.register_added = *(esmp_v1_register_RegisterAdded *)payload;
    break;
  default:
    WS_DEBUG_PRINTLN("ERROR: Invalid signal payload type, bailing out!");
    return false;
  }

  // Get the encoded size of the signal message
  if (!pb_get_encoded_size(&szMessageBuf,
                           esmp_v1_SignalResponse_fields,
                           &msg_signal_response)) {
    WS_DEBUG_PRINTLN("ERROR: Unable to get encoded size of SignalResponse message, bailing out!");
    return false;
  }

  // Size the message buffer to fit the encoded signal message
  uint8_t msgBuf[szMessageBuf];

  // Encode the signal message
  WS_DEBUG_PRINT("Encoding signal response message...");
  pb_ostream_t stream = pb_ostream_from_buffer(msgBuf, szMessageBuf);
  if (!ws_pb_encode(&stream, esmp_v1_SignalResponse_fields,
                    &msg_signal_response)) {
    WS_DEBUG_PRINTLN(
        "ERROR: Unable to encode signal response message, bailing out!");
    return false;
  }
  WS_DEBUG_PRINTLN("Encoded!");

  // Check that we are still connected
  runNetFSMV2();
  WsV2.feedWDTV2();

#ifdef DEBUG_PROFILE
  unsigned long publish_start_time = micros();
#endif

  // Attempt to publish the signal message to the broker
  WS_DEBUG_PRINT("Publishing signal message to broker...");
#ifdef DEBUG_PROFILE
  WS_DEBUG_PRINT("Message buffer size: ");
  WS_DEBUG_PRINTLN(szMessageBuf);
#endif
  if (!WsV2._mqttV2->publish(WsV2._topicD2b, msgBuf, szMessageBuf, 1)) {
    WS_DEBUG_PRINTLN("ERROR: Failed to publish signal message to broker!");
    return false;
  }
  WS_DEBUG_PRINTLN("Published!");

#ifdef DEBUG_PROFILE
  unsigned long publish_end_time = micros();
  WS_DEBUG_PRINT("Publishing time: ");
  WS_DEBUG_PRINTLN(publish_end_time - publish_start_time);
  unsigned long total_end_time = micros();
  WS_DEBUG_PRINT("Total PublishSignalResponse() execution time: ");
  WS_DEBUG_PRINTLN(total_end_time - total_start_time);
#endif

  return true;
}

/*!
    @brief    Polls for and handles the checkin response
              message from the broker.
*/
void Wippersnapper_V2::PollRegisterResponse() {
  WsV2.got_register_response = false;
  WS_DEBUG_PRINTLN("Waiting for checkin response...");
  // If we don't get a response within WS_WDT_TIMEOUT seconds, the WDT
  // will expire and reset the device
  while (!WsV2.got_register_response) {
    pingBrokerV2(); // Pinging the broker to keep the connection alive
    WsV2._mqttV2->processPackets(10); // Process incoming packets
  }
  WS_DEBUG_PRINTLN("Completed checkin process!");
}

/*!
    @brief  Pings the MQTT broker within the keepalive interval
            to keep the connection alive. Blinks the keepalive LED
            every STATUS_LED_KAT_BLINK_TIME milliseconds.
*/
void Wippersnapper_V2::pingBrokerV2() {
  // ping within keepalive-10% to keep connection open
  if (millis() > (_prv_pingV2 + (WS_KEEPALIVE_INTERVAL_MS -
                                 (WS_KEEPALIVE_INTERVAL_MS * 0.10)))) {
    WS_DEBUG_PRINT("Sending MQTT PING: ");
    if (WsV2._mqttV2->ping()) {
      WS_DEBUG_PRINTLN("SUCCESS!");
    } else {
      WS_DEBUG_PRINTLN("FAILURE! Running network FSM...");
      WsV2._mqttV2->disconnect();
      runNetFSMV2();
    }
    _prv_pingV2 = millis();
    WS_DEBUG_PRINT("WiFi RSSI: ");
    WS_DEBUG_PRINTLN(getRSSI());
  }
  // Blink the status LED to indicate that the device is still alive
  BlinkKATStatus();
}

/*!
    @brief  Blinks the status LED every STATUS_LED_KAT_BLINK_TIME
            milliseconds to indicate that the device is still alive.
*/
void Wippersnapper_V2::BlinkKATStatus() {
  if (millis() > (_prvKATBlinkV2 + STATUS_LED_KAT_BLINK_TIME)) {
    statusLEDBlink(WS_LED_STATUS_KAT);
    _prvKATBlinkV2 = millis();
  }
}

/*!
    @brief    Feeds the WDT to prevent hardware reset.
*/
void Wippersnapper_V2::feedWDTV2() {
#ifndef OFFLINE_MODE_WOKWI
  // TODO: This is a temporary fix for watchdog.reset() not firing
  Watchdog.reset();
// esp_task_wdt_reset(); // TODO: Putback for ESP32 WDT
#endif
}

/*!
    @brief  Enables the watchdog timer.
    @param  timeoutMS
            The desired amount of time to elapse before
            the WDT executes.
*/
void Wippersnapper_V2::enableWDTV2(int timeoutMS) {
#ifndef ARDUINO_ARCH_RP2040
  Watchdog.disable();
#endif
  if (Watchdog.enable(timeoutMS) == 0) {
    WsV2.haltErrorV2("WDT initialization failure!");
  }
}

/*!
    @brief  Process all incoming packets from the
            Adafruit IO MQTT broker. Handles network
            connectivity.
*/
void Wippersnapper_V2::processPacketsV2() {
  // runNetFSMV2(); // NOTE: Removed for now, causes error with virtual
  // _connect() method when caused with WsV2 object in another file.
  WsV2.feedWDTV2();
  // Process all incoming packets from Wippersnapper_V2 MQTT Broker
  WsV2._mqttV2->processPackets(10);
}

/*!
    @brief    Prints information about the WsV2 device to the serial monitor.
*/
void printDeviceInfoV2() {
  WS_DEBUG_PRINTLN("-------Device Information-------");
  WS_DEBUG_PRINT("Firmware Version: ");
  WS_DEBUG_PRINTLN(WS_VERSION);
  WS_DEBUG_PRINTLN("API: Version 2");
  WS_DEBUG_PRINT("Board ID: ");
  WS_DEBUG_PRINTLN(BOARD_ID);
  WS_DEBUG_PRINT("Adafruit.io User: ");
  WS_DEBUG_PRINTLN(WsV2._configV2.aio_user);
  WS_DEBUG_PRINT("WiFi Network: ");
  WS_DEBUG_PRINTLN(WsV2._configV2.network.ssid);

  char sMAC[18] = {0};
  sprintf(sMAC, "%02X:%02X:%02X:%02X:%02X:%02X", WsV2._macAddrV2[0],
          WsV2._macAddrV2[1], WsV2._macAddrV2[2], WsV2._macAddrV2[3],
          WsV2._macAddrV2[4], WsV2._macAddrV2[5]);
  WS_DEBUG_PRINT("MAC Address: ");
  WS_DEBUG_PRINTLN(sMAC);
  WS_DEBUG_PRINTLN("-------------------------------");

// (ESP32-Only) Print reason why device was reset
#ifdef ARDUINO_ARCH_ESP32
  esp_reset_reason_t r = esp_reset_reason();
  WS_DEBUG_PRINT("ESP Reset Reason: ");
  WS_DEBUG_PRINTLN(resetReasonName(r));
#endif
}

/*!
    @brief    Connects to Adafruit IO+ Wippersnapper_V2 broker.
*/
void Wippersnapper_V2::connect() {
  WS_DEBUG_PRINTLN("ESMP v1.0 Demo");
  // Dump device info to the serial monitor
  printDeviceInfoV2();

  // enable global WDT
  WsV2.enableWDTV2(WS_WDT_TIMEOUT);

  // Generate device identifier
  WS_DEBUG_PRINTLN("Generating device UID...");
  if (!generateDeviceUID()) {
    haltErrorV2("Unable to generate Device UID");
  }
  WS_DEBUG_PRINTLN("Device UID generated successfully!");

  // Configures an Adafruit Arduino MQTT object
  WS_DEBUG_PRINTLN("Setting up MQTT client...");
  setupMQTTClient(_device_uidV2);
  WS_DEBUG_PRINTLN("Set up MQTT client successfully!");

  WS_DEBUG_PRINTLN("Generating device's MQTT topics...");
  if (!generateMQTTTopics()) {
    haltErrorV2("Unable to allocate space for MQTT topics");
  }
  WS_DEBUG_PRINTLN("Generated device's MQTT topics successfully!");

  // Connect to Network
  WS_DEBUG_PRINTLN("Establishing network connection...");
  // Run the network fsm
  runNetFSMV2();
  WsV2.feedWDTV2();

  WS_DEBUG_PRINTLN("Registering Device with MQTT Broker...");
  if (!CreateRegisterRequest()) {
    haltErrorV2("Unable to publish checkin request");
  }
  // Handle the checkin response
  PollRegisterResponse();

  // Set the status LED to green to indicate successful configuration
  setStatusLEDColor(0x00A300, WsV2.status_pixel_brightnessV2);
  delay(100);
  // Set the status LED to off during app runtime
  setStatusLEDColor(0x000000, WsV2.status_pixel_brightnessV2);

  WS_DEBUG_PRINTLN("Running app loop...");
}

/*!
    @brief    Processes incoming commands and handles network connection.
    @returns  Network status, as ws_status_t.
*/
ws_status_t Wippersnapper_V2::run() {
  // Handle networking functions
  runNetFSMV2();
  pingBrokerV2();
  // Process all incoming packets from MQTT Broker
  WsV2._mqttV2->processPackets(10);

  // Process all digital events
  // WsV2.digital_io_controller->Update();

  // Process all analog inputs
  // WsV2.analogio_controller->update();

  return WS_NET_CONNECTED; // TODO: Make this funcn void!
}
