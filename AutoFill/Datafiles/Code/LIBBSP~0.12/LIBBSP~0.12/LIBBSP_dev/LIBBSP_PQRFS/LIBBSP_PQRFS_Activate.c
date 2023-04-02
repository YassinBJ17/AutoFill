/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PQRFS_Activate.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*  -- LIBBSP_PQRFS_Activate_PQRFS_Sending --
    * Return type : LIBBSP_PQRFS_Error 
    * IN:
        * v_start               :   TRUE will turn on the sending, FALSE will turn it off.
    * Out:
        * v_ret                 :   E_LIBBSP_PQRFS_OK or E_LIBBSP_PQRFS_KO depending on the running.
*/
TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Activate_Sending( const boolean_t v_start )
{

    TE_LIBBSP_PQRFS_Error v_ret ;
    TS_LIBBSP_PQRFS_RegPqrCmd v_Reg_pqr_cmd ;
    uint32_t reg_pqr_en;
    uint32_t v_add;
    TS_LIBBSP_PQRFS_RegPqrCmd* p_addr_to_write;
    
    /* Init return to OK */
    v_ret = E_LIBBSP_PQRFS_OK;

    /* Enable data consistency*/
    v_add = ((uint32_t)C_ADDR_EN_DATA_CONSISTENCY/sizeof(uint32_t));
    ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = C_ITF_DATA_CONSISTENCY;
    /* Get current register at C_LIBBSP_PQRFS_REG_PQR_CMD */
    v_Reg_pqr_cmd = *(TS_LIBBSP_PQRFS_RegPqrCmd *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_PQR_CMD);

    /* 1st case : activate the sending */
    if (v_start != FALSE)
    {
        /* Write the register reg_pqr_en to 1 and the check value to 1 as well */
        v_Reg_pqr_cmd.Reg_pqr_en = (uint32_t) 1;
        reg_pqr_en = (uint32_t) 1;
    }
    else /* Otherwise, set both to 0 */
    {
        v_Reg_pqr_cmd.Reg_pqr_en = (uint32_t) 0;
        reg_pqr_en = (uint32_t) 0;
    }
    
    /* Write the modified register at C_LIBBSP_PQRFS_REG_PQR_CMD */
    p_addr_to_write = (TS_LIBBSP_PQRFS_RegPqrCmd*) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_PQR_CMD);
    *p_addr_to_write = v_Reg_pqr_cmd; 

    /* Check that the current register has been successfully written */
    if(p_addr_to_write->Reg_pqr_en != reg_pqr_en)
    {
        v_ret = E_LIBBSP_PQRFS_KO;
    }
    return (v_ret);
}

/*==== END =============================================================================*/
