#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "etsec.h"
#include "tbi.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "smi.h"

 int32_t mii_phy_read(const uint32_t bus, const uint32_t address, const uint32_t reg_number ) {    int32_t timeout;    TS_ETSEC_MDIO* volatile p_etsec_mdio;    int32_t value;    int32_t invalid_mask = MIIMIND_BUSY | MIIMIND_NOT_VALID;    p_etsec_mdio = (TS_ETSEC_MDIO*) ((uint32_t)CONF_CPU.init[bus].mdio_base_address | (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address);     asm("sync");    p_etsec_mdio->MIIMADD = ( (address & 0x1Ful) << 8) | (reg_number & 0x1Ful);    asm("sync");    p_etsec_mdio->MIIMCOM = 0ul;    asm("sync");    p_etsec_mdio->MIIMCOM = (uint32_t)MIIMCOM_READ_CYCLE_EN;    asm("sync");    value = (int32_t)p_etsec_mdio->MIIMIND;     for( timeout = (int32_t)1000000 ; (timeout > (int32_t)0) ; timeout --)    {        asm("sync");        value = (int32_t)p_etsec_mdio->MIIMIND;         if((value & invalid_mask ) == (int32_t)0)        {     	   break;        }    }    asm("sync");    value = (int32_t)(p_etsec_mdio->MIIMSTAT & 0xFFFFul);     if( timeout == (int32_t)1 )    {       value = (int32_t)(-1);    }    else    {       value = value & (int32_t)0xFFFF;    }    return value; }
