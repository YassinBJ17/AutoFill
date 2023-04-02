/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_Erase.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_Erase(const TE_LIBBSP_SPI_Device devID, const TE_LIBBSP_FNOR_EraseCommand command, const uint32_t flashAddress)
{
	TE_LIBBSP_SPI_ErrorCode v_Rc;
    TE_LIBBSP_FNOR_ErrorCode v_StatusFlash;


    v_StatusFlash = E_LIBBSP_FNOR_OK;
    if ( (devID == E_LIBBSP_SPI_FLASH_PROGRAM) ||  (devID == E_LIBBSP_SPI_FLASH_BITE) )
	{

        /* Enable Write */
        v_Rc = LIBBSP_FNOR_EnableWrite(devID);
        if (v_Rc != E_LIBBSP_SPI_OK)
        {
            v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x30*/;
        }

        /* Enter 4 bytes addressing mode */
        if (v_StatusFlash == E_LIBBSP_FNOR_OK)
        {
            v_Rc = LIBBSP_FNOR_Enter4B(devID);
            if (v_Rc != E_LIBBSP_SPI_OK)
            {
                v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x31*/;
            }
        }

        /* Enable Write */
        if (v_StatusFlash == E_LIBBSP_FNOR_OK)
        {
            v_Rc = LIBBSP_FNOR_EnableWrite(devID);
            if (v_Rc != E_LIBBSP_SPI_OK)
            {
                v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x32*/;
            }
        }

        /* Clear Flag Status Register  */
        if (v_StatusFlash == E_LIBBSP_FNOR_OK)
        {
            v_Rc = LIBBSP_FNOR_ClearFlagStatusReg(devID);
            if (v_Rc != E_LIBBSP_SPI_OK)
            {
                v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x33*/;
            }
        }

        LIBBSP_FNOR_EraseCmd(devID, flashAddress, command, &v_StatusFlash);

        /* Final v_StatusFlash */
        if(v_StatusFlash != E_LIBBSP_FNOR_OK)
        {
            /* Exit 4 bytes addressing mode */
            (void)LIBBSP_FNOR_Exit4B(devID);
        }
        
    }
    else
	{
		v_StatusFlash = E_LIBBSP_FNOR_INVALID_ID;
	}

    return v_StatusFlash; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
