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

 void etsec_rx_enable (const uint32_t device,                        const boolean_t enable) {           t_ETSEC* p_etsec;       p_etsec = (t_ETSEC*)((uint32_t)(CONF_CPU.init[device].etsec_base_address) + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address);        if(enable != FALSE)     {        p_etsec->MACCFG1 = p_etsec->MACCFG1 | ETSEC_MACCFG1_RX_EN;     }     else     {        p_etsec->MACCFG1 = p_etsec->MACCFG1 & (~ETSEC_MACCFG1_RX_EN);     } }
