/*!
 * @file ws_display_driver.cpp
 *
 * Wippersnapper LVGL Display Driver
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Copyright (c) Brent Rubell 2023 for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */
#include "ws_display_driver.h"

/**************************************************************************/
/*!
    @brief    Callback for LVGL logging through USB serial
    @param    buf
              Data to write out to serial.
*/
/**************************************************************************/
static void my_log_cb(const char *buf) { WS_DEBUG_PRINTLN(buf); }

/**************************************************************************/
/*!
    @brief    Creates a new WipperSnapper display driver object from a
              configuration struct.
    @param    config
              Configuration struct., from FS.parseDisplayConfig();
*/
/**************************************************************************/
ws_display_driver::ws_display_driver(displayConfig config) {
  WS_DEBUG_PRINT("Display Configuration: \n");
  WS_DEBUG_PRINTLN(config.pinCS);
  WS_DEBUG_PRINTLN(config.pinDC);
  WS_DEBUG_PRINTLN(config.pinRST);
  WS_DEBUG_PRINTLN(config.width);
  WS_DEBUG_PRINTLN(config.height);
  
  // let's dynamically create the display driver from the configuration file
  if (strcmp(config.driver, "ST7789") == 0) {
    Serial.println("Configuring the Adafruit_ST7789 driver");
    _tft_st7789 =
        new Adafruit_ST7789(config.pinCS, config.pinDC, config.pinRST);
  } else {
    Serial.println("ERROR: Display driver type not implemented!");
  }

  setResolution(config.width, config.height);
  setRotation(config.rotation);
}

/**************************************************************************/
/*!
    @brief    Deletes a new WipperSnapper display driver object.
*/
/**************************************************************************/
ws_display_driver::~ws_display_driver() {
  if (_tft_st7789 != nullptr) {
    delete _tft_st7789;
  }
}

/**************************************************************************/
/*!
    @brief    Sets the display resolution, must be called BEFORE begin()!
    @param    displayWidth
              The width of the display, in pixels.
    @param    displayHeight
              The height of the display, in pixels.
*/
/**************************************************************************/
void ws_display_driver::setResolution(uint16_t displayWidth,
                                      uint16_t displayHeight) {
  _displayWidth = displayWidth;
  _displayHeight = displayHeight;
}

/**************************************************************************/
/*!
    @brief    Enables LVGL logging using the usb serial. Must be called
              AFTER calling Serial.begin().
*/
/**************************************************************************/
void ws_display_driver::enableLogging() {  }

/**************************************************************************/
/*!
    @brief    Sets the display's rotation mode.
    @param    rotationMode
              The index for rotation (0-3 inclusive).
*/
/**************************************************************************/
void ws_display_driver::setRotation(uint8_t rotationMode) {
  _displayRotationMode = rotationMode;
}

/**************************************************************************/
/*!
    @brief    Initializes the display and the lvgl_glue driver.
    @returns  True if LVGL_Glue began successfully, False otherwise.
*/
/**************************************************************************/
bool ws_display_driver::begin() {

  // TODO: This function could use some cleanup around how it inits glue

  // initialize display driver
  if (_tft_st7789 != nullptr) {
    WS_DEBUG_PRINTLN("INIT st7789 tft");
    _tft_st7789->init(_displayWidth, _displayHeight);
  } else {
    Serial.println("ERROR: Unable to initialize the display driver!");
    return false;
  }

    // Hardware-specific display commands
    #ifdef ARDUINO_FUNHOUSE_ESP32S2
    pinMode(TFT_BACKLIGHT, OUTPUT);
    digitalWrite(TFT_BACKLIGHT, HIGH);
    #endif // ARDUINO_FUNHOUSE_ESP32S2

    //WS_DEBUG_PRINTLN("Fill screen");
    //_tft_st7789->fillScreen(ST77XX_BLACK);

  // initialize LVGL_glue
  WS_DEBUG_PRINTLN("INIT lvgl_glue");
  _glue = new Adafruit_LvGL_Glue();
  LvGLStatus status = _glue->begin(_tft_st7789);
  WS_DEBUG_PRINT("LVGL GLUE STATUS: ");
  WS_DEBUG_PRINTLN((int) status);

  // check if lvgl initialized correctly
  if (status != LVGL_OK) {
    Serial.printf("LVGL_Glue error %d\r\n", (int)status);
    return false;
  }

  WS_DEBUG_PRINTLN("Setting screen BLACK");
  esp32_lvgl_acquire();
  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_white(), LV_STATE_DEFAULT);
  esp32_lvgl_release();

  return true;
}

void ws_display_driver::esp32_lvgl_acquire() {
    _glue->lvgl_acquire();
}

void ws_display_driver::esp32_lvgl_release() {
    _glue->lvgl_release();
}