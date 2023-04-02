   .file "BOOT_VectorTable.s"

   .include "BOOT_Registers.inc"
   .include "BOOT_VectorTable.inc"

; Define Small Const Area (SDA2) begin address
   .extern _SDA2_BASE_

; Define Small Data Area (SDA) begin for SDATA & SBSS address
   .extern _SDA_BASE_

; Define stack pointer address
   .extern __SP_INIT

; Define SPEFSCR Default value at start of a process
   .extern C_CONF_DLD_SPEFSCR_Default

   .global IVOR0_Handler
   .global IVOR1_Handler
   .global IVOR2_Handler
   .global IVOR3_Handler
   .global IVOR4_Handler
   .global IVOR5_Handler
   .global IVOR6_Handler
   .global IVOR7_Handler
   .global IVOR8_Handler
   .global IVOR10_Handler
   .global IVOR11_Handler
   .global IVOR13_Handler
   .global IVOR14_Handler
   .global IVOR15_Handler
   .global IVOR32_Handler
   .global IVOR33_Handler
   .global IVOR34_Handler
   .global IVOR35_Handler
   .global VECT_Reset

; PowerPC Vector table definition
   .section ".VectorTable", 4, rx
IVOR0_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl CriticalInputInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000040 - (.- IVOR0_Handler)
IVOR1_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl MachineCheckInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfmci

   .skip   0x000080 - (.- IVOR0_Handler)
IVOR2_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl DataStorageInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfspr   r3, REG_SRR0
   addi    r3, r3, 0x0004
   mtspr   REG_SRR0, r3
   mfsprg1 r3
   rfi

   .skip   0x0000C0 - (.- IVOR0_Handler)
IVOR3_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl InstructionStorageInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000100 - (.- IVOR0_Handler)
IVOR4_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl ExternalInputInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000140 - (.- IVOR0_Handler)
IVOR5_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl AlignementInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000180 - (.- IVOR0_Handler)
IVOR6_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl ProgramInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x0001C0 - (.- IVOR0_Handler)
IVOR7_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl FPU_UnavailableInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000200 - (.- IVOR0_Handler)
IVOR8_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl SystemCallInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000240 - (.- IVOR0_Handler)
IVOR10_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl ClearDecrementerIT_Status
   bl DecrementerInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000280 - (.- IVOR0_Handler)
IVOR11_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl FixedIntervalTimerInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x0002C0 - (.- IVOR0_Handler)
IVOR13_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl DataTLB_InterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfspr   r3, REG_SRR0
   addi    r3, r3, 0x0004
   mtspr   REG_SRR0, r3
   mfsprg1 r3
   rfi

   .skip   0x000300 - (.- IVOR0_Handler)
IVOR14_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl InstructionTLB_InterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000340 - (.- IVOR0_Handler)
IVOR15_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl DebugInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000380 - (.- IVOR0_Handler)
IVOR32_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl SPE_APU_UnavailableInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x0003C0 - (.- IVOR0_Handler)
IVOR33_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl EFP_DataExceptionInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfspr   r3, REG_SRR0
   addi    r3, r3, 0x0004
   mtspr   REG_SRR0, r3
   mfsprg1 r3
   rfi
   
   .skip   0x000400 - (.- IVOR0_Handler)
IVOR34_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl EFP_RoundExceptionInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .skip   0x000440 - (.- IVOR0_Handler)
IVOR35_Handler:
   mtsprg1 r3
   mflr    r3
   mtsprg0 r3
   mfsprg1 r3
   bl SaveContext
   bl PerformanceMonitorInterruptHandler
   bl RestoreContext
   mtsprg1 r3
   mfsprg0 r3
   mtlr    r3
   mfsprg1 r3
   rfi

   .section ".Reset", 4, rx
VECT_Reset:
   bl BOOT_ConfigureBasicHW
   bl BOOT_PostCBHW_Main
   rfi