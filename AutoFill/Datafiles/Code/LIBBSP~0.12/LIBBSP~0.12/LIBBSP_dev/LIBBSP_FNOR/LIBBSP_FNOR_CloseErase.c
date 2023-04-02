/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_CloseErase.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_CloseErase(const TE_LIBBSP_SPI_Device devID)
{
	TE_LIBBSP_SPI_ErrorCode v_Rc;
    TE_LIBBSP_FNOR_ErrorCode v_StatusFlash;
    TU_LIBBSP_FNOR_FlashRegister v_Reg;

    v_StatusFlash = E_LIBBSP_FNOR_OK;

    if ( (devID == E_LIBBSP_SPI_FLASH_PROGRAM) ||  (devID == E_LIBBSP_SPI_FLASH_BITE) )
	{
        /* Read Flag Status Register  */
        V_FNOR_WriteBuffer[0] = (uint8_t)E_LIBBSP_FNOR_RFSR; /* %RELAX<SYNCHRONe_C_Code_10.7> enum field on 8 bits , no loss of precision */
        v_Rc = LIBBSP_SPI_Exchange(devID, 1ul, &v_Reg.R, 1ul, V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: no cast on NULL */

        if (v_Rc != E_LIBBSP_SPI_OK)
        {
            v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x36;*/
        }


        /* Verify erase command */
        if(v_StatusFlash == E_LIBBSP_FNOR_OK)
        {
            if (v_Reg.FLAGSTATUS.ER == (uint8_t)1)
            {
                v_StatusFlash = E_LIBBSP_FNOR_ERASE_ERROR;
            }
        }
        if(v_StatusFlash == E_LIBBSP_FNOR_OK)
        {
            if (v_Reg.FLAGSTATUS.PROT == (uint8_t)1)
            {
                v_StatusFlash = E_LIBBSP_FNOR_PROTECTION_ERROR;
            }
        }
        if(v_StatusFlash != E_LIBBSP_FNOR_OK)
        {
            /* Exit 4 bytes addressing mode */
            v_Rc = LIBBSP_FNOR_Exit4B(devID);
            if (v_Rc != E_LIBBSP_SPI_OK)
            {
                v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x37;*/
            }
        }


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
