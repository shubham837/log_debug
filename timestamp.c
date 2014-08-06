/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "timestamp.h"

#if defined TM_IN_SYS_TIME
#include <sys/time.h>
#endif

#if defined (HAVE_TIME_H) && defined (HAVE_STRFTIME)
#include <time.h>
#else
#define NO_TIMESTAMP
#include <stdio.h>
#endif

/* =========== PUBLIC FUNCTIONS ============================================ */

void
addTimestamp(
      char* str
      )
{
#ifndef NO_TIMESTAMP
   struct tm tim;
   time_t now;
#endif

   if (str != NULL) {
#ifndef NO_TIMESTAMP
      now = time(NULL);
      tim = *(localtime(&now));
      strftime(str, TIMEST_LENGTH, "%c", &tim);
#else
      const char* noTm = "<no timestamp on host>  ";
      sprintf(str, "%s", noTm);
#endif
      str[TIMEST_LENGTH-1] = 0x20;
   }
}


