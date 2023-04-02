#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_MatchingFiles.h"

    else if ( (((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->OnBoardRunningLoad) != 0x55555555 )    {       *OutOfOperationalConditionSUP = e_CMN_FLAG_YES;       return;    }
