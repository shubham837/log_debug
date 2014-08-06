
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "flf_log.h"

#include "logger.h"
#include "log_record.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
logc_log_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_logLevel_t level,
      const char* formatStr,
      ...
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   va_list vaList;
   logRecord_t record = {0};

   if (formatStr == NULL) {
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
         va_start(vaList, formatStr);
         record.file = file;
         record.line = line;
         record.function = func;
         record.rtype = logger->logRecordType;
         record.formatStr = formatStr;
         record.vaList = &vaList;
         err = newLogRecord(&record);
         if (err == LOG_ERR_OK) {
            logger->publisher(record.newRecord, record.vaList, logger->dest);
            deleteLogRecord(&record);
         }
         va_end(vaList);
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */
/* ========================== END OF FILE ================================== */

