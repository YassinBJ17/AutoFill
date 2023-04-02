/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#include "LIBBSP_BLADES_Write.h"

boolean_t LIBBSP_BLADES_WriteBlades( uint32_t const v_write_value, uint32_t const v_expected_value )
{
    /* Using volatile to force the compiler not to optimize instructions about this pointer. */
    /* When we don't use "volatile", the while loop is optimized during compilation to an endless loop. */
    uint32_t * volatile p_register_address;
    uint32_t v_current_value;
    uint32_t v_timeout_value;
    uint32_t v_current_time;
    uint32_t v_start_time;
    p_register_address = (uint32_t*) (C_LIBBSP_BLADES_Start_Address + C_LIBBSP_BLADES_REG_ALL_BLADES_DBG_FORCE_DBG);
    v_timeout_value = C_LIBBSP_BLADES_TIMEOUT_MS*C_LIBBSP_BLADES_10_MICRO*100; 

    *p_register_address = v_write_value;
    v_current_value = 1;
    
    v_current_time = LIBBSP_CMN_GetTicks();
    v_start_time = LIBBSP_CMN_GetTicks();

    while(v_current_value != v_expected_value && v_timeout_value >= (v_current_time-v_start_time))
    {
        v_current_value = *p_register_address;
        v_current_time = LIBBSP_CMN_GetTicks();
    }
    if(v_timeout_value > (v_current_time-v_start_time))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}