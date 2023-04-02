/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_CMN_H
#define LIBBSP_CMN_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"
/*==== Definitions =====================================================================*/
/*==== Types ===========================================================================*/
/* Conditionnal function */
typedef uint32_t (*conditionnalFunction)(void);


/*typedef enum {*/
/*   E_LIBBSP_CMN_TIME_IS_REACHED = 0,*/
/*   E_LIBBSP_CMN_TIME_IS_NOT_REACHED = 1*/
/*} TE_LIBBSP_CMN_Status;*/
/* defined in kcg_types.h */


/*==== Variables========================================================================*/



/*==== Services ========================================================================*/
extern uint32_t LIBBSP_CMN_GetTicks(void);
extern uint32_t LIBBSP_CMN_isElapsed(uint32_t * const Count);
extern void LIBBSP_CMN_waitForTrueCondition(/*const conditionnalFunction func,*/ const uint32_t timeout);
extern void LIBBSP_CMN_Wait(const uint32_t timeout);

/*==== END =============================================================================*/
#endif
