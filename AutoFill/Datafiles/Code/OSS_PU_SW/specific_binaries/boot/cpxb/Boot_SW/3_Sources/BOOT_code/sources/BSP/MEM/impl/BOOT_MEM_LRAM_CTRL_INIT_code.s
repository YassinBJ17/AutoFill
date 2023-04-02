;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : This function initializes the IMEM and DMEM Registers.
; --------------------------------------------------------------------------


; ---------- include required interface: -----------------------------------
   .include "BOOT_MEM_LRAM_public.inc"

; ---------- internal define constants: ------------------------------------
; none

; ---------- provided datas: -------------------------------------------
; none
;----------------------------------------------------------------------------
;  C PROTOTYPE :
;-----------------
;  void BOOT_MEM_LRAM_CTRL_INIT( void );
;

;  STACK USAGE :
; -----------------
;   TBC
;

;  REGISTER USAGE :
; -----------------
;
   .file  "BOOT_MEM_LRAM_CTRL_INIT_code.s"
   .globl BOOT_MEM_LRAM_CTRL_INIT
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_043
BOOT_MEM_LRAM_CTRL_INIT:

;  Configure access to DMEM/IMEM Control Register 0 (DMEMCTL0/IMEMCTL0)
;  Without this, theses areas are not readable before being written
;  Get base address of D_MEM
   MFSPR   r3, REG_DMEMCFG0
   LIS     r4, REG_DMEMCFG0_MASK_VALUE@ha
   ADDI    r4, r4, REG_DMEMCFG0_MASK_VALUE@l
   AND     r4, r4, r3
;  Set DMEMCTL0 value
   LIS     r3, REG_DMEMCTL0_INIT_VALUE@ha
   ADDI    r3, r3, REG_DMEMCTL0_INIT_VALUE@l
   ADD     r3, r3, r4
   MTDCR   REG_DMEMCTL0, r3

;  Set DMEMCTL1 value
   LIS     r3, REG_DMEMCTL1_INIT_VALUE@ha
   ADDI    r3, r3, REG_DMEMCTL1_INIT_VALUE@l
   MTDCR   REG_DMEMCTL1, r3

;  Get base address of I_MEM
   MFSPR   r3, REG_IMEMCFG0
   LIS     r4, REG_IMEMCFG0_MASK_VALUE@ha
   ADDI    r4, r4, REG_IMEMCFG0_MASK_VALUE@l
   AND     r4, r4, r3
;  Set IMEMCTL0 value
   LIS     r3, REG_IMEMCTL0_INIT_VALUE@ha
   ADDI    r3, r3, REG_IMEMCTL0_INIT_VALUE@l
   ADD     r3, r3, r4
   MTDCR   REG_IMEMCTL0, r3
;  Set IMEMCTL1 value
   LIS     r3, REG_IMEMCTL1_INIT_VALUE@ha
   ADDI    r3, r3, REG_IMEMCTL1_INIT_VALUE@l
   MTDCR   REG_IMEMCTL1, r3


; End of function
   BLR
