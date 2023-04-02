/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef DRV_I2C_PUBLIC_H
#define DRV_I2C_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
/* */
#define drv_I2C_MASK_ADDR_READ  (uint8_t)0x01
#define drv_I2C_MASK_ADDR_WRITE (uint8_t)0xFE

/* With a baudrate 94, output at 200 RTC */
#define drv_I2C_TIMEMOUT        (uint32_t)300

/* I2C Baud Rate value */
#define I2C_BAUD_RATE (uint8_t)0x5B

/* ---------- provided types: ----------------------------------------------- */

/* I2C controler description */
typedef struct
{
  /* I2C Bus Address Register */
   uint8_t s_IBAD;
  /* I2C Bus Frequency Divider Register */
   uint8_t s_IBFD;
  /* I2C Bus Control Register */
   uint8_t s_IBCR;
  /* I2C Bus Status Register */
   uint8_t s_IBSR;
  /* I2C Bus Data I/O Register */
   uint8_t s_IBDR;
  /* I2C Bus Interrupt Config Register */
   uint8_t s_IBIC;
  /* I2C Bus Debug Register */
   uint8_t s_IBDBG;
}
ts_drv_I2C_REG_TYPE;


/* */
typedef enum
{
  e_I2C_LINE_0 = 0,    /* I2C 0  */
  e_I2C_LINE_1 = 1,    /* I2C 1  */
  e_I2C_LINE_NB = 2
}
te_I2C_LINE_TYPE;

/* */
typedef enum
{
  e_I2C_STEP_READ_W_ADDR = 0,       /*    Begin    */
  e_I2C_STEP_READ_R_DUMMY = 1,      /*     ...     */
  e_I2C_STEP_READ_R_DATA0 = 2,      /*     ...     */
  e_I2C_STEP_READ_R_DATA1_END = 3,  /*     End     */
  e_I2C_STEP_READ_CANCEL = 4        /* After Error */
}
te_I2C_STEP_READ_TYPE;

/* */
typedef enum
{
  e_I2C_STEP_WRITE_W_ADDR = 0,      /*    Begin    */
  e_I2C_STEP_WRITE_W_CMD = 1,       /*     ...     */
  e_I2C_STEP_WRITE_W_DATA1 = 2,     /*     ...     */
  e_I2C_STEP_WRITE_W_DATA0 = 3,     /*     ...     */
  e_I2C_STEP_WRITE_W_END = 4,       /*     End     */
  e_I2C_STEP_WRITE_CANCEL = 5       /* After Error */
}
te_I2C_STEP_WRITE_TYPE;

/* */
typedef enum
{
  e_I2C_STEP_W_CMD_W_ADDR = 0,      /*    Begin    */
  e_I2C_STEP_W_CMD_W_CMD = 1,       /*     ...     */
  e_I2C_STEP_W_CMD_W_END = 2,       /*     End     */
  e_I2C_STEP_W_CMD_CANCEL = 3       /* After Error */
}
te_I2C_STEP_W_CMD_TYPE;

/* ---------- provided constants: ------------------------------------------- */
/* */
extern uint32_t const c_drv_I2C_addr[e_I2C_LINE_NB];

/* ---------- provided datas: ----------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */
/* */
extern void drv_I2C_INIT ( te_I2C_LINE_TYPE  const p_i2c_line,
                           uint8_t           const p_i2c_baudrate );

/* Check the availability of I2C driver */
extern void drv_I2C_BUSY_CHECK ( te_I2C_LINE_TYPE      const p_i2c_line,
                                 tu_CMN_RC *           const p_bsw_errno_pt);
/* */
extern void drv_I2C_READ_WORD16 ( te_I2C_LINE_TYPE const p_i2c_line,
                                  uint8_t          const p_i2c_addr,
                                  uint16_t *       const p_read_word16_pt,
                                  tu_CMN_RC *      const p_bsw_errno_pt);
/* */
extern void drv_I2C_WRITE_WORD16 ( te_I2C_LINE_TYPE const p_i2c_line,
                                   uint8_t          const p_i2c_addr,
                                   uint8_t          const p_i2c_cmd,
                                   uint16_t         const p_write_word16_pt,
                                   tu_CMN_RC *      const p_bsw_errno_pt);
/* */
extern void drv_I2C_WRITE_CMD ( te_I2C_LINE_TYPE const p_i2c_line,
                                uint8_t          const p_i2c_addr,
                                uint8_t          const p_i2c_cmd,
                                tu_CMN_RC *      const p_bsw_errno_pt);

/* */
extern void drv_I2C_STEP_READ_WORD16 ( te_I2C_LINE_TYPE      const p_i2c_line,
                                       te_I2C_STEP_READ_TYPE const p_i2c_step,
                                       uint8_t               const p_i2c_addr,
                                       uint16_t *            const p_read_word16_pt,
                                       tu_CMN_RC *           const p_bsw_errno_pt);
/* */
extern void drv_I2C_STEP_WRITE_WORD16 ( te_I2C_LINE_TYPE       const p_i2c_line,
                                        te_I2C_STEP_WRITE_TYPE const p_i2c_step,
                                        uint8_t                const p_i2c_addr,
                                        uint8_t                const p_i2c_cmd,
                                        uint16_t               const p_write_word16_pt,
                                        tu_CMN_RC *            const p_bsw_errno_pt);
/* */
extern void drv_I2C_STEP_WRITE_CMD ( te_I2C_LINE_TYPE       const p_i2c_line,
                                     te_I2C_STEP_W_CMD_TYPE const p_i2c_step,
                                     uint8_t                const p_i2c_addr,
                                     uint8_t                const p_i2c_cmd,
                                     tu_CMN_RC *            const p_bsw_errno_pt);

/* */

#endif /* DRV_I2C_PUBLIC_H */
