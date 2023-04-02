/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_ProgPrecStatusCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/


/*==== Services ========================================================================*/
/*Ecriture de la commande de precession*/

void LIBBSP_IMU_ProgPrecStatusCommand(const boolean_t PrecessionCmd, const TE_LIBBSP_IMU_WriteAddr WritePrecAddr)
{

	/*Ecriture de la commande de precession*/
	if (WritePrecAddr == E_LIBBSP_IMU_WRITE_ADDRESS)
	{
		V_IMUTicRegs->tic_sw2hw_buffer.input_write_sw2hw[0] = (uint32_t)C_IMU_activ_precession;
	}

	V_IMUTicRegs->tic_sw2hw_buffer.input_write_sw2hw[1] = (uint32_t)PrecessionCmd;

}

/*==== END =============================================================================*/
