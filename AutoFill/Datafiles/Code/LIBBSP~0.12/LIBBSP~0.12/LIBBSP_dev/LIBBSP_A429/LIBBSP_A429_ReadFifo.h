/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_A429_READ_FIFO_H
#define LIBBSP_A429_READ_FIFO_H

#include "LIBBSP_A429_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_A429_ReadFifo(

   const TE_LIBBSP_A429_RxLine devID,
   const uint32_t NbLabToRead,
   uint32_t * const buffer,
   uint32_t * const timetags,
   uint32_t v_fifoPointerFirst,
   const uint32_t v_fifoPointerLast,
   const uint32_t v_fifoRollover,
   uint32_t * const NbLabRead,
   TE_LIBBSP_A429_RxErrorCode * const v_rc 
);
/*==== END =============================================================================*/
#endif
