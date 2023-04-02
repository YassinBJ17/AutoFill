/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_Enter4B.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_SPI_ErrorCode LIBBSP_FNOR_Enter4B(const TE_LIBBSP_SPI_Device devID)
{
	TE_LIBBSP_SPI_ErrorCode v_ret;

	v_ret = LIBBSP_SPI_Exchange(devID, (uint32_t)0, NULL, sizeof(C_FNOR_ENTER4B), &C_FNOR_ENTER4B, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: no cast on NULL */

	return v_ret;

}
/*==== END =============================================================================*/
