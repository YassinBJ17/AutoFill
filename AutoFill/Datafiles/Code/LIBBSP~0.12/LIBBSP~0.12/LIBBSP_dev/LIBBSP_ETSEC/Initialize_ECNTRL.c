/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "etsec.h"
#include "HW_CONF.h"
#include "Initialize_ECNTRL.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void Initialize_ECNTRL(uint32_t * const init_value, uint32_t const interface, uint32_t const speed)
{


    if (interface == HW_CONF_LINK_TYPE_SGMII)
    {
       if (speed == HW_CONF_LINK_SPEED_100_MBITS)
       {
           *init_value = ETSEC_ECNTRL_STEN | ETSEC_ECNTRL_CLRCNT |
                        ETSEC_ECNTRL_TBIM | ETSEC_ECNTRL_SGMIIM | ETSEC_ECNTRL_R100M;
       }
       else
       {
           *init_value = ETSEC_ECNTRL_STEN | ETSEC_ECNTRL_CLRCNT |
                        ETSEC_ECNTRL_TBIM | ETSEC_ECNTRL_SGMIIM;
       }
    }
    else if (interface == (uint32_t)HW_CONF_LINK_TYPE_RGMII)
    {
       if (speed == HW_CONF_LINK_SPEED_100_MBITS)
       {
          *init_value = ETSEC_ECNTRL_STEN | ETSEC_ECNTRL_CLRCNT |
                       ETSEC_ECNTRL_RPM  | ETSEC_ECNTRL_R100M;
       }
       else
       {
          *init_value = ETSEC_ECNTRL_STEN | ETSEC_ECNTRL_CLRCNT |
                       ETSEC_ECNTRL_RPM;
       }
    }
    else if (interface == (uint32_t)HW_CONF_LINK_TYPE_RMII)
    {
       if (speed == HW_CONF_LINK_SPEED_100_MBITS)
       {
          *init_value = ETSEC_ECNTRL_STEN | ETSEC_ECNTRL_CLRCNT |
                       ETSEC_ECNTRL_RMM  | ETSEC_ECNTRL_R100M;
       }
       else
       {
          *init_value = ETSEC_ECNTRL_STEN | ETSEC_ECNTRL_CLRCNT |
                       ETSEC_ECNTRL_RMM;
       }
    }
    else /* HW_CONF_LINK_TYPE_MII */
    {
       *init_value = ETSEC_ECNTRL_STEN | ETSEC_ECNTRL_CLRCNT;
    }


}

/*==== END =============================================================================*/
