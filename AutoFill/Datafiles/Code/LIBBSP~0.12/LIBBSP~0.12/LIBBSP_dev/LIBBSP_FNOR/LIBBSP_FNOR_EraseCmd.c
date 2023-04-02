/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_EraseCmd.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_FNOR_EraseCmd( const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const TE_LIBBSP_FNOR_EraseCommand command, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash)
{
	TE_LIBBSP_SPI_ErrorCode v_Rc;

	v_Rc = E_LIBBSP_SPI_OK;

    if (*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
        /* Choose correct opcode corresponding to erase command  */
    	LIBBSP_FNOR_PrepareCommand((uint8_t)0, flashAddress);
        switch(command) {
            case E_LIBBSP_FNOR_BULK_ERASE:
                V_FNOR_WriteBuffer[0] = (uint8_t)E_LIBBSP_FNOR_BULKE; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum max value within range of uint8 */
                v_Rc = LIBBSP_SPI_Exchange(devID, 0ul, (uint8_t*)0, 1ul, V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: no cast on NULL */
                break;
            case E_LIBBSP_FNOR_SECTOR_ERASE:
                V_FNOR_WriteBuffer[0] = (uint8_t)E_LIBBSP_FNOR_SE; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum max value within range of uint8 */
                v_Rc = LIBBSP_SPI_Exchange(devID, 0ul, (uint8_t*)0, C_FNOR_EXCHANGE_SIZE_OUT, V_FNOR_WriteBuffer,(uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: no cast on NULL */
                break;
            case E_LIBBSP_FNOR_SUB_SECTOR_ERASE_4KB:
                V_FNOR_WriteBuffer[0] = (uint8_t)E_LIBBSP_FNOR_SUBSE; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum max value within range of uint8 */
                v_Rc = LIBBSP_SPI_Exchange(devID, 0ul, (uint8_t*)0, C_FNOR_EXCHANGE_SIZE_OUT, V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: no cast on NULL */
                break;
            default:
                *v_StatusFlash = E_LIBBSP_FNOR_INVALID_ERASE;
                break;
        }

        if (v_Rc != E_LIBBSP_SPI_OK)
        {
            *v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x34;*/
        }
    }


}
/*==== END =============================================================================*/
