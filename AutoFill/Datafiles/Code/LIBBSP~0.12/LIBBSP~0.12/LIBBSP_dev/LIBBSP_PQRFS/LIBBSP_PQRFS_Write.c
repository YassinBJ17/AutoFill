/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PQRFS_Write.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/


/*  -- LIBBSP_PQRFS_WriteUserLabels --
    * Return type : LIBBSP_PQRFS_Error 
    * IN:
        * v_buffer              :   Label's buffer
        * v_buffer_size         :   Number of labels
        * v_buffer_size_1_or_3  :   Number of labels for the first 5ms
        * v_1st_5ms             :   If set to true, configure the cycles 1 and 2, else set the cycles 3 and 4
    * Out:
        * v_ret                 :   E_LIBBSP_PQRFS_OK or E_LIBBSP_PQRFS_KO depending on the running.
*/
TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_WriteUserLabels( 
    const uint32_t* const p_buffer, const uint32_t v_buffer_size, const uint32_t v_buffer_size_1_or_3, const TE_LIBBSP_PQRFS_1ST_OR_3RD_CYCLE v_1st_5ms, const uint32_t v_failure
)
{
    TE_LIBBSP_PQRFS_Error v_ret;
    uint32_t v_nb;
    uint32_t v_add;
    uint32_t v_loopIterator;
    uint32_t v_cycle_identifier;
    int32_t v_current_data_time_ref;
    v_ret = E_LIBBSP_PQRFS_OK;

    /* Init cycle identifier variable */
    switch (v_1st_5ms)
    {
    case E_LIBBSP_PQRFS_1ST_CYCLE:
        v_cycle_identifier = (int32_t) C_LIBBSP_PQRFS_ITF_CI_12;
        break;

    case E_LIBBSP_PQRFS_3RD_CYCLE:
        v_cycle_identifier = (int32_t) C_LIBBSP_PQRFS_ITF_CI_34;
        break;
    default:
        v_ret = E_LIBBSP_PQRFS_KO;
        return (v_ret);
    }


    v_add = C_ADDR_DATA_START_ITF/sizeof(uint32_t);
    ((int32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = C_LIBBSP_PQRFS_ITF_Data_Start;
    

    v_add = ((uint32_t) C_ADDR_DATA_TIME_REF/sizeof(uint32_t));
    v_current_data_time_ref = ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[ v_add];    
    ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[ v_add] = v_current_data_time_ref + 1;
    
    /* Write cycle identifier */
    v_add = ((uint32_t) C_CYCLE_IDENTIFIER/sizeof(uint32_t));
    ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[ v_add] = v_cycle_identifier;    
    
    /* Calculate buffer size for 2nd or 4th cycle */
    if(v_buffer_size_1_or_3 >= v_buffer_size)
    {
        v_nb = 0;
    }
    else
    {
        v_nb = v_buffer_size - v_buffer_size_1_or_3;
    }
    

    /* Write the labels for 1st or 3rd cycle */
    for ( v_loopIterator = (uint32_t) 0 ; v_loopIterator < v_buffer_size_1_or_3; v_loopIterator ++ )
    {
        v_add = ((uint32_t) C_ADDR_DATA_ITF0/sizeof(uint32_t)  + v_loopIterator);
        ((int32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = p_buffer[v_loopIterator];
    }

    /* Fill with 0s */
    for ( v_loopIterator = (uint32_t) v_buffer_size_1_or_3 ; v_loopIterator < C_DIFF_CN_to_CNp1; v_loopIterator ++ )
    {
        v_add = ((uint32_t) C_ADDR_DATA_ITF0/sizeof(uint32_t)  + v_loopIterator);
        ((int32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = 0;
    }

    
    /* Write the labels for 2nd or 4th cycle*/
    for ( v_loopIterator = (uint32_t) 0 ; v_loopIterator < v_nb; v_loopIterator ++ )
    {
        v_add = ((uint32_t) C_ADDR_DATA_ITF13/sizeof(uint32_t) + v_loopIterator);
        ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[ v_add] = p_buffer[v_loopIterator + v_buffer_size_1_or_3];
    }   
    /* Fill with 0s */
    for ( v_loopIterator = (uint32_t) v_nb ; v_loopIterator < C_DIFF_CN_to_CNp1; v_loopIterator ++ )
    {
        v_add = ((uint32_t) C_ADDR_DATA_ITF13/sizeof(uint32_t)  + v_loopIterator);
        ((int32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = 0;
    }



    /* Write the failure case */
    v_add = ((uint32_t) C_ADDR_SW_FAILURE/sizeof(uint32_t) );
    ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[ v_add] = v_failure;

    v_add = ((uint32_t) C_ADDR_DATA_END_ITF/sizeof(uint32_t));
    ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[ v_add] = C_LIBBSP_PQRFS_ITF_Data_End;
    

    return (v_ret);
}


/*==== END =============================================================================*/
