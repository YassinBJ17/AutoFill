#include "LIBUTI_CRC.h"


/* CRC 16 initial value */
#define C_CRC16_INIT_VALUE (uint16_t)0xFFFF
/* CRC 32 initial value */
#define C_CRC32_INIT_VALUE (uint32_t)0xFFFFFFFF



uint16_t LIBUTI_CRC_ComputeCRC16(const uint8_t* const DataAddress, const uint32_t DataSize)
{
   uint16_t v_ret;
   
   v_ret = LIBUTI_CRC_UpdateCRC16(DataAddress, DataSize, C_CRC16_INIT_VALUE); 
   return ( v_ret );
}


uint32_t LIBUTI_CRC_ComputeCRC32(const uint8_t* const DataAddress, const uint32_t DataSize)
{
   uint32_t CRC_Value;
   uint32_t v_ret;

   CRC_Value =  (C_CRC32_INIT_VALUE ^ ((uint32_t) 0xFFFFFFFF));
   v_ret = LIBUTI_CRC_UpdateCRC32(DataAddress, DataSize, CRC_Value); 
   return ( v_ret );
}
