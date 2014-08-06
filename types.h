
#ifndef __LOGC_TYPES_H__
#define __LOGC_TYPES_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */

/*
 * log errors
 */
#define LOG_ERR_OK                   0x00000000

#define LOG_ERR_DATA                 0x00000001

#define LOG_ERR_PARAM                0x00000002

#define LOG_ERR_MEM                  0x00000003

#define LOG_ERR_NOT_FOUND            0x00000004

#define LOG_ERR_LEVEL                0x00000005

#define LOG_ERR_NULL                 0x00000006

#define LOG_ERR_OPEN_FILE            0x00000007

#define LOG_ERR_NO_ENTRIES           0x00000008

#define LOG_ERR_INSUFFICIENT_BUFFER  0x00000009

#define LOG_ERR_CREATE_RNGBUF        0x0000000A

#define LOG_ERR_NO_RNGBUF            0x0000000B

#define LOG_ERR_WRONG_TYPE           0x0000000C

#define LOG_ERR_NOT_IMPLEMENTED      0x00000010


/* =========== DATA TYPES ================================================== */

/* log error type */
typedef uint32_t logc_error_t;

/*
 * boolean type
 */
typedef enum {
   LOG_TRUE = 1,
   LOG_FALSE = 0
} logc_bool_t;

/*
 * log levels enumeration
 */
typedef enum {
   /* no logging */
   LOG_SILENT,
   /* severe message or error message */
   LOG_BASIC,
   /* warning message */
   LOG_WARNING,
   /* an info message */
   LOG_INFO,
   /* debug message */
   LOG_FINE,
   /* a detailed debug message */
   LOG_FINEST

} logc_logLevel_t;


/*
 * output types
 */
typedef enum {
   /* standard output */
   STDOUT,
   /* standard error output */
   STDERROUT,
   /* file output */
   FILEOUT,
   /* ringbuffer output */
   RBUFOUT
   /*syslog output*/
   SYSLOG

} logc_loggerType_t;


/*
 * type of error record format
 */
typedef enum {
   /* ERR: message */
   ERR,
   /* ERR 0xYYYYYYYY: message */
   ERR_TAG,
   /* ERR: 0xYYYYYYYY <timestamp>: message */
   ERR_TAG_TIMESTAMP,
   /* ERR <timestamp> 0xYYYYYYYY: message */
   ERR_TIMESTAMP_TAG,
   /* <timestamp> ERR: 0xYYYYYYYY: message */
   TIMESTAMP_ERR_TAG

} logc_errRecordType_t;

/*
 * type of log record format
 */
typedef enum {
   /* message */
   CLEAN,
   /* <timestamp> message */
   TIMESTAMP

} logc_logRecordType_t;



/*
 * type of tag format
 */
typedef struct {
    /* Tag Category */
    char *category;
    LoggingTagsList *next;
} LoggingTagsList;

/*
 * channel format
 */
 
typedef struct {
    /* Channel Type */
    int channel_type;
    int channel_number;
    char *channel_parameter;
    LoggingTagsList categories;
    LoggingChannel *next;
} LoggingChannel;

/* =========== PUBLIC PROTOTYPES =========================================== */

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif /* header guard */
/* ========================== END OF FILE ================================== */


