/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_ReadPage.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_ReadPage(const TE_LIBBSP_SPI_Device devID,
                                              const uint32_t flashAddress,
                                              const uint32_t size,
                                              uint8_t * const buffer, /* %RELAX<SYNCHRONe_C_Code_8.18> Output only used by subfunction not detected as subfunction */
                                              const boolean_t fastRead)
{
    TE_LIBBSP_SPI_ErrorCode v_Rc;
    TE_LIBBSP_FNOR_ErrorCode v_StatusFlash;

    v_StatusFlash = E_LIBBSP_FNOR_OK;
    v_Rc = E_LIBBSP_SPI_TIMEOUT_WRONG_CMD;

    /* check the availability for reading */
    LIBBSP_FNOR_ReadCheckAvailability(devID, &v_Rc, &v_StatusFlash);

    /* Enable Write */
    if (v_Rc == E_LIBBSP_SPI_OK)
    {
        v_Rc = LIBBSP_FNOR_EnableWrite(devID);
        if (v_Rc != E_LIBBSP_SPI_OK)
        {
            v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x50*/;
        }
    }

    /* Enter 4 bytes addressing mode */
    if(v_StatusFlash == E_LIBBSP_FNOR_OK)
    {
        v_Rc = LIBBSP_FNOR_Enter4B(devID);
        if (v_Rc != E_LIBBSP_SPI_OK)
        {
            v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x51*/;
        }
    }

    if(v_StatusFlash == E_LIBBSP_FNOR_OK)
    {
        LIBBSP_FNOR_ReadPageSeg(devID, flashAddress, size, buffer, &v_StatusFlash, fastRead);
        LIBBSP_FNOR_ReadEnable(devID, &v_StatusFlash);
    }

    /* Final v_StatusFlash */
    if(v_StatusFlash != E_LIBBSP_FNOR_OK)
    {
        /* Exit 4 bytes addressing mode */
       (void) LIBBSP_FNOR_Exit4B(devID);
    }

    return v_StatusFlash; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
