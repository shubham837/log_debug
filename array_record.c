
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "array_record.h"

#include "timestamp.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* =========== DEFINES ===================================================== */

#define MAX_INT   10

/* =========== PRIVATE PROTOTYPES ========================================== */
static void
clean_record(
      arrayRecord_t* rec
      );


static void
timestamp_record(
      arrayRecord_t* rec
      );

/* =========== PUBLIC FUNCTIONS ============================================ */

logc_error_t
newArrayRecord(
      arrayRecord_t* rec
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (rec == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      rec->newRecord = NULL;
      switch (rec->rtype) {
         case CLEAN:
            clean_record(rec);
            break;
         case TIMESTAMP:
            timestamp_record(rec);
            break;
         default:
            err = LOG_ERR_PARAM;
            break;
      }
   }

   if (err == LOG_ERR_OK) {
      if (rec->newRecord == NULL) {
         err = LOG_ERR_MEM;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
void
deleteArrayRecord(
      arrayRecord_t* rec
      )
{
   if (rec != NULL) {
      if (rec->newRecord != NULL) {
         free(rec->newRecord);
      }
   }
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */

/*---------------------------------------------------------------------------*/
static void
clean_record(
      arrayRecord_t* rec
      )
{
   int recordSize = 0;
   logc_bool_t flf = LOG_FALSE;
   int i = 0;

   if (rec->file == NULL) {
      recordSize = strlen(rec->descriptor) + strlen(" : ") +
         (rec->len * 2) + 2;
   } else {
      flf = LOG_TRUE;
      recordSize = strlen(rec->file) + MAX_INT + strlen(rec->function) +
         strlen(rec->descriptor) + strlen(" : ") + (rec->len * 2) +
         strlen(": - ") + 2;
   }
   rec->newRecord = malloc(recordSize);

   if (rec->newRecord != NULL) {
      memset(rec->newRecord, 0, recordSize);
      if (flf == LOG_TRUE) {
         sprintf(rec->newRecord, "%s:%d %s - ",
               rec->file, rec->line, rec->function);
      }
      sprintf(rec->newRecord + strlen(rec->newRecord), "%s : ", rec->descriptor);

      for (i=0; i<rec->len; i++) {
         sprintf(rec->newRecord + strlen(rec->newRecord), "%02X",
               rec->array[i]);
      }

      rec->newRecord[strlen(rec->newRecord)] = '\n';
   }
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
static void
timestamp_record(
      arrayRecord_t* rec
      )
{
   const char* timest = "day mon dd hh:mm:ss YYYY ";
   int recordSize = 0;
   logc_bool_t flf = LOG_FALSE;
   int i = 0;

   if (rec->file == NULL) {
      recordSize = strlen(rec->descriptor) + strlen(" : ") + (rec->len * 2) +
         strlen(timest) + 2;
   } else {
      flf = LOG_TRUE;
      recordSize = strlen(rec->file) + MAX_INT + strlen(rec->function) +
         strlen(rec->descriptor) + strlen(" : ") + (rec->len * 2) +
         strlen(timest) + strlen(": - ") + 2;
   }
   rec->newRecord = malloc(recordSize);

   if (rec->newRecord != NULL) {
      memset(rec->newRecord, 0, recordSize);
      strcpy(rec->newRecord, timest);
      addTimestamp(rec->newRecord);
      if (flf == LOG_TRUE) {
         sprintf(rec->newRecord + strlen(rec->newRecord), "%s:%d %s - ",
               rec->file, rec->line, rec->function);
      }
      sprintf(rec->newRecord + strlen(rec->newRecord), "%s : ",
            rec->descriptor);

      for (i=0; i<rec->len; i++) {
         sprintf(rec->newRecord + strlen(rec->newRecord), "%02X",
               rec->array[i]);
      }

      rec->newRecord[strlen(rec->newRecord)] = '\n';
   }
}


