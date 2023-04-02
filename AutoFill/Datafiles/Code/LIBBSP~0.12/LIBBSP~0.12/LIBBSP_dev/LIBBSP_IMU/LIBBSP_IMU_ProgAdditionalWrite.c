/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_ProgAdditionalWrite.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_IMU_ProgStatus LIBBSP_IMU_ProgAdditionalWrite(const uint32_t * const BuffAddDataAddr,const int32_t * const BuffAddData, const uint32_t NbAddDataToWrite)
{
   TE_LIBBSP_IMU_ProgStatus v_ret;

	uint32_t v_index;

	if (NbAddDataToWrite <= (C_IMU_BLADE_TIC_NB_DATA_WRITE_MAX - C_IMU_NB_PERMANENT_DATA_TO_WRITE))
	{

		for (v_index = 0ul; v_index < NbAddDataToWrite; v_index++)
		{
		/*{{RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_10.7> Pointer used as buffer. So there is no loss of precision line 29*/
         V_IMUTicRegs->tic_sw2hw_buffer.input_write_sw2hw[(v_index + C_IMU_NB_PERMANENT_DATA_TO_WRITE)*C_IMU_COEFF_ADDR] = BuffAddDataAddr[v_index];

         V_IMUTicRegs->tic_sw2hw_buffer.input_write_sw2hw[((v_index + C_IMU_NB_PERMANENT_DATA_TO_WRITE)* C_IMU_COEFF_ADDR) + (uint32_t)1] = (uint32_t)BuffAddData[v_index];
		/*}}RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_10.7> */

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
