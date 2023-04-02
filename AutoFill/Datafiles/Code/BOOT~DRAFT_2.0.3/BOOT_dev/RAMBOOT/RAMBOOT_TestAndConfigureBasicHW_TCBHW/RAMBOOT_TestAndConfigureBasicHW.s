   .file "RAMBOOT_TestAndConfigureBasicHW.s"
   .include "RAMBOOT_Registers.inc"
   .include "RAMBOOT_VectorTable.inc"
   .include "RAMBOOT_TCBHW_TestGPRs.inc"
   .include "RAMBOOT_TCBHW_TestALU.inc"
   
   .global RAMBOOT_TestAndConfigureBasicHW

RAMBOOT_TCBHW_InfiniteLoop:
   b RAMBOOT_TCBHW_InfiniteLoop

RAMBOOT_TestAndConfigureBasicHW:
; GPR test
   RAMBOOT_TCBHW_TestGPRs
   
; ALU test
   RAMBOOT_TCBHW_TestALU
   
; Set HID0 default value to start timer base ???
   lis     r3, C_HID0_INIT_VALUE@ha
   addi    r3, r3, C_HID0_INIT_VALUE@l
   mtspr   REG_HID0, r3
   
; Configure interrupt vector registers
   lis     r3, IVOR_Handler@ha
   mtspr   REG_IVPR, r3 ; Configure base vector address
   li      r3, IVOR_Handler@l
   mtspr   REG_IVOR0, r3 ; IVOR0 offset
   mtspr   REG_IVOR1, r3 ; IVOR1 offset
   mtspr   REG_IVOR2, r3 ; IVOR2 offset
   mtspr   REG_IVOR3, r3 ; IVOR3 offset
   mtspr   REG_IVOR4, r3 ; IVOR4 offset
   mtspr   REG_IVOR5, r3 ; IVOR5 offset
   mtspr   REG_IVOR6, r3 ; IVOR6 offset
   mtspr   REG_IVOR7, r3 ; IVOR7 offset
   mtspr   REG_IVOR8, r3 ; IVOR8 offset
   mtspr   REG_IVOR10, r3 ; IVOR10 offset
   mtspr   REG_IVOR11, r3 ; IVOR11 offset
   mtspr   REG_IVOR13, r3 ; IVOR13 offset
   mtspr   REG_IVOR14, r3 ; IVOR14 offset
   mtspr   REG_IVOR15, r3 ; IVOR15 offset
   mtspr   REG_IVOR32, r3 ; IVOR32 offset
   mtspr   REG_IVOR33, r3 ; IVOR33 offset
   mtspr   REG_IVOR34, r3 ; IVOR34 offset
   mtspr   REG_IVOR35, r3 ; IVOR35 offset
   
; Inhibate P1011 watchdog
   mfspr r3,REG_TCR
   and r3,r3,0
   mtspr REG_TCR, r3
   
; Clear SRR1 register
   lis     r3, 0
   addi    r3, r3, 0
   mtspr   REG_SRR1, r3
; Set SPE ME and DE bits in MSR
   lis     r3, C_MSR_RAMBOOT_CONFIG@ha
   addi    r3, r3, C_MSR_RAMBOOT_CONFIG@l
   REG_MSR_WRITE r3
   
; Configure GPR in compliance with EABI
; Stack pointer initialization
   lis     r1, __SP_INIT@ha
   addi    r1, r1, __SP_INIT@l
   stwu    r1, -8 (r1)
; Initialize R2 with sda2 (read only small data area) base address
   lis     r2, _SDA2_BASE_@ha
   addi    r2, r2, _SDA2_BASE_@l
; Initialize R13 with sda (read/write small data area) base address
   lis     r13, _SDA_BASE_@ha
   addi    r13, r13, _SDA_BASE_@l
   
; Clear the FPSCR
   lis     r3, 0x00000000@ha
   addi    r3, r3, 0x00000000@l
   mtspr   REG_SPEFSCR, r3
   isync
   
; Enable branch target buffer
   lis     r3, 0x00000000@ha
   addi    r3, r3, C_REG_BUCSR_BBFI@l
   addi    r3, r3, C_REG_BUCSR_BPEN@l
   mtspr   REG_BUCSR, r3
   isync
   
; Invalidate instruction and data cache
   REG_L1CSR0_CINV r3
; Enable instruction and data cache
   REG_L1CSR0_SET_CE r3
   REG_L1CSR1_SET_CE r3
   
   blr
