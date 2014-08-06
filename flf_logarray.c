
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "flf_logarray.h"

#include "logger.h"
#include "array_record.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */

#define MAX_INT   10

/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
extern logger_t*
getLogger(
      uint16_t ident
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_logArray_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_logLevel_t level,
      const char* descriptor,
      const uint8_t* array,
      size_t len
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   arrayRecord_t record = {0};

   if (descriptor == NULL || array == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      }
   }

   if (err == LOG_ERR_OK) {
      if (logger->level < level) {
         err = LOG_ERR_LEVEL;
      } else {
         record.file = file;
         record.line = line;
         record.function = func;
         record.rtype = logger->logRecordType;
         record.descriptor = descriptor;
         record.array = array;
         record.len = len;
         err = newArrayRecord(&record);
         if (err == LOG_ERR_OK) {
            logger->publisher(record.newRecord, NULL, logger->dest);
            deleteArrayRecord(&record);
         }
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */
/* ========================== END OF FILE ================================== */

