/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PQRFS_Status.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*  -- LIBBSP_PQRFS_GetStatus --
    * Return type : LIBBSP_PQRFS_Error 
    * IN : 
        * v_1st_5ms             : 
    * OUT :
        * p_status_1_or_3       :  status for the cycles 1 or 3
        * p_status_2_or_4       :  status for the cycles 2 or 4
        * v_ret                 :   E_LIBBSP_PQRFS_OK or E_LIBBSP_PQRFS_KO depending on the running.
*/
TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_GetStatus( TS_LIBBSP_PQRFS_Status * const p_status_1_or_3,TS_LIBBSP_PQRFS_Status * const p_status_2_or_4 , const boolean_t v_1st_5ms )
{
    TE_LIBBSP_PQRFS_Error v_ret = E_LIBBSP_PQRFS_OK;
    TS_LIBBSP_PQRFS_Status_data_bitField v_data_BitField_1_or_3;
    TS_LIBBSP_PQRFS_Status_data_bitField v_data_BitField_2_or_4;
    TS_LIBBSP_PQRFS_Status_status_bitField v_status_bitField_1_or_3;
    TS_LIBBSP_PQRFS_Status_status_bitField v_status_bitField_2_or_4;

    if(v_1st_5ms != FALSE) /* IF v_1st_5ms != false then look for cycles 1 and 2 */
    {
        v_data_BitField_1_or_3 = *(TS_LIBBSP_PQRFS_Status_data_bitField *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_C1_ERR_DATA);
        v_data_BitField_2_or_4 = *(TS_LIBBSP_PQRFS_Status_data_bitField *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_C2_ERR_DATA);
        v_status_bitField_1_or_3 = *(TS_LIBBSP_PQRFS_Status_status_bitField *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_C1_ERR_STS);
        v_status_bitField_2_or_4 = *(TS_LIBBSP_PQRFS_Status_status_bitField *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_C2_ERR_STS);
    }
    else  /* Otherwise, look for cycles 3 and 4*/
    {
        v_data_BitField_1_or_3 = *(TS_LIBBSP_PQRFS_Status_data_bitField *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_C3_ERR_DATA);
        v_data_BitField_2_or_4 = *(TS_LIBBSP_PQRFS_Status_data_bitField *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_C4_ERR_DATA);
        v_status_bitField_1_or_3 = *(TS_LIBBSP_PQRFS_Status_status_bitField *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_C3_ERR_STS);
        v_status_bitField_2_or_4 = *(TS_LIBBSP_PQRFS_Status_status_bitField *) (C_LIBBSP_PQRFS_Start_Address + C_LIBBSP_PQRFS_REG_C4_ERR_STS);
    }

    /* Convert the bitfield structure to a conventionnal structure. */
    p_status_1_or_3->data.label_err_1 = v_data_BitField_1_or_3.label_err_1;
    p_status_1_or_3->data.label_err_2 = v_data_BitField_1_or_3.label_err_2;
    p_status_1_or_3->data.label_err_3 = v_data_BitField_1_or_3.label_err_3;
    p_status_1_or_3->data.label_err_4 = v_data_BitField_1_or_3.label_err_4;
    p_status_1_or_3->data.label_err_5 = v_data_BitField_1_or_3.label_err_5;
    p_status_1_or_3->data.label_err_6 = v_data_BitField_1_or_3.label_err_6;
    p_status_1_or_3->data.label_err_7 = v_data_BitField_1_or_3.label_err_7;
    p_status_1_or_3->data.label_err_8 = v_data_BitField_1_or_3.label_err_8;
    p_status_1_or_3->data.label_err_9 = v_data_BitField_1_or_3.label_err_9;
    p_status_1_or_3->data.label_err_10 = v_data_BitField_1_or_3.label_err_10;
    p_status_1_or_3->data.label_err_11 = v_data_BitField_1_or_3.label_err_11;
    p_status_1_or_3->data.label_err_12 = v_data_BitField_1_or_3.label_err_12;
    p_status_1_or_3->data.label_err_13 = v_data_BitField_1_or_3.label_err_13;

    p_status_2_or_4->data.label_err_1 = v_data_BitField_1_or_3.label_err_1;
    p_status_2_or_4->data.label_err_2 = v_data_BitField_1_or_3.label_err_2;
    p_status_2_or_4->data.label_err_3 = v_data_BitField_1_or_3.label_err_3;
    p_status_2_or_4->data.label_err_4 = v_data_BitField_1_or_3.label_err_4;
    p_status_2_or_4->data.label_err_5 = v_data_BitField_1_or_3.label_err_5;
    p_status_2_or_4->data.label_err_6 = v_data_BitField_1_or_3.label_err_6;
    p_status_2_or_4->data.label_err_7 = v_data_BitField_1_or_3.label_err_7;
    p_status_2_or_4->data.label_err_8 = v_data_BitField_1_or_3.label_err_8;
    p_status_2_or_4->data.label_err_9 = v_data_BitField_1_or_3.label_err_9;
    p_status_2_or_4->data.label_err_10 = v_data_BitField_1_or_3.label_err_10;
    p_status_2_or_4->data.label_err_11 = v_data_BitField_1_or_3.label_err_11;
    p_status_2_or_4->data.label_err_12 = v_data_BitField_1_or_3.label_err_12;
    p_status_2_or_4->data.label_err_13 = v_data_BitField_1_or_3.label_err_13;

    p_status_1_or_3->status = v_status_bitField_1_or_3.TBC;
    p_status_2_or_4->status = v_status_bitField_2_or_4.TBC;
    
    return (v_ret);
};

/*==== END =============================================================================*/
