#include "LibIEEE.h"
#include "Floor.h"
#include "IsInf.h"
#include "LibTrig.h"

          cosX = C_ONE_FLOAT - ((X * X) / C_TWO_FLOAT);       }       else       {          cosX = ((-C_C[6]) * C_Z) + C_ONE_FLOAT;          cosX = ((cosX * C_C[5]) * C_Z) - C_ONE_FLOAT;          cosX = ((cosX * C_C[4]) * C_Z) + C_ONE_FLOAT;          cosX = ((cosX * C_C[3]) * C_Z) - C_ONE_FLOAT;          cosX = ((cosX * C_C[2]) * C_Z) + C_ONE_FLOAT;          cosX = ((cosX * C_C[1]) * C_Z) - C_ONE_FLOAT;          cosX = ((cosX * C_C[0]) * C_Z) + C_ONE_FLOAT;       }
