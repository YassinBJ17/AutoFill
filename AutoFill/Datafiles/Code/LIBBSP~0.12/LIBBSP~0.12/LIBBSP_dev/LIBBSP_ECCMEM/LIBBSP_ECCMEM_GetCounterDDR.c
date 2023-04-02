/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ECCMEM_GetCounterDDR.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*XBX:
Cette fonction retourne le nombre de SEU détecté et remet le compteur à 0 à l'aide du registre DDR_ERR_SBE*/

void LIBBSP_ECCMEM_GetCounterDDR(uint8_t * const NbSeu, TE_LIBBSP_ECCMEM_SeuStatus * const v_ret)
{
	boolean_t v_ErrThresh;

	*v_ret = E_LIBBSP_ECCMEM_SEU_OK;

	/*Read the number of SBE*/
	*NbSeu = (uint8_t)(V_EccmemDdrRegs->ddr_err_sbe.ErrSBE.SBEC); /* %RELAX<SYNCHRONe_C_Code_10.7> Struc member on 8 bits reserved, no loss of precision */
	/*Reset the SBE counter*/
	V_EccmemDdrRegs->ddr_err_sbe.ErrSBE.SBEC = 0ul;


	/*SBE threshold bit error*/
	v_ErrThresh = (boolean_t)V_EccmemDdrRegs->ddr_err_detect.ErrDetect.SBE_error_detect; /* %RELAX<SYNCHRONe_C_Code_10.7> Struc member on one bit reserved, no loss of precision */

	if (v_ErrThresh != FALSE)
	{
		*NbSeu = (uint8_t)(V_EccmemDdrRegs->ddr_err_sbe.ErrSBE.SBET); /* %RELAX<SYNCHRONe_C_Code_10.7> Struc member on 8 bits reserved, no loss of precision */

		/*Clear the error detect SBE bit by writing 1*/
		V_EccmemDdrRegs->ddr_err_detect.ErrDetect.SBE_error_detect = 1ul;

		*v_ret = E_LIBBSP_ECCMEM_SEU_THRESH_EXCEED;
	}

}

/*==== END =============================================================================*/
