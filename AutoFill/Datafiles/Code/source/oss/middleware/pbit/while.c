#include "middleware/pbit/pbit_private.h"

    while ((uint8_t)0 == err_flag && w_i < SRAM_TEST_VAL_NB)    {       ext_sram_pointer = (uint32_t*)ext_sram_addresses[w_i];       ext_sram_read_value = *ext_sram_pointer;       if((uint32_t)0 == w_i)       {          if (ext_sram_read_value != SRAM_VAL_1_55)          {             err_flag = (uint8_t)1;          }          else          {             *ext_sram_pointer = ext_sram_value_save[w_i];          }       }       else if ((uint32_t)1 == i)       {          if(ext_sram_read_value != SRAM_VAL_2_AA)          {             err_flag =  (uint8_t)1;          }          else          {             *ext_sram_pointer = ext_sram_value_save[w_i];          }       }       else       {          if(ext_sram_read_value != (uint32_t)(ext_sram_addresses[w_i]))          {             err_flag =  (uint8_t)1;             *ext_sram_pointer = ext_sram_value_save[w_i];          }          else          {             *ext_sram_pointer = ext_sram_value_save[w_i];          }       }       w_i++;    }
