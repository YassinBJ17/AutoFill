#include "middleware/pbit/pbit_private.h"

    for (i=(uint32_t)0; i<SRAM_TEST_VAL_NB; i++)    {       ext_sram_pointer = (uint32_t*)ext_sram_addresses[i];       ext_sram_value_save[i] = *ext_sram_pointer;       if((uint32_t)0 == i)       {          *ext_sram_pointer = SRAM_VAL_1_55;       }       else if ((uint32_t)1 == i)       {          *ext_sram_pointer = SRAM_VAL_2_AA;       }       else       {          *ext_sram_pointer = (uint32_t)(ext_sram_addresses[i]);       }    }
