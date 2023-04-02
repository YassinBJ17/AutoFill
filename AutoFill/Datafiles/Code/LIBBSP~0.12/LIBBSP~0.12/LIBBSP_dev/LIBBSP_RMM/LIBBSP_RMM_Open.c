/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_RMM_Open.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_RMM_Open(void)
{
    TE_LIBBSP_I2C_Code v_ret;
    uint8_t v_buf;

    V_RMM_State = E_LIBBSP_RMM_CLOSED;

    /* open the link */
    v_ret = LIBBSP_I2C_Open(C_RMM_USED_BUS,
            C_RMM_DIGITAL_FILTER,
            C_RMM_DIVISOR_VALUE );

    if ( v_ret == E_LIBBSP_I2C_OK )
    {
        v_ret = LIBBSP_I2C_Read(C_RMM_USED_BUS, C_RMM_24FC1025_B0_ADDR, 1ul, &v_buf);
        if (v_ret == E_LIBBSP_I2C_OK)
        {
            V_RMM_State = E_LIBBSP_RMM_OPEN;
        }
    }

    return (v_ret); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
