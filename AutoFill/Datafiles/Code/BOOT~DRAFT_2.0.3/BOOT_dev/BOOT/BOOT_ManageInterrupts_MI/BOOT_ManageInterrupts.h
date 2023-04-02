#ifndef _BOOT_MANAGE_INTERRUPTS_
#define _BOOT_MANAGE_INTERRUPTS_

#include "LIBMCP_Types.h"

#define C_BMI_SCHEDULING_IT_VECTOR 0x55ul
#define C_BMI_ERROR_INTERNAL_IT_VECTOR 0xAAul

typedef union 
{
    struct
    {
        uint32_t        : 16;
        uint32_t VECTOR : 16;
    } Fields;
    uint32_t Value;
} tu_PIC_IACK;

typedef union 
{
    struct
    {
        uint32_t            : 28;
        uint32_t EOI_CODE   : 4;
    } Fields;
    uint32_t Value;
} tu_PIC_EOI;

extern volatile boolean_t MEGATICE_ExpectedExternalIT_Raised;
extern volatile boolean_t L2SRAM_ECC_ExpectedExternalIT_Raised;
extern volatile boolean_t SDRAM_ECC_ExpectedExternalIT_Raised;
extern volatile boolean_t ExpectedDataTLB_ErrorIT_Raised;
extern volatile boolean_t ExpectedDataStorageIT_Raised;
extern volatile boolean_t ExpectedDecrementerIT_Raised;
extern volatile boolean_t ExpectedEFP_DataExceptionIT_Raised;

extern void CriticalInputInterruptHandler(void);
extern void MachineCheckInterruptHandler(void);
extern void DataStorageInterruptHandler(void);
extern void InstructionStorageInterruptHandler(void);
extern void ExternalInputInterruptHandler(void);
extern void AlignementInterruptHandler(void);
extern void ProgramInterruptHandler(void);
extern void SystemCallInterruptHandler(void);
extern void FPU_UnavailableInterruptHandler(void);
extern void DecrementerInterruptHandler(void);
extern void FixedIntervalTimerInterruptHandler(void);
extern void DataTLB_InterruptHandler(void);
extern void InstructionTLB_InterruptHandler(void);
extern void DebugInterruptHandler(void);
extern void SPE_APU_UnavailableInterruptHandler(void);
extern void EFP_DataExceptionInterruptHandler(void);
extern void EFP_RoundExceptionInterruptHandler(void);
extern void PerformanceMonitorInterruptHandler(void);
#endif