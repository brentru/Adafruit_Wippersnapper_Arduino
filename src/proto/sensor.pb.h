/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.3-dev */

#ifndef PB_SENSOR_V1_SENSOR_V1_SENSOR_PB_H_INCLUDED
#define PB_SENSOR_V1_SENSOR_V1_SENSOR_PB_H_INCLUDED
#include <nanopb/pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _sensor_v1_SensorResponses {
    sensor_v1_SensorResponses_SENSOR_RESPONSES_UNSPECIFIED = 0,
    sensor_v1_SensorResponses_SENSOR_RESPONSES_OK = 1,
    sensor_v1_SensorResponses_SENSOR_RESPONSES_DUPLICATE_ID = 2,
    sensor_v1_SensorResponses_SENSOR_RESPONSES_MISSING_SENSOR_ID = 3,
    sensor_v1_SensorResponses_SENSOR_RESPONSES_INVALID_SENSOR_TYPE = 4,
    sensor_v1_SensorResponses_SENSOR_RESPONSES_MAX_MIN_VALUE_TYPE = 5,
    sensor_v1_SensorResponses_SENSOR_RESPONSES_MEASUREMENT_PERIOD_INVALID = 6
} sensor_v1_SensorResponses;

typedef enum _sensor_v1_AttachOrUpdateSensorRequest_SensorType {
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_UNSPECIFIED = 0,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_ACCELEROMETER = 1,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_MAGNETIC_FIELD = 2,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_ORIENTATION = 3,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_GYROSCOPE = 4,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_LIGHT = 5,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_PRESSURE = 6,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_PROXIMITY = 8,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_GRAVITY = 9,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_LINEAR_ACCELERATION = 10,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_ROTATION_VECTOR = 11,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_RELATIVE_HUMIDITY = 12,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_AMBIENT_TEMPERATURE = 13,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_OBJECT_TEMPERATURE = 14,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_VOLTAGE = 15,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_CURRENT = 16,
    sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_COLOR = 17
} sensor_v1_AttachOrUpdateSensorRequest_SensorType;

/* Struct definitions */
typedef struct _sensor_v1_AttachOrUpdateSensorRequest {
    pb_callback_t name;
    int32_t sensor_id;
    sensor_v1_AttachOrUpdateSensorRequest_SensorType sensor_type;
    float max_value;
    float min_value;
    int32_t measurement_period;
} sensor_v1_AttachOrUpdateSensorRequest;

typedef struct _sensor_v1_AttachOrUpdateSensorResponse {
    sensor_v1_SensorResponses response;
} sensor_v1_AttachOrUpdateSensorResponse;

typedef struct _sensor_v1_DetachSensorRequest {
    int32_t sensor_id;
} sensor_v1_DetachSensorRequest;

typedef struct _sensor_v1_DetachSensorResponse {
    sensor_v1_SensorResponses response;
} sensor_v1_DetachSensorResponse;

typedef struct _sensor_v1_SensorEventRequest_SensorColor {
    float r;
    float g;
    float b;
    uint32_t rgba;
} sensor_v1_SensorEventRequest_SensorColor;

typedef struct _sensor_v1_SensorEventRequest_SensorVect {
    float x;
    float y;
    float z;
    float roll;
    float pitch;
    float heading;
    pb_callback_t status;
} sensor_v1_SensorEventRequest_SensorVect;

typedef struct _sensor_v1_SensorEventResponse {
    sensor_v1_SensorResponses response;
} sensor_v1_SensorEventResponse;

typedef struct _sensor_v1_SensorEventRequest {
    int32_t sensor_id;
    int32_t timestamp;
    pb_size_t which_value;
    union {
        float data;
        float temperature;
        float distance;
        float light;
        float pressure;
        float relative_humidity;
        float current;
        float voltage;
        sensor_v1_SensorEventRequest_SensorVect acceleration;
        sensor_v1_SensorEventRequest_SensorVect magnetic;
        sensor_v1_SensorEventRequest_SensorVect orientation;
        sensor_v1_SensorEventRequest_SensorVect gyro;
        sensor_v1_SensorEventRequest_SensorColor colors;
    } value;
} sensor_v1_SensorEventRequest;


/* Helper constants for enums */
#define _sensor_v1_SensorResponses_MIN sensor_v1_SensorResponses_SENSOR_RESPONSES_UNSPECIFIED
#define _sensor_v1_SensorResponses_MAX sensor_v1_SensorResponses_SENSOR_RESPONSES_MEASUREMENT_PERIOD_INVALID
#define _sensor_v1_SensorResponses_ARRAYSIZE ((sensor_v1_SensorResponses)(sensor_v1_SensorResponses_SENSOR_RESPONSES_MEASUREMENT_PERIOD_INVALID+1))

#define _sensor_v1_AttachOrUpdateSensorRequest_SensorType_MIN sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_UNSPECIFIED
#define _sensor_v1_AttachOrUpdateSensorRequest_SensorType_MAX sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_COLOR
#define _sensor_v1_AttachOrUpdateSensorRequest_SensorType_ARRAYSIZE ((sensor_v1_AttachOrUpdateSensorRequest_SensorType)(sensor_v1_AttachOrUpdateSensorRequest_SensorType_SENSOR_TYPE_COLOR+1))


/* Initializer values for message structs */
#define sensor_v1_AttachOrUpdateSensorRequest_init_default {{{NULL}, NULL}, 0, _sensor_v1_AttachOrUpdateSensorRequest_SensorType_MIN, 0, 0, 0}
#define sensor_v1_AttachOrUpdateSensorResponse_init_default {_sensor_v1_SensorResponses_MIN}
#define sensor_v1_DetachSensorRequest_init_default {0}
#define sensor_v1_DetachSensorResponse_init_default {_sensor_v1_SensorResponses_MIN}
#define sensor_v1_SensorEventRequest_init_default {0, 0, 0, {0}}
#define sensor_v1_SensorEventRequest_SensorVect_init_default {0, 0, 0, 0, 0, 0, {{NULL}, NULL}}
#define sensor_v1_SensorEventRequest_SensorColor_init_default {0, 0, 0, 0}
#define sensor_v1_SensorEventResponse_init_default {_sensor_v1_SensorResponses_MIN}
#define sensor_v1_AttachOrUpdateSensorRequest_init_zero {{{NULL}, NULL}, 0, _sensor_v1_AttachOrUpdateSensorRequest_SensorType_MIN, 0, 0, 0}
#define sensor_v1_AttachOrUpdateSensorResponse_init_zero {_sensor_v1_SensorResponses_MIN}
#define sensor_v1_DetachSensorRequest_init_zero  {0}
#define sensor_v1_DetachSensorResponse_init_zero {_sensor_v1_SensorResponses_MIN}
#define sensor_v1_SensorEventRequest_init_zero   {0, 0, 0, {0}}
#define sensor_v1_SensorEventRequest_SensorVect_init_zero {0, 0, 0, 0, 0, 0, {{NULL}, NULL}}
#define sensor_v1_SensorEventRequest_SensorColor_init_zero {0, 0, 0, 0}
#define sensor_v1_SensorEventResponse_init_zero  {_sensor_v1_SensorResponses_MIN}

/* Field tags (for use in manual encoding/decoding) */
#define sensor_v1_AttachOrUpdateSensorRequest_name_tag 1
#define sensor_v1_AttachOrUpdateSensorRequest_sensor_id_tag 2
#define sensor_v1_AttachOrUpdateSensorRequest_sensor_type_tag 3
#define sensor_v1_AttachOrUpdateSensorRequest_max_value_tag 4
#define sensor_v1_AttachOrUpdateSensorRequest_min_value_tag 5
#define sensor_v1_AttachOrUpdateSensorRequest_measurement_period_tag 7
#define sensor_v1_AttachOrUpdateSensorResponse_response_tag 1
#define sensor_v1_DetachSensorRequest_sensor_id_tag 1
#define sensor_v1_DetachSensorResponse_response_tag 1
#define sensor_v1_SensorEventRequest_SensorColor_r_tag 1
#define sensor_v1_SensorEventRequest_SensorColor_g_tag 2
#define sensor_v1_SensorEventRequest_SensorColor_b_tag 3
#define sensor_v1_SensorEventRequest_SensorColor_rgba_tag 4
#define sensor_v1_SensorEventRequest_SensorVect_x_tag 1
#define sensor_v1_SensorEventRequest_SensorVect_y_tag 2
#define sensor_v1_SensorEventRequest_SensorVect_z_tag 3
#define sensor_v1_SensorEventRequest_SensorVect_roll_tag 4
#define sensor_v1_SensorEventRequest_SensorVect_pitch_tag 5
#define sensor_v1_SensorEventRequest_SensorVect_heading_tag 6
#define sensor_v1_SensorEventRequest_SensorVect_status_tag 7
#define sensor_v1_SensorEventResponse_response_tag 1
#define sensor_v1_SensorEventRequest_sensor_id_tag 1
#define sensor_v1_SensorEventRequest_timestamp_tag 2
#define sensor_v1_SensorEventRequest_data_tag    3
#define sensor_v1_SensorEventRequest_temperature_tag 4
#define sensor_v1_SensorEventRequest_distance_tag 5
#define sensor_v1_SensorEventRequest_light_tag   6
#define sensor_v1_SensorEventRequest_pressure_tag 7
#define sensor_v1_SensorEventRequest_relative_humidity_tag 8
#define sensor_v1_SensorEventRequest_current_tag 9
#define sensor_v1_SensorEventRequest_voltage_tag 10
#define sensor_v1_SensorEventRequest_acceleration_tag 11
#define sensor_v1_SensorEventRequest_magnetic_tag 12
#define sensor_v1_SensorEventRequest_orientation_tag 13
#define sensor_v1_SensorEventRequest_gyro_tag    14
#define sensor_v1_SensorEventRequest_colors_tag  15

/* Struct field encoding specification for nanopb */
#define sensor_v1_AttachOrUpdateSensorRequest_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   name,              1) \
X(a, STATIC,   SINGULAR, INT32,    sensor_id,         2) \
X(a, STATIC,   SINGULAR, UENUM,    sensor_type,       3) \
X(a, STATIC,   SINGULAR, FLOAT,    max_value,         4) \
X(a, STATIC,   SINGULAR, FLOAT,    min_value,         5) \
X(a, STATIC,   SINGULAR, INT32,    measurement_period,   7)
#define sensor_v1_AttachOrUpdateSensorRequest_CALLBACK pb_default_field_callback
#define sensor_v1_AttachOrUpdateSensorRequest_DEFAULT NULL

#define sensor_v1_AttachOrUpdateSensorResponse_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response,          1)
#define sensor_v1_AttachOrUpdateSensorResponse_CALLBACK NULL
#define sensor_v1_AttachOrUpdateSensorResponse_DEFAULT NULL

#define sensor_v1_DetachSensorRequest_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    sensor_id,         1)
#define sensor_v1_DetachSensorRequest_CALLBACK NULL
#define sensor_v1_DetachSensorRequest_DEFAULT NULL

#define sensor_v1_DetachSensorResponse_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response,          1)
#define sensor_v1_DetachSensorResponse_CALLBACK NULL
#define sensor_v1_DetachSensorResponse_DEFAULT NULL

#define sensor_v1_SensorEventRequest_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    sensor_id,         1) \
X(a, STATIC,   SINGULAR, INT32,    timestamp,         2) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,data,value.data),   3) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,temperature,value.temperature),   4) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,distance,value.distance),   5) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,light,value.light),   6) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,pressure,value.pressure),   7) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,relative_humidity,value.relative_humidity),   8) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,current,value.current),   9) \
X(a, STATIC,   ONEOF,    FLOAT,    (value,voltage,value.voltage),  10) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,acceleration,value.acceleration),  11) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,magnetic,value.magnetic),  12) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,orientation,value.orientation),  13) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,gyro,value.gyro),  14) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,colors,value.colors),  15)
#define sensor_v1_SensorEventRequest_CALLBACK NULL
#define sensor_v1_SensorEventRequest_DEFAULT NULL
#define sensor_v1_SensorEventRequest_value_acceleration_MSGTYPE sensor_v1_SensorEventRequest_SensorVect
#define sensor_v1_SensorEventRequest_value_magnetic_MSGTYPE sensor_v1_SensorEventRequest_SensorVect
#define sensor_v1_SensorEventRequest_value_orientation_MSGTYPE sensor_v1_SensorEventRequest_SensorVect
#define sensor_v1_SensorEventRequest_value_gyro_MSGTYPE sensor_v1_SensorEventRequest_SensorVect
#define sensor_v1_SensorEventRequest_value_colors_MSGTYPE sensor_v1_SensorEventRequest_SensorColor

#define sensor_v1_SensorEventRequest_SensorVect_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    x,                 1) \
X(a, STATIC,   SINGULAR, FLOAT,    y,                 2) \
X(a, STATIC,   SINGULAR, FLOAT,    z,                 3) \
X(a, STATIC,   SINGULAR, FLOAT,    roll,              4) \
X(a, STATIC,   SINGULAR, FLOAT,    pitch,             5) \
X(a, STATIC,   SINGULAR, FLOAT,    heading,           6) \
X(a, CALLBACK, SINGULAR, BYTES,    status,            7)
#define sensor_v1_SensorEventRequest_SensorVect_CALLBACK pb_default_field_callback
#define sensor_v1_SensorEventRequest_SensorVect_DEFAULT NULL

#define sensor_v1_SensorEventRequest_SensorColor_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    r,                 1) \
X(a, STATIC,   SINGULAR, FLOAT,    g,                 2) \
X(a, STATIC,   SINGULAR, FLOAT,    b,                 3) \
X(a, STATIC,   SINGULAR, UINT32,   rgba,              4)
#define sensor_v1_SensorEventRequest_SensorColor_CALLBACK NULL
#define sensor_v1_SensorEventRequest_SensorColor_DEFAULT NULL

#define sensor_v1_SensorEventResponse_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response,          1)
#define sensor_v1_SensorEventResponse_CALLBACK NULL
#define sensor_v1_SensorEventResponse_DEFAULT NULL

extern const pb_msgdesc_t sensor_v1_AttachOrUpdateSensorRequest_msg;
extern const pb_msgdesc_t sensor_v1_AttachOrUpdateSensorResponse_msg;
extern const pb_msgdesc_t sensor_v1_DetachSensorRequest_msg;
extern const pb_msgdesc_t sensor_v1_DetachSensorResponse_msg;
extern const pb_msgdesc_t sensor_v1_SensorEventRequest_msg;
extern const pb_msgdesc_t sensor_v1_SensorEventRequest_SensorVect_msg;
extern const pb_msgdesc_t sensor_v1_SensorEventRequest_SensorColor_msg;
extern const pb_msgdesc_t sensor_v1_SensorEventResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define sensor_v1_AttachOrUpdateSensorRequest_fields &sensor_v1_AttachOrUpdateSensorRequest_msg
#define sensor_v1_AttachOrUpdateSensorResponse_fields &sensor_v1_AttachOrUpdateSensorResponse_msg
#define sensor_v1_DetachSensorRequest_fields &sensor_v1_DetachSensorRequest_msg
#define sensor_v1_DetachSensorResponse_fields &sensor_v1_DetachSensorResponse_msg
#define sensor_v1_SensorEventRequest_fields &sensor_v1_SensorEventRequest_msg
#define sensor_v1_SensorEventRequest_SensorVect_fields &sensor_v1_SensorEventRequest_SensorVect_msg
#define sensor_v1_SensorEventRequest_SensorColor_fields &sensor_v1_SensorEventRequest_SensorColor_msg
#define sensor_v1_SensorEventResponse_fields &sensor_v1_SensorEventResponse_msg

/* Maximum encoded size of messages (where known) */
/* sensor_v1_AttachOrUpdateSensorRequest_size depends on runtime parameters */
#define sensor_v1_AttachOrUpdateSensorRequest_size -1
#define sensor_v1_AttachOrUpdateSensorResponse_size 2
#define sensor_v1_DetachSensorRequest_size       11
#define sensor_v1_DetachSensorResponse_size      2
/* sensor_v1_SensorEventRequest_size depends on runtime parameters */
#define sensor_v1_SensorEventRequest_size -1
/* sensor_v1_SensorEventRequest_SensorVect_size depends on runtime parameters */
#define sensor_v1_SensorEventRequest_SensorColor_size 21
#define sensor_v1_SensorEventResponse_size       2

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
