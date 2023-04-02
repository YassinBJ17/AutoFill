;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : This function resets the memories (Cache, SRAM) and
;               registers values to the default one after a platform reset.
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------
   .include "BOOT_RESET_DEF_public.inc"

; ---------- internal define constants: ------------------------------------
; none

; ---------- internal types: -----------------------------------------------
; none

; ---------- internal operations: ------------------------------------------
; none

; ---------- internal constants: -------------------------------------------
; none



; ---------- internal data: ------------------------------------------------
; none

; ---------- provided operation bodies: ------------------------------------

;----------------------------------------------------------------------------
; C PROTOTYPE :
;-----------------
; void BOOT_RESET_PLATFORM(void)
;

; STACK USAGE :
;-----------------
;  TBC
;

;  REGISTER USAGE :
; -----------------
;  TBC
;

   .extern BOOT_INIT_LOCAL_RAM
   .extern BOOT_INIT_LOCAL_RAM_END
; tres important, cela permet au link de ne pas supprimer les donnees BOOT_RCHW_HEADER
   .extern BOOT_RCHW_HEADER

; -----------------
;  BODY :
;
;
   .file "BOOT_RESET_PLATFORM_code.s"

   .section  ".startup", "ax"
   .globl  BOOT_RESET_PLATFORM
   .globl  _start_boot
   .align 4

; keep _start as a generic symbol for the software start point
; Implements REQ_[User Project Name]_BOOT-LLR_050
_start_boot:
BOOT_RESET_PLATFORM:

   LI       r0, 0

   ; Disable MPU
   ; Set MPUEN bit to 0
   MFSPR    r3, REG_MPU0CSR0
   RLWINM   r3, r3, 0, 0, 30
   ORI      r3, r3, 0
   MTSPR    REG_MPU0CSR0, r3

BOOT_RESET_PLATFORM_ICACHE_CFG:
; invalidate and disable instruction cache
   LIS      r5, ICACHE_L1CSR1_VALUE@ha
   ADDI     r5, r5, ICACHE_L1CSR1_VALUE@l
   MTSPR    REG_L1CSR1, r5

; load icache abort mask
   LIS      r11, ICACHE_L1CSR1_ABT_MSK@ha
   ADDI     r11, r11, ICACHE_L1CSR1_ABT_MSK@l
; load icache configuration
   LIS      r8, ICACHE_L1CSR1_VALUE@ha
   ADDI     r8, r8, ICACHE_L1CSR1_VALUE@l
; load icache abort value
   LI       r7, ICACHE_L1CSR1_ABT_VALUE

BOOT_RESET_PLATFORM_ICACHE_INV:
   MFSPR    r9, REG_L1CSR1
   AND.     r10, r11, r9
   BEQ      BOOT_RESET_PLATFORM_ICACHE_NO_ABORT
   AND.     r10, r11, r9
   MTSPR    REG_L1CSR1, r10
   B        BOOT_RESET_PLATFORM_ICACHE_CFG

BOOT_RESET_PLATFORM_ICACHE_NO_ABORT:
   AND.     r10, r8, r9
   BNE      BOOT_RESET_PLATFORM_ICACHE_INV

   ISYNC
   MSYNC

; Branch target buffer flash invalidate and Branch target enable
   LIS      r3, BUCSR_VALUE@ha
   ADDI     r3, r3, BUCSR_VALUE@l
   MTSPR    REG_BUCSR, r3
   ISYNC

   LI       r0, 0x0

; Init Special Purpose Registers (SPR)
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

; Set MSR
   LIS      r3, CORE_MSR_VALUE@ha
   ADDI     r3, r3, CORE_MSR_VALUE@l
   MTMSR    r3

;  Configure Interrupt Vector Offset Registers IVPR (default reset value)
   LIS      r3,BOOT_INTC_VECTOR_TABLE_C2@ha  ; loading exception table
   ADDI     r3,r3, BOOT_INTC_VECTOR_TABLE_C2@l  ; loading exception table
   MTSPR    REG_IVPR , r3
   ;  enable external interrupts
   WRTEEI   1
   ISYNC

; initialize System Ram for BOOT usage (stack and data)
; If this area is not initialized, it is not accessible in read and write.
; Only the beginning of RAM can be initialised at this moment. This avoid
; to have an exception.
   LIS      r3, BOOT_INIT_LOCAL_RAM@ha
   ADDI     r3, r3, BOOT_INIT_LOCAL_RAM@l

   LIS      r4, BOOT_INIT_LOCAL_RAM_END@ha
   ADDI     r4, r4, BOOT_INIT_LOCAL_RAM_END@l

   LIS      r30, INIT_SRAM_VAL_1@ha
   ADDI     r30, r30, INIT_SRAM_VAL_1@l

   LIS      r31, INIT_SRAM_VAL_2@ha
   ADDI     r31, r31, INIT_SRAM_VAL_2@l

; size area is divided by 8 because the core will write by blocks of 2*32 bits (see stmw)
   SUBF     r4,r3,r4

   LI       r5, 8
; Warning: r4 and r5 must be aligned on 8 bytes and the difference must be of a size multiple of 8.
   DIVW     r4, r4, r5
   MTCTR    r4

BOOT_INIT_LOOP_SYS_RAM_START:
   STMW     r30, 0(r3)
   ADDI     r3, r3, 8
   BDNZ     BOOT_INIT_LOOP_SYS_RAM_START

; Initialize core registers
   LI       r0, 0x0
   LI       r1, 0x0
   LI       r2, 0x0
   LI       r3, 0x0
   LI       r4, 0x0
   LI       r5, 0x0
   LI       r6, 0x0
   LI       r7, 0x0
   LI       r8, 0x0
   LI       r9, 0x0
   LI       r10, 0x0
   LI       r11, 0x0
   LI       r12, 0x0
   LI       r13, 0x0
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

; values defined in linker command file
   LIS      r1, __BOOT_PLATFORM_SP_INIT@ha
   ADDI     r1, r1, __BOOT_PLATFORM_SP_INIT@l

; Initialize higher order two bytes of GPR2 with higher order two bytes
; of sdata2 area base address
   LIS      r2, _BOOT_SDA2_BASE_@ha
; Add GPR2 with lower order two bytes of sdata2 area base address
   ADDI     r2, r2, _BOOT_SDA2_BASE_@l

; Initialize higher order two bytes of GPR13 with
; higher order two bytes of sdata area base address
   LIS      r13, _BOOT_SDA_BASE_@ha
; Add GPR13 with lower order two bytes of sdata area base address
   ADDI     r13, r13, _BOOT_SDA_BASE_@l

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; NOW YOU CAN USE STACK, GLOBALS AND CONSTS
; NOW YOU CAN CALL C FUNCTIONS
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Power PC EABI : move the stack pointer from 8 bytes
   STWU     r1, -8 (r1)

   BL       BOOT_MAIN_INIT

; ---------- internal operation bodies: ------------------------------------
; none

   .end



