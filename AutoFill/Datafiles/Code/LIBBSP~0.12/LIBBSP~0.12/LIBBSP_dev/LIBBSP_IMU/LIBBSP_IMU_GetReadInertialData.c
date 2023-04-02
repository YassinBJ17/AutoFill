/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_GetReadInertialData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_IMU_GetReadInertialData(TS_LIBBSP_IMU_InertialData* const ReadInertialData)
{
	TS_LIBBSP_IMU_DoubleWord v_RawInertialData [C_IMU_NB_INERTIAL_DATA_TO_READ];
	uint32_t v_index;

	/* Get undecoded inertial data */
	for (v_index = 0ul; v_index < C_IMU_NB_INERTIAL_DATA_TO_READ; v_index++)
	{

		v_RawInertialData[v_index].double_int.msb = V_IMUTicRegs->tic_hw2sw_buffer.output_read_sw2hw[v_index*C_IMU_COEFF_ADDR];

		v_RawInertialData[v_index].double_int.lsb = V_IMUTicRegs->tic_hw2sw_buffer.output_read_sw2hw[(v_index*C_IMU_COEFF_ADDR) + 1ul];
	}

	/*Convert float40 to float64 and set ReadInertialData*/
	ReadInertialData->dTheta[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_0]);
	ReadInertialData->dTheta[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_1]);
	ReadInertialData->dTheta[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_2]);

	ReadInertialData->dV[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_3]);
	ReadInertialData->dV[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_4]);
	ReadInertialData->dV[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_5]);

	ReadInertialData->Cp[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_6]);
	ReadInertialData->Cp[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_7]);
	ReadInertialData->Cp[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_8]);

	ReadInertialData->TheteE[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_9]);
	ReadInertialData->TheteE[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_10]);
	ReadInertialData->TheteE[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_11]);

	ReadInertialData->ErrFEP[E_LIBBSP_IMU_INDEX_0] = - LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_12]);
	ReadInertialData->ErrFEP[E_LIBBSP_IMU_INDEX_1] = - LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_13]);
	ReadInertialData->ErrFEP[E_LIBBSP_IMU_INDEX_2] = - LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_14]);

	ReadInertialData->IndFEP[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_15]);
	ReadInertialData->IndFEP[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_16]);
	ReadInertialData->IndFEP[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_17]);

	ReadInertialData->synth_umi = v_RawInertialData[E_LIBBSP_IMU_INDEX_18].double_int.msb;
	ReadInertialData->cpt_tache_fNav = v_RawInertialData[E_LIBBSP_IMU_INDEX_19].double_int.msb;

	ReadInertialData->fs_filtA_BdL_fPilot_custUnit[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_20]);
	ReadInertialData->fs_filtA_BdL_fPilot_custUnit[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_21]);
	ReadInertialData->fs_filtA_BdL_fPilot_custUnit[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_22]);

	ReadInertialData->fs_filtB_BdL_fPilot_custUnit[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_23]);
	ReadInertialData->fs_filtB_BdL_fPilot_custUnit[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_24]);
	ReadInertialData->fs_filtB_BdL_fPilot_custUnit[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_25]);

	ReadInertialData->pqr_filtE_fPilot_custUnit[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_26]);
	ReadInertialData->pqr_filtE_fPilot_custUnit[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_27]);
	ReadInertialData->pqr_filtE_fPilot_custUnit[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_28]);

	ReadInertialData->pqr_filtF_fPilot_custUnit[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_29]);
	ReadInertialData->pqr_filtF_fPilot_custUnit[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_30]);
	ReadInertialData->pqr_filtF_fPilot_custUnit[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_31]);

	ReadInertialData->accAng_filtE_fPilot_custUnit[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_32]);
	ReadInertialData->accAng_filtE_fPilot_custUnit[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_33]);
	ReadInertialData->accAng_filtE_fPilot_custUnit[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_34]);

	ReadInertialData->accAng_filtF_fPilot_custUnit[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_35]);
	ReadInertialData->accAng_filtF_fPilot_custUnit[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_36]);
	ReadInertialData->accAng_filtF_fPilot_custUnit[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_37]);

	ReadInertialData->Tacc_filtre[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_38]);
	ReadInertialData->Tacc_filtre[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_39]);
	ReadInertialData->Tacc_filtre[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_40]);

   ReadInertialData->Tida_filtre = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_41]);

   ReadInertialData->Tacc_sature[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_42]);
   ReadInertialData->Tacc_sature[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_43]);
   ReadInertialData->Tacc_sature[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_44]);

   ReadInertialData->Cpulse_sature[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_45]);
   ReadInertialData->Cpulse_sature[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_46]);
   ReadInertialData->Cpulse_sature[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_47]);

   ReadInertialData->Tida_sature = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_48]);

	ReadInertialData->AccStatus = v_RawInertialData[E_LIBBSP_IMU_INDEX_49].double_int.msb;
	ReadInertialData->HrgStatus1 = v_RawInertialData[E_LIBBSP_IMU_INDEX_50].double_int.msb;
	ReadInertialData->HrgStatus2 = v_RawInertialData[E_LIBBSP_IMU_INDEX_51].double_int.msb;
	ReadInertialData->TicStatus1 = v_RawInertialData[E_LIBBSP_IMU_INDEX_52].double_int.msb;
	ReadInertialData->TicStatus2 = v_RawInertialData[E_LIBBSP_IMU_INDEX_53].double_int.msb;

	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_0] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_54]);
	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_1] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_55]);
	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_2] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_56]);
	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_3] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_57]);
	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_4] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_58]);
	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_5] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_59]);
	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_6] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_60]);
	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_7] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_61]);
	ReadInertialData->TmgyrData[E_LIBBSP_IMU_INDEX_8] = LIBBSP_IMU_F40toF64( &v_RawInertialData[E_LIBBSP_IMU_INDEX_62]);
}

/*==== END =============================================================================*/
