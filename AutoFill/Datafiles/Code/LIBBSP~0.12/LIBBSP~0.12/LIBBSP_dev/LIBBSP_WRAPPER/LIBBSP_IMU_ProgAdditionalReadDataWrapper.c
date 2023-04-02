/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_ProgAdditionalReadDataWrapper.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_IMU_ProgAdditionalReadDataWrapper(const uint32_t CurrentCycle)
{
   /* Les premieres donnees additionnelles sont programmees en ecriture qu'a partir du cycle 2 */
   //TE_LIBBSP_IMU_ProgStatus v_ret;
   
   if (CurrentCycle >= (uint32_t)C_FIRST_INDEX && CurrentCycle < (uint32_t)C_SIZE)
   {
		(void)LIBBSP_IMU_ProgAdditionalReadData(
        C_LINK_CYCLE_DATA[CurrentCycle],
        (uint32_t)C_IMU_ADDITIONAL_NB_DATA_TO_READ);
   }
}

/*==== END =============================================================================*/
