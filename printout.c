/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "printout.h"
#include "ringbuffer.h"

#include "types.h"

#include <stdio.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logc_error_t
prn_stdprint(
      const char* const message,
      va_list* vaList,
      void* dest
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL) {
      err = LOG_ERR_NULL;
   } else {
      if (vaList != NULL) {
         vfprintf(stdout, message, *vaList);
      } else {
         fputs(message, stdout);
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_stderrprint(
      const char* const message,
      va_list* vaList,
      void* dest
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL) {
      err = LOG_ERR_NULL;
   } else {
      if (vaList != NULL) {
         vfprintf(stderr, message, *vaList);
      } else {
         fputs(message, stderr);
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_fileprint(
      const char* const message,
      va_list* vaList,
      void* dest
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL || dest == NULL) {
      err = LOG_ERR_NULL;
   } else {
      if (vaList != NULL) {
         vfprintf((FILE*)dest, message, *vaList);
      } else {
         fputs(message, (FILE*)dest);
      }
      fflush((FILE*)dest);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_rbufprint(
      const char* const message,
      va_list* vaList,
      void* dest
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL || dest == NULL) {
      err = LOG_ERR_NULL;
   } else {
      if (vaList != NULL) {
         char tmp[256] = {0};
         vsnprintf(tmp, sizeof(tmp), message, *vaList);
         err = rng_writeRingbuffer((rng_ringBuffer_t*)dest, tmp);
      } else {
         err = rng_writeRingbuffer((rng_ringBuffer_t*)dest, message);
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */
/* ========================== END OF FILE ================================== */
