#include "driver/i2c/drv_I2C_public.h"

       while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )          {         timeout++;       }     }     else     {       p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;     }     ptr_i2cReg->s_IBCR = ptr_i2cReg->s_IBCR & 0xDF;      ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR & 0xEF;         ptr_i2cReg->s_IBSR = 0x02;   }   else   {     p_bsw_errno_pt->u_b.s_RC_NOT_AVAILABLE = 1;   }
