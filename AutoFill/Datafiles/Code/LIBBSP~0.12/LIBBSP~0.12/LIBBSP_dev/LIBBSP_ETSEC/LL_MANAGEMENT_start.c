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

 void LL_MANAGEMENT_start (const uint32_t controller,                            const boolean_t rx_start,                            const boolean_t tx_start) {       if (tx_start != FALSE)     {         etsec_tx_enable(controller, TRUE);     }     if (rx_start != FALSE)     {         etsec_rx_enable(controller, TRUE);     } }
