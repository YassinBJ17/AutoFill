#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_MatchingFiles.h"

     if((uint32_t)(((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->NumberOfLUP_Files)          != NumberOfDataFiles)     {         *OutOfOperationalConditionSUP = TRUE;         return;     }
