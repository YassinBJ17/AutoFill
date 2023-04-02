/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_Open.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_Open(const TE_LIBBSP_SPI_Device devID)
{

	TE_LIBBSP_SPI_ErrorCode v_Rc;
    TU_LIBBSP_SPI_Config v_FLASH_spmodex;
    TE_LIBBSP_FNOR_ErrorCode v_FlashStatus;


    /* Close SPI before open a new one */
    LIBBSP_SPI_Close();

	if ( (devID == E_LIBBSP_SPI_FLASH_PROGRAM) ||  (devID == E_LIBBSP_SPI_FLASH_BITE) )
	{
        /* Prepare bus signal configuration for FLASH */
        v_FLASH_spmodex.R = 0ul;       /* RAZ register image */

        v_FLASH_spmodex.B.CI    = 0ul; /* CLOCK_INVERT - low */
        v_FLASH_spmodex.B.CP    = 0ul; /* CLOCK_PHASE - middle */
        v_FLASH_spmodex.B.REV   = 1ul; /* FIRST_CHAR - MSB first */
        v_FLASH_spmodex.B.DIV16 = 0ul; /* DIV_16 - CCB/2 ie 333/2 = 166 Mhz */
        v_FLASH_spmodex.B.PM    = 1ul; /* PRESCALE - (2 * (PM + 1) = 6 -> esPI CLK = 166,5/6 = 27 Mhz*/
        v_FLASH_spmodex.B.ODD   = 0ul; /* ODD_DIVISION - Even division */
        v_FLASH_spmodex.B.POL   = 1ul; /* CS_POLARITY - Asserted low */
        v_FLASH_spmodex.B.LEN   = C_FNOR_CHAR_LENGTH; /* CHAR_LENGTH - 8 bits */
        v_FLASH_spmodex.B.CSBEF = 0ul; /* CS_BEFORE_FRAME */
        v_FLASH_spmodex.B.CSAFT = 0ul; /* CS_AFTER_FRAME */
        v_FLASH_spmodex.B.CSCG  = C_FNOR_CS_CLOCK_GAP; /* CS_CLOCK_GAP - Gap = 2 */

        /* Open eSPI resource */
        v_Rc = LIBBSP_SPI_Open(devID, &v_FLASH_spmodex);
		if (v_Rc == E_LIBBSP_SPI_OK)
		{
			v_FlashStatus = E_LIBBSP_FNOR_OK;
		}
        else
        {
            v_FlashStatus = E_LIBBSP_FNOR_INVALID_ID;
        }
	}
	else
	{
		v_FlashStatus = E_LIBBSP_FNOR_INVALID_ID;
	}

	return v_FlashStatus; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
