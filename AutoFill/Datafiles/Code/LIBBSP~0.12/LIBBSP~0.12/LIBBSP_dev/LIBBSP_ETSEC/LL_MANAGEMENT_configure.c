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

 void LL_MANAGEMENT_configure( const uint32_t controller ) {    uint32_t    v_driver;    uint32_t    v_interface;    uint32_t    v_phy;    v_driver =    CONF_CPU.init[controller].driver;    v_phy =       CONF_CPU.init[controller].phy_device;    v_interface = CONF_CPU.init[controller].interface;    if( v_driver == ETSEC )    {        etsec_reset( controller );        if (v_interface == HW_CONF_LINK_TYPE_SGMII)        {           tbi_config( controller );             }        if (v_phy != NO_PHY)        {              phy_connect( v_phy );           phy_reset  ( v_phy );           phy_config ( v_phy );        }     }     else      {     } }
