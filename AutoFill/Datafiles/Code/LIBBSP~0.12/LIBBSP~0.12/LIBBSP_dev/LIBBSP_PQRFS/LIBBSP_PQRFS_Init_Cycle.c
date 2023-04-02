/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PQRFS_Init_Cycle.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/


/*  -- LIBBSP_PQRFS_Init_Cycle --
    * Init the {v_cycle} cycle with the given 
    * Return type : TE_LIBBSP_PQRFS_Error 
    * IN:
        * p_cycle           :   array of pointers to config data to send
        * v_nb_labels_cycle :   number of labels to set for the cycle
        * v_cycle           :   Cycle to configure  
    * Out:      
        * v_ret             :   E_LIBBSP_PQRFS_OK or E_LIBBSP_PQRFS_KO depending on the running.
*/

TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Init_Cycle( const uint32_t* const p_cycle, const uint32_t v_nb_labels_cycle, const TE_LIBBSP_PQRFS_Cycle v_cycle )
{
    TE_LIBBSP_PQRFS_Error v_ret = E_LIBBSP_PQRFS_OK;
    
    uint32_t v_add;
    uint32_t v_cycle_address;
    uint32_t v_loopIterator;

    /* Get the correct cycle's address */
    switch (v_cycle)
    {
        case E_LIBBSP_PQRFS_Cycle1:
            v_cycle_address = C_ADDR_DATA_TO_GET_C1;
            break;

        case E_LIBBSP_PQRFS_Cycle2:
            v_cycle_address = C_ADDR_DATA_TO_GET_C2;
            break;
        
        case E_LIBBSP_PQRFS_Cycle3:
            v_cycle_address = C_ADDR_DATA_TO_GET_C3;
            break;
        
        case E_LIBBSP_PQRFS_Cycle4:
            v_cycle_address = C_ADDR_DATA_TO_GET_C4;
            break;
        
        default:
            return E_LIBBSP_PQRFS_KO;
            break;
    }

    /* Write the data to send */
    for (v_loopIterator = 0; v_loopIterator < v_nb_labels_cycle; v_loopIterator++)
    {
        v_add = ((uint32_t)v_cycle_address/sizeof(uint32_t) + v_loopIterator);
        ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = p_cycle[v_loopIterator];
    }

    /* Fill with 0s */
    for (v_loopIterator = v_nb_labels_cycle; v_loopIterator < C_DIFF_CN_to_CNp1; v_loopIterator++)
    {
        v_add = ((uint32_t)v_cycle_address/sizeof(uint32_t) + v_loopIterator);
        ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = 0;
    }

    return (v_ret);
}

/*==== END =============================================================================*/
