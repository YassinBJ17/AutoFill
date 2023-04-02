/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_Read.h"
#include "LIBBSP_FNOR_ReadPage.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_Read(const TE_LIBBSP_SPI_Device devID,
		                                  const uint32_t flashAddress,
										  const uint32_t size,
										  uint8_t * const buffer) /* %RELAX<SYNCHRONe_C_Code_8.18> Output only used by subfunction not detected as Output */
{

    TE_LIBBSP_FNOR_ErrorCode v_StatusFlash;

	if (flashAddress < C_FNOR_ADDRESS_MIN && flashAddress + size > C_FNOR_ADDRESS_MAX)
	{
		return (E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR);
	}

	if ( (devID == E_LIBBSP_SPI_FLASH_PROGRAM) ||  (devID == E_LIBBSP_SPI_FLASH_BITE) )
	{
        v_StatusFlash = LIBBSP_FNOR_ReadPage(devID, flashAddress, size, buffer, FALSE);
    }
    else
	{
		v_StatusFlash = E_LIBBSP_FNOR_INVALID_ID;
	}

    return v_StatusFlash; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
