/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_RazWriteData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_IMU_RazWriteData(const TE_LIBBSP_IMU_WriteEraseCmd EraseCmd)
{
	/*volatile uint32_t * p_reg;*/
	uint32_t v_index;

	if (EraseCmd == E_LIBBSP_IMU_RESET_ALL_W_ADDR)
	{
		for (v_index = 0ul; v_index < C_IMU_BLADE_TIC_NB_DATA_WRITE_MAX; v_index++)
		{

			V_IMUTicRegs->tic_sw2hw_buffer.input_write_sw2hw[v_index*C_IMU_COEFF_ADDR] = 0ul;
			V_IMUTicRegs->tic_sw2hw_buffer.input_write_sw2hw[(v_index*C_IMU_COEFF_ADDR) +1ul] = 0ul;


		}

	}
	else
	{
		for (v_index = C_IMU_NB_PERMANENT_DATA_TO_WRITE; v_index < C_IMU_BLADE_TIC_NB_DATA_WRITE_MAX; v_index++)
		{

			V_IMUTicRegs->tic_sw2hw_buffer.input_write_sw2hw[v_index*C_IMU_COEFF_ADDR] = 0ul;
			V_IMUTicRegs->tic_sw2hw_buffer.input_write_sw2hw[(v_index*C_IMU_COEFF_ADDR) +1ul] = 0ul;
		}
	}
}

/*==== END =============================================================================*/
