/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429CF_MuxSelection.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_A429CF_ErrorCode LIBBSP_A429CF_MuxSelection(const uint8_t v_TxChannelNum)
{

    TE_LIBBSP_A429CF_ErrorCode v_ret;

    if (v_TxChannelNum > (uint8_t)7)
    {
        v_ret = E_LIBBSP_A429CF_INVALID_TX_LINE;
    }
    else
    {
        /* Write the channel num in the register, A429 Monitoring Multiplexer Control */
        *(volatile uint32_t *)V_A429CF_Pointer = v_TxChannelNum; /* %RELAX<SYNCHRONe_C_Code_10.2> No cast needed: affect value to a part of the register */
        v_ret = E_LIBBSP_A429CF_OK;
    }
    return v_ret;
}
/*==== END =============================================================================*/
