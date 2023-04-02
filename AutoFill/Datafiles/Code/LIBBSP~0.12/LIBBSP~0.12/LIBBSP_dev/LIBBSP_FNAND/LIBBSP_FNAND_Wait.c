/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Wait.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Internal definition of LIBBSP_CMD_Wait. This function wait v_Timeout * 1 us instead of v_Timeout * 10us.
 */
void Wait(const uint32_t v_Timeout)
{
   uint32_t count;

   count = v_Timeout;
   while ( IsElapsed(&count) == 0ul){};
   /* If v_ret = 0 => Time is reached*/
}

/*==== END =============================================================================*/
