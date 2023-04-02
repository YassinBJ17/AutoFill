;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Init_FPCCR_Reg: To initialize FPCCR system register
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_FPCCR_Reg.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   ; R/W, FPSCR, Floating-point Status Control Register
   .set C_DrvCPU_FPCCR_REG,      0xE000EF34
   .set C_DrvCPU_FPCCR_REG_MASK, 0xC0000000
   .set C_DrvCPU_FPCCR_REG_VAL,  0xC0000000

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_FPCCR_Reg
   .type DrvCPU_Init_FPCCR_Reg, $function

; DrvCPU_Init_FPCCR_Reg: To initialize FPCCR system register
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Init_FPCCR_Reg:
   ; C prototype:
      ; void DrvCPU_Init_FPCCR_Reg (void)

   ; Read register
   LDR.W r0, =C_DrvCPU_FPCCR_REG
   LDR   r1, [r0]

   ; Get the mask to apply
   LDR   r2, =C_DrvCPU_FPCCR_REG_MASK

   ; Apply mask
   BIC   r1, r1, r2

   ; Get the value to write
   LDR   r2, =C_DrvCPU_FPCCR_REG_VAL

   ; Form value to write
   ORR   r1, r1, r2

   ; Write register
   STR   r1, [r0]


   ; Exit Function
   BX   lr

   .end
