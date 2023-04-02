#include "LibIEEE.h"
#include "Floor.h"
#include "IsInf.h"
#include "LibTrig.h"

       if (IsZeroOrSubnormalX != FALSE)       {          *pa_RedX = C_ZERO_FLOAT;       }       else       {             reduceAngle = (absX - (y * M_D_PI_2)) - (y * M_D_PI_2_LOW);          if (reduceAngle < -(M_D_PI_4 + M_D_PI_4_LOW))          {             reduceAngle = -(M_D_PI_4 + M_D_PI_4_LOW);          }          *pa_RedX = reduceAngle;       }
