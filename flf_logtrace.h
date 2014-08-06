
#ifndef __LOGC_FLF_LOGTRACE_H__
#define __LOGC_FLF_LOGTRACE_H__


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
 * trace logger
 * loggs entering of a function
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * used to trace function calls
 * log level is LOG_FINEST
 *
 * @param file           in : __FILE__
 * @param line           in : __LINE__
 * @param func           in : __func__
 * @param ident          in : identifier of the logger
 * @param functionName   in : name of the function
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       LOG_ERR_MEM if needed memory could not be
 *                       allocated
 */
logc_error_t
logc_logEnter_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      const char* functionName
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * trace logger
 * loggs leaving of a function
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * used to trace function calls
 * log level is LOG_FINEST
 *
 * @param file           in : __FILE__
 * @param line           in : __LINE__
 * @param func           in : __func__
 * @param ident          in : identifier of the logger
 * @param functionName   in : name of the function
 * @return logc_error_t   LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       LOG_ERR_MEM if needed memory could not be
 *                       allocated
 */
logc_error_t
logc_logLeave_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      const char* functionName
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif /* header guard */
/* ========================== END OF FILE ================================== */

