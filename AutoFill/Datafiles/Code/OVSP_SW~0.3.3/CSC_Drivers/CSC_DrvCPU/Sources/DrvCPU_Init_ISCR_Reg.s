;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : BOOT PROC Init ISCR Register: To initialize ISCR system register
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_ISCR_Reg.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
.set C_DrvCPU_MCM_ISCR_REG,      0xE0080010
.set C_DrvCPU_MCM_ISCR_FPU_MASK, 0x9F000000
.set C_DrvCPU_MCM_ISCR_FPU_VAL,  0x07000000

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_ISCR_Reg
   .type DrvCPU_Init_ISCR_Reg, $function

; DrvCPU_Init_ISCR_Reg: To initialize ISCR system register
;
; Parameters:
;   Inputs: None
;   Outputs: None
;
;

DrvCPU_Init_ISCR_Reg:
   ; C prototype:
      ; void DrvCPU_Init_ISCR_Reg(void)

   ; R/W, MCM_ISCR, Interrupt Status and Control Register
      ; Disable FPU input denormal interrupt
      ; Disable FPU inexact interrupt
      ; Disable FPU underflow interrupt
      ; Enable FPU overflow interrupt
      ; Enable FPU divide-by-zero interrupt
      ; Enable FPU invalid operation interrupt



   ; Read register
   LDR.W r0, =C_DrvCPU_MCM_ISCR_REG
   LDR   r1, [r0]

   ; Get the mask to apply
   LDR   r2, =C_DrvCPU_MCM_ISCR_FPU_MASK

   ; Apply mask
   BIC   r1, r1, r2

   ; Get the value to write
   LDR   r2, =C_DrvCPU_MCM_ISCR_FPU_VAL

   ; Form value to write
   ORR   r1, r1, r2

   ; Write register
   STR   r1, [r0]

   ; Exit Function
   BX    lr

   .end
