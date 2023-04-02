/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PQRFS_Deactivate_Line.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*  -- LIBBSP_PQRFS_Activate_PQRFS_Deactivate --
    * Return type : LIBBSP_PQRFS_Error 
    * IN:
        * v_line                :  Line to deactivate
        * v_stop                :  TRUE will stop the sending on {v_line} line, FALSE will activate it.
    * Out:
        * v_ret                 :   E_LIBBSP_PQRFS_OK or E_LIBBSP_PQRFS_KO depending on the running.
*/
TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Deactivate_Line( const TE_LIBBSP_PQRFS_Line v_line, const boolean_t v_stop )
{

    TE_LIBBSP_PQRFS_Error v_ret = E_LIBBSP_PQRFS_OK;
    TS_LIBBSP_PQRFS_RegPqrCmd v_Reg_pqr_cmd;
    uint32_t v_activate;
    TS_LIBBSP_PQRFS_RegPqrCmd* p_addr_to_write;
    
    /* Get the current register status */
    v_Reg_pqr_cmd = *(TS_LIBBSP_PQRFS_RegPqrCmd *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_PQR_CMD);

    /* Set the v_activate variable to the wanted value : 0 if we wanna stop ({v_stop} is TRUE), 1 otherwise. */
    if(v_stop != FALSE)
    {
        v_activate = 0;
    }
    else
    {
        v_activate = 1;
    }

    /* Check that the wanted line is an existing one. */
    if(v_line < E_LIBBSP_PQRFS_NbLine){
        /* 1st case: Line 1. Change the bit value according to the {v_stop} variable */
        if(v_line == E_LIBBSP_PQRFS_Line1)
        {
            v_Reg_pqr_cmd.Reg_pqr_en_atx1 = v_activate;
        }
        else if (v_line == E_LIBBSP_PQRFS_Line4)
        {
            v_Reg_pqr_cmd.Reg_pqr_en_atx4 = v_activate;
        }
        else /* This else case won't ever be called in the current implementation. Just here for robustness*/
        {
            v_ret = E_LIBBSP_PQRFS_KO;
        }

        /* Write the modified register at C_LIBBSP_PQRFS_REG_PQR_CMD */
        p_addr_to_write = (TS_LIBBSP_PQRFS_RegPqrCmd*) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_PQR_CMD);
        *p_addr_to_write = v_Reg_pqr_cmd;

        /* Check that the register as been successfully written. */
        if((v_line == E_LIBBSP_PQRFS_Line1 && p_addr_to_write->Reg_pqr_en_atx1 != v_activate) 
        || (v_line == E_LIBBSP_PQRFS_Line4 && p_addr_to_write->Reg_pqr_en_atx4 != v_activate))
        {
            v_ret = E_LIBBSP_PQRFS_KO;
        }
    }
    else /* Otherwise, set {v_ret} to KO */
    {
        v_ret = E_LIBBSP_PQRFS_KO;
    }

    return (v_ret);
}
/*==== END =============================================================================*/
