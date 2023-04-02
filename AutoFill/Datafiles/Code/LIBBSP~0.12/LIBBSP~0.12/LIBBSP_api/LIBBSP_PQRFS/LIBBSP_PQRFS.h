/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PQRFS_H
#define LIBBSP_PQRFS_H

#include "kcg_types.h"


/*==== Types ===========================================================================*/

typedef enum{
    E_LIBBSP_PQRFS_3RD_CYCLE = 0,
    E_LIBBSP_PQRFS_1ST_CYCLE = 1
} TE_LIBBSP_PQRFS_1ST_OR_3RD_CYCLE;

/*==== Variables========================================================================*/

/*==== Services ========================================================================*/

extern TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Deactivate_Line( const TE_LIBBSP_PQRFS_Line v_line, const boolean_t v_stop);
extern TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Activate_Sending( const boolean_t v_start );
extern TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_GetStatus( TS_LIBBSP_PQRFS_Status * const p_status_1_or_3,TS_LIBBSP_PQRFS_Status * const p_status_2_or_4 , const boolean_t v_1st_5ms );
extern TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Init_Cycle( const uint32_t* const pa_cycle, const uint32_t v_nb_labels_cycle, const TE_LIBBSP_PQRFS_Cycle v_cycle );
extern TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Init_Label( const TS_LIBBSP_PQRFS_LabelConfig v_label_configuration);
extern TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Init_tic_data(const uint32_t * const p_buffer, const uint32_t v_size);

extern TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_WriteUserLabels(  const uint32_t* const p_buffer, const uint32_t v_buffer_size, const uint32_t v_buffer_size_1_or_3, const TE_LIBBSP_PQRFS_1ST_OR_3RD_CYCLE v_1st_5ms, const uint32_t v_failure);

/*==== END =============================================================================*/
#endif
