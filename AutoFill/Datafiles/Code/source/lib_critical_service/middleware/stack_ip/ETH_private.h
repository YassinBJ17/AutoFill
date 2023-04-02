/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef ETH_PRIVATE_H
#define ETH_PRIVATE_H

#include "type/common_type.h"
#include "middleware/stack_ip/ETH_common.h"


/*---------------------------------------------------------------------------*/
/*-- Types*/
/*---------------------------------------------------------------------------*/

typedef enum
{
   e_ETH_DRV_NOT_INITIALIZED = 0 ,
   e_ETH_DRV_NO_LINK = 1 ,
   e_ETH_DRV_READY = 2
} te_ETH_DRV_STATE ;

typedef struct
{
   ts_ETH_STATS            s_ETHstats;
   te_ETH_DRV_STATE        s_DriverStatus;
} ts_ETH_CONTROL;


extern ts_ETH_CONTROL  v_ETH_DRV_ControlETH;  /* ethernet control object*/

#endif /* ETH_PRIVATE_H */
