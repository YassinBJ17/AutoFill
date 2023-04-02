#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "HW_TB.h"
#include "smi.h"
#include "etsec.h"
#include "phy.h"

 		if (duplex == HW_CONF_LINK_FULL_DUPLEX ) 		{ 		   ctl = ctl | (uint16_t)BMCR_FULLDPLX | (uint16_t)BMCR_ANENABLE; 		}
