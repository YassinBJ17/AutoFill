/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PQRFS_Init_Label.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*  -- LIBBSP_PQRFS_Init_tic_data -- 
    * Description : This method writes in the TIC RAM the data contained in "p_buffer" at the memory "addr_tic_pqr"
    * Return type : TE_LIBBSP_PQRFS_Error 
    * IN :
        * p_buffer          :   Address of the data that has to be emmitted 
        * v_size            :   Number of label
    * Out :
        * v_ret             :   E_LIBBSP_PQRFS_OK or E_LIBBSP_PQRFS_KO depending on the running.
*/
TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Init_tic_data(const uint32_t * const p_buffer, const uint32_t v_size)
{
    TE_LIBBSP_PQRFS_Error v_ret = E_LIBBSP_PQRFS_OK;
    uint32_t v_add;
    uint32_t v_loopIterator;


    for ( v_loopIterator = (uint32_t) 0 ; v_loopIterator < v_size; v_loopIterator ++ )
    {
        /* v_loopIterator*2 as the RAM TIC is made of 64 bits words */
        v_add = ((uint32_t) (C_RAM_TIC_DATA_START/sizeof(uint32_t) + v_loopIterator*2));
        ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = p_buffer[v_loopIterator];
    }


    return (v_ret);
}

/*==== END =============================================================================*/