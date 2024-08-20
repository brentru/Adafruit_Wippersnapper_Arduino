/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8 at Tue Aug 20 16:38:43 2024. */

#ifndef PB_WIPPERSNAPPER_SERVO_SERVO_PB_H_INCLUDED
#define PB_WIPPERSNAPPER_SERVO_SERVO_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* *
 ServoAdd represents a request to attach a servo to a pin. */
typedef struct _wippersnapper_servo_ServoAdd {
    pb_callback_t servo_pin; /* * The name of pin to attach a servo to. */
    int32_t servo_freq; /* * The overall PWM frequency, default sent by Adafruit IO is 50Hz. * */
    int32_t min_pulse_width; /* * The minimum pulse length in uS. Default sent by Adafruit IO is 500uS. * */
    int32_t max_pulse_width; /* * The maximum pulse length in uS. Default sent by Adafruit IO is 2500uS. * */
} wippersnapper_servo_ServoAdd;

/* *
 ServoAdded represents the result of attaching a servo to a pin. */
typedef struct _wippersnapper_servo_ServoAdded {
    bool attach_success; /* * True if a servo was attached successfully, False otherwise. * */
    pb_callback_t servo_pin; /* * The name of pin we're responding about. */
} wippersnapper_servo_ServoAdded;

/* *
 ServoRemove represents a request to detach a servo from a pin and de-initialize the pin for other uses. */
typedef struct _wippersnapper_servo_ServoRemove {
    pb_callback_t servo_pin; /* * The name of pin to use as a servo pin. */
} wippersnapper_servo_ServoRemove;

/* *
 ServoWrite represents a message to write the servo's position.

 NOTE: Position is sent from Adafruit IO as a pulse width in uS between 0uS
 and 2500uS. The client application must convert pulse width to duty cycle w/fixed
 freq of 50Hz prior to writing to the servo pin. */
typedef struct _wippersnapper_servo_ServoWrite {
    pb_callback_t servo_pin; /* * The name of pin we're addressing. */
    int32_t pulse_width; /* * The pulse width to write to the servo, in uS * */
} wippersnapper_servo_ServoWrite;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define wippersnapper_servo_ServoAdd_init_default {{{NULL}, NULL}, 0, 0, 0}
#define wippersnapper_servo_ServoAdded_init_default {0, {{NULL}, NULL}}
#define wippersnapper_servo_ServoRemove_init_default {{{NULL}, NULL}}
#define wippersnapper_servo_ServoWrite_init_default {{{NULL}, NULL}, 0}
#define wippersnapper_servo_ServoAdd_init_zero   {{{NULL}, NULL}, 0, 0, 0}
#define wippersnapper_servo_ServoAdded_init_zero {0, {{NULL}, NULL}}
#define wippersnapper_servo_ServoRemove_init_zero {{{NULL}, NULL}}
#define wippersnapper_servo_ServoWrite_init_zero {{{NULL}, NULL}, 0}

/* Field tags (for use in manual encoding/decoding) */
#define wippersnapper_servo_ServoAdd_servo_pin_tag 1
#define wippersnapper_servo_ServoAdd_servo_freq_tag 2
#define wippersnapper_servo_ServoAdd_min_pulse_width_tag 3
#define wippersnapper_servo_ServoAdd_max_pulse_width_tag 4
#define wippersnapper_servo_ServoAdded_attach_success_tag 1
#define wippersnapper_servo_ServoAdded_servo_pin_tag 2
#define wippersnapper_servo_ServoRemove_servo_pin_tag 1
#define wippersnapper_servo_ServoWrite_servo_pin_tag 1
#define wippersnapper_servo_ServoWrite_pulse_width_tag 2

/* Struct field encoding specification for nanopb */
#define wippersnapper_servo_ServoAdd_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   servo_pin,         1) \
X(a, STATIC,   SINGULAR, INT32,    servo_freq,        2) \
X(a, STATIC,   SINGULAR, INT32,    min_pulse_width,   3) \
X(a, STATIC,   SINGULAR, INT32,    max_pulse_width,   4)
#define wippersnapper_servo_ServoAdd_CALLBACK pb_default_field_callback
#define wippersnapper_servo_ServoAdd_DEFAULT NULL

#define wippersnapper_servo_ServoAdded_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     attach_success,    1) \
X(a, CALLBACK, SINGULAR, STRING,   servo_pin,         2)
#define wippersnapper_servo_ServoAdded_CALLBACK pb_default_field_callback
#define wippersnapper_servo_ServoAdded_DEFAULT NULL

#define wippersnapper_servo_ServoRemove_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   servo_pin,         1)
#define wippersnapper_servo_ServoRemove_CALLBACK pb_default_field_callback
#define wippersnapper_servo_ServoRemove_DEFAULT NULL

#define wippersnapper_servo_ServoWrite_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   servo_pin,         1) \
X(a, STATIC,   SINGULAR, INT32,    pulse_width,       2)
#define wippersnapper_servo_ServoWrite_CALLBACK pb_default_field_callback
#define wippersnapper_servo_ServoWrite_DEFAULT NULL

extern const pb_msgdesc_t wippersnapper_servo_ServoAdd_msg;
extern const pb_msgdesc_t wippersnapper_servo_ServoAdded_msg;
extern const pb_msgdesc_t wippersnapper_servo_ServoRemove_msg;
extern const pb_msgdesc_t wippersnapper_servo_ServoWrite_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define wippersnapper_servo_ServoAdd_fields &wippersnapper_servo_ServoAdd_msg
#define wippersnapper_servo_ServoAdded_fields &wippersnapper_servo_ServoAdded_msg
#define wippersnapper_servo_ServoRemove_fields &wippersnapper_servo_ServoRemove_msg
#define wippersnapper_servo_ServoWrite_fields &wippersnapper_servo_ServoWrite_msg

/* Maximum encoded size of messages (where known) */
/* wippersnapper_servo_ServoAdd_size depends on runtime parameters */
/* wippersnapper_servo_ServoAdded_size depends on runtime parameters */
/* wippersnapper_servo_ServoRemove_size depends on runtime parameters */
/* wippersnapper_servo_ServoWrite_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif