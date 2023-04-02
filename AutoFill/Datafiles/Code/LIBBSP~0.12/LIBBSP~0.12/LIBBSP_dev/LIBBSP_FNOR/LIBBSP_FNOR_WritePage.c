/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_WritePage.h"

/*==== Definitions =====================================================================*/
/*const uint32_t C_FNOR_TIMEOUT = 1000;*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_WritePage(const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const uint32_t size, const uint8_t * const buffer)
{
	TE_LIBBSP_SPI_ErrorCode v_Rc;
    TE_LIBBSP_FNOR_ErrorCode v_StatusFlash;
    /*uint32_t v_ByteIndex;*/
	/*uint32_t v_Timeout;*/


    v_StatusFlash = E_LIBBSP_FNOR_OK;

    /* Clear Flag Status Register  */
	v_Rc = LIBBSP_FNOR_ClearFlagStatusReg(devID);
	if (v_Rc != E_LIBBSP_SPI_OK)
	{
		v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x60*/;
	}

    /* Enable Write */
    if(v_StatusFlash == E_LIBBSP_FNOR_OK)
    {
        v_Rc = LIBBSP_FNOR_EnableWrite(devID);
        if (v_Rc != E_LIBBSP_SPI_OK)
        {
            v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x61*/;
        }
    }

	/* Enter 4 bytes addressing mode */
    if(v_StatusFlash == E_LIBBSP_FNOR_OK)
    {
        v_Rc = LIBBSP_FNOR_Enter4B(devID);
        if (v_Rc != E_LIBBSP_SPI_OK)
        {
            v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x62*/;
        }
    }

	/* Enable Write */
    if(v_StatusFlash == E_LIBBSP_FNOR_OK)
    {
        v_Rc = LIBBSP_FNOR_EnableWrite(devID);
        if (v_Rc != E_LIBBSP_SPI_OK)
        {
            v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x63*/;
        }
    }

    if(v_StatusFlash == E_LIBBSP_FNOR_OK)
    {
        LIBBSP_FNOR_PrepareWritePage(devID, flashAddress, size, buffer, &v_StatusFlash);

        LIBBSP_FNOR_WritePageStatus(devID, &v_StatusFlash);
    }


    /* Final v_StatusFlash */
    if(v_StatusFlash != E_LIBBSP_FNOR_OK)
    {
        /* Exit 4 bytes addressing mode */
        (void)LIBBSP_FNOR_Exit4B(devID);
    }

    return v_StatusFlash; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}


/*==== END =============================================================================*/
