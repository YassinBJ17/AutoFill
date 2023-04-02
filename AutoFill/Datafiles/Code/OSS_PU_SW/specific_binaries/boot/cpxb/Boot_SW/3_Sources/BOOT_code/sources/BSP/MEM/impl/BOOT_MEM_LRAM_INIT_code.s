;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : This function initializes the IMEM and DMEM Registers.
; --------------------------------------------------------------------------


; ---------- include required interface: -----------------------------------
   .include "BOOT_MEM_LRAM_public.inc"
   .include "BOOT_RESET_DEF_public.inc"

; ---------- internal define constants: ------------------------------------
; none

   .set IMEM0_L, 0x50000000
   .set IMEM0_H, 0x50004000
   .set DMEM0_L, 0x50800000
   .set DMEM0_H, 0x50810000

   .set IMEM1_L, 0x51000000
   .set IMEM1_H, 0x51004000
   .set DMEM1_L, 0x51800000
   .set DMEM1_H, 0x51810000

   .set IMEM2_L, 0x52000000
   .set IMEM2_H, 0x52004000
   .set DMEM2_L, 0x52800000
   .set DMEM2_H, 0x52810000

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
   .file  "BOOT_MEM_LRAM_INIT_code.s"
   .globl BOOT_MEM_LRAM_INIT
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_043
BOOT_MEM_LRAM_INIT:

   ; Save LR register without using the stack
   MFSPR   r3, REG_LR
   MTSPR   REG_SPRG0, r3

   LIS     r3, IMEM2_L@ha
   ADDI    r3, r3, IMEM2_L@l
   LIS     r4, IMEM2_H@ha
   ADDI    r4, r4, IMEM2_H@l
   BL BOOT_MEM_RAM_INIT

   LIS     r3, DMEM2_L@ha
   ADDI    r3, r3, DMEM2_L@l
   LIS     r4, DMEM2_H@ha
   ADDI    r4, r4, DMEM2_H@l
   BL BOOT_MEM_RAM_INIT

   LIS     r3, IMEM0_L@ha
   ADDI    r3, r3, IMEM0_L@l
   LIS     r4, IMEM0_H@ha
   ADDI    r4, r4, IMEM0_H@l
   BL BOOT_MEM_RAM_INIT

   LIS     r3, DMEM0_L@ha
   ADDI    r3, r3, DMEM0_L@l
   LIS     r4, DMEM0_H@ha
   ADDI    r4, r4, DMEM0_H@l
   BL BOOT_MEM_RAM_INIT

   LIS     r3, IMEM1_L@ha
   ADDI    r3, r3, IMEM1_L@l
   LIS     r4, IMEM1_H@ha
   ADDI    r4, r4, IMEM1_H@l
   BL BOOT_MEM_RAM_INIT

   LIS     r3, DMEM1_L@ha
   ADDI    r3, r3, DMEM1_L@l
   LIS     r4, DMEM1_H@ha
   ADDI    r4, r4, DMEM1_H@l
   BL BOOT_MEM_RAM_INIT

   MFSPR   r3, REG_SPRG0
   MTSPR   REG_LR, r3

; End of function
   BLR
