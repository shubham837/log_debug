
#ifndef __LOGC_FLF_LOGARRAY_H__
#define __LOGC_FLF_LOGARRAY_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger and log level
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param file           in : __FILE__
 * @param line           in : __LINE__
 * @param func           in : __func__
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newArrayRecord function
 */
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
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif /* header guard */
/* ========================== END OF FILE ================================== */

