/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function initializes the INTC Registers. It disables
 *               all external interrupts except the powercut interrupt
 *               (IRQ#243, EIRQ0).
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_INTC_private.h"
#include "BOOT_INTC_public.h"
#include "BOOT_PINOUT_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
typedef struct
{

   uint16_t s_start;
   uint16_t s_end ;

} ts_INTC_RANGE ;

/* ---------- internal operations/ data ------------------------------------- */
#define INTC_INIT_PSR_0_RANGE_SIZE ((uint32_t)39)
#define INTC_PSR_SIU_EXTERNAL_IT_0 ((uint32_t)243)
#define INTC_PSR_FCCU_ALARM_IT     ((uint32_t)488)

const ts_INTC_RANGE c_INTC_INIT_PSR_0_RANGE [ INTC_INIT_PSR_0_RANGE_SIZE ] =
{
   { 
      0, 
      47
   }
   ,
   { 
      52, 
      180 
   }
   ,
   { 
      185, 
      185 
   }
   ,
   { 
      218, 
      220 
   }
   ,
   { 
      226, 
      233 
   }
   ,
   { 
      239, 
      244 
   }
   ,
   { 
      251, 
      255 
   }
   ,
   { 
      259, 
      263 
   }
   ,
   { 
      266, 
      266 
   }
   ,
   { 
      268, 
      272 
   }
   ,
   { 
      275, 
      275 
   }
   ,
   { 
      277, 
      281 
   }
   ,
   { 
      284, 
      284 
   }
   ,
   { 
      286, 
      290 
   }
   ,
   { 
      293, 
      293 
   }
   ,
   { 
      295, 
      321 
   }
   ,
   { 
      367, 
      371 
   }
   ,
   { 
      374, 
      374 
   }
   ,
   { 
      376, 
      378 
   }
   ,
   { 
      380, 
      382 
   }
   ,
   { 
      384, 
      386 
   }
   ,
   { 
      416, 
      418 
   }
   ,
   { 
      432, 
      434 
   }
   ,
   { 
      436, 
      438 
   }
   ,
   { 
      440, 
      440 
   }
   ,
   { 
      442, 
      442 
   }
   ,
   { 
      453, 
      462 
   }
   ,
   { 
      465, 
      474 
   }
   ,
   { 
      477, 
      478 
   }
   ,
   { 
      488, 
      491 
   }
   ,
   { 
      494, 
      538 
   }
   ,
   { 
      543, 
      553 
   }
   ,
   { 
      558, 
      608 
   }
   ,
   { 
      612, 
      641 
   }
   ,
   { 
      654, 
      665 
   }
   ,
   { 
      677, 
      679 
   }
   ,
   { 
      688, 
      695 
   }
   ,
   { 
      706, 
      931 
   }
   ,
   { 
      946, 
      964 
   }
};

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_023 */
void BOOT_INTC_INIT( void )
{
   uint32_t v_index ;
   uint32_t v_range_index ;
   uint32_t v_start, v_end;

   /* {{RELAX<SYNCHRONe_C_Code_10.2> INTC_0_xxx.xxx.u_R is reg32_t type */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from address (uint32_t) to pointer (on volatile struct) */
   /* {{RELAX<SYNCHRONe_C_Code_7.2> ~0xFFFFEEEEU and ~0xF03F are the mask values */

   INTC_0.s_MPROT = 0x00U;

   INTC_0.s_BCR  = (INTC_0.s_BCR & INTC_0_BCR_MASK);

   INTC_0.s_IACKR[0] =  0x00U ;
   INTC_0.s_IACKR[1] =  0x00U ;
   INTC_0.s_IACKR[2]  =  0x00U ;

   for( v_range_index = 0ul ; v_range_index < INTC_INIT_PSR_0_RANGE_SIZE ; v_range_index ++ )
   {
      v_start = c_INTC_INIT_PSR_0_RANGE[v_range_index].s_start;
      v_end = c_INTC_INIT_PSR_0_RANGE[v_range_index].s_end;
      for( v_index =  v_start ; v_index <= v_end ; v_index ++ )
      {
         INTC_0.s_PSR[v_index]  &= INTC_0_PSR_MASK ;
      }
   }

   INTC_0.s_CPR[0].u_CPR_R  =  0x00U ;
   INTC_0.s_CPR[1].u_CPR_R  =  0x00U ;
   INTC_0.s_CPR[2].u_CPR_R  =  0x00U ;

   /************************************************/
   /**       Configure Powerdown Interrupt        **/
   /************************************************/

   /* Set Powercut Interrupt priority */
   INTC_0.s_PSR[INTC_PSR_SIU_EXTERNAL_IT_0]  |= INTC_0_PSR_POWERDOWN_IRQ_EN ;

   /* Set Powercut interrupt as interrupt request to processor */
   SIUL2.s_DIRSR0 = (SIUL2.s_DIRSR0 & (~SIUL2_EIRE3));

   /* Enable Powercut interrupt */
   SIUL2.s_DIRER0 |= SIUL2_EIRE3;

   /* Set Powercut Interrupt to falling edge detection*/
   SIUL2.s_IFEER0 |= SIUL2_EIRE3;


   /************************************************/
   /**      Configure FCCU Alarm Interrupt        **/
   /************************************************/

   /* Set FCCU Interrupt priority */
   INTC_0.s_PSR[INTC_PSR_FCCU_ALARM_IT]  |= INTC_0_PSR_FCCU_ALARM_IRQ_EN ;


   /* }}<SYNCHRONe_C_Code_7.2> */
   /* }}<SYNCHRONe_C_Code_10.2> */
   /* }}<SYNCHRONe_C_Code_10.7> */
}
/* ---------- internal operation bodies: ------------------------------------ */
/* none */
