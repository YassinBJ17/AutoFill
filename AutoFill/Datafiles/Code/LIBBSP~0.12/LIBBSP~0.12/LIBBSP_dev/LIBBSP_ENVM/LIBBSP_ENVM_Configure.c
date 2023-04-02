/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_Configure.h"

/*==== Definitions =====================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_ENVM_ErrorCode LIBBSP_ENVM_Configure(const TE_LIBBSP_ENVM_Device device, const uint32_t nb, const TS_LIBBSP_ENVM_CompagnonMap * const p_Envm_Map)
{
    TE_LIBBSP_ENVM_ErrorCode v_ret;
    uint32_t v_Index;

    if(p_Envm_Map != NULL) /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: NULL */
    {
        if (nb <= C_LIBBSP_ENVM_COMPAGNON_MAP_MAX)
        {
            if (device == E_LIBBSP_ENVM_COMPAGNON)
            {
                for (v_Index=0ul;v_Index<nb;v_Index++)
                {
                    ENVM_Compagnon_Map[v_Index] = p_Envm_Map[v_Index]; /* %RELAX<SYNCHRONe_C_Code_17.4> Size of array is unkonwn at compile time */
                }
                ENVM_Compagnon_Map_Size = nb;
                ENVM_OverrideReg.p_SSI_COMP_ReqAddress = NULL; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: NULL */
                ENVM_OverrideReg.v_SSI_COMP_ReqValue = 0ul;
                v_ret = E_LIBBSP_ENVM_OK;
            }
            else
            {
                v_ret = E_LIBBSP_ENVM_INVALID_DEVICE;
            }
        }
        else
        {
            v_ret = E_LIBBSP_ENVM_OVERSIZED;
        }
    }
    else
    {
        v_ret = E_LIBBSP_ENVM_INVALID_ADDR;
    }

    return (v_ret); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
