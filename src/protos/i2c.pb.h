/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8 at Wed Aug 21 15:48:44 2024. */

#ifndef PB_WIPPERSNAPPER_I2C_I2C_PB_H_INCLUDED
#define PB_WIPPERSNAPPER_I2C_I2C_PB_H_INCLUDED
#include <pb.h>
#include "sensor.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* *
 I2cBusStatus represents the status of a board's I2C bus */
typedef enum _wippersnapper_i2c_I2cBusStatus {
    wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_UNSPECIFIED = 0, /* * Unspecified error occurred. * */
    wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_SUCCESS = 1, /* * I2C bus successfully initialized. * */
    wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_ERROR_HANG = 2, /* * I2C Bus hang, user should reset their board if this persists. * */
    wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_ERROR_PULLUPS = 3, /* * I2C bus failed to initialize - SDA or SCL needs a pull up. * */
    wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_ERROR_WIRING = 4, /* * I2C bus failed to communicate - Please check your wiring. * */
    wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_ERROR_INVALID_CHANNEL = 5 /* * I2C MUX failed - Output channel must be within range 0-7. * */
} wippersnapper_i2c_I2cBusStatus;

/* *
 I2cDeviceStatus represents the state of an I2C device/peripheral */
typedef enum _wippersnapper_i2c_I2cDeviceStatus {
    wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_UNSPECIFIED = 0, /* * Unspecified error occurred. * */
    wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_SUCCESS = 1, /* * I2C device successfully initialized. * */
    wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_FAIL_INIT = 2, /* * I2C device failed to initialize. * */
    wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_FAIL_DEINIT = 3, /* * I2C device failed to deinitialize. * */
    wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_FAIL_UNSUPPORTED_SENSOR = 4, /* * WipperSnapper version is outdated and does not include this device. * */
    wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_NOT_FOUND = 5 /* * I2C device not found on the bus. * */
} wippersnapper_i2c_I2cDeviceStatus;

/* Struct definitions */
/* *
 I2cBusScan represents a command for a device to perform an i2c scan. It is an empty message. */
typedef struct _wippersnapper_i2c_I2cBusScan {
    char dummy_field;
} wippersnapper_i2c_I2cBusScan;

/* *
 I2cDeviceDescriptor represents the I2c device's address and related metadata. */
typedef struct _wippersnapper_i2c_I2cDeviceDescriptor {
    uint32_t i2c_bus; /* * The desired i2c bus to address.* */
    uint32_t i2c_device_mux_address; /* * The desired address of the I2C device or (optionally) the I2C MUX address.* */
    uint32_t i2c_mux_channel; /* * (Optional) The desired I2C mux's output channel, from 0-7.* */
} wippersnapper_i2c_I2cDeviceDescriptor;

/* *
 I2cBusScanned represents a list of I2c addresses
 found on the bus after I2cScan has executed. */
typedef struct _wippersnapper_i2c_I2cBusScanned {
    pb_size_t i2c_bus_found_devices_count;
    wippersnapper_i2c_I2cDeviceDescriptor i2c_bus_found_devices[120]; /* * The 7-bit addresses of the I2c devices found on the bus, empty if not found. */
    wippersnapper_i2c_I2cBusStatus i2c_bus_status; /* * The I2c bus' status. * */
} wippersnapper_i2c_I2cBusScanned;

/* *
 I2cDeviceAddOrReplace is a message for initializing (or replacing/updating) an i2c device. */
typedef struct _wippersnapper_i2c_I2cDeviceAddOrReplace {
    bool has_i2c_device_description;
    wippersnapper_i2c_I2cDeviceDescriptor i2c_device_description; /* * The I2c device's address and metadata. */
    char i2c_device_name[15]; /* * The I2c device's name, MUST MATCH the name on the JSON definition file on
https://github.com/adafruit/Wippersnapper_Components. */
    float i2c_device_period; /* * The desired period to update the I2c device's sensor(s), in seconds. */
    pb_size_t i2c_device_sensor_types_count;
    wippersnapper_sensor_SensorType i2c_device_sensor_types[15]; /* * SI Types for each sensor on the I2c device. */
} wippersnapper_i2c_I2cDeviceAddOrReplace;

/* *
 I2cDeviceAddedOrReplaced contains the response from a device after processing a I2cDeviceAddOrReplace message. */
typedef struct _wippersnapper_i2c_I2cDeviceAddedOrReplaced {
    bool has_i2c_device_description;
    wippersnapper_i2c_I2cDeviceDescriptor i2c_device_description; /* * The I2c device's address and metadata. */
    wippersnapper_i2c_I2cBusStatus i2c_bus_status; /* * The I2c bus' status. * */
    wippersnapper_i2c_I2cDeviceStatus i2c_device_status; /* * The I2c device's status. * */
} wippersnapper_i2c_I2cDeviceAddedOrReplaced;

/* *
 I2cDeviceRemove represents a request to de-init an i2c device. */
typedef struct _wippersnapper_i2c_I2cDeviceRemove {
    bool has_i2c_device_description;
    wippersnapper_i2c_I2cDeviceDescriptor i2c_device_description; /* * The I2c device's address and metadata. */
} wippersnapper_i2c_I2cDeviceRemove;

/* *
 I2cDeviceRemoved represents a response to a I2cDeviceRemove message. */
typedef struct _wippersnapper_i2c_I2cDeviceRemoved {
    bool has_i2c_device_description;
    wippersnapper_i2c_I2cDeviceDescriptor i2c_device_description; /* * The I2c device's address and metadata. */
    wippersnapper_i2c_I2cBusStatus i2c_bus_status; /* * The I2c bus' status. * */
    wippersnapper_i2c_I2cDeviceStatus i2c_device_status; /* * The I2c device's status. * */
} wippersnapper_i2c_I2cDeviceRemoved;

/* *
 Each I2cDeviceEvent represents data from **one** I2c sensor.
 NOTE: An I2cDeviceEvent can have multiple sensor events if
 the I2c device contains > 1 sensor. */
typedef struct _wippersnapper_i2c_I2cDeviceEvent {
    bool has_i2c_device_description;
    wippersnapper_i2c_I2cDeviceDescriptor i2c_device_description; /* * The I2c device's address and metadata. */
    pb_size_t i2c_device_events_count;
    wippersnapper_sensor_SensorEvent i2c_device_events[15]; /* * A, optionally repeated, SensorEvent from a sensor. */
} wippersnapper_i2c_I2cDeviceEvent;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _wippersnapper_i2c_I2cBusStatus_MIN wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_UNSPECIFIED
#define _wippersnapper_i2c_I2cBusStatus_MAX wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_ERROR_INVALID_CHANNEL
#define _wippersnapper_i2c_I2cBusStatus_ARRAYSIZE ((wippersnapper_i2c_I2cBusStatus)(wippersnapper_i2c_I2cBusStatus_I2C_BUS_STATUS_ERROR_INVALID_CHANNEL+1))

#define _wippersnapper_i2c_I2cDeviceStatus_MIN wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_UNSPECIFIED
#define _wippersnapper_i2c_I2cDeviceStatus_MAX wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_NOT_FOUND
#define _wippersnapper_i2c_I2cDeviceStatus_ARRAYSIZE ((wippersnapper_i2c_I2cDeviceStatus)(wippersnapper_i2c_I2cDeviceStatus_I2C_DEVICE_STATUS_NOT_FOUND+1))


#define wippersnapper_i2c_I2cBusScanned_i2c_bus_status_ENUMTYPE wippersnapper_i2c_I2cBusStatus


#define wippersnapper_i2c_I2cDeviceAddOrReplace_i2c_device_sensor_types_ENUMTYPE wippersnapper_sensor_SensorType

#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_i2c_bus_status_ENUMTYPE wippersnapper_i2c_I2cBusStatus
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_i2c_device_status_ENUMTYPE wippersnapper_i2c_I2cDeviceStatus


#define wippersnapper_i2c_I2cDeviceRemoved_i2c_bus_status_ENUMTYPE wippersnapper_i2c_I2cBusStatus
#define wippersnapper_i2c_I2cDeviceRemoved_i2c_device_status_ENUMTYPE wippersnapper_i2c_I2cDeviceStatus



/* Initializer values for message structs */
#define wippersnapper_i2c_I2cBusScan_init_default {0}
#define wippersnapper_i2c_I2cBusScanned_init_default {0, {wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default, wippersnapper_i2c_I2cDeviceDescriptor_init_default}, _wippersnapper_i2c_I2cBusStatus_MIN}
#define wippersnapper_i2c_I2cDeviceDescriptor_init_default {0, 0, 0}
#define wippersnapper_i2c_I2cDeviceAddOrReplace_init_default {false, wippersnapper_i2c_I2cDeviceDescriptor_init_default, "", 0, 0, {_wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN}}
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_init_default {false, wippersnapper_i2c_I2cDeviceDescriptor_init_default, _wippersnapper_i2c_I2cBusStatus_MIN, _wippersnapper_i2c_I2cDeviceStatus_MIN}
#define wippersnapper_i2c_I2cDeviceRemove_init_default {false, wippersnapper_i2c_I2cDeviceDescriptor_init_default}
#define wippersnapper_i2c_I2cDeviceRemoved_init_default {false, wippersnapper_i2c_I2cDeviceDescriptor_init_default, _wippersnapper_i2c_I2cBusStatus_MIN, _wippersnapper_i2c_I2cDeviceStatus_MIN}
#define wippersnapper_i2c_I2cDeviceEvent_init_default {false, wippersnapper_i2c_I2cDeviceDescriptor_init_default, 0, {wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default, wippersnapper_sensor_SensorEvent_init_default}}
#define wippersnapper_i2c_I2cBusScan_init_zero   {0}
#define wippersnapper_i2c_I2cBusScanned_init_zero {0, {wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, wippersnapper_i2c_I2cDeviceDescriptor_init_zero}, _wippersnapper_i2c_I2cBusStatus_MIN}
#define wippersnapper_i2c_I2cDeviceDescriptor_init_zero {0, 0, 0}
#define wippersnapper_i2c_I2cDeviceAddOrReplace_init_zero {false, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, "", 0, 0, {_wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN, _wippersnapper_sensor_SensorType_MIN}}
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_init_zero {false, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, _wippersnapper_i2c_I2cBusStatus_MIN, _wippersnapper_i2c_I2cDeviceStatus_MIN}
#define wippersnapper_i2c_I2cDeviceRemove_init_zero {false, wippersnapper_i2c_I2cDeviceDescriptor_init_zero}
#define wippersnapper_i2c_I2cDeviceRemoved_init_zero {false, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, _wippersnapper_i2c_I2cBusStatus_MIN, _wippersnapper_i2c_I2cDeviceStatus_MIN}
#define wippersnapper_i2c_I2cDeviceEvent_init_zero {false, wippersnapper_i2c_I2cDeviceDescriptor_init_zero, 0, {wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero, wippersnapper_sensor_SensorEvent_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define wippersnapper_i2c_I2cDeviceDescriptor_i2c_bus_tag 1
#define wippersnapper_i2c_I2cDeviceDescriptor_i2c_device_mux_address_tag 2
#define wippersnapper_i2c_I2cDeviceDescriptor_i2c_mux_channel_tag 3
#define wippersnapper_i2c_I2cBusScanned_i2c_bus_found_devices_tag 1
#define wippersnapper_i2c_I2cBusScanned_i2c_bus_status_tag 2
#define wippersnapper_i2c_I2cDeviceAddOrReplace_i2c_device_description_tag 1
#define wippersnapper_i2c_I2cDeviceAddOrReplace_i2c_device_name_tag 2
#define wippersnapper_i2c_I2cDeviceAddOrReplace_i2c_device_period_tag 3
#define wippersnapper_i2c_I2cDeviceAddOrReplace_i2c_device_sensor_types_tag 4
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_i2c_device_description_tag 1
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_i2c_bus_status_tag 2
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_i2c_device_status_tag 3
#define wippersnapper_i2c_I2cDeviceRemove_i2c_device_description_tag 1
#define wippersnapper_i2c_I2cDeviceRemoved_i2c_device_description_tag 1
#define wippersnapper_i2c_I2cDeviceRemoved_i2c_bus_status_tag 2
#define wippersnapper_i2c_I2cDeviceRemoved_i2c_device_status_tag 3
#define wippersnapper_i2c_I2cDeviceEvent_i2c_device_description_tag 1
#define wippersnapper_i2c_I2cDeviceEvent_i2c_device_events_tag 2

/* Struct field encoding specification for nanopb */
#define wippersnapper_i2c_I2cBusScan_FIELDLIST(X, a) \

#define wippersnapper_i2c_I2cBusScan_CALLBACK NULL
#define wippersnapper_i2c_I2cBusScan_DEFAULT NULL

#define wippersnapper_i2c_I2cBusScanned_FIELDLIST(X, a) \
X(a, STATIC,   REPEATED, MESSAGE,  i2c_bus_found_devices,   1) \
X(a, STATIC,   SINGULAR, UENUM,    i2c_bus_status,    2)
#define wippersnapper_i2c_I2cBusScanned_CALLBACK NULL
#define wippersnapper_i2c_I2cBusScanned_DEFAULT NULL
#define wippersnapper_i2c_I2cBusScanned_i2c_bus_found_devices_MSGTYPE wippersnapper_i2c_I2cDeviceDescriptor

#define wippersnapper_i2c_I2cDeviceDescriptor_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   i2c_bus,           1) \
X(a, STATIC,   SINGULAR, UINT32,   i2c_device_mux_address,   2) \
X(a, STATIC,   SINGULAR, UINT32,   i2c_mux_channel,   3)
#define wippersnapper_i2c_I2cDeviceDescriptor_CALLBACK NULL
#define wippersnapper_i2c_I2cDeviceDescriptor_DEFAULT NULL

#define wippersnapper_i2c_I2cDeviceAddOrReplace_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  i2c_device_description,   1) \
X(a, STATIC,   SINGULAR, STRING,   i2c_device_name,   2) \
X(a, STATIC,   SINGULAR, FLOAT,    i2c_device_period,   3) \
X(a, STATIC,   REPEATED, UENUM,    i2c_device_sensor_types,   4)
#define wippersnapper_i2c_I2cDeviceAddOrReplace_CALLBACK NULL
#define wippersnapper_i2c_I2cDeviceAddOrReplace_DEFAULT NULL
#define wippersnapper_i2c_I2cDeviceAddOrReplace_i2c_device_description_MSGTYPE wippersnapper_i2c_I2cDeviceDescriptor

#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  i2c_device_description,   1) \
X(a, STATIC,   SINGULAR, UENUM,    i2c_bus_status,    2) \
X(a, STATIC,   SINGULAR, UENUM,    i2c_device_status,   3)
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_CALLBACK NULL
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_DEFAULT NULL
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_i2c_device_description_MSGTYPE wippersnapper_i2c_I2cDeviceDescriptor

#define wippersnapper_i2c_I2cDeviceRemove_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  i2c_device_description,   1)
#define wippersnapper_i2c_I2cDeviceRemove_CALLBACK NULL
#define wippersnapper_i2c_I2cDeviceRemove_DEFAULT NULL
#define wippersnapper_i2c_I2cDeviceRemove_i2c_device_description_MSGTYPE wippersnapper_i2c_I2cDeviceDescriptor

#define wippersnapper_i2c_I2cDeviceRemoved_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  i2c_device_description,   1) \
X(a, STATIC,   SINGULAR, UENUM,    i2c_bus_status,    2) \
X(a, STATIC,   SINGULAR, UENUM,    i2c_device_status,   3)
#define wippersnapper_i2c_I2cDeviceRemoved_CALLBACK NULL
#define wippersnapper_i2c_I2cDeviceRemoved_DEFAULT NULL
#define wippersnapper_i2c_I2cDeviceRemoved_i2c_device_description_MSGTYPE wippersnapper_i2c_I2cDeviceDescriptor

#define wippersnapper_i2c_I2cDeviceEvent_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  i2c_device_description,   1) \
X(a, STATIC,   REPEATED, MESSAGE,  i2c_device_events,   2)
#define wippersnapper_i2c_I2cDeviceEvent_CALLBACK NULL
#define wippersnapper_i2c_I2cDeviceEvent_DEFAULT NULL
#define wippersnapper_i2c_I2cDeviceEvent_i2c_device_description_MSGTYPE wippersnapper_i2c_I2cDeviceDescriptor
#define wippersnapper_i2c_I2cDeviceEvent_i2c_device_events_MSGTYPE wippersnapper_sensor_SensorEvent

extern const pb_msgdesc_t wippersnapper_i2c_I2cBusScan_msg;
extern const pb_msgdesc_t wippersnapper_i2c_I2cBusScanned_msg;
extern const pb_msgdesc_t wippersnapper_i2c_I2cDeviceDescriptor_msg;
extern const pb_msgdesc_t wippersnapper_i2c_I2cDeviceAddOrReplace_msg;
extern const pb_msgdesc_t wippersnapper_i2c_I2cDeviceAddedOrReplaced_msg;
extern const pb_msgdesc_t wippersnapper_i2c_I2cDeviceRemove_msg;
extern const pb_msgdesc_t wippersnapper_i2c_I2cDeviceRemoved_msg;
extern const pb_msgdesc_t wippersnapper_i2c_I2cDeviceEvent_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define wippersnapper_i2c_I2cBusScan_fields &wippersnapper_i2c_I2cBusScan_msg
#define wippersnapper_i2c_I2cBusScanned_fields &wippersnapper_i2c_I2cBusScanned_msg
#define wippersnapper_i2c_I2cDeviceDescriptor_fields &wippersnapper_i2c_I2cDeviceDescriptor_msg
#define wippersnapper_i2c_I2cDeviceAddOrReplace_fields &wippersnapper_i2c_I2cDeviceAddOrReplace_msg
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_fields &wippersnapper_i2c_I2cDeviceAddedOrReplaced_msg
#define wippersnapper_i2c_I2cDeviceRemove_fields &wippersnapper_i2c_I2cDeviceRemove_msg
#define wippersnapper_i2c_I2cDeviceRemoved_fields &wippersnapper_i2c_I2cDeviceRemoved_msg
#define wippersnapper_i2c_I2cDeviceEvent_fields &wippersnapper_i2c_I2cDeviceEvent_msg

/* Maximum encoded size of messages (where known) */
#define WIPPERSNAPPER_I2C_I2C_PB_H_MAX_SIZE      wippersnapper_i2c_I2cBusScanned_size
#define wippersnapper_i2c_I2cBusScan_size        0
#define wippersnapper_i2c_I2cBusScanned_size     2402
#define wippersnapper_i2c_I2cDeviceAddOrReplace_size 71
#define wippersnapper_i2c_I2cDeviceAddedOrReplaced_size 24
#define wippersnapper_i2c_I2cDeviceDescriptor_size 18
#define wippersnapper_i2c_I2cDeviceRemove_size   20
#define wippersnapper_i2c_I2cDeviceRemoved_size  24
#if defined(wippersnapper_sensor_SensorEvent_size)
#define wippersnapper_i2c_I2cDeviceEvent_size    (110 + 15*wippersnapper_sensor_SensorEvent_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif