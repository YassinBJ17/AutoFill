/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_RMM_WritePage.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_RMM_WritePage(const uint32_t         rmmAddress,
                                        const uint32_t         size,
                                        const uint8_t * const  buffer)
{
    TE_LIBBSP_I2C_Code v_rc;
    uint8_t v_i2cAddr;

    if (((rmmAddress % (uint32_t)C_RMM_PAGE_SIZE) + size) > (uint32_t)C_RMM_PAGE_SIZE)
    {
        return (E_LIBBSP_I2C_INVALID_ID);
    }
    if ((rmmAddress&0x00010000ul) == 0ul)
    {
        v_i2cAddr = C_RMM_24FC1025_B0_ADDR;
    }
    else
    {
        v_i2cAddr = C_RMM_24FC1025_B1_ADDR;
    }
    V_RMMWriteBuffer[0] = (uint8_t)((rmmAddress & 0x0000FF00ul) >> 8);
    V_RMMWriteBuffer[1] = (uint8_t)(rmmAddress & 0x000000FFul);
    LibC_Memcpy(&V_RMMWriteBuffer[2], buffer, size);
    v_rc = LIBBSP_I2C_Write(C_RMM_USED_BUS, v_i2cAddr, size + 2ul, V_RMMWriteBuffer);

    if (v_rc == E_LIBBSP_I2C_OK)
    {
        v_rc = E_LIBBSP_I2C_NO_ACK;
        while (v_rc == E_LIBBSP_I2C_NO_ACK || v_rc == E_LIBBSP_I2C_BUS_BUSY)
        {
            v_rc = LIBBSP_I2C_Write(C_RMM_USED_BUS, v_i2cAddr, 0ul, NULL);
        }
    }

    return (v_rc);
}

/*==== END =============================================================================*/
