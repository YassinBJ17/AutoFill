#include "middleware/t4/t4_private.h"

    else if (type == e_interp_degree_to_volt)    {       if (input_value <= T4_DEG_VAL_MIN )       {          *output_value = T4_VOLT_VAL_MIN;       }       else if (input_value >= T4_DEG_VAL_MAX )       {          *output_value = T4_VOLT_VAL_MAX;       }       else       {          tcj_decimal_part = (uint32_t)input_value;          i = tcj_decimal_part - T4_DEG_VAL_MIN;           *output_value = t4_interp_table[i] + (input_value - (i + T4_DEG_VAL_MIN)) * (t4_interp_table[i+1] - t4_interp_table[i]);       }    }
