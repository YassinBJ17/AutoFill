/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : this function is used to set the ack level of the rx FIFO 0/1
 * "Rx FIFO 0 Acknowledge Index. After the Host has read a message or a
 * sequence of messages from Rx FIFO it has to write the buffer index of the
 * last element read from Rx FIFO to FxAI. This will set the Rx FIFO 0 Get
 * Index to FxAI + 1 and update the FIFO Fill Level "
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0010 */
void can_init_baudrate(uint32_t            const can_x_reg_addr,
                       ts_can_conf const * const ptr_can_conf)
{
   ts_can_reg_t* p_can_reg_descr;
   ts_can_tq_t   time_quantum;

   /* Get the driver registers in local variable */
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* Bus CAN clk => 40MHz, Pcan = 25ns */
   /* TQ is configured at 20 bits CAN => 25ns * 20 bits = 500ns */
   /* CAN speed depends of BRP configuration => 500ns * BRP */

   /* Time quantum registers adds 1 */
   time_quantum.s_phase1 = CAN_CFEX_TQ_PHASE1_VALUE;
   time_quantum.s_phase2 = CAN_CFEX_TQ_PHASE2_VALUE;
   time_quantum.s_prop   = CAN_CFEX_TQ_PROP_VALUE;

   /* Configuration of TQ => 20 bits */
   /* TQ = TSEG1 + TSEG2 + 3 */
   /* TSEG1 = Prop_Seg + PSEG1 */
   /* TSEG1 register value adds 1 */
   p_can_reg_descr->s_btp.u_bit.s_tseg1 = (reg32_t)time_quantum.s_prop + (reg32_t)time_quantum.s_phase1;
   /* TSEG2 register value adds 1 */
   p_can_reg_descr->s_btp.u_bit.s_tseg2 = (reg32_t)time_quantum.s_phase2;

   /* TODO: A checker */
   p_can_reg_descr->s_btp.u_bit.s_sjw = (reg32_t)CAN_CFEX_TQ_SJW_VALUE;

   /* Configure prescalar value depending on baudrate expected */
   /* TODO : Modify to make it configurable by UOD */
   switch (ptr_can_conf->s_can_baudrate)
   {
      /* very slow value = 125kbs */
      case e_can_baudrate_veryslow:
      {
         p_can_reg_descr->s_btp.u_bit.s_brp = (reg32_t)CAN_CFEX_BRP_125KBITSPS;
         break;
      }
      /* slow value = 250kbs */
      case e_can_baudrate_slow:
      {
         p_can_reg_descr->s_btp.u_bit.s_brp = (reg32_t)CAN_CFEX_BRP_250KBITSPS;
         break;
      }
      /* fast value = 500kbs */
      case e_can_baudrate_fast:
      {
         p_can_reg_descr->s_btp.u_bit.s_brp = (reg32_t)CAN_CFEX_BRP_500KBITSPS;
         break;
      }
      /* very_fast value = 1000kbs */
      case e_can_baudrate_very_fast:
      {
         p_can_reg_descr->s_btp.u_bit.s_brp = (reg32_t)CAN_CFEX_BRP_1000KBITSPS;
         break;
      }
      /* default value = 500kbs */
      default:
      {
         p_can_reg_descr->s_btp.u_bit.s_brp = (reg32_t)CAN_CFEX_BRP_500KBITSPS;
      }
      break;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */

