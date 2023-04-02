#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "HW_TB.h"
#include "smi.h"
#include "etsec.h"
#include "phy.h"

    for( timeout = (int32_t)0 ; timeout < (int32_t)1000 ; timeout ++ )    {       val = (int32_t)phy_read(phy, (uint32_t)MII_BMCR);       HW_TB_wait(1000ul);       if((val & (int32_t)BMCR_RESET) == (int32_t)0)       {     	  break;       }    }
