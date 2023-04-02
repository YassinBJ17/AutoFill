/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_PrepareCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* {{RELAX<SYNCHRONe_C_Code_10.7> Type transformation : Apply serveral byte mask , cast to uint8_t  */
void LIBBSP_FNOR_PrepareCommand(const uint8_t command, const uint32_t flashAddress)
{
	V_FNOR_WriteBuffer[0] = command;
	V_FNOR_WriteBuffer[1] = (uint8_t)((flashAddress&C_FNOR_MASK_FIRST_LSB_BYTE) >> C_FNOR_SHIFT_24_BITS);
	V_FNOR_WriteBuffer[2] = (uint8_t)((flashAddress&C_FNOR_MASK_SECOND_LSB_BYTE) >> C_FNOR_SHIFT_16_BITS);
	V_FNOR_WriteBuffer[3] = (uint8_t)((flashAddress&C_FNOR_MASK_SECOND_MSB_BYTE) >> C_FNOR_SHIFT_8_BITS);
	V_FNOR_WriteBuffer[4] = (uint8_t)(flashAddress&C_FNOR_MASK_FIRST_MSB_BYTE);
}
/* }} RELAX<SYNCHRONe_C_Code_10.7> */
/*==== END =============================================================================*/
