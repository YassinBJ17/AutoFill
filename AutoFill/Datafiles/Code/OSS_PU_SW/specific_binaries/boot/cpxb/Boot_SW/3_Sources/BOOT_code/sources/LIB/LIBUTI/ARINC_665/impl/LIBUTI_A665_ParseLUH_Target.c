/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#include "LIBUTI_A665_ParseLUH_Target.h"
#include "BOOT_LIBMEM_public.h"

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_Target(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
    const uint32_t                                  v_MaxNumberOfTargetHW_IDs,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint32_t * const                                p_NumberOfTargetHW_IDs,
    TS_TargetHW_ID_WithLength * const               p_TargetHW_IDs_WithLengths
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
    uint32_t  v_index;
    uint32_t  v_TargetHW_ID_ListOffset;
    uint8_t * p_TargetHW_ID_Iterator;

    /*Target HW IDs*/
    v_TargetHW_ID_ListOffset = p_LUH_ConstantSizeFirstFields->s_PointerToTargetHW_ID_List * (uint32_t)2;
    if ( v_TargetHW_ID_ListOffset > v_LUH_Length )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_T_HW_IDS_POINTER );
    }
    *p_NumberOfTargetHW_IDs = (uint32_t)*((uint16_t*)((uint32_t)p_LUH_RAM_Address + v_TargetHW_ID_ListOffset)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
    if ( *p_NumberOfTargetHW_IDs > v_MaxNumberOfTargetHW_IDs )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS );
    }

    p_TargetHW_ID_Iterator = (uint8_t*)( (uint32_t)p_LUH_RAM_Address + v_TargetHW_ID_ListOffset + (uint32_t)2 ); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
/* {{RELAX<SYNCHRONe_C_Code_17.4> Need to access the table dynamically as size is not known at compile time */
    for ( v_index = (uint32_t)0; v_index < *p_NumberOfTargetHW_IDs; v_index++ )
    {
        p_TargetHW_IDs_WithLengths[v_index].Length = *((uint16_t*)p_TargetHW_ID_Iterator); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
        if ( p_TargetHW_IDs_WithLengths[v_index].Length > (uint16_t)K_TARGET_HW_ID_MAX_LENGTH )
        {
            return ( E_LIBUTI_PARSE_LUH_KO_T_HW_ID_NAME_LEN );
        }

        BOOT_LIBMEM_CPY(
            p_TargetHW_IDs_WithLengths[v_index].TargetHW_ID,
            (uint8_t*)( (uint32_t)p_TargetHW_ID_Iterator + (uint32_t)2 ), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
            (uint32_t)p_TargetHW_IDs_WithLengths[v_index].Length );

        p_TargetHW_ID_Iterator = (uint8_t*)( (uint32_t)p_TargetHW_ID_Iterator + (uint32_t)p_TargetHW_IDs_WithLengths[v_index].Length + (uint32_t)2 ); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
    }
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
    return ( E_LIBUTI_PARSE_LUH_OK );
}