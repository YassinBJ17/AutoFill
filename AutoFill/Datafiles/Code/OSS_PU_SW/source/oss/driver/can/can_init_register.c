/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"
#include "driver/can/can_private.h"
#include "libtools/time/LIB_TIME_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0010 */
void can_init_register(uint32_t            const can_x_reg_addr,
                       ts_can_conf const * const ptr_can_conf,
                       uint32_t            const can_ram_start_addr)
{
   /* Local variables */
   uint32_t       iteration;
   ts_can_reg_t * p_can_reg_descr;
   tu_CMN_RC      return_code;
   uint8_t      * ptr_216;

   /* Initialisation of Local variables */
   /* return code in case of error during the set of init register (possible HW error) */
   return_code.u_r = (uint32_t)0;

   /* set of the adresses of GPIO 216 (adapt resistance presence) */
   ptr_216  = GPIO_216;

   /* Get the driver registers in local variable */
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   iteration = (uint32_t)0;
   do
   {
      /* Set CAN to Init mode, try CAN_OP_MODE_ITERATION times */
      /* wait a certain time to be sure the MPC has the time to set the register */
      p_can_reg_descr->s_cccr.u_bit.s_init = (reg32_t)0x1;
      LIBT_WAIT_REG_TIMEOUT((uint32_t)p_can_reg_descr->s_cccr.u_bit.s_init,
                            (int32_t)0x1,
                            CAN_TIME_TO_WAIT,
                            &return_code);
      iteration++;
   }
   while ((return_code.u_r != (uint32_t)0) && (iteration < CAN_OP_MODE_ITERATION));

   if ((uint32_t)0 == return_code.u_r)
   {
      /* Reset the number of trys to change the mode*/
      iteration = (uint32_t)0;
      do
      {
         /* same procedure as init but for cce = Disable CPU access to CAN */
         p_can_reg_descr->s_cccr.u_bit.s_cce = (reg32_t)0x1;
         LIBT_WAIT_REG_TIMEOUT((uint32_t)p_can_reg_descr->s_cccr.u_bit.s_cce,
                               (int32_t)0x1,
                               CAN_TIME_TO_WAIT,
                               &return_code);
         iteration++;
      }
      while ((return_code.u_r != 0UL) && (iteration < CAN_OP_MODE_ITERATION));
   }
   /* following registers can only be set in init mode and with disable CPU access to CAN */
   /* If no error occured before : */
   if (0UL == return_code.u_r)
   {
      /* set the baudrate from configuration */
      can_init_baudrate(can_x_reg_addr, ptr_can_conf);

      /* Set the GPIO 216 (adapt res presence -> 1 = res disconnected / 0 = res connected): */
      /* If CAN 1 meaning can_1_reg_addr = 0xFFEE4000 */
      if ( can_x_reg_addr == ((uint32_t)0xFFEE4000) && ptr_can_conf->s_can_adapt_pres == e_can_adapt_res_is_connected)
      {
         /* SET GPIO 216 for adapt presence */
         *ptr_216 = (uint8_t)0x0;
      }
      else if(can_x_reg_addr == ((uint32_t)0xFFEE4000) && ptr_can_conf->s_can_adapt_pres == e_can_adapt_res_is_disconnected)
      {
         /* SET GPIO 216 for adapt presence disconnected */
         *ptr_216 = (uint8_t)0x1;
      }

      /* Deactivate Watchdog */
      p_can_reg_descr->s_rwd.u_reg = (reg32_t)0x00000000;

      /* Timestamp is equal to 10 * CAN bit time, so CAN counter resolution is equal to 5s */
      /* TCP register value adds 1 */
      p_can_reg_descr->s_tscc.u_bit.s_tcp = (reg32_t)CAN_CFEX_TIMESTAMP_VALUE;

      /* selects TCP value for timecount */
      p_can_reg_descr->s_tscc.u_bit.s_tss = (reg32_t)CAN_CFEX_TIMESTAMP_SEL_VALUE;

      /* M_CAN_GFC */
      /* frames identification policy => reject bad frames */
      /* ANFS = 2 => Reject Non-matching Frames Standard */
      p_can_reg_descr->s_gfc.u_bit.s_anfs = (reg32_t)CAN_CFEX_NMF_POLICY_VALUE;
      /* ANFE = 2 => Reject Non-matching Frames extended */
      p_can_reg_descr->s_gfc.u_bit.s_anfe = (reg32_t)CAN_CFEX_NMF_POLICY_VALUE;
      /* RRFS = 1 => REJECT all standard remote frames */
      p_can_reg_descr->s_gfc.u_bit.s_rrfs = (reg32_t)CAN_CFEX_RRF_POLICY_VALUE;
      /* RRFE = 1 => REJECT all extended remote frames */
      p_can_reg_descr->s_gfc.u_bit.s_rrfe = (reg32_t)CAN_CFEX_RRF_POLICY_VALUE;

      /* M_CAN_CCCR */
      /* Request CAN operation according ISO11898-1 */
      p_can_reg_descr->s_cccr.u_bit.s_cmr = (reg32_t)CAN_CFEX_CMR_POLICY_VALUE;
      /* CAN operation according to ISO11898-1 enabled */
      p_can_reg_descr->s_cccr.u_bit.s_cme = (reg32_t)CAN_CFEX_CME_POLICY_VALUE;


      /* Configure FIFO RX */
      can_init_buff_rx(can_x_reg_addr, can_ram_start_addr);

      /* Configure TX buffer */
      can_init_buff_tx(can_x_reg_addr, can_ram_start_addr);

      /* M_CAN_SIDFC  */
      /* Configure Standard ID filter */
      if (ptr_can_conf->s_can_type_id == e_can_02_a)
      {
         p_can_reg_descr->s_sidfc.u_bit.s_lss = (reg32_t)CAN_CFEX_CAN_STD_ID_MAX_NB;
         /* set the start adress of the filter id list (should be stored in CAN ram) */
         p_can_reg_descr->s_sidfc.u_bit.s_flssa = (reg32_t)((can_ram_start_addr - CAN1_RAM_ADDR) +
                                                            CAN_STD_FILT_CAN_OFF);
      }
      else
      {
         /* M_CAN_XIDFC  */
         /* Configure Extended ID filter */
         p_can_reg_descr->s_xidfc.u_bit.s_lse = (reg32_t)CAN_CFEX_CAN_XTD_ID_MAX_NB;
         /* set the start adress of the filter id list (should be stored in CAN ram) */
         p_can_reg_descr->s_xidfc.u_bit.s_flesa = (reg32_t)((can_ram_start_addr - CAN1_RAM_ADDR) +
                                                            CAN_XTD_FILT_CAN_OFF);
      }
      /* Enable CPU access to CAN */
      p_can_reg_descr->s_cccr.u_bit.s_cce = (reg32_t)0x0;
      /* wait to be sure the MPC has the time to set the register */
      LIBT_WAIT_REG_TIMEOUT((uint32_t)p_can_reg_descr->s_cccr.u_bit.s_cce,
                            (int32_t)0x0,
                            CAN_TIME_TO_WAIT,
                            &return_code);

      /* is CCCR protection is disabled? = no error occured*/
      if (0UL == return_code.u_r)
      {
         /* Reset the number of trys to change the mode*/
         iteration = (uint32_t)0;
         do
         {
            /* Set CAN IP in operational state */
            p_can_reg_descr->s_cccr.u_bit.s_init = (reg32_t)0x0;
            /* wait to be sure the MPC has the time to set the register */
            LIBT_WAIT_REG_TIMEOUT((uint32_t)p_can_reg_descr->s_cccr.u_bit.s_init,
                                  (int32_t)0x0,
                                  CAN_TIME_TO_WAIT,
                                  &return_code);
            iteration++;
         }
         while ((return_code.u_r != 0UL) && (iteration < CAN_OP_MODE_ITERATION));
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
