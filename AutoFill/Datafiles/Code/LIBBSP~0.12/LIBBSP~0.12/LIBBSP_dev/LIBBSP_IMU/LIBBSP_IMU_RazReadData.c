/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_RazReadData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_IMU_RazReadData(const TE_LIBBSP_IMU_ReadEraseCmd EraseCmd)
{
	uint32_t v_index;

	if (EraseCmd == E_LIBBSP_IMU_RESET_ALL_R_ADDR)
	{
		for (v_index = 0ul; v_index < C_IMU_BLADE_TIC_NB_DATA_READ_MAX; v_index++)
		{


			V_IMUTicRegs->tic_sw2hw_buffer.input_read_sw2hw[v_index] = 0ul;
		}

	}
	else
	{

		for (v_index = C_IMU_NB_INERTIAL_DATA_TO_READ; v_index < C_IMU_BLADE_TIC_NB_DATA_READ_MAX; v_index++)
		{

			V_IMUTicRegs->tic_sw2hw_buffer.input_read_sw2hw[v_index] = 0ul;
		}

	}
}

/*==== END =============================================================================*/
