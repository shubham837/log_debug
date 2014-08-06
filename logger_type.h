
#ifndef __LOGC_LOGGGER_TYPE__H__
#define __LOGC_LOGGGER_TYPE_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"
#include "ringbuffer.h"

#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */

/* typedef for publisher function */
typedef logc_error_t (*publisher_t)(
      const char* const message,
      va_list* vaList,
      void* dest
      );

/* logger type */
struct logger_s {
   /* identifier of the logger */
   uint16_t id;
   /* logger output type */
   logc_loggerType_t type;
   /* log level */
   logc_logLevel_t level;
   /* record type for error logging */
   logc_errRecordType_t errRecordType;
   /* record type for log logging */
   logc_logRecordType_t logRecordType;
   /* pointer to publisher function */
   publisher_t publisher;
   /* destination to write */
   void* dest;
};
typedef struct logger_s logger_t;

/* =========== PUBLIC PROTOTYPES =========================================== */

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif
/* ========================== END OF FILE ================================== */
