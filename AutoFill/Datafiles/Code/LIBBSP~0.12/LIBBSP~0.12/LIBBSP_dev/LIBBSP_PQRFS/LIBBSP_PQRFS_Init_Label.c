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

/*  -- LIBBSP_PQRFS_Init_Label -- 
    * Return type : TE_LIBBSP_PQRFS_Error 
    * IN :
        * v_label_configuration : structure containing the following informations:   
            * min             : minimal value of the tic_data
            * max             : maximal value of the tic_data
            * msb             : Position of the most significant bit
            * lsb             : Position of the less significant bit
            * q               : Q value (msb / (2 ^ number of bits))
            * label_id        : Id of the label (octal)
            * label_index     : Position of the label in the configuration arrays
    * Out :
        * v_ret             :   E_LIBBSP_PQRFS_OK or E_LIBBSP_PQRFS_KO depending on the running.
*/
TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Init_Label( const TS_LIBBSP_PQRFS_LabelConfig v_label_configuration)
{
    TE_LIBBSP_PQRFS_Error v_ret = E_LIBBSP_PQRFS_OK;
    uint32_t v_add;

    v_add = ((uint32_t)C_LIBBSP_PQRFS_OperationalMax_Address/sizeof(uint32_t) + v_label_configuration.label_index);
    ((float32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = v_label_configuration.max;
    
    v_add = ((uint32_t)C_LIBBSP_PQRFS_OperationalMin_Address/sizeof(uint32_t) + v_label_configuration.label_index);
    ((float32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = v_label_configuration.min;
    
    /* Write LabelNumber */
    v_add = C_LIBBSP_PQRFS_LabelNumber_Address/sizeof(uint32_t) + v_label_configuration.label_index;
    ((uint32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = v_label_configuration.label_id;
    
    v_add = ((uint32_t) C_LIBBSP_PQRFS_MSBLocation_Address/sizeof(uint32_t) + v_label_configuration.label_index);
    ((uint32_t *)C_LIBBSP_PQRFS_Start_Address)[v_add] = v_label_configuration.msb;
    
    v_add = ((uint32_t) C_LIBBSP_PQRFS_LSBLocation_Address/sizeof(uint32_t) + v_label_configuration.label_index);
    ((uint32_t *)C_LIBBSP_PQRFS_Start_Address)[v_add] = v_label_configuration.lsb;
    
    v_add = ((uint32_t)C_LIBBSP_PQRFS_LSBValue_Address/sizeof(uint32_t) + v_label_configuration.label_index);
    ((float32_t*)C_LIBBSP_PQRFS_Start_Address)[v_add] = v_label_configuration.q_value;

    return (v_ret);
}

/*==== END =============================================================================*/
