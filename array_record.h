#ifndef __LOGC_ARRAY_RECORD_H__
#define __LOGC_ARRAY_RECORD_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdarg.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */



/* =========== DATA TYPES ================================================== */

/*
 * record struct for array logging
 */
struct arrayRecord_s {
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
   /* descriptor */
   const char* descriptor;
   /* data */
   const uint8_t* array;
   /* length of data */
   size_t len;
};
typedef struct arrayRecord_s arrayRecord_t;

/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * create a new array record
 * allocated on heap, rec->newRecord must be freed by the caller
 *
 * @param rec            in : array record struct
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_NULL if parameter rec is NULL
 *                       LOG_ERR_PARAM for invalid record type
 *                       LOG_ERR_MEM if no memory could be allocated
 */
logc_error_t
newArrayRecord(
      arrayRecord_t* rec
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * delete a array record
 * frees rec->newRecord
 *
 * @param rec            in : array record struct
 */
void
deleteArrayRecord(
      arrayRecord_t* rec
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif
/* ========================== END OF FILE ================================== */

