;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : Common initialization of all cores after software reset
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------
   .include "BOOT_RESET_DEF_public.inc"
   .include "BOOT_MEM_LRAM_public.inc"
; ---------- internal define constants: ------------------------------------
; none

; ---------- internal types: -----------------------------------------------
; none

; ---------- internal operations: ------------------------------------------
; none

; ---------- internal constants: -------------------------------------------


; ---------- internal data: ------------------------------------------------
; none

; ---------- provided operation bodies: ------------------------------------

; ----------------------------------------------------------------------------
; C PROTOTYPE :
; -----------------
;    void BOOT_RESET_CORE(void)
;

; STACK USAGE :
; -----------------
; None
;

; REGISTER USAGE :
; -----------------
; received from caller:
; r20 : address of CORE_X_INIT
; r21 : address of BOOT_CORE_x_CONF_tab

; -----------------
; BODY :
;  - Set value of idle process super stack
;  - Set value of sdata2 area base address
;  - Set value of kernel short const base address
;  - Store the kernel short const base address into sdata2 area base address
;  - Set the MSR with reset default value
;  - Wait for all previous Cpu instructions completed
;  - Configure Interrupt Vector Offset Registers
;  - Reset default error context values
;  - Configure Apex default Floating point precise mode exception
;  - Call the system init operation
;  - The precedent call never returns, an infinite Loop is add here
;
   .section  ".startup_core", "ax"
   .global  BOOT_RESET_CORE
   .globl  _start_core
   .extern BOOT_CORE_E_INIT_SYNC


   ; structure s_BOOT_CORE_E_MAPPING

   .set s_BOOT_CORE_E_MAPPING_MSR_OFFSET   ,0x0
   .set s_BOOT_CORE_E_MAPPING_HID0_OFFSET  ,0x4
   .set s_BOOT_CORE_E_MAPPING_HID1_OFFSET  ,0x8

   .set s_BOOT_CORE_E_MAPPING_STACK_OFFSET         , 0xC
   .set s_BOOT_CORE_E_MAPPING_STACK_SDA2_OFFSET    , 0x10
   .set s_BOOT_CORE_E_MAPPING_STACK_SDA_OFFSET     , 0x14

   .set s_BOOT_CORE_E_MAPPING_TAB_EXCEP_OFFSET     , 0x18


   ; the align 4 is mandatory because the address of BOOT_RESET_CORE is givent to the MC_ME_CADDR register which
   ; impose that the address is align on 4 bytes.
   .align 4

; ;; ;; ;; ;; ;; ;; ;;
;  e200Z710n3        ;
; ;; ;; ;; ;; ;; ;; ;;
;  Keep _start as a generic symbol for the software start point
_start_core:
BOOT_RESET_CORE:

   LI       r0, 0

; Disable MPU
; Set MPUEN bit to 0
   MFSPR    r10, REG_MPU0CSR0
   RLWINM   r10, r10, 0, 0, 30
   ORI      r10, r10, 0
   MTSPR    REG_MPU0CSR0, r10

BOOT_RESET_CORE_ICACHE_CFG_CORE:
;  Invalidate and disable instruction cache
   LIS      r10, ICACHE_L1CSR1_VALUE@ha
   ADDI     r10, r10, ICACHE_L1CSR1_VALUE@l
   MTSPR    REG_L1CSR1, r10

;  Load icache abort mask
   LIS      r4, ICACHE_L1CSR1_ABT_MSK@ha
   ADDI     r4, r4, ICACHE_L1CSR1_ABT_MSK@l
;  Load icache configuration
   LIS      r5, ICACHE_L1CSR1_VALUE@ha
   ADDI     r5, r5, ICACHE_L1CSR1_VALUE@l
;  Load icache abort value
   LI       r6, ICACHE_L1CSR1_ABT_VALUE

BOOT_RESET_CORE_ICACHE_INV_CORE:
   MFSPR    r8, REG_L1CSR1
   AND.     r9, r4, r8
   BEQ      BOOT_RESET_CORE_ICACHE_NO_ABORT_CORE
   AND.     r9, r4, r8
   MTSPR    REG_L1CSR1, r9
   B        BOOT_RESET_CORE_ICACHE_CFG_CORE

BOOT_RESET_CORE_ICACHE_NO_ABORT_CORE:
   AND.     r9, r5, r8
   BNE      BOOT_RESET_CORE_ICACHE_INV_CORE


   ISYNC
   MSYNC


BOOT_RESET_CORE_DCACHE_CFG_CORE:
;  Invalidate and disable data cache
   LIS      r10, DCACHE_L1CSR0_VALUE@ha
   ADDI     r10, r10, DCACHE_L1CSR0_VALUE@l
   MTSPR    REG_L1CSR0, r10

;  Load dcache abort mask
   LIS      r4, DCACHE_L1CSR0_ABT_MSK@ha
   ADDI     r4, r4, DCACHE_L1CSR0_ABT_MSK@l
;  Load dcache configuration
   LIS      r5, DCACHE_L1CSR0_VALUE@ha
   ADDI     r5, r5, DCACHE_L1CSR0_VALUE@l
;  Load dcache abort value
   LI       r6, DCACHE_L1CSR0_ABT_VALUE

BOOT_RESET_CORE_DCACHE_INV_CORE:
   MFSPR    r8, REG_L1CSR0
   AND.     r9, r4, r8
   BEQ      BOOT_RESET_CORE_DCACHE_NO_ABORT_CORE
   AND.     r9, r4, r8
   MTSPR    REG_L1CSR0, r9
   B        BOOT_RESET_CORE_DCACHE_CFG_CORE

BOOT_RESET_CORE_DCACHE_NO_ABORT_CORE:
   AND.     r9, r5, r8
   BNE      BOOT_RESET_CORE_DCACHE_INV_CORE

   ISYNC
   MSYNC

#  Configure access to DMEM/IMEM Control Register 0 (DMEMCTL0/IMEMCTL0)
#  Without this, theses areas are not readable before being written
#  Get base address of D_MEM
   MFSPR    r5, REG_DMEMCFG0
   LIS      r4, REG_DMEMCFG0_MASK_VALUE@ha
   ADDI     r4, r4, REG_DMEMCFG0_MASK_VALUE@l
   AND      r4, r4, r5
#  Set DMEMCTL0 value
   LIS      r5, REG_DMEMCTL0_INIT_VALUE@ha
   ADDI     r5, r5, REG_DMEMCTL0_INIT_VALUE@l
   ADD      r5, r5, r4
   MTDCR    REG_DMEMCTL0, r5
#  Set DMEMCTL1 value
   LIS      r5, REG_DMEMCTL1_INIT_VALUE@ha
   ADDI     r5, r5, REG_DMEMCTL1_INIT_VALUE@l
   MTDCR    REG_DMEMCTL1, r5
#  Get base address of I_MEM
   MFSPR    r5, REG_IMEMCFG0
   LIS      r4, REG_IMEMCFG0_MASK_VALUE@ha
   ADDI     r4, r4, REG_IMEMCFG0_MASK_VALUE@l
   AND      r4, r4, r5
#  Set IMEMCTL0 value
   LIS      r5, REG_IMEMCTL0_INIT_VALUE@ha
   ADDI     r5, r5, REG_IMEMCTL0_INIT_VALUE@l
   ADD      r5, r5, r4
   MTDCR    REG_IMEMCTL0, r5
#  Set IMEMCTL1 value
   LIS      r5, REG_IMEMCTL1_INIT_VALUE@ha
   ADDI     r5, r5, REG_IMEMCTL1_INIT_VALUE@l
   MTDCR    REG_IMEMCTL1, r5

#-----------------------------------------------#
#                 Erase STACK                #
#-----------------------------------------------#
   LI       r31, INIT_SRAM_VAL_1
   LI       r30, INIT_SRAM_VAL_1
# r20 : start Addr
# r21 : length of the area
# r22 : temporary data
   LWZ      r4, s_BOOT_CORE_E_MAPPING_STACK_OFFSET(r20)
   ; The use of @ha ensures the correct computation is done even when the MSB of the 16th low order bits is 1.
   ; See paragraph on High Adjust Operator in the Windriver Compiler user guide
   LWZ      r5, s_BOOT_CORE_E_MAPPING_STACK_SDA_OFFSET(r20)
   SUBF     r4, r5 ,r4
    # size area is divided by 8 because the core will write by blocks of 2*32 bits (see stmw)
   LI       r6, 8
   DIVW     r4,r4,r6
   # add one to remove 0xDEADCODE
   ADDI     r4,r4,1
   MTCTR    r4
BOOT_RESET_CORE_INIT_STACK:
   STMW     r30, 0(r5)
   ADDI     r5, r5, 8
   BDNZ     BOOT_RESET_CORE_INIT_STACK
;  Branch target buffer flash invalidate and Branch target enable
   LIS      r10, BUCSR_VALUE@ha
   ADDI     r10, r10, BUCSR_VALUE@l
   MTSPR    REG_BUCSR, r10
   ISYNC

   LI       r0, 0x0

;  Init Special Purpose Registers (SPR)
   MTSPR    REG_XER,r0
   MTCRF    0xFF, r0
   MTSPR    REG_CTR,  r0
   MTSPR    REG_SPRG0, r0
   MTSPR    REG_SPRG1, r0
   MTSPR    REG_SPRG2, r0
   MTSPR    REG_SPRG3, r0
   MTSPR    REG_SRR0, r0
   MTSPR    REG_SRR1, r0
   MTSPR    REG_CSRR0, r0
   MTSPR    REG_CSRR1, r0
   MTSPR    REG_MCSRR0, r0
   MTSPR    REG_MCSRR1, r0
   MTSPR    REG_DEAR, r0
   MTSPR    REG_IVPR, r0
   MTSPR    REG_USPRG0, r0
   MTSPR    REG_ESR, r0
   MTSPR    REG_LR, r0
   MTSPR    REG_DSRR0, r0
   MTSPR    REG_DSRR1, r0

;  Set MSR
   lWZ      r10, s_BOOT_CORE_E_MAPPING_MSR_OFFSET(r20)
   MTMSR    r10

;  Configure Interrupt Vector Offset Registers IVPR (default reset value)
   lWZ      r10, s_BOOT_CORE_E_MAPPING_TAB_EXCEP_OFFSET(r20)  ; loading exception table
   MTSPR    REG_IVPR , r10
   ;  enable external interrupts
   WRTEEI   1
   ISYNC


;  TODO : MPU initialisation

;  Initialize HID0 and HID1
   lWZ      r10, s_BOOT_CORE_E_MAPPING_HID0_OFFSET(r20)  ; HID0 address
   MTSPR    REG_HID0, r10

   lWZ      r10, s_BOOT_CORE_E_MAPPING_HID1_OFFSET(r20)  ; HID1 address
   MTSPR    REG_HID1, r10

;
; ;  Values defined in linker command file
   lWZ      r1, s_BOOT_CORE_E_MAPPING_STACK_OFFSET(r20)  ; stack address address
;
;  Initialize higher order two bytes of GPR2 with higher order two bytes
;   of sdata2 area base address
   lWZ      r2, s_BOOT_CORE_E_MAPPING_STACK_SDA2_OFFSET(r20)  ; stack address address

;  Initialize higher order two bytes of GPR13 with
;  higher order two bytes of sdata area base address
   lWZ      r13, s_BOOT_CORE_E_MAPPING_STACK_SDA_OFFSET(r20)  ; stack address address

; in order to know on which core is being executed
;   MFSPR    r5, REG_PIR

; set the magic stop end of stack word
   LIS      r30, STACK_END_VAL@ha
   ADDI     r30, r30, STACK_END_VAL@l
   STW      r30, 0(r1)

; all core are synchronized : go

;
; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;
; ; NOW YOU CAN USE STACK, GLOBALS AND CONSTS
; ; NOW YOU CAN CALL C FUNCTIONS
; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;; ;
;

; Power PC EABI : move the stack pointer from 8 bytes
   STWU     r1, -8(r1)

   ;  Initialize core registers
   LI       r0, 0x0



   LI       r4, 0x0
   LI       r5, 0x0
   LI       r6, 0x0
   LI       r7, 0x0
   LI       r8, 0x0
   LI       r9, 0x0
   LI       r10, 0x0
   LI       r11, 0x0
   LI       r12, 0x0

   LI       r14, 0x0
   LI       r15, 0x0
   LI       r16, 0x0
   LI       r17, 0x0
   LI       r18, 0x0
   LI       r19, 0x0
   LI       r20, 0x0
   LI       r21, 0x0
   LI       r22, 0x0
   LI       r23, 0x0
   LI       r24, 0x0
   LI       r25, 0x0
   LI       r26, 0x0
   LI       r27, 0x0
   LI       r28, 0x0
   LI       r29, 0x0
   LI       r30, 0x0
   LI       r31, 0x0

   B       BOOT_MAIN_START_SW

; ---------- internal operation bodies: ------------------------------------
; none

   .end
