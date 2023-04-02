/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#include "LIBUTI_A665_ParseLUH_VersionPN.h"
#include "BOOT_LIBMEM_public.h"

TE_ParseLUH_ReturnCode LIBUTI_A665_ParseLUH_VersionPN(
/*IN*/
    const uint8_t *                                 p_LUH_RAM_Address,
    const uint32_t                                  v_LUH_Length,
    const TS_LUH_ConstantSizeFirstFields * const    p_LUH_ConstantSizeFirstFields,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
    uint16_t * const                                p_LoadPN_Length,
    uint8_t * const                                 p_LoadPN
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
    uint32_t  v_LoadPN_Offset;

/*Version check*/
    switch (p_LUH_ConstantSizeFirstFields->s_LoadFileFormatVersion)
    {
#ifdef A665_PART2
    case K_LOAD_FILE_FORMAT_VERSION_2:
#endif
#ifdef A665_PART3
    case K_LOAD_FILE_FORMAT_VERSION_3:
#endif
        break;
    
    default:
        return ( E_LIBUTI_PARSE_LUH_KO_VERSION );
        break;
    }

/*Load PN*/
    v_LoadPN_Offset = p_LUH_ConstantSizeFirstFields->s_PointerToLoadPN * (uint32_t)2;
    if ( v_LoadPN_Offset > v_LUH_Length )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_PN_POINTER );
    }

    *p_LoadPN_Length = *((uint16_t*)((uint32_t)p_LUH_RAM_Address + v_LoadPN_Offset)); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Reading value in memory */
    if ( *p_LoadPN_Length > (uint16_t)K_PN_MAX_LENGTH )
    {
        return ( E_LIBUTI_PARSE_LUH_KO_PN_LEN );
    }

    BOOT_LIBMEM_CPY( 
        p_LoadPN,
        (uint8_t*)((uint32_t)p_LUH_RAM_Address + v_LoadPN_Offset + (uint32_t)2), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using as memory address */
        (uint32_t)*p_LoadPN_Length );
    
    return ( E_LIBUTI_PARSE_LUH_OK );
}