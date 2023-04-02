/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_Configure.h"
/*==== Definitions =====================================================================*/

/*==== Variables ===========================================================================*/


/*==== SERVICES ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_DISC_Configure(const TE_LIBBSP_DISC_Expander expanderID)
{
    TE_LIBBSP_I2C_Code v_ret;
    uint32_t v_index;


    if (expanderID >= E_LIBBSP_DISC_NB_EXPANDER)
    {
        v_ret = E_LIBBSP_I2C_INVALID_ID;
    }
    else if (V_DISC_Max7312State[expanderID] != E_LIBBSP_DISC_MAX7312_OPEN)
    {
        v_ret = E_LIBBSP_I2C_CLOSED;
    }
    else
    {

       v_ret = E_LIBBSP_I2C_OK;
       v_index = (uint32_t)0;

        if (expanderID == E_LIBBSP_DISC_EXPANDER_1)
        {
           while ( (v_index < (uint32_t)C_DISC_NB_MAX7312_CONF) && (v_ret == E_LIBBSP_I2C_OK ))
           {
               v_ret = LIBBSP_DISC_WriteReg(C_DISC_MAX7312_IO_EXP1_ADDR, C_DISC_MAX7312_CONF_EXP_1[v_index].v_reg, C_DISC_MAX7312_CONF_EXP_1[v_index].v_data);
               v_index += (uint32_t)1 ;
           }

        }
        else
        {
           while ( (v_index < (uint32_t)C_DISC_NB_MAX7312_CONF) && (v_ret == E_LIBBSP_I2C_OK ))
           {
               v_ret = LIBBSP_DISC_WriteReg(C_DISC_MAX7312_IO_EXP2_ADDR, C_DISC_MAX7312_CONF_EXP_2[v_index].v_reg, C_DISC_MAX7312_CONF_EXP_2[v_index].v_data);
               v_index += (uint32_t)1;
           }
        }

    }

    return v_ret;
}
