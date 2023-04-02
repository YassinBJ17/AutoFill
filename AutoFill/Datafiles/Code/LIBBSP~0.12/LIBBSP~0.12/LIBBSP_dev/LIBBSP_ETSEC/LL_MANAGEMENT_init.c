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

 void LL_MANAGEMENT_init (const uint32_t controller, const TS_LIBBSP_ETSEC_ConfHostMac * const p_mac ) {     const uint8_t * pt_rxbds_address;     const uint8_t * pt_txbds_address;     uint32_t v_driver;     v_driver = CONF_CPU.init[ controller ].driver;     pt_rxbds_address = LL_RX_initialize (controller);     pt_txbds_address = LL_TX_initialize (controller);     if( v_driver == ETSEC )     {         etsec_init (controller,                      pt_txbds_address,                     pt_rxbds_address,                      p_mac);     }     else if ( v_driver == FEC )     {     }     else     {     } }
