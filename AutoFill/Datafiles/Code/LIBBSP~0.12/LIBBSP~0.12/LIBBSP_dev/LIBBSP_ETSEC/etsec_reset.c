#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "HW_TB.h"
#include "tbi.h"
#include "phy.h"
#include "smi.h"
#include "Initialize_MACCFG2.h"
#include "Initialize_ECNTRL.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "etsec.h"

 void etsec_reset( const uint32_t device ) {    uint32_t          tbi_base_address;    t_ETSEC         *p_etsec;     p_etsec = (t_ETSEC*)((uint32_t)(CONF_CPU.init[device].etsec_base_address) + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address);     tbi_base_address =   (uint32_t)CONF_CPU.init[device].tbi_base_address;    asm("sync");    p_etsec->MACCFG1 = p_etsec->MACCFG1 | ETSEC_MACCFG1_SOFT_RESET;            HW_TB_wait(0x6ul);    asm("sync");    p_etsec->MACCFG1 = p_etsec->MACCFG1 & (~ETSEC_MACCFG1_SOFT_RESET) ;    p_etsec->TBIPA = tbi_base_address;   }
