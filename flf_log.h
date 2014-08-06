
#ifndef __LOGC_FLF_LOG_H__
#define __LOGC_FLF_LOG_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger and log level
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param file           in : __FILE__
 * @param line           in : __LINE__
 * @param func           in : __func__
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newLogRecord function
 */
logc_error_t
logc_log_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_logLevel_t level,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif /* header guard */
/* ========================== END OF FILE ================================== */

