#include "BOOT_TCAHW_PIC.h"
#include "BOOT_ManageInterrupts.h"

#include "LIBBSP_CMN.h"

#define C_ERROR_INTERNAL_IT_PRIORITY_LVL    (10)
#define C_SCHEDULING_IT_PRIORITY_LVL        (10)

void BOOT_TCAHW_EnableExternalITs(void);
void BOOT_TCAHW_DisableExternalITs(void);

const tu_PIC_CTPR_Register PIC_CTPR =
{
   {
      0 /* Lowest priority */
   }
};

const tu_PIC_GCR_Register PIC_GCR_Reset =
{
   {
      1, /* Force reset of the PIC */
      0
   }
};

const tu_PIC_GCR_Register PIC_GCR_Set =
{
   {
      0,
      1  /* Mixed mode */
   }
};

const tu_PIC_EIVPR_Register PIC_EIVPR =
{
   {
      1, /* masked */
      0, /* (RO) */
      1, /* active-high */
      0, /* edge sensitive */
      C_SCHEDULING_IT_PRIORITY_LVL,
      C_BMI_SCHEDULING_IT_VECTOR,
   }
};

const tu_PIC_EIDR_Register PIC_EIDR =
{
   {
      0, /* Interrupt is not routed to IRQ_OUT_B */
      0, /* disable cint0 */
      0, /* disable cint1 */
      0, /* disable int1 */
      1, /* enable int0*/
   }
};

const tu_PIC_IIVPR_Register PIC_IIVPR =
{
   {
      0, /* unmasked */
      0, /* (RO) */
      1, /* active-high */
      C_ERROR_INTERNAL_IT_PRIORITY_LVL,
      C_BMI_ERROR_INTERNAL_IT_VECTOR,
   }
};

const tu_PIC_IIDR_Register PIC_IIDR =
{
   {
      0, /* Interrupt is not routed to IRQ_OUT_B */
      0, /* disable cint0 */
      1, /* enable int0*/
   }
};

boolean_t BOOT_TCAHW_PIC(void)
{
   uint32_t v_TimeoutCounter;
   uint32_t v_regAddr;

   v_TimeoutCounter = 1000ul; /*10000us*/
   
   v_regAddr = C_REG_PIC_GCR_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = PIC_GCR_Reset.Value;
   while((LIBBSP_CMN_isElapsed(&v_TimeoutCounter) == 0ul)
      && (*((volatile uint32_t *)v_regAddr) != 0ul))
   {}
   if(*((volatile uint32_t *)v_regAddr) != 0ul)
   {
      return FALSE;
   }

   v_regAddr = C_REG_PIC_CTPR_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = PIC_CTPR.Value;

   v_regAddr = C_REG_PIC_EIVPR_0_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = PIC_EIVPR.Value;

   v_regAddr = C_REG_PIC_EIDR_0_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = PIC_EIDR.Value;

   v_regAddr = C_REG_PIC_IIVPR_0_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = PIC_IIVPR.Value;

   v_regAddr = C_REG_PIC_IIDR_0_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = PIC_IIDR.Value;

   v_regAddr = C_REG_PIC_GCR_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = PIC_GCR_Set.Value;
   BOOT_TCAHW_EnableExternalITs();
   return TRUE;
}
