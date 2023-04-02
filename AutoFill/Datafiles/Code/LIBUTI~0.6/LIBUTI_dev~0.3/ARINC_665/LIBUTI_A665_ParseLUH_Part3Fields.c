#include "LIBUTI_A665_ParseLUH_Part3Fields.h"
#include "Memcpy.h"

#ifdef A665_PART3
TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_Part3Fields(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint16_t * const                                p_LoadCheckValueLength,
    TE_ParseLUH_CheckValueType * const              p_LoadCheckValueType,
    uint8_t * const                                 p_LoadCheckValue,
    uint16_t * const                                p_LoadTypeDescriptionLength,
    uint8_t * const                                 p_LoadTypeDescription,
    uint16_t * const                                p_LoadTypeID
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
    uint32_t  v_LoadTypeOffset;
    uint32_t  v_LoadCheckOffset;
    uint16_t  v_CheckType;

/* Load Type Description */
    v_LoadTypeOffset = p_LUH_ConstantSizeFirstFields->s_PointerToLoadTypeDescriptionLength * 2ul;
    if ( v_LoadTypeOffset > v_LUH_Length )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_LOADTYPE_POINTER );
    }

    if (v_LoadTypeOffset != 0ul)
    {
        *p_LoadTypeDescriptionLength = *((uint16_t*)((uint32_t)p_LUH_RAM_Address + v_LoadTypeOffset)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
        if (*p_LoadTypeDescriptionLength > (uint16_t)0)
        {
            LibC_Memcpy(
                p_LoadTypeDescription,
                (uint8_t*)((uint32_t)p_LUH_RAM_Address + v_LoadTypeOffset + 2ul), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
                (uint32_t)*p_LoadTypeDescriptionLength );
            *p_LoadTypeID = *((uint16_t*)((uint32_t)p_LUH_RAM_Address + v_LoadTypeOffset + 2ul + (uint32_t)(*p_LoadTypeDescriptionLength) + ((uint32_t)(*p_LoadTypeDescriptionLength) % 2ul))); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
        }
    }

/* Load check */
    v_LoadCheckOffset = p_LUH_ConstantSizeFirstFields->s_PointerToLoadCheckValueLength * 2ul;
    if ( v_LoadCheckOffset > v_LUH_Length )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_LOADCHK_POINTER );
    }

    if (v_LoadCheckOffset != 0ul)
    {
        *p_LoadCheckValueLength = *((uint16_t*)((uint32_t)p_LUH_RAM_Address + v_LoadCheckOffset)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
        if (*p_LoadCheckValueLength > (uint16_t)0)
        {
            *p_LoadCheckValueLength -= (uint16_t)4;
            v_CheckType = *((uint16_t*)((uint32_t)p_LUH_RAM_Address + v_LoadCheckOffset + 2ul)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
            if (v_CheckType < (uint16_t)E_LIBUTI_PARSE_LUH_CHKVAL_UNKNOWN) /* %RELAX<SYNCHRONe_C_Code_10.7> No loss of precision here, this test ensure convertion is valid */
            {
                *p_LoadCheckValueType = (TE_ParseLUH_CheckValueType) v_CheckType;
            }
            else
            {
                *p_LoadCheckValueType = E_LIBUTI_PARSE_LUH_CHKVAL_UNKNOWN;
            }
            LibC_Memcpy(
                p_LoadCheckValue,
                (uint8_t*)((uint32_t)p_LUH_RAM_Address + v_LoadCheckOffset + 4ul), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
                (uint32_t)*p_LoadCheckValueLength);
        }
    }
    return ( E_LIBUTI_PARSE_LUH_OK );
}
#endif