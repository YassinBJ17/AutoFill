#ifndef BOOT_INTC_PRIVATE_H
#define BOOT_INTC_PRIVATE_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
/* */
#include "CMN_TYPES_common.h"



/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- provided define constants: ------------------------------------ */
#define INTC_0_BASE_ADDR          (0xFC040000UL)
#define INTC_0                         (*(ts_INTC_tag volatile *) INTC_0_BASE_ADDR)
#define INTC_0_PSR_MASK                (reg16_t)(~0xF03FU)
#define INTC_0_BCR_MASK                (reg32_t)(0xFFFFEEEEU)

/* Enable powerdown interrupts to processors (PRC_SELNx = 1) and select the interrupt priority (PRIN = 0x3F)*/
#define INTC_0_PSR_POWERDOWN_IRQ_EN     ( ((reg32_t)0xF000) | (reg32_t)INTC_0_PSR_POWERDOWN_IRQ_PRIN )
#define INTC_0_PSR_POWERDOWN_IRQ_PRIN   (0x3F)
/* Enable FCCU Alarm interrupts to processors (PRC_SELNx = 1) and select the interrupt priority (PRIN = 0x3E)*/
#define INTC_0_PSR_FCCU_ALARM_IRQ_EN   ( ((reg32_t)0xF000) | (reg32_t)INTC_0_PSR_FCCU_ALARM_IRQ_PRIN)
#define INTC_0_PSR_FCCU_ALARM_IRQ_PRIN (0x3E)
/* Set Powercut interrupt as interrupt request to processor (EIRQ3)*/
#define SIUL2_EIRE3                    (reg32_t)(0x8U)


/* ---------- provided types: ----------------------------------------------- */
/* ============================================================================
   =============================== Module: INTC ===============================
   ============================================================================ */

typedef struct
{
   /* {{RELAX<SYNCHRONe_C_Code_6.6> Following structures and unions are used for the mapping of the MPC registers. */
   
   /* INTC Block Configuration Register */
   reg32_t s_BCR;

   /* INTC Master Protection Register */
   reg32_t s_MPROT;
   
   /* {{RELAX<SYNCHRONe_C_Code_7.2> All the literal values express the number of register for each kind (CPR, IACKR, */
   /* EOIR, SSCIR, PSR). These values can be found in Table 7-22 of MPC5777M RM  */
   uint8_t s_INTC_reserved0[8];
   union
   {                              /* INTC Current Priority Register for Processor n */
      reg32_t u_CPR_R;
      struct
      {
         reg32_t  :26;
         reg32_t s_PRI:6;
      }
      u_CPR_B;
   }
   s_CPR[4];
   
   /* INTC Interrupt Acknowledge Register for Processor n */
   reg32_t s_IACKR[4];
   
   /* INTC End Of Interrupt Register for Processor n */
   reg32_t s_EOIR[4];
   
   /* INTC Software Set/Clear Interrupt Register */
   reg8_t s_SSCIR[32];
   
   /* INTC Priority Select Register */
   reg16_t s_PSR[1024];
   /* }}<SYNCHRONe_C_Code_7.2> */
   /* }}<SYNCHRONe_C_Code_6.6> */
}
ts_INTC_tag;

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif /* BOOT_INTC_PRIVATE_H */
