/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8 at Tue Aug 20 16:38:43 2024. */

#ifndef PB_WIPPERSNAPPER_DS18X20_DS18X20_PB_H_INCLUDED
#define PB_WIPPERSNAPPER_DS18X20_DS18X20_PB_H_INCLUDED
#include <pb.h>
#include "sensor.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* *
 Ds18x20Add represents a  to initialize
 a DS18X20 Maxim temperature sensor, from the broker.
 NOTE: This API currently only supports ONE device per OneWire bus. */
typedef struct _wippersnapper_ds18x20_Ds18x20Add {
    pb_callback_t onewire_pin; /* * The desired pin to use as a OneWire bus. */
    int32_t sensor_resolution; /* * The desired sensor resolution (9, 10, 11, or 12 bits). */
    float period; /* * The desired period to read the sensor, in seconds. */
    pb_callback_t sensor_types; /* * SI types used by the DS18x20 sensor. */
} wippersnapper_ds18x20_Ds18x20Add;

/* *
 Ds18x20AddDs18x20AddedResponse represents a device's response
 to a Ds18x20Add message. */
typedef struct _wippersnapper_ds18x20_Ds18x20Added {
    bool is_initialized; /* * True if the 1-wire bus has been initialized successfully, False otherwise. */
    pb_callback_t onewire_pin; /* * The pin being used as a OneWire bus. */
} wippersnapper_ds18x20_Ds18x20Added;

/* *
 Ds18x20Remove represents a  to de-initialize a DS18X20
 Maxim temperature sensor, from the broker. */
typedef struct _wippersnapper_ds18x20_Ds18x20Remove {
    pb_callback_t onewire_pin; /* * The desired onewire bus to de-initialize a DS18x sensor on and release. */
} wippersnapper_ds18x20_Ds18x20Remove;

/* *
 Ds18x20Event event represents data from **one** DS18X20 sensor. */
typedef struct _wippersnapper_ds18x20_Ds18x20Event {
    pb_callback_t onewire_pin; /* * The desired pin to use as a OneWire bus. */
    pb_callback_t sensor_events; /* * The DS18X20's SensorEvent. */
} wippersnapper_ds18x20_Ds18x20Event;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define wippersnapper_ds18x20_Ds18x20Add_init_default {{{NULL}, NULL}, 0, 0, {{NULL}, NULL}}
#define wippersnapper_ds18x20_Ds18x20Added_init_default {0, {{NULL}, NULL}}
#define wippersnapper_ds18x20_Ds18x20Remove_init_default {{{NULL}, NULL}}
#define wippersnapper_ds18x20_Ds18x20Event_init_default {{{NULL}, NULL}, {{NULL}, NULL}}
#define wippersnapper_ds18x20_Ds18x20Add_init_zero {{{NULL}, NULL}, 0, 0, {{NULL}, NULL}}
#define wippersnapper_ds18x20_Ds18x20Added_init_zero {0, {{NULL}, NULL}}
#define wippersnapper_ds18x20_Ds18x20Remove_init_zero {{{NULL}, NULL}}
#define wippersnapper_ds18x20_Ds18x20Event_init_zero {{{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define wippersnapper_ds18x20_Ds18x20Add_onewire_pin_tag 1
#define wippersnapper_ds18x20_Ds18x20Add_sensor_resolution_tag 2
#define wippersnapper_ds18x20_Ds18x20Add_period_tag 3
#define wippersnapper_ds18x20_Ds18x20Add_sensor_types_tag 4
#define wippersnapper_ds18x20_Ds18x20Added_is_initialized_tag 1
#define wippersnapper_ds18x20_Ds18x20Added_onewire_pin_tag 2
#define wippersnapper_ds18x20_Ds18x20Remove_onewire_pin_tag 1
#define wippersnapper_ds18x20_Ds18x20Event_onewire_pin_tag 1
#define wippersnapper_ds18x20_Ds18x20Event_sensor_events_tag 2

/* Struct field encoding specification for nanopb */
#define wippersnapper_ds18x20_Ds18x20Add_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   onewire_pin,       1) \
X(a, STATIC,   SINGULAR, INT32,    sensor_resolution,   2) \
X(a, STATIC,   SINGULAR, FLOAT,    period,            3) \
X(a, CALLBACK, REPEATED, UENUM,    sensor_types,      4)
#define wippersnapper_ds18x20_Ds18x20Add_CALLBACK pb_default_field_callback
#define wippersnapper_ds18x20_Ds18x20Add_DEFAULT NULL

#define wippersnapper_ds18x20_Ds18x20Added_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     is_initialized,    1) \
X(a, CALLBACK, SINGULAR, STRING,   onewire_pin,       2)
#define wippersnapper_ds18x20_Ds18x20Added_CALLBACK pb_default_field_callback
#define wippersnapper_ds18x20_Ds18x20Added_DEFAULT NULL

#define wippersnapper_ds18x20_Ds18x20Remove_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   onewire_pin,       1)
#define wippersnapper_ds18x20_Ds18x20Remove_CALLBACK pb_default_field_callback
#define wippersnapper_ds18x20_Ds18x20Remove_DEFAULT NULL

#define wippersnapper_ds18x20_Ds18x20Event_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   onewire_pin,       1) \
X(a, CALLBACK, REPEATED, MESSAGE,  sensor_events,     2)
#define wippersnapper_ds18x20_Ds18x20Event_CALLBACK pb_default_field_callback
#define wippersnapper_ds18x20_Ds18x20Event_DEFAULT NULL
#define wippersnapper_ds18x20_Ds18x20Event_sensor_events_MSGTYPE wippersnapper_sensor_SensorEvent

extern const pb_msgdesc_t wippersnapper_ds18x20_Ds18x20Add_msg;
extern const pb_msgdesc_t wippersnapper_ds18x20_Ds18x20Added_msg;
extern const pb_msgdesc_t wippersnapper_ds18x20_Ds18x20Remove_msg;
extern const pb_msgdesc_t wippersnapper_ds18x20_Ds18x20Event_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define wippersnapper_ds18x20_Ds18x20Add_fields &wippersnapper_ds18x20_Ds18x20Add_msg
#define wippersnapper_ds18x20_Ds18x20Added_fields &wippersnapper_ds18x20_Ds18x20Added_msg
#define wippersnapper_ds18x20_Ds18x20Remove_fields &wippersnapper_ds18x20_Ds18x20Remove_msg
#define wippersnapper_ds18x20_Ds18x20Event_fields &wippersnapper_ds18x20_Ds18x20Event_msg

/* Maximum encoded size of messages (where known) */
/* wippersnapper_ds18x20_Ds18x20Add_size depends on runtime parameters */
/* wippersnapper_ds18x20_Ds18x20Added_size depends on runtime parameters */
/* wippersnapper_ds18x20_Ds18x20Remove_size depends on runtime parameters */
/* wippersnapper_ds18x20_Ds18x20Event_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif