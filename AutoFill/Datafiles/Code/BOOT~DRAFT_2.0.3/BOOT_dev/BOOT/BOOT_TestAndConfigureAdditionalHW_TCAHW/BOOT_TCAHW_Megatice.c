#include "BOOT_TCAHW_Megatice.h"
#include "BOOT_TCAHW_PIC.h"
#include "BOOT_ManageInterrupts.h"

#include "LIBBSP_CMN.h"

#define C_MEGATICE_BASE_ADDRESS                 0xF1000000ul
#define C_MEGATICE_REG_SELECT_ADDRESS           (C_MEGATICE_BASE_ADDRESS + 0x00000004ul)
#define C_MEGATICE_REG_IRQ_RTC_SEL_ADDRESS      (C_MEGATICE_BASE_ADDRESS + 0x00000034ul)
#define C_MEGATICE_REG_RTC_EN_ADDRESS           (C_MEGATICE_BASE_ADDRESS + 0x00000038ul)
#define C_MEGATICE_REG_BLADES_TIC_RDY_ADDRESS   (C_MEGATICE_BASE_ADDRESS + 0x00000308ul)


/* Address of TIC is mapped in PLD at 0x0030_0000 */
/* Writable data is 40bits long, so access has to be done in 2 steps */
/* If we want to write 0x98_7654_3210 at address N in TIC: */
/* 1: write 0x9876_5432 at 4x(2xN) */
/* 2: write 0x1000_0000 at 4x(2xN+1) */
#define C_MEGATICE_RAM_TIC_ADDRESS              (C_MEGATICE_BASE_ADDRESS + 0x00300000ul)
#define C_MEGATICE_TIC_SLAVE_FREQ_MULT_ADDRESS  0x4C2ul
#define C_MEGATICE_RAM_TIC_FREQ_MULT_ADDRESS_1  (C_MEGATICE_RAM_TIC_ADDRESS + (4ul * ((2ul * C_MEGATICE_TIC_SLAVE_FREQ_MULT_ADDRESS) + 0ul)))
#define C_MEGATICE_RAM_TIC_FREQ_MULT_ADDRESS_2  (C_MEGATICE_RAM_TIC_ADDRESS + (4ul * ((2ul * C_MEGATICE_TIC_SLAVE_FREQ_MULT_ADDRESS) + 1ul)))

#define C_MEGATICE_TIC_SLAVE_FREQ_MULT_DATA     0x1400ul

#define C_MEGATICE_SELECT_HRG_CAL_MODE          0xA365E167
#define C_MEGATICE_SELECT_OPERATIONAL_MODE      0xA365E13A

volatile boolean_t SchedulingIT_TestUnderway;

const tu_MEGATICE_SELECT_Register Megatice_SELECT_HRGCAL_Mode =
{
   {
      C_MEGATICE_SELECT_HRG_CAL_MODE
   }
};

const tu_MEGATICE_SELECT_Register Megatice_SELECT_OPER_Mode =
{
   {
      C_MEGATICE_SELECT_OPERATIONAL_MODE
   }
};

const tu_MEGATICE_IRQ_RTC_SEL_Register Megatice_IRQ_RTC_SEL =
{
   {
      0, /* No source */
      6  /* IRQ_APPL_TIC selected */
   }
};

const tu_MEGATICE_RTC_EN_Register Megatice_RTC_EN =
{
   {
      1, /* Debug mode enabled */
      1  /* All synchronization signals enabled */
   }
};

void BOOT_TCAHW_Megatice(
/*IN*/
   const boolean_t v_PIC_Ready,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   uint32_t v_TimeoutCounter;
   uint32_t v_regAddr;

   /* Configure and enable scheduling clock */
   v_regAddr = C_MEGATICE_REG_SELECT_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = Megatice_SELECT_HRGCAL_Mode.Value;

   v_regAddr = C_MEGATICE_REG_IRQ_RTC_SEL_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = Megatice_IRQ_RTC_SEL.Value;

   v_TimeoutCounter = 10000ul; /*100000us*/
   v_regAddr = C_MEGATICE_REG_BLADES_TIC_RDY_ADDRESS;
   while((LIBBSP_CMN_isElapsed(&v_TimeoutCounter) == 0ul)
      && (((volatile tu_MEGATICE_BLADES_TIC_RDY_Register *)v_regAddr)->Fields.blades_rdy != 1ul)) /* %RELAX<SYNCHRONe_C_Code_10.7> Reading 1 bit in a 32bit register; there is no loss of precision */
   {}
   if(((volatile tu_MEGATICE_BLADES_TIC_RDY_Register *)v_regAddr)->Fields.blades_rdy != 1ul) /* %RELAX<SYNCHRONe_C_Code_10.7> Reading 1 bit in a 32bit register; there is no loss of precision */
   {
      v_regAddr = C_MEGATICE_REG_SELECT_ADDRESS;
      *((volatile uint32_t *)v_regAddr) = Megatice_SELECT_OPER_Mode.Value;
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->SchedulingIT_PBIT_Failed = TRUE;
      return;
   }
   v_regAddr = C_MEGATICE_RAM_TIC_FREQ_MULT_ADDRESS_1;
   *((volatile uint32_t *)v_regAddr) = C_MEGATICE_TIC_SLAVE_FREQ_MULT_DATA >> 8ul;
   asm("mbar");
   v_regAddr = C_MEGATICE_RAM_TIC_FREQ_MULT_ADDRESS_2;
   *((volatile uint32_t *)v_regAddr) = C_MEGATICE_TIC_SLAVE_FREQ_MULT_DATA & 0xFFul;
   asm("mbar");
   v_regAddr = C_MEGATICE_REG_RTC_EN_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = Megatice_RTC_EN.Value;
   v_regAddr = C_MEGATICE_REG_SELECT_ADDRESS;
   *((volatile uint32_t *)v_regAddr) = Megatice_SELECT_OPER_Mode.Value;
   if (v_PIC_Ready == FALSE)
   {  
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->SchedulingIT_PBIT_Failed = TRUE;
      return;
   }
   v_TimeoutCounter = 1500ul; /*15000us*/
   SchedulingIT_TestUnderway = TRUE;
   v_regAddr = C_REG_PIC_EIVPR_0_ADDRESS;
   /*Unmask Scheduling IT*/
   ((volatile tu_PIC_EIVPR_Register *)v_regAddr)->Fields.MSK = 0ul; /* %RELAX<SYNCHRONe_C_Code_10.7> Changing 1 bit in a 32bit register; there is no loss of precision */
   while((LIBBSP_CMN_isElapsed(&v_TimeoutCounter) == 0ul)
      &&(MEGATICE_ExpectedExternalIT_Raised == FALSE))
   {}
   /*Remask Scheduling IT*/
   ((volatile tu_PIC_EIVPR_Register *)v_regAddr)->Fields.MSK = 1ul; /* %RELAX<SYNCHRONe_C_Code_10.7> Changing 1 bit in a 32bit register; there is no loss of precision */
   SchedulingIT_TestUnderway = FALSE;
   if(MEGATICE_ExpectedExternalIT_Raised == FALSE)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->SchedulingIT_PBIT_Failed = TRUE;
   }
}
