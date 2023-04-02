#include "LIBUTI_A665_ParseLUH_Part3Targets.h"
#include "Memcpy.h"

#ifdef A665_PART3
TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_Part3Targets(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
    const uint32_t                                  v_MaxNumberOfTargetHW_IDs_WithPositions,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint32_t * const                                p_NumberOfTargetHW_ID_WithPositions,
    TS_TargetHW_ID_WithPositions * const            p_TargetHW_ID_WithPositions
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
    uint32_t  v_index;
    uint32_t  v_index_bis;
    uint32_t  v_TargetHW_ID_WithPositions_ListOffset;
    uint8_t * p_TargetHW_ID_With_Pos_Iterator;
    uint8_t * p_TargetHW_ID_Pos_Iterator;
    uint16_t  v_LengthTargetHW_ID_With_Pos;
    uint16_t  v_LengthTargetHW_ID_Pos;

/* Target HW IDs with Positions */
    v_TargetHW_ID_WithPositions_ListOffset = p_LUH_ConstantSizeFirstFields->s_PointerToTargetHW_ID_withPositions_List * 2ul;
    if ( v_TargetHW_ID_WithPositions_ListOffset > v_LUH_Length )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_T_HW_IDS_WITH_POS_POINTER );
    }

    if (v_TargetHW_ID_WithPositions_ListOffset != 0ul)
    {
        /* Get the number of target HW ID with position */
        *p_NumberOfTargetHW_ID_WithPositions = (uint32_t)*((uint16_t*)((uint32_t)p_LUH_RAM_Address + v_TargetHW_ID_WithPositions_ListOffset)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
        if ( *p_NumberOfTargetHW_ID_WithPositions > v_MaxNumberOfTargetHW_IDs_WithPositions )
        {
            return ( E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS_WITH_POS );
        }
        /* Set iterator for each target HW id with position */
        p_TargetHW_ID_With_Pos_Iterator = (uint8_t*)((uint32_t)p_LUH_RAM_Address + v_TargetHW_ID_WithPositions_ListOffset + 2ul); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */

        /* Browse and copy each target HW id with position element */
/* {{RELAX<SYNCHRONe_C_Code_17.4> Need to access the table dynamically as size is not known at compile time */
        for ( v_index = 0ul; v_index < *p_NumberOfTargetHW_ID_WithPositions; v_index++ )
        {
            p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_WithLength.Length = *((uint16_t*)(p_TargetHW_ID_With_Pos_Iterator)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
            if ( p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_WithLength.Length > (uint16_t)C_TARGET_HW_ID_MAX_LENGTH )
            {
                return ( E_LIBUTI_PARSE_LUH_KO_T_HW_ID_WITH_POS_NAME_LEN );
            }

            LibC_Memcpy(
                p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_WithLength.TargetHW_ID,
                (uint8_t*)((uint32_t)p_TargetHW_ID_With_Pos_Iterator + 2ul), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
                (uint32_t)p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_WithLength.Length );

            /* Get the length in 16 bits of the target ID with position */
            v_LengthTargetHW_ID_With_Pos = (p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_WithLength.Length / (uint16_t)2) + (p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_WithLength.Length % (uint16_t)2);

            /* Get the number of target HW ID position */
            p_TargetHW_ID_WithPositions[v_index].NumberOfTargetHW_ID_Positions = *((uint16_t*)p_TargetHW_ID_With_Pos_Iterator + (uint16_t)1 + v_LengthTargetHW_ID_With_Pos); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
            if ( p_TargetHW_ID_WithPositions[v_index].NumberOfTargetHW_ID_Positions > (uint16_t)C_MAX_TARGET_HW_ID_POSITIONS )
            {
                return ( E_LIBUTI_PARSE_LUH_KO_NB_T_HW_IDS_POS );
            }

            /* Set iterator for each target HW id with position */
            p_TargetHW_ID_Pos_Iterator = (uint8_t*)((uint16_t*)p_TargetHW_ID_With_Pos_Iterator + (uint16_t)1 + v_LengthTargetHW_ID_With_Pos + (uint16_t)1); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */

            /* Browse and copy each target HW id position element */
            for ( v_index_bis = 0ul; v_index_bis < (uint32_t)p_TargetHW_ID_WithPositions[v_index].NumberOfTargetHW_ID_Positions; v_index_bis++ )
            {
                p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_Positions[v_index_bis].Length = *((uint16_t*)(p_TargetHW_ID_Pos_Iterator)); /* %RELAX<SYNCHRONe_C_Code_11.1> Reading value in memory */
                if ( p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_Positions[v_index_bis].Length > (uint16_t)C_TARGET_HW_ID_POSITIONS_MAX_LENGTH )
                {
                    return ( E_LIBUTI_PARSE_LUH_KO_T_HW_ID_WITH_POS_NAME_POS_LEN );
                }

                LibC_Memcpy(
                    p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_Positions[v_index_bis].Position,
                    (uint8_t*)((uint32_t)p_TargetHW_ID_Pos_Iterator + 2ul), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
                    (uint32_t)p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_Positions[v_index_bis].Length );

                /* Get the length in 16 bits of the target ID with position */
                v_LengthTargetHW_ID_Pos = (p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_Positions[v_index_bis].Length / (uint16_t)2) + (p_TargetHW_ID_WithPositions[v_index].TargetHW_ID_Positions[v_index_bis].Length % (uint16_t)2);
                p_TargetHW_ID_Pos_Iterator = (uint8_t*)((uint16_t*)p_TargetHW_ID_Pos_Iterator + (uint16_t)1 + v_LengthTargetHW_ID_Pos); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
            }
            p_TargetHW_ID_With_Pos_Iterator = p_TargetHW_ID_Pos_Iterator ;
        }
    }
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
    return ( E_LIBUTI_PARSE_LUH_OK );
}
#endif