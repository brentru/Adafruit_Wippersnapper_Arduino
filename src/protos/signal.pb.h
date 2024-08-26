/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8 at Wed Aug 21 15:48:44 2024. */

#ifndef PB_WIPPERSNAPPER_SIGNAL_SIGNAL_PB_H_INCLUDED
#define PB_WIPPERSNAPPER_SIGNAL_SIGNAL_PB_H_INCLUDED
#include <pb.h>
#include "analogio.pb.h"
#include "checkin.pb.h"
#include "digitalio.pb.h"
#include "ds18x20.pb.h"
#include "error.pb.h"
#include "i2c.pb.h"
#include "pixels.pb.h"
#include "pwm.pb.h"
#include "servo.pb.h"
#include "uart.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* BrokerToDevice
 The BrokerToDevice message is sent from the broker to the device.
 It contains a oneof payload, which is a union of all the possible
 messages that can be sent from the broker to a device. */
typedef struct _wippersnapper_signal_BrokerToDevice {
    pb_callback_t cb_payload;
    pb_size_t which_payload;
    union {
        /* digitalio.proto */
        wippersnapper_digitalio_DigitalIOAdd digitalio_add;
        wippersnapper_digitalio_DigitalIORemove digitalio_remove;
        wippersnapper_digitalio_DigitalIOEvent digitalio_event;
        wippersnapper_digitalio_DigitalIOWrite digitalio_write;
        /* analogio.proto */
        wippersnapper_analogio_AnalogIOAdd analogio_add;
        wippersnapper_analogio_AnalogIORemove analogio_remove;
        /* checkin.proto */
        wippersnapper_checkin_CheckinResponse checkin_response;
        /* servo.proto */
        wippersnapper_servo_ServoAdd servo_add;
        wippersnapper_servo_ServoRemove servo_remove;
        wippersnapper_servo_ServoWrite servo_write;
        /* pwm.proto */
        wippersnapper_pwm_PWMAdd pwm_add;
        wippersnapper_pwm_PWMRemove pwm_remove;
        wippersnapper_pwm_PWMWriteDutyCycle pwm_write_duty;
        wippersnapper_pwm_PWMWriteDutyCycleMulti pwm_write_duty_multi;
        wippersnapper_pwm_PWMWriteFrequency pwm_write_freq;
        /* pixels.proto */
        wippersnapper_pixels_PixelsAdd pixels_add;
        wippersnapper_pixels_PixelsRemove pixels_remove;
        wippersnapper_pixels_PixelsWrite pixels_write;
        /* ds18x20.proto */
        wippersnapper_ds18x20_Ds18x20Add ds18x20_add;
        wippersnapper_ds18x20_Ds18x20Remove ds18x20_remove;
        /* uart.proto */
        wippersnapper_uart_UARTAdd uart_add;
        wippersnapper_uart_UARTRemove uart_remove;
        /* i2c.proto */
        wippersnapper_i2c_I2cBusScan i2c_bus_scan;
        wippersnapper_i2c_I2cDeviceAddOrReplace i2c_device_add_replace;
        wippersnapper_i2c_I2cDeviceRemove i2c_device_remove;
        /* error.proto */
        wippersnapper_error_Error error;
    } payload;
} wippersnapper_signal_BrokerToDevice;

/* DeviceToBroker
 The DeviceToBroker message is sent from the device to the broker.
 It contains a oneof payload, which is a union of all the possible
 messages that can be sent from a device to the broker. */
typedef struct _wippersnapper_signal_DeviceToBroker {
    pb_callback_t cb_payload;
    pb_size_t which_payload;
    union {
        /* digitalio.proto */
        wippersnapper_digitalio_DigitalIOEvent digitalio_event;
        /* analogio.proto */
        wippersnapper_analogio_AnalogIOEvent analogio_event;
        /* checkin.proto */
        wippersnapper_checkin_CheckinRequest checkin_request;
        /* servo.proto */
        wippersnapper_servo_ServoAdded servo_added;
        /* pwm.proto */
        wippersnapper_pwm_PWMAdded pwm_added;
        /* pixels.proto */
        wippersnapper_pixels_PixelsAdded pixels_added;
        /* ds18x20.proto */
        wippersnapper_ds18x20_Ds18x20Added ds18x20_added;
        wippersnapper_ds18x20_Ds18x20Event ds18x20_event;
        /* uart.proto */
        wippersnapper_uart_UARTAdded uart_added;
        wippersnapper_uart_UARTEvent uart_event;
        /* i2c.proto */
        wippersnapper_i2c_I2cBusScanned i2c_bus_scanned;
        wippersnapper_i2c_I2cDeviceAddedOrReplaced i2c_device_added_replaced;
        wippersnapper_i2c_I2cDeviceRemoved i2c_device_removed;
        wippersnapper_i2c_I2cDeviceEvent i2c_device_event;
    } payload;
} wippersnapper_signal_DeviceToBroker;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define wippersnapper_signal_BrokerToDevice_init_default {{{NULL}, NULL}, 0, {wippersnapper_digitalio_DigitalIOAdd_init_default}}
#define wippersnapper_signal_DeviceToBroker_init_default {{{NULL}, NULL}, 0, {wippersnapper_digitalio_DigitalIOEvent_init_default}}
#define wippersnapper_signal_BrokerToDevice_init_zero {{{NULL}, NULL}, 0, {wippersnapper_digitalio_DigitalIOAdd_init_zero}}
#define wippersnapper_signal_DeviceToBroker_init_zero {{{NULL}, NULL}, 0, {wippersnapper_digitalio_DigitalIOEvent_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define wippersnapper_signal_BrokerToDevice_digitalio_add_tag 10
#define wippersnapper_signal_BrokerToDevice_digitalio_remove_tag 11
#define wippersnapper_signal_BrokerToDevice_digitalio_event_tag 12
#define wippersnapper_signal_BrokerToDevice_digitalio_write_tag 13
#define wippersnapper_signal_BrokerToDevice_analogio_add_tag 20
#define wippersnapper_signal_BrokerToDevice_analogio_remove_tag 21
#define wippersnapper_signal_BrokerToDevice_checkin_response_tag 30
#define wippersnapper_signal_BrokerToDevice_servo_add_tag 40
#define wippersnapper_signal_BrokerToDevice_servo_remove_tag 41
#define wippersnapper_signal_BrokerToDevice_servo_write_tag 42
#define wippersnapper_signal_BrokerToDevice_pwm_add_tag 50
#define wippersnapper_signal_BrokerToDevice_pwm_remove_tag 51
#define wippersnapper_signal_BrokerToDevice_pwm_write_duty_tag 52
#define wippersnapper_signal_BrokerToDevice_pwm_write_duty_multi_tag 53
#define wippersnapper_signal_BrokerToDevice_pwm_write_freq_tag 54
#define wippersnapper_signal_BrokerToDevice_pixels_add_tag 60
#define wippersnapper_signal_BrokerToDevice_pixels_remove_tag 61
#define wippersnapper_signal_BrokerToDevice_pixels_write_tag 62
#define wippersnapper_signal_BrokerToDevice_ds18x20_add_tag 70
#define wippersnapper_signal_BrokerToDevice_ds18x20_remove_tag 71
#define wippersnapper_signal_BrokerToDevice_uart_add_tag 80
#define wippersnapper_signal_BrokerToDevice_uart_remove_tag 81
#define wippersnapper_signal_BrokerToDevice_i2c_bus_scan_tag 90
#define wippersnapper_signal_BrokerToDevice_i2c_device_add_replace_tag 91
#define wippersnapper_signal_BrokerToDevice_i2c_device_remove_tag 92
#define wippersnapper_signal_BrokerToDevice_error_tag 100
#define wippersnapper_signal_DeviceToBroker_digitalio_event_tag 10
#define wippersnapper_signal_DeviceToBroker_analogio_event_tag 20
#define wippersnapper_signal_DeviceToBroker_checkin_request_tag 30
#define wippersnapper_signal_DeviceToBroker_servo_added_tag 40
#define wippersnapper_signal_DeviceToBroker_pwm_added_tag 50
#define wippersnapper_signal_DeviceToBroker_pixels_added_tag 60
#define wippersnapper_signal_DeviceToBroker_ds18x20_added_tag 70
#define wippersnapper_signal_DeviceToBroker_ds18x20_event_tag 80
#define wippersnapper_signal_DeviceToBroker_uart_added_tag 90
#define wippersnapper_signal_DeviceToBroker_uart_event_tag 100
#define wippersnapper_signal_DeviceToBroker_i2c_bus_scanned_tag 110
#define wippersnapper_signal_DeviceToBroker_i2c_device_added_replaced_tag 111
#define wippersnapper_signal_DeviceToBroker_i2c_device_removed_tag 112
#define wippersnapper_signal_DeviceToBroker_i2c_device_event_tag 113

/* Struct field encoding specification for nanopb */
#define wippersnapper_signal_BrokerToDevice_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,digitalio_add,payload.digitalio_add),  10) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,digitalio_remove,payload.digitalio_remove),  11) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,digitalio_event,payload.digitalio_event),  12) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,digitalio_write,payload.digitalio_write),  13) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,analogio_add,payload.analogio_add),  20) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,analogio_remove,payload.analogio_remove),  21) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,checkin_response,payload.checkin_response),  30) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,servo_add,payload.servo_add),  40) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,servo_remove,payload.servo_remove),  41) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,servo_write,payload.servo_write),  42) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pwm_add,payload.pwm_add),  50) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pwm_remove,payload.pwm_remove),  51) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pwm_write_duty,payload.pwm_write_duty),  52) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pwm_write_duty_multi,payload.pwm_write_duty_multi),  53) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pwm_write_freq,payload.pwm_write_freq),  54) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pixels_add,payload.pixels_add),  60) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pixels_remove,payload.pixels_remove),  61) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pixels_write,payload.pixels_write),  62) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,ds18x20_add,payload.ds18x20_add),  70) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,ds18x20_remove,payload.ds18x20_remove),  71) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,uart_add,payload.uart_add),  80) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,uart_remove,payload.uart_remove),  81) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,i2c_bus_scan,payload.i2c_bus_scan),  90) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,i2c_device_add_replace,payload.i2c_device_add_replace),  91) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,i2c_device_remove,payload.i2c_device_remove),  92) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,error,payload.error), 100)
#define wippersnapper_signal_BrokerToDevice_CALLBACK NULL
#define wippersnapper_signal_BrokerToDevice_DEFAULT NULL
#define wippersnapper_signal_BrokerToDevice_payload_digitalio_add_MSGTYPE wippersnapper_digitalio_DigitalIOAdd
#define wippersnapper_signal_BrokerToDevice_payload_digitalio_remove_MSGTYPE wippersnapper_digitalio_DigitalIORemove
#define wippersnapper_signal_BrokerToDevice_payload_digitalio_event_MSGTYPE wippersnapper_digitalio_DigitalIOEvent
#define wippersnapper_signal_BrokerToDevice_payload_digitalio_write_MSGTYPE wippersnapper_digitalio_DigitalIOWrite
#define wippersnapper_signal_BrokerToDevice_payload_analogio_add_MSGTYPE wippersnapper_analogio_AnalogIOAdd
#define wippersnapper_signal_BrokerToDevice_payload_analogio_remove_MSGTYPE wippersnapper_analogio_AnalogIORemove
#define wippersnapper_signal_BrokerToDevice_payload_checkin_response_MSGTYPE wippersnapper_checkin_CheckinResponse
#define wippersnapper_signal_BrokerToDevice_payload_servo_add_MSGTYPE wippersnapper_servo_ServoAdd
#define wippersnapper_signal_BrokerToDevice_payload_servo_remove_MSGTYPE wippersnapper_servo_ServoRemove
#define wippersnapper_signal_BrokerToDevice_payload_servo_write_MSGTYPE wippersnapper_servo_ServoWrite
#define wippersnapper_signal_BrokerToDevice_payload_pwm_add_MSGTYPE wippersnapper_pwm_PWMAdd
#define wippersnapper_signal_BrokerToDevice_payload_pwm_remove_MSGTYPE wippersnapper_pwm_PWMRemove
#define wippersnapper_signal_BrokerToDevice_payload_pwm_write_duty_MSGTYPE wippersnapper_pwm_PWMWriteDutyCycle
#define wippersnapper_signal_BrokerToDevice_payload_pwm_write_duty_multi_MSGTYPE wippersnapper_pwm_PWMWriteDutyCycleMulti
#define wippersnapper_signal_BrokerToDevice_payload_pwm_write_freq_MSGTYPE wippersnapper_pwm_PWMWriteFrequency
#define wippersnapper_signal_BrokerToDevice_payload_pixels_add_MSGTYPE wippersnapper_pixels_PixelsAdd
#define wippersnapper_signal_BrokerToDevice_payload_pixels_remove_MSGTYPE wippersnapper_pixels_PixelsRemove
#define wippersnapper_signal_BrokerToDevice_payload_pixels_write_MSGTYPE wippersnapper_pixels_PixelsWrite
#define wippersnapper_signal_BrokerToDevice_payload_ds18x20_add_MSGTYPE wippersnapper_ds18x20_Ds18x20Add
#define wippersnapper_signal_BrokerToDevice_payload_ds18x20_remove_MSGTYPE wippersnapper_ds18x20_Ds18x20Remove
#define wippersnapper_signal_BrokerToDevice_payload_uart_add_MSGTYPE wippersnapper_uart_UARTAdd
#define wippersnapper_signal_BrokerToDevice_payload_uart_remove_MSGTYPE wippersnapper_uart_UARTRemove
#define wippersnapper_signal_BrokerToDevice_payload_i2c_bus_scan_MSGTYPE wippersnapper_i2c_I2cBusScan
#define wippersnapper_signal_BrokerToDevice_payload_i2c_device_add_replace_MSGTYPE wippersnapper_i2c_I2cDeviceAddOrReplace
#define wippersnapper_signal_BrokerToDevice_payload_i2c_device_remove_MSGTYPE wippersnapper_i2c_I2cDeviceRemove
#define wippersnapper_signal_BrokerToDevice_payload_error_MSGTYPE wippersnapper_error_Error

#define wippersnapper_signal_DeviceToBroker_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,digitalio_event,payload.digitalio_event),  10) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,analogio_event,payload.analogio_event),  20) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,checkin_request,payload.checkin_request),  30) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,servo_added,payload.servo_added),  40) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pwm_added,payload.pwm_added),  50) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,pixels_added,payload.pixels_added),  60) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,ds18x20_added,payload.ds18x20_added),  70) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,ds18x20_event,payload.ds18x20_event),  80) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,uart_added,payload.uart_added),  90) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,uart_event,payload.uart_event), 100) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,i2c_bus_scanned,payload.i2c_bus_scanned), 110) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,i2c_device_added_replaced,payload.i2c_device_added_replaced), 111) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,i2c_device_removed,payload.i2c_device_removed), 112) \
X(a, STATIC,   ONEOF,    MSG_W_CB, (payload,i2c_device_event,payload.i2c_device_event), 113)
#define wippersnapper_signal_DeviceToBroker_CALLBACK NULL
#define wippersnapper_signal_DeviceToBroker_DEFAULT NULL
#define wippersnapper_signal_DeviceToBroker_payload_digitalio_event_MSGTYPE wippersnapper_digitalio_DigitalIOEvent
#define wippersnapper_signal_DeviceToBroker_payload_analogio_event_MSGTYPE wippersnapper_analogio_AnalogIOEvent
#define wippersnapper_signal_DeviceToBroker_payload_checkin_request_MSGTYPE wippersnapper_checkin_CheckinRequest
#define wippersnapper_signal_DeviceToBroker_payload_servo_added_MSGTYPE wippersnapper_servo_ServoAdded
#define wippersnapper_signal_DeviceToBroker_payload_pwm_added_MSGTYPE wippersnapper_pwm_PWMAdded
#define wippersnapper_signal_DeviceToBroker_payload_pixels_added_MSGTYPE wippersnapper_pixels_PixelsAdded
#define wippersnapper_signal_DeviceToBroker_payload_ds18x20_added_MSGTYPE wippersnapper_ds18x20_Ds18x20Added
#define wippersnapper_signal_DeviceToBroker_payload_ds18x20_event_MSGTYPE wippersnapper_ds18x20_Ds18x20Event
#define wippersnapper_signal_DeviceToBroker_payload_uart_added_MSGTYPE wippersnapper_uart_UARTAdded
#define wippersnapper_signal_DeviceToBroker_payload_uart_event_MSGTYPE wippersnapper_uart_UARTEvent
#define wippersnapper_signal_DeviceToBroker_payload_i2c_bus_scanned_MSGTYPE wippersnapper_i2c_I2cBusScanned
#define wippersnapper_signal_DeviceToBroker_payload_i2c_device_added_replaced_MSGTYPE wippersnapper_i2c_I2cDeviceAddedOrReplaced
#define wippersnapper_signal_DeviceToBroker_payload_i2c_device_removed_MSGTYPE wippersnapper_i2c_I2cDeviceRemoved
#define wippersnapper_signal_DeviceToBroker_payload_i2c_device_event_MSGTYPE wippersnapper_i2c_I2cDeviceEvent

extern const pb_msgdesc_t wippersnapper_signal_BrokerToDevice_msg;
extern const pb_msgdesc_t wippersnapper_signal_DeviceToBroker_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define wippersnapper_signal_BrokerToDevice_fields &wippersnapper_signal_BrokerToDevice_msg
#define wippersnapper_signal_DeviceToBroker_fields &wippersnapper_signal_DeviceToBroker_msg

/* Maximum encoded size of messages (where known) */
#if defined(wippersnapper_digitalio_DigitalIOAdd_size) && defined(wippersnapper_digitalio_DigitalIORemove_size) && defined(wippersnapper_digitalio_DigitalIOEvent_size) && defined(wippersnapper_digitalio_DigitalIOWrite_size) && defined(wippersnapper_analogio_AnalogIOAdd_size) && defined(wippersnapper_analogio_AnalogIORemove_size) && defined(wippersnapper_uart_UARTAdd_size) && defined(wippersnapper_uart_UARTRemove_size)
union wippersnapper_signal_BrokerToDevice_payload_size_union {char f10[(6 + wippersnapper_digitalio_DigitalIOAdd_size)]; char f11[(6 + wippersnapper_digitalio_DigitalIORemove_size)]; char f12[(6 + wippersnapper_digitalio_DigitalIOEvent_size)]; char f13[(6 + wippersnapper_digitalio_DigitalIOWrite_size)]; char f20[(7 + wippersnapper_analogio_AnalogIOAdd_size)]; char f21[(7 + wippersnapper_analogio_AnalogIORemove_size)]; char f80[(7 + wippersnapper_uart_UARTAdd_size)]; char f81[(7 + wippersnapper_uart_UARTRemove_size)]; char f0[83];};
#endif
#if defined(wippersnapper_digitalio_DigitalIOEvent_size) && defined(wippersnapper_analogio_AnalogIOEvent_size) && defined(wippersnapper_ds18x20_Ds18x20Event_size) && defined(wippersnapper_uart_UARTAdded_size) && defined(wippersnapper_uart_UARTEvent_size) && defined(wippersnapper_i2c_I2cDeviceEvent_size)
union wippersnapper_signal_DeviceToBroker_payload_size_union {char f10[(6 + wippersnapper_digitalio_DigitalIOEvent_size)]; char f20[(7 + wippersnapper_analogio_AnalogIOEvent_size)]; char f80[(7 + wippersnapper_ds18x20_Ds18x20Event_size)]; char f90[(7 + wippersnapper_uart_UARTAdded_size)]; char f100[(7 + wippersnapper_uart_UARTEvent_size)]; char f113[(7 + wippersnapper_i2c_I2cDeviceEvent_size)]; char f0[2406];};
#endif
#if defined(wippersnapper_digitalio_DigitalIOAdd_size) && defined(wippersnapper_digitalio_DigitalIORemove_size) && defined(wippersnapper_digitalio_DigitalIOEvent_size) && defined(wippersnapper_digitalio_DigitalIOWrite_size) && defined(wippersnapper_analogio_AnalogIOAdd_size) && defined(wippersnapper_analogio_AnalogIORemove_size) && defined(wippersnapper_uart_UARTAdd_size) && defined(wippersnapper_uart_UARTRemove_size)
#define WIPPERSNAPPER_SIGNAL_SIGNAL_PB_H_MAX_SIZE wippersnapper_signal_BrokerToDevice_size
#define wippersnapper_signal_BrokerToDevice_size (0 + sizeof(union wippersnapper_signal_BrokerToDevice_payload_size_union))
#endif
#if defined(wippersnapper_digitalio_DigitalIOEvent_size) && defined(wippersnapper_analogio_AnalogIOEvent_size) && defined(wippersnapper_ds18x20_Ds18x20Event_size) && defined(wippersnapper_uart_UARTAdded_size) && defined(wippersnapper_uart_UARTEvent_size) && defined(wippersnapper_i2c_I2cDeviceEvent_size)
#define wippersnapper_signal_DeviceToBroker_size (0 + sizeof(union wippersnapper_signal_DeviceToBroker_payload_size_union))
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif