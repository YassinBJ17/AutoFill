/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_GetAdditionalReadData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/*==== Services ========================================================================*/
/*{{RELAX<SYNCHRONe_C_Code_17.4>*/
/*Use of pointer array indexing :can't guess the size of the memory to read*/
/*Overflow is avoid in th efor instruction with v_index < NbDataToRead*/
void LIBBSP_IMU_GetAdditionalReadData(const uint32_t NbDataToRead, TS_LIBBSP_IMU_DoubleWord* const v_RawAdditionalData)
{
	uint32_t v_index;

	for (v_index = (uint32_t)0; v_index < NbDataToRead; v_index++)
	{

		v_RawAdditionalData[v_index].double_int.msb = V_IMUTicRegs->tic_hw2sw_buffer.output_read_sw2hw[(v_index + C_IMU_NB_INERTIAL_DATA_TO_READ)*C_IMU_COEFF_ADDR];

		v_RawAdditionalData[v_index].double_int.lsb = V_IMUTicRegs->tic_hw2sw_buffer.output_read_sw2hw[((v_index + C_IMU_NB_INERTIAL_DATA_TO_READ)*C_IMU_COEFF_ADDR) + 1ul];

	}


}

/*}}RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
