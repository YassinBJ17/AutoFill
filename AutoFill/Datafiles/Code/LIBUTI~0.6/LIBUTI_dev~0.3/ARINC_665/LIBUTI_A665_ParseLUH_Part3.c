#include "LIBUTI_A665_ParseLUH_Part3.h"
#include "LIBUTI_A665_ParseLUH_Part3Fields.h"
#include "LIBUTI_A665_ParseLUH_Part3Targets.h"

#ifdef A665_PART3
TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_Part3(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
    const uint32_t                                  v_MaxNumberOfTargetHW_IDs_WithPositions,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint32_t * const                                p_NumberOfTargetHW_ID_WithPositions,
    TS_TargetHW_ID_WithPositions * const            p_TargetHW_ID_WithPositions,
    uint16_t * const                                p_LoadCheckValueLength,
    TE_ParseLUH_CheckValueType * const              p_LoadCheckValueType,
    uint8_t * const                                 p_LoadCheckValue,
    uint16_t * const                                p_LoadTypeDescriptionLength,
    uint8_t * const                                 p_LoadTypeDescription,
    uint16_t * const                                p_LoadTypeID
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
    TE_ParseLUH_ReturnCode  v_ret;

    v_ret = E_LIBUTI_PARSE_LUH_OK;
    if (p_LUH_ConstantSizeFirstFields->s_LoadFileFormatVersion == C_LOAD_FILE_FORMAT_VERSION_3)
    {
        v_ret = LIBUTI_A665_ParseLUH_Part3Targets(
            p_LUH_RAM_Address,
            v_LUH_Length,
            p_LUH_ConstantSizeFirstFields,
            v_MaxNumberOfTargetHW_IDs_WithPositions,
            p_NumberOfTargetHW_ID_WithPositions,
            p_TargetHW_ID_WithPositions
        );
        if ( v_ret != E_LIBUTI_PARSE_LUH_OK )
        {
            return ( v_ret );
        }

        v_ret = LIBUTI_A665_ParseLUH_Part3Fields(
            p_LUH_RAM_Address,
            v_LUH_Length,
            p_LUH_ConstantSizeFirstFields,
            p_LoadCheckValueLength,
            p_LoadCheckValueType,
            p_LoadCheckValue,
            p_LoadTypeDescriptionLength,
            p_LoadTypeDescription,
            p_LoadTypeID
        );
    }
    return ( v_ret );
}
#endif