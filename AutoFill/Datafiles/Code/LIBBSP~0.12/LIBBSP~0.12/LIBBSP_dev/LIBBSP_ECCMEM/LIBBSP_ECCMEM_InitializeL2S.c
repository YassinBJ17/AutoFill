/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ECCMEM_InitializeL2S.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*XBX:
Cette fonction initialise la gestion l'ecc (pointeur et registres):
-> activation de la d�tection des seu et mbu sur le DDR
-> deselection des it sur le SEU
-> selection du machine check sur MBU
-> configuration du seuil de MBU � la valeur donn�e en param�tre (entre 0 et 255)
� l'aide des registres DDR_ERR_DISABLE, DDR_ERR_INT_EN, DDR_ERR_SBE*/

void LIBBSP_ECCMEM_InitializeL2S( const TE_LIBBSP_ECCMEM_SeuMbuEn v_SeuMbuEn,
								  const TE_LIBBSP_ECCMEM_SeuMbuIt v_SeuMbuIT, const uint8_t v_SeuThresh )
{
	/*L2_ERR_DISABLE*/
	V_EccmemL2SRAMRegs->l2_err_disable = (uint32_t) v_SeuMbuEn; /* %RELAX<SYNCHRONe_C_Code_10.7> field on 8 bits , no loss of precision */

	/*L2_ERR_INT_EN*/
	V_EccmemL2SRAMRegs->l2_err_int_en = (uint32_t) v_SeuMbuIT; /* %RELAX<SYNCHRONe_C_Code_10.7> field on 8 bits , no loss of precision */


	/*L2_ERR_SBE*/
	V_EccmemL2SRAMRegs->l2_err_ctl.ErrSBE.SBET = (uint32_t)v_SeuThresh;


}


/*==== END =============================================================================*/
