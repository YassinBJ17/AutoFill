/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */


/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/i2c/drv_I2C_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */


/* ---------- provided operation bodies: ------------------------------------ */
/* */
void drv_I2C_STEP_READ_WORD16 ( te_I2C_LINE_TYPE      const p_i2c_line,
                                te_I2C_STEP_READ_TYPE const p_i2c_step,
                                uint8_t               const p_i2c_addr,
                                uint16_t *            const p_read_word16_pt,
                                tu_CMN_RC *           const p_bsw_errno_pt)
{
  volatile ts_drv_I2C_REG_TYPE *ptr_i2cReg;
  volatile uint8_t dummy_data;
  uint8_t * pt_data;
  uint32_t  timeout;

  /* Init pt data */
  pt_data = (uint8_t *)p_read_word16_pt;

  /* Instanciation of the I2C registers */
  ptr_i2cReg = (ts_drv_I2C_REG_TYPE *)c_drv_I2C_addr[p_i2c_line];

  switch (p_i2c_step)
  {
    case e_I2C_STEP_READ_W_ADDR:
      /* Init error return */
      p_bsw_errno_pt->u_r = 0;

      /* Busy ? (s_IBSR -> IBB) */
      if ((ptr_i2cReg->s_IBSR & 0x20) == 0)
      {
        /* Generate a START signal by making the I2C module of the CPU master */
        ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x20;    /* MSSL = 1*/

        /* Enable the transmit mode for the I2C module of the CPU */
        ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x10;    /* TXRX = 1;*/

        /* Send slave addr_onlineess on the bus */
        ptr_i2cReg->s_IBDR = p_i2c_addr | drv_I2C_MASK_ADDR_READ;  /* Read device address*/
      }
      else
      {
          p_bsw_errno_pt->u_b.s_RC_NOT_AVAILABLE = 1;
      }
      /* */
      break;

    case e_I2C_STEP_READ_R_DUMMY:
      /* Wait for the slave address to be received by the appropriate slave */
      timeout = 0;
      while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF & RXAK*/
      {
        timeout++;
      }

      if (timeout < drv_I2C_TIMEMOUT)
      {
        /* Enable the receive mode for the I2C module of the CPU */
        ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR & 0xEF;    /* TXRX = 0;*/

        /* Do a dummy read to make the I2C slave send what it received through the sensor it is connected */
        dummy_data = ptr_i2cReg->s_IBDR;

        /* clear IBIF flag */
        ptr_i2cReg->s_IBSR = 0x02;
      }
      else
      {
        p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;
      }
      /* */
      break;

    case e_I2C_STEP_READ_R_DATA0:
      /* Wait for the slave address to be received by the appropriate slave */
      timeout = 0;
      while ( ((ptr_i2cReg->s_IBSR & 0x02) == 0) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF;*/
      {
        timeout++;
      }

      if (timeout < drv_I2C_TIMEMOUT)
      {
        /* Enable the acknowledgement indicating the transfer series is finished */
        ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x08;    /* NOACK = 1;*/

        /* Read the first data byte from slave in I2C data register */
        pt_data[0] = ptr_i2cReg->s_IBDR;

        /* clear IBIF flag */
        ptr_i2cReg->s_IBSR = 0x02;

      }
      else
      {
        p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;
      }
      /* */
      break;

    case e_I2C_STEP_READ_R_DATA1_END:
      /* Wait for the slave address to be received by the appropriate slave */
      timeout = 0;
      while ( ((ptr_i2cReg->s_IBSR & 0x02) == 0) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF;*/
      {
        timeout++;
      }
      /*      */
      if ( timeout >= drv_I2C_TIMEMOUT )
      {
        p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;;
      }
      /* No break : Do the next code */
    case e_I2C_STEP_READ_CANCEL:
      /* Generate a STOP signal */
      ptr_i2cReg->s_IBCR = ptr_i2cReg->s_IBCR & 0xDF; /* MSSL = 0*/

      /* Disable the acknowledgement indicating the transfer series is finished */
      ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR & 0xF7;    /* NOACK = 0;*/

      /* Read the last and second data byte previously sent by the slave and received by the I2C module of the CPU */
      pt_data[1] = ptr_i2cReg->s_IBDR;

      /* clear IBIF flag */
      ptr_i2cReg->s_IBSR = 0x02;

      /*      */
      if ( p_bsw_errno_pt->u_r != 0 )
      {
        *p_read_word16_pt = 0;
      }
      /* */
      break;

    default:
      /* */
      break;
  }

}

/* */
void drv_I2C_STEP_WRITE_WORD16 ( te_I2C_LINE_TYPE const p_i2c_line,
                                 te_I2C_STEP_WRITE_TYPE const p_i2c_step,
                                 uint8_t          const p_i2c_addr,
                                 uint8_t          const p_i2c_cmd,
                                 uint16_t         const p_write_word16_pt,
                                 tu_CMN_RC *      const p_bsw_errno_pt)
{
  volatile ts_drv_I2C_REG_TYPE *ptr_i2cReg;
  uint8_t * pt_data;
  uint32_t  timeout;

  /* Init pt data */
  pt_data = (uint8_t *)&p_write_word16_pt;

  /* Instanciation of the I2C registers */
  ptr_i2cReg = (ts_drv_I2C_REG_TYPE *)c_drv_I2C_addr[p_i2c_line];

  switch (p_i2c_step)
  {
    case e_I2C_STEP_WRITE_W_ADDR:
      /* Init error return */
      p_bsw_errno_pt->u_r = 0;

      /* Busy ? (s_IBSR -> IBB) */
      if ((ptr_i2cReg->s_IBSR & 0x20) == 0)
      {
        /* Generate a START signal by making the I2C module of the CPU master */
        ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x20;    /* MSSL = 1*/

        /* Enable the transmit mode for the I2C module of the CPU */
        ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x10;    /* TXRX = 1;*/

        /* Send slave address on the bus */
        ptr_i2cReg->s_IBDR = p_i2c_addr & drv_I2C_MASK_ADDR_WRITE;  /* Write device address*/
      }
      else
      {
        p_bsw_errno_pt->u_b.s_RC_NOT_AVAILABLE = 1;
      }
      /* */
      break;

    case e_I2C_STEP_WRITE_W_CMD:
      /* Wait for the slave address to be received by the appropriate slave (TBD : to optimize) */
      timeout = 0;
      while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF & RXAK*/
      {
        timeout++;
      }
      if (timeout < drv_I2C_TIMEMOUT)
      {
        /* Send slave command on the bus */
        ptr_i2cReg->s_IBDR = p_i2c_cmd;     /* Write device command*/

        /* clear IBIF flag */
        ptr_i2cReg->s_IBSR = 0x02;
      }
      else
      {
        p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;
      }
     /* */
     break;

   case e_I2C_STEP_WRITE_W_DATA1:
      /* Wait for the slave address to be received by the appropriate slave (TBD : to optimize) */
      timeout = 0;
      while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF & RXAK*/
      {
        timeout++;
      }
      if (timeout < drv_I2C_TIMEMOUT)
      {
         /* Send slave data 0 (LSB write_word16) on the bus */
         ptr_i2cReg->s_IBDR = pt_data[0];    /* Write device command*/

         /* clear IBIF flag */
         ptr_i2cReg->s_IBSR = 0x02;
      }
      else
      {
        p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;
      }
      /* */
      break;

    case e_I2C_STEP_WRITE_W_DATA0:
      /* Wait for the slave address to be received by the appropriate slave (TBD : to optimize) */
      timeout = 0;
      while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF & RXAK*/
      {
        timeout++;
      }
      if (timeout < drv_I2C_TIMEMOUT)
      {

        /* Send slave data 1 (MSB write_word16) on the bus */
        ptr_i2cReg->s_IBDR = pt_data[1];    /* Write device command*/

        /* clear IBIF flag */
        ptr_i2cReg->s_IBSR = 0x02;

      }
      else
      {
        p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;
      }
      /* */
      break;

    case e_I2C_STEP_WRITE_W_END:
      /* Wait for the slave address to be received by the appropriate slave (TBD : to optimize) */
      timeout = 0;
      while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF & RXAK*/
      {
        timeout++;
      }
      if (timeout >= drv_I2C_TIMEMOUT)
      {
        p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;
      }
      /* No break : Do the next code */
    case e_I2C_STEP_WRITE_CANCEL:
      /* Generate a STOP signal */
      ptr_i2cReg->s_IBCR = ptr_i2cReg->s_IBCR & 0xDF; /* MSSL = 0*/

      /* Disable the acknowledgement indicating the transfer series is finished */
      /*ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR & 0xF7;*/  /* NOACK = 0;*/

      /* Disable the transmit mode for the I2C module of the CPU */
      ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR & 0xEF;    /* TXRX = 0;*/

      /* clear IBIF flag */
      ptr_i2cReg->s_IBSR = 0x02;
      /* */
      break;

    default:
      /* */
      break;
  }
}

/* */
void drv_I2C_STEP_WRITE_CMD ( te_I2C_LINE_TYPE       const p_i2c_line,
                              te_I2C_STEP_W_CMD_TYPE const p_i2c_step,
                              uint8_t                const p_i2c_addr,
                              uint8_t                const p_i2c_cmd,
                              tu_CMN_RC *            const p_bsw_errno_pt)
{
      volatile ts_drv_I2C_REG_TYPE *ptr_i2cReg;
      uint32_t  timeout;

      /* Instanciation of the I2C registers */
      ptr_i2cReg = (ts_drv_I2C_REG_TYPE *)c_drv_I2C_addr[p_i2c_line];

      switch (p_i2c_step)
      {
        case e_I2C_STEP_W_CMD_W_ADDR:
          /* Init error return */
          p_bsw_errno_pt->u_r = 0;

          /* Busy ? (s_IBSR -> IBB) */
          if ((ptr_i2cReg->s_IBSR & 0x20) == 0)
          {
            /* Generate a START signal by making the I2C module of the CPU master */
            ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x20;    /* MSSL = 1*/

            /* Enable the transmit mode for the I2C module of the CPU */
            ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR | 0x10;    /* TXRX = 1;*/

            /* Send slave address on the bus */
            ptr_i2cReg->s_IBDR = p_i2c_addr & drv_I2C_MASK_ADDR_WRITE;  /* Write device address*/
          }
          else
          {
            p_bsw_errno_pt->u_b.s_RC_NOT_AVAILABLE = 1;
          }
          /* */
          break;

        case e_I2C_STEP_W_CMD_W_CMD:
          /* Wait for the slave address to be received by the appropriate slave (TBD : to optimize) */
          timeout = 0;
          while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF & RXAK*/
          {
            timeout++;
          }
          if (timeout < drv_I2C_TIMEMOUT)
          {
            /* Send slave command on the bus */
            ptr_i2cReg->s_IBDR = p_i2c_cmd;     /* Write device command*/

            /* clear IBIF flag */
            ptr_i2cReg->s_IBSR = 0x02;
          }
          else
          {
            p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;
          }
         /* */
         break;

        case e_I2C_STEP_W_CMD_W_END:
          /* Wait for the slave address to be received by the appropriate slave (TBD : to optimize) */
          timeout = 0;
          while ( ((ptr_i2cReg->s_IBSR & 0x03) != 0x02) && (timeout < drv_I2C_TIMEMOUT) )   /* Wait until IBIF & RXAK*/
          {
            timeout++;
          }
          if (timeout >= drv_I2C_TIMEMOUT)
          {
            p_bsw_errno_pt->u_b.s_RC_TIMED_OUT = 1;
          }
          /* No break : Do the next code */
        case e_I2C_STEP_W_CMD_CANCEL:
          /* Generate a STOP signal */
          ptr_i2cReg->s_IBCR = ptr_i2cReg->s_IBCR & 0xDF; /* MSSL = 0*/

          /* Disable the acknowledgement indicating the transfer series is finished */
          /*ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR & 0xF7;*/  /* NOACK = 0;*/

          /* Disable the transmit mode for the I2C module of the CPU */
          ptr_i2cReg->s_IBCR =  ptr_i2cReg->s_IBCR & 0xEF;    /* TXRX = 0;*/

          /* clear IBIF flag */
          ptr_i2cReg->s_IBSR = 0x02;
          /* */
          break;

        default:
          /* */
          break;
      }
}

