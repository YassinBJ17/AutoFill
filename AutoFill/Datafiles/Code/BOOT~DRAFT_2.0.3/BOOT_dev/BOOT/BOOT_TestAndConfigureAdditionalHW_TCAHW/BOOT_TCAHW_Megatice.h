#ifndef _BOOT_TCAHW_MEGATICE_
#define _BOOT_TCAHW_MEGATICE_

#include "BOOT_Types.h"

typedef union
{
   struct
   {
      uint32_t selreg   : 32; /* Transfer/Command Initiator selection */
   } Fields;
   uint32_t Value;
} tu_MEGATICE_SELECT_Register;

typedef union
{
   struct
   {
      uint32_t             : 21; 
      uint32_t rs_rtc_sel  : 3; /* Selection of the RS_RTC sync source */
      uint32_t             : 5;
      uint32_t cpu_rtc_sel : 3; /* Selection of the CPU_RTC sync source */
   } Fields;
   uint32_t Value;
} tu_MEGATICE_IRQ_RTC_SEL_Register;

typedef union
{
   struct
   {
      uint32_t force_rtc   : 1; /* Enable global debut mode of RTC generation */
      uint32_t             : 30;
      uint32_t cpu_rtc_en  : 1; /* Enable sync signals */
   } Fields;
   uint32_t Value;
} tu_MEGATICE_RTC_EN_Register;

typedef union
{
   struct
   {
      uint32_t             : 31;
      uint32_t blades_rdy  :  1; /* Blades status (RO) */
   } Fields;
   uint32_t Value;
} tu_MEGATICE_BLADES_TIC_RDY_Register;

extern volatile boolean_t SchedulingIT_TestUnderway;

extern void BOOT_TCAHW_Megatice(
/*IN*/
   const boolean_t v_PIC_Ready,
/*OUT*/
   boolean_t *p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
);

#endif