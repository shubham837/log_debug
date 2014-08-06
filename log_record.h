
#ifndef __LOGC_LOG_RECORD_H__
#define __LOGC_LOG_RECORD_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */

/* =========== DATA TYPES ================================================== */

/*
 * record struct for logging
 */
struct logRecord_s {
   /* __FILE__ */
   const char* file;
   /* __LINE__ */
   int line;
   /* __FUNCTION__ */
   const char* function;
   /* pointer to new record */
   char* newRecord;
   /* record type */
   logc_logRecordType_t rtype;
   /* format string */
   const char* formatStr;
   /* arguments of format string */
   va_list* vaList;
};
typedef struct logRecord_s logRecord_t;

/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * create a new log record
 * allocated on heap, rec->newRecord must be freed by the caller
 *
 * @param rec            in : log record struct
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_NULL if parameter rec is NULL
 *                       LOG_ERR_PARAM for invalid record type
 *                       LOG_ERR_MEM if no memory could be allocated
 */
logc_error_t
newLogRecord(
      logRecord_t* rec
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * delete a log record
 * frees rec->newRecord
 *
 * @param rec            in : log record struct
 */
void
deleteLogRecord(
      logRecord_t* rec
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif
/* ========================== END OF FILE ================================== */

