/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_ProgAdditionalReadData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_IMU_ProgStatus LIBBSP_IMU_ProgAdditionalReadData (const uint32_t * const BufferAddrRead, const uint32_t NbDataToRead)
{
   TE_LIBBSP_IMU_ProgStatus v_ret;

	uint32_t v_index;


	if (NbDataToRead <= (C_IMU_BLADE_TIC_NB_DATA_READ_MAX - C_IMU_NB_INERTIAL_DATA_TO_READ))
	{

		for (v_index = 0ul; v_index < NbDataToRead; v_index++)
		{
			/*{{RELAX<SYNCHRONe_C_Code_17.4> Pointer used as buffer. Can't guess the size of data to read*/
			V_IMUTicRegs->tic_sw2hw_buffer.input_read_sw2hw[v_index + C_IMU_NB_INERTIAL_DATA_TO_READ] = BufferAddrRead[v_index];
			/*}}RELAX<SYNCHRONe_C_Code_17.4> */
		}

		v_ret = E_LIBBSP_IMU_NB_DATA_OK;
	}
	else
	{
		v_ret = E_LIBBSP_IMU_NB_DATA_EXCEEDED;
	}


	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
