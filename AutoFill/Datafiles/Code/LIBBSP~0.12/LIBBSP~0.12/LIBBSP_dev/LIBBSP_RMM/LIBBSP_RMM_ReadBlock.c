/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_RMM_ReadBlock.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_RMM_ReadBlock(  const uint8_t i2cAddress,
                                          const uint16_t rmmAddress,
                                          const uint32_t size,
                                          uint8_t * const buffer)
{
   TE_LIBBSP_I2C_Code v_rc;

   v_rc = LIBBSP_I2C_Write(C_RMM_USED_BUS, i2cAddress, sizeof(uint16_t), (uint8_t*)&rmmAddress);
   if (v_rc == E_LIBBSP_I2C_OK)
   {
      v_rc = LIBBSP_I2C_Read(C_RMM_USED_BUS, i2cAddress, size, buffer);
   }

   return (v_rc);
}

/*==== END =============================================================================*/
