/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ECCMEM_PostDDR.h"
#include "LIBBSP_CMN.h"

/*==== Definitions =====================================================================*/

#define C_LIBBSP_ECCMEM_WAIT_COUNT	100ul

/*==== Variables =======================================================================*/

uint32_t V_EccmemDdrWait;

/*==== Services ========================================================================*/
/*XBX:
Cette fonction test les 64 bits de data et les 8 bits d'ecc 1 � 1 et v�rifie que le nombre de seu est correct (i.e. 72)�
l'aide des registres DDR_CAPTURE_DATA_HI, DDR_CAPTURE_DATA_LO, DDR_CAPTURE_ECC et DDR_ERR_SBE. */

TE_LIBBSP_ECCMEM_SeuStatus LIBBSP_ECCMEM_PostDDR(const uint32_t * const DDR_data_Addr)
{
	TE_LIBBSP_ECCMEM_SeuStatus v_ret;
	uint32_t * pt_addr;
	uint32_t v_SavedValue;
	uint32_t v_SavedRegDis;
	uint32_t v_SavedRegIt;
	uint32_t v_DataTest;
	uint32_t v_index;
	uint32_t v_CountSBE;
	boolean_t v_ErrThresh;
	boolean_t v_MBUErrDetect;

	v_DataTest = 0xA5A5A5A5ul;

	v_ret = E_LIBBSP_ECCMEM_SEU_OK;

	/*Inject SBE error bit by bit on 32 bits*/

	pt_addr = (uint32_t*)DDR_data_Addr;
	v_SavedValue = *pt_addr;
	v_SavedRegDis = V_EccmemDdrRegs->ddr_err_disable;
	v_SavedRegIt = V_EccmemDdrRegs->ddr_err_int_en;
	V_EccmemDdrRegs->ddr_err_sbe.ErrSBE.SBEC = (uint32_t)0;

	for (v_index=0ul; v_index < (uint32_t)(C_ECCMEM_NB_ECC_INJ + C_ECCMEM_NB_MBU_INJ) ; v_index++)
	{
		if (v_index < C_ECCMEM_NB_ECC_INJ)
		{
			/* Inject ECC error*/
			V_EccmemDdrRegs->ddr_data_err_inject_lo = C_ECCMEM_ERROR_INJ_LO_MASK << v_index;
		}
		else
		{
			/*Inject MBU error*/
			V_EccmemDdrRegs->ddr_data_err_inject_lo = C_ECCMEM_MBU_ERROR_INJ;
		}

		/* Error injection enable*/
		V_EccmemDdrRegs->ddr_err_inject.ErrInjEn.Err_inj_en = 1ul;
		asm("isync");

		/* Write the value value that will be corrupted*/
		*pt_addr = v_DataTest;
		asm("msync");
		asm("isync");
		for(V_EccmemDdrWait=0ul;V_EccmemDdrWait<C_LIBBSP_ECCMEM_WAIT_COUNT;++V_EccmemDdrWait);

		/* Disable Error injection*/
		V_EccmemDdrRegs->ddr_err_inject.ErrInjEn.Err_inj_en = 0ul;
		asm("isync");

		/* Detect the corruption by forcing data reload */
		*pt_addr = v_DataTest;
		asm("msync");
		asm("isync");
		for(V_EccmemDdrWait=0ul;V_EccmemDdrWait<C_LIBBSP_ECCMEM_WAIT_COUNT;++V_EccmemDdrWait);
	}

	/* Check SBE error detect bit*/
	v_ErrThresh = (boolean_t)V_EccmemDdrRegs->ddr_err_detect.ErrDetect.SBE_error_detect; /* %RELAX<SYNCHRONe_C_Code_10.7> field on one bit  , no loss of precision */

	/* Check MBU error detect bit*/
	v_MBUErrDetect = (boolean_t)V_EccmemDdrRegs->ddr_err_detect.ErrDetect.MBU_error_detect; /* %RELAX<SYNCHRONe_C_Code_10.7> field on one bit  , no loss of precision */

	if (v_ErrThresh)
	{
		V_EccmemDdrRegs->ddr_err_detect.ErrDetect.SBE_error_detect = (uint32_t)1;
	}

	if (v_MBUErrDetect)
	{
		V_EccmemDdrRegs->ddr_err_detect.ErrDetect.MBU_error_detect = (uint32_t)1;
	}

	/* Retrieve the counter of ECC errors*/
	v_CountSBE = V_EccmemDdrRegs->ddr_err_sbe.ErrSBE.SBEC;

	/* Reset values to previous state */
	V_EccmemDdrRegs->ddr_err_disable = (uint32_t)E_LIBBSP_ECCMEM_MBU_SEU_DIS; /* %RELAX<SYNCHRONe_C_Code_10.7> field on 8 bits  , no loss of precision */
	asm("isync");
	*pt_addr = v_SavedValue;
	LIBBSP_CMN_Wait((uint32_t)1); /* 10 us */
	V_EccmemDdrRegs->ddr_data_err_inject_lo = (uint32_t)0;
	V_EccmemDdrRegs->ddr_err_disable = v_SavedRegDis;
	V_EccmemDdrRegs->ddr_err_int_en = v_SavedRegIt;
	V_EccmemDdrRegs->ddr_err_sbe.ErrSBE.SBEC = (uint32_t)0;

	if (v_ErrThresh != FALSE)
	{
		v_ret = E_LIBBSP_ECCMEM_SEU_THRESH_EXCEED;
	}
	else if (v_CountSBE != C_ECCMEM_NB_ECC_INJ)
	{
		v_ret = E_LIBBSP_ECCMEM_SEU_WRONG_NB;
	}
	else if (v_MBUErrDetect == FALSE)
	{
		v_ret = E_LIBBSP_ECCMEM_MBU_NOT_DETECTED;
	}


    return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
