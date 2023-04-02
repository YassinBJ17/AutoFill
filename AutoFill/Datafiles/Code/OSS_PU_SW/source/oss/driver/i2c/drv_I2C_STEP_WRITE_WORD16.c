#include "driver/i2c/drv_I2C_public.h"

 void drv_I2C_STEP_WRITE_WORD16 ( te_I2C_LINE_TYPE const p_i2c_line,                                  te_I2C_STEP_WRITE_TYPE const p_i2c_step,                                  uint8_t          const p_i2c_addr,                                  uint8_t          const p_i2c_cmd,                                  uint16_t         const p_write_word16_pt,                                  tu_CMN_RC *      const p_bsw_errno_pt) {   volatile ts_drv_I2C_REG_TYPE *ptr_i2cReg;   uint8_t * pt_data;   uint32_t  timeout;   pt_data = (uint8_t *)&p_write_word16_pt;   ptr_i2cReg = (ts_drv_I2C_REG_TYPE *)c_drv_I2C_addr[p_i2c_line];   switch (p_i2c_step)   {     case e_I2C_STEP_WRITE_W_ADDR:       p_bsw_errno_pt->u_r = 0;       if ((ptr_i2cReg->s_IBSR & 0x20) == 0)       {         ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x20;             ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x10;             ptr_i2cReg->s_IBDR = p_i2c_addr & drv_I2C_MASK_ADDR_WRITE;         }       else       {         p_bsw_errno_pt->u_b.s_RC_NOT_AVAILABLE = 1;       }       break;     case e_I2C_STEP_WRITE_W_CMD:       timeout = 0;       while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )          {         timeout++;       }       if (timeout < drv_I2C_TIMEMOUT)       {         ptr_i2cReg->s_IBDR = p_i2c_cmd;              ptr_i2cReg->s_IBSR = 0x02;       }       else       {         p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;       }      break;    case e_I2C_STEP_WRITE_W_DATA1:       timeout = 0;       while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )          {         timeout++;       }       if (timeout < drv_I2C_TIMEMOUT)       {          ptr_i2cReg->s_IBDR = pt_data[0];              ptr_i2cReg->s_IBSR = 0x02;       }       else       {         p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;       }       break;     case e_I2C_STEP_WRITE_W_DATA0:       timeout = 0;       while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )          {         timeout++;       }       if (timeout < drv_I2C_TIMEMOUT)       {         ptr_i2cReg->s_IBDR = pt_data[1];             ptr_i2cReg->s_IBSR = 0x02;       }       else       {         p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;       }       break;     case e_I2C_STEP_WRITE_W_END:       timeout = 0;       while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )          {         timeout++;       }       if (timeout >= drv_I2C_TIMEMOUT)       {         p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;       }     case e_I2C_STEP_WRITE_CANCEL:       ptr_i2cReg->s_IBCR = ptr_i2cReg->s_IBCR & 0xDF;        ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR & 0xEF;           ptr_i2cReg->s_IBSR = 0x02;       break;     default:       break;   } }
