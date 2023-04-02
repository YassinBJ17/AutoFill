/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_IMU_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
volatile TS_LIBBSP_IMU_TicBuffersReg * const V_IMUTicRegs = (volatile TS_LIBBSP_IMU_TicBuffersReg * const) C_LIBBSP_MEGREG_TIC_ACCESS ; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: address */

const uint32_t C_IMU_MASK_23_MSB_BITS = 0x7fffff;
const uint32_t C_IMU_SHIFT_8_BITS = 8;
const uint32_t C_IMU_MASK_BIT_31 = 0x40000000;
const uint32_t C_IMU_MASK_31_MSB_BITS = 0x7fffffff;
const uint32_t C_IMU_SHIFT_11_BITS = 11;
const uint32_t C_IMU_MASK_11_MSB_BITS = 0x7FF;
const uint32_t C_IMU_SHIFT_21_BITS = 21;
const uint32_t C_IMU_EXPONENT_BIAS_SINGLE_PRECISION = 127;
const uint32_t C_IMU_EXPONENT_BIAS_DOUBLE_PRECISION = 1023;
const uint32_t C_IMU_EXPONENT_VALUE_MAX_SINGLE_PRECISION = 255;
const uint32_t C_IMU_EXPONENT_VALUE_MAX_DOUBLE_PRECISION = 2047;
const uint32_t C_IMU_MASK_BIT_23 = 0x400000;
const uint32_t C_IMU_MASK_BIT_20 = 0x80000;
const uint32_t C_IMU_SHIFT_3_BITS = 3;
const uint32_t C_IMU_MASK_3_MSB_BITS = 0x7;
const uint32_t C_IMU_SHIFT_29_BITS = 29;

const uint32_t C_IMU_BLADE_TIC_NB_DATA_READ_MAX = 64;

const uint32_t C_IMU_BLADE_TIC_NB_DATA_WRITE_MAX = 32;

const uint32_t C_IMU_INERTIAL_DATA_TO_READ[C_IMU_NB_INERTIAL_DATA_TO_READ] =
{
	C_IMU_dTheta_m_fNav_0,
	C_IMU_dTheta_m_fNav_1,
	C_IMU_dTheta_m_fNav_2,
	C_IMU_dV_m_fNav_0,
	C_IMU_dV_m_fNav_1,
	C_IMU_dV_m_fNav_2,
	C_IMU_Cp_fNav_0,
	C_IMU_Cp_fNav_1,
	C_IMU_Cp_fNav_2,
	C_IMU_ThetaE_fNav_0,
	C_IMU_ThetaE_fNav_1,
	C_IMU_ThetaE_fNav_2,
	C_IMU_errFEP_2kHz_0,
	C_IMU_errFEP_2kHz_1,
	C_IMU_errFEP_2kHz_2,
	C_IMU_indFEP_2kHz_0,
	C_IMU_indFEP_2kHz_1,
	C_IMU_indFEP_2kHz_2,
	C_IMU_synth_imu,
	C_IMU_cpt_tache_fNav,
	C_IMU_fs_filtA_BdL_fPilot_0,
	C_IMU_fs_filtA_BdL_fPilot_1,
	C_IMU_fs_filtA_BdL_fPilot_2,
	C_IMU_fs_filtB_BdL_fPilot_0,
	C_IMU_fs_filtB_BdL_fPilot_1,
	C_IMU_fs_filtB_BdL_fPilot_2,
	C_IMU_pqr_filtE_fPilot_0,
	C_IMU_pqr_filtE_fPilot_1,
	C_IMU_pqr_filtE_fPilot_2,
	C_IMU_pqr_filtF_fPilot_0,
	C_IMU_pqr_filtF_fPilot_1,
	C_IMU_pqr_filtF_fPilot_2,
	C_IMU_accAng_filtE_fPilot_0,
	C_IMU_accAng_filtE_fPilot_1,
	C_IMU_accAng_filtE_fPilot_2,
	C_IMU_accAng_filtF_fPilot_0,
	C_IMU_accAng_filtF_fPilot_1,
	C_IMU_accAng_filtF_fPilot_2,
	C_IMU_Tacc_filtre_0,
	C_IMU_Tacc_filtre_1,
	C_IMU_Tacc_filtre_2,
	C_IMU_Tida_filtre,
	C_IMU_Tacc_sature_0,
	C_IMU_Tacc_sature_1,
	C_IMU_Tacc_sature_2,
	C_IMU_Cpulse_deg_0,
	C_IMU_Cpulse_deg_1,
	C_IMU_Cpulse_deg_2,
	C_IMU_Tida_sature,
	C_IMU_acc_status,
	C_IMU_hrg_status_1,
	C_IMU_hrg_status_2,
	C_IMU_tic_status_1,
	C_IMU_tic_status_2,
	C_IMU_Mgyr_0,
	C_IMU_Mgyr_1,
	C_IMU_Mgyr_2,
	C_IMU_Mgyr_3,
	C_IMU_Mgyr_4,
	C_IMU_Mgyr_5,
	C_IMU_Mgyr_6,
	C_IMU_Mgyr_7,
	C_IMU_Mgyr_8
};

const uint32_t C_IMU_SW2HW_NB_REGISTERS = 64;

const uint32_t C_IMU_SW2HW_EN_CONSISTENT_DATA = 0xE152A4CB;

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
