
#ifndef __LOGC_PRINTOUT_H__
#define __LOGC_PRINTOUT_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * print message to standard out
 *
 * @param message        in : logging message
 * @param vaList         in : va_list of formatStr, could be NULL
 * @param dest           in : not used could be NULL
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message is NULL
 */
logc_error_t
prn_stdprint(
      const char* const message,
      va_list* vaList,
      void* dest
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to standard err
 *
 * @param message        in : logging message
 * @param vaList         in : va_list of formatStr, could be NULL
 * @param dest           in : not used could be NULL
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message is NULL
 */
logc_error_t
prn_stderrprint(
      const char* const message,
      va_list* vaList,
      void* dest
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to log file
 *
 * @param message        in : logging message
 * @param vaList         in : va_list of formatStr, could be NULL
 * @param dest           in : file descriptor for logging file
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message or fd is NULL
 */
logc_error_t
prn_fileprint(
      const char* const message,
      va_list* vaList,
      void* dest
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to ringbuffer
 *
 * @param message        in : logging message
 * @param vaList         in : va_list of formatStr, could be NULL
 * @param dest           in : pointer to ringbuffer
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message or fd is NULL
 *                       TODO not implemented
 */
logc_error_t
prn_rbufprint(
      const char* const message,
      va_list* vaList,
      void* dest
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif /* header guard */
/* ========================== END OF FILE ================================== */

