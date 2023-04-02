/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_ProgReadInertialData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/*const uint32_t C_IMU_SW2HW_READ_BASE_ADDRESS = 0x2104;*/


/*==== Services ========================================================================*/
void LIBBSP_IMU_ProgReadInertialData(void)
{
	uint32_t v_index;

	for (v_index = 0ul; v_index < C_IMU_NB_INERTIAL_DATA_TO_READ; v_index++)
	{

		V_IMUTicRegs->tic_sw2hw_buffer.input_read_sw2hw[v_index] = C_IMU_INERTIAL_DATA_TO_READ[v_index];
	}

}

/*==== END =============================================================================*/
