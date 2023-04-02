/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_A429_READ_ERROR_H
#define LIBBSP_A429_READ_ERROR_H

#include "LIBBSP_A429_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_A429_RxErrorCode LIBBSP_A429_ReadError(

	const TE_LIBBSP_A429_RxLine devID,
	const uint32_t NbLabToRead,
	uint32_t * const buffer,
	uint32_t * const timetags,
	uint32_t * const NbLabRead,
	const TU_LIBBSP_A429_RxState * const ErrorState,
	uint32_t  * const v_fifoPointerFirst,
    const uint32_t  * const v_fifoPointerLast,
    boolean_t  * const v_gap,
    boolean_t  * const v_par,
    boolean_t  * const v_format    
);

/*==== END =============================================================================*/
#endif
