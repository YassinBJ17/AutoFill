#include "LIBMCP_Types.h"
#include "HW_TB.h"
    #include "HW_CONF.h"
    #include "etsec.h"
    #include "smi.h"
    #include "tbi.h"
    #include "phy.h"
#include "LL.h"
#include "LL_RX.h"
#include "LL_TX.h"
#include "etsec.h"
#include "tbi.h"
#include "phy.h"

 void LL_MANAGEMENT_stop( const uint32_t controller,                           const boolean_t rx_stop,                           const boolean_t tx_stop) {    uint32_t v_driver;    v_driver    = CONF_CPU.init[controller].driver;    if( v_driver == ETSEC )    {         if (tx_stop != FALSE)         {             etsec_tx_enable (controller, FALSE);         }         if (rx_stop != FALSE)         {             etsec_rx_enable (controller, FALSE);         }    }    else if (v_driver == FEC)    {    } }
