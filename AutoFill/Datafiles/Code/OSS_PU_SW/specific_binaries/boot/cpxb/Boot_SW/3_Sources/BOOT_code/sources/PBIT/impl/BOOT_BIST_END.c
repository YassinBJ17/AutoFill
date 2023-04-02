#include "BOOT_MC_public.h"
#include "BOOT_BIST_public.h"
#include "BOOT_BIST_CFEX_public.h"
#include "BOOT_FAULT_public.h"
#include "BOOT_FCCU_public.h"

 void BOOT_BIST_END ( void ) {    ts_STCU2_REG volatile* pt_stcu2_reg = (ts_STCU2_REG volatile*) STCU2_BASE_ADDR;    uint32_t v_LBIST_index;    uint32_t v_lbssw = (uint32_t)pt_stcu2_reg->LBSSW;    uint32_t v_lbesw = (uint32_t)pt_stcu2_reg->LBESW;    uint32_t v_mbslsw = (uint32_t)pt_stcu2_reg->MBSLSW;    uint32_t v_mbsmsw = (uint32_t)pt_stcu2_reg->MBSMSW;    uint32_t v_mbshsw = (uint32_t)pt_stcu2_reg->MBSHSW;    uint32_t v_mbelsw = (uint32_t)pt_stcu2_reg->MBELSW;    uint32_t v_mbemsw = (uint32_t)pt_stcu2_reg->MBEMSW;    uint32_t v_mbehsw = (uint32_t)pt_stcu2_reg->MBEHSW;    te_CMN_FLAG_QUESTION v_fail = e_CMN_FLAG_NO;    if ( ((uint32_t)pt_stcu2_reg->s_ERR_STAT & STCU2_GENERAL_RESULTS) != (uint32_t)0x0  )    {       BOOT_FAULT_LOG ( BOOT_FAULT_XBIST,                        PBIT_ORIGIN,                        pt_stcu2_reg->s_ERR_STAT,                        pt_stcu2_reg->ERR_FM,                        LGBK_FIELD_DEFAULT_VALUE,                        LGBK_FIELD_DEFAULT_VALUE );       v_fail = e_CMN_FLAG_YES;    }    for ( v_LBIST_index = 0; v_LBIST_index <= 9; v_LBIST_index++ )    {       if (v_LBIST_index == 6)       {          v_fail = e_CMN_FLAG_NO;       }       else if ( ( ( v_lbssw >> v_LBIST_index ) & ( v_lbesw >> v_LBIST_index ) & LBIST_OK ) != LBIST_OK )       {          BOOT_FAULT_LOG ( ( BOOT_FAULT_LBIST_HSM + v_LBIST_index ),                           LBIST_ORIGIN,                           v_lbssw,                           v_lbesw,                           LGBK_FIELD_DEFAULT_VALUE,                           LGBK_FIELD_DEFAULT_VALUE );          v_fail = e_CMN_FLAG_YES;       }    }    if ( ( v_mbslsw & v_mbelsw & MBIST_LMEM_0_OK ) != MBIST_LMEM_0_OK )    {       BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_LMEM_0,                        MBIST_ORIGIN,                        pt_stcu2_reg->MBSLSW,                        pt_stcu2_reg->MBELSW,                        LGBK_FIELD_DEFAULT_VALUE,                        LGBK_FIELD_DEFAULT_VALUE );       v_fail = e_CMN_FLAG_YES;    }    if ( ( v_mbslsw & v_mbelsw & MBIST_LMEM_1_OK ) != MBIST_LMEM_1_OK )    {       BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_LMEM_1,                        MBIST_ORIGIN,                        v_mbslsw,                        v_mbelsw,                        LGBK_FIELD_DEFAULT_VALUE,                        LGBK_FIELD_DEFAULT_VALUE );       v_fail = e_CMN_FLAG_YES;    }    if ( ( v_mbslsw & v_mbelsw & MBIST_LMEM_2_OK ) != MBIST_LMEM_2_OK )    {       BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_LMEM_2,                        MBIST_ORIGIN,                        v_mbslsw,                        v_mbelsw,                        LGBK_FIELD_DEFAULT_VALUE,                        LGBK_FIELD_DEFAULT_VALUE );       v_fail = e_CMN_FLAG_YES;    }    if ( ( ( v_mbslsw & v_mbelsw & MBIST_OTHER_RAM_L_OK ) != MBIST_OTHER_RAM_L_OK )    || ( ( v_mbsmsw & v_mbemsw & MBIST_OTHER_RAM_M_OK ) != MBIST_OTHER_RAM_M_OK )    || ( ( v_mbshsw & v_mbehsw & MBIST_OTHER_RAM_H_OK ) != MBIST_OTHER_RAM_H_OK ) )    {       BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_OTHER_RAM,                        MBIST_ORIGIN,                        v_mbslsw,                        v_mbelsw,                        v_mbsmsw,                        v_mbemsw );       v_fail = e_CMN_FLAG_YES;    }    if ( ( v_mbsmsw & v_mbemsw & MBIST_DMA_RMA_OK ) != MBIST_DMA_RMA_OK )    {       BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_DMA_RMA,                        MBIST_ORIGIN,                        v_mbsmsw,                        v_mbemsw,                        LGBK_FIELD_DEFAULT_VALUE,                        LGBK_FIELD_DEFAULT_VALUE );       v_fail = e_CMN_FLAG_YES;    }    if ( ( ( v_mbsmsw & v_mbemsw & MBIST_SRAM_M_OK ) != MBIST_SRAM_M_OK )    || ( ( v_mbshsw & v_mbehsw & MBIST_SRAM_H_OK ) != MBIST_SRAM_H_OK ) )    {       BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_SRAM,                        MBIST_ORIGIN,                        v_mbsmsw,                        v_mbemsw,                        v_mbshsw,                        v_mbehsw );       v_fail = e_CMN_FLAG_YES;    }    if ( ( v_mbshsw & v_mbehsw & MBIST_BAR_OK ) != MBIST_BAR_OK )    {       BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_BAR,                        MBIST_ORIGIN,                        v_mbshsw,                        v_mbehsw,                        LGBK_FIELD_DEFAULT_VALUE,                        LGBK_FIELD_DEFAULT_VALUE );       v_fail = e_CMN_FLAG_YES;    }    if ( ( v_mbshsw & v_mbehsw & MBIST_DBG_RAM_OK ) != MBIST_DBG_RAM_OK )    {       BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_DBG_RAM,                        MBIST_ORIGIN,                        v_mbshsw,                        v_mbehsw,                        LGBK_FIELD_DEFAULT_VALUE,                        LGBK_FIELD_DEFAULT_VALUE );       v_fail = e_CMN_FLAG_YES;    }    BOOT_MC_RGM_CLEAR_ERROR ();    if ( v_fail == e_CMN_FLAG_YES )    {       BOOT_FAULT_INFINITELOOP ();    } }
