#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "etsec.h"
#include "tbi.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "smi.h"

 void mii_reset (const uint32_t bus) {    TS_ETSEC_MDIO* volatile p_etsec_mdio;    uint32_t value;    uint32_t timeout;    p_etsec_mdio = (TS_ETSEC_MDIO*) ((uint32_t)CONF_CPU.init[bus].mdio_base_address + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address);     p_etsec_mdio->IEVENTM = 0ul;    p_etsec_mdio->IMASKM = 0ul;    p_etsec_mdio->EMAPM = 0ul;    asm("sync");    p_etsec_mdio->MIIMCFG = (uint32_t)MIIMCFG_RESET;    asm("sync");    p_etsec_mdio->MIIMCFG = CONF_CPU.init[bus].mdio_speed;    asm("sync");    value = p_etsec_mdio->MIIMIND;     for( timeout = 1000000ul ; (timeout > 0ul) ; timeout --)    {        asm("sync");        value = p_etsec_mdio->MIIMIND;            if((value & (uint32_t)MIIMIND_BUSY) == 0ul)        {     	   break;        }    } }
