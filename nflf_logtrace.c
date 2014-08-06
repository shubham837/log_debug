
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "nflf_logtrace.h"

#include "logger.h"

#include <stdlib.h>
#include <string.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
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
logc_logEnter_nflf_(
      uint16_t ident,
      const char* functionName
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   char* record = NULL;

   if (functionName == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else {
         if (logger->level < LOG_FINEST) {
            err = LOG_ERR_LEVEL;
         }
      }
   }

   if (err == LOG_ERR_OK) {
      record = malloc(strlen(functionName) + sizeof("Enter > ") + 1);
      if (record == NULL) {
         err = LOG_ERR_MEM;
      } else {
         sprintf(record, "Enter > %s\n", functionName);
         logger->publisher(record, NULL, logger->dest);
      }
   }

   if (record != NULL) {
      free(record);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_logLeave_nflf_(
      uint16_t ident,
      const char* functionName
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   char* record = NULL;

   if (functionName == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else {
         if (logger->level < LOG_FINEST) {
            err = LOG_ERR_LEVEL;
         }
      }
   }

   if (err == LOG_ERR_OK) {
      record = malloc(strlen(functionName) + sizeof("Leave < ") + 1);
      if (record == NULL) {
         err = LOG_ERR_MEM;
      } else {
         sprintf(record, "Leave < %s\n", functionName);
         logger->publisher(record, NULL, logger->dest);
      }
   }

   if (record != NULL) {
      free(record);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */
/* ========================== END OF FILE ================================== */

