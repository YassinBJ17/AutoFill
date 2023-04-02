#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "etsec.h"
#include "tbi.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "smi.h"

 void mii_phy_write(const uint32_t bus, const uint32_t address, const uint32_t reg_number, int32_t value ) {    int32_t timeout;    TS_ETSEC_MDIO* volatile p_etsec_mdio;    p_etsec_mdio = (TS_ETSEC_MDIO*) ((uint32_t)CONF_CPU.init[bus].mdio_base_address | (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address);     asm("sync");    p_etsec_mdio->MIIMADD = ((address & 0x1Ful) << 8) | (reg_number & 0x1Ful);    asm("sync");    p_etsec_mdio->MIIMCON = (uint32_t)value;     asm("sync");    value = (int32_t)p_etsec_mdio->MIIMIND;     for( timeout = (int32_t)1000000 ; (timeout > (int32_t)0) ; timeout --)    {        asm("sync");        value = (int32_t)p_etsec_mdio->MIIMIND;         if((value & (int32_t)MIIMIND_BUSY) == (int32_t)0)        {     	   break;        }    } }
