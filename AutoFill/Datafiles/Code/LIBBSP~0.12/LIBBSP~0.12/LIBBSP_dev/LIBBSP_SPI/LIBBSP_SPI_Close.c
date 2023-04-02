/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Close.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_SPI_Close(void)
{
   volatile TU_LIBBSP_SPI_Spmode v_Reg_spmode;

   /* Disable whole eSPI block */
   v_Reg_spmode.R = 0ul;                 /* RAZ register image */
   v_Reg_spmode.B.EN = 0ul;              /* Disable eSPI block */
   V_SPI_Regs->spmode.R = v_Reg_spmode.R; /* Effective access   */

}
/*==== END =============================================================================*/
