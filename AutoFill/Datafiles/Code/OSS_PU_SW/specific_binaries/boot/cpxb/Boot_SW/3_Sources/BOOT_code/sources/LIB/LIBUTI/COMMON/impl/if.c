#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_MatchingFiles.h"

    if ( (((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->OnBoardRunningLoad) == 0xFFFFFFFF )    {       *LoadLoadedByBoot = e_CMN_FLAG_YES;    }
