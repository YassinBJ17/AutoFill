;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Init_FPSCR_Reg: To initialize FPSCR system register
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_FPSCR_Reg.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   ; R/W, FPSCR, Floating-point Status Control Register
   .set C_DrvCPU_FPSCR_Init_Val,  0x07C00000
   .set C_DrvCPU_FPSCR_Init_Mask, 0x0200009F

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_FPSCR_Reg
   .type DrvCPU_Init_FPSCR_Reg, $function

; DrvCPU_Init_FPSCR_Reg: To initialize FPSCR system register
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Init_FPSCR_Reg:
   ; C prototype:
      ; void DrvCPU_Init_FPSCR_Reg (void)

   ; Read register
   VMRS r0, FPSCR

   ; Get the mask to apply
   LDR r1, =C_DrvCPU_FPSCR_Init_Mask

   ; Apply mask
   BIC r0, r0, r1

   ; Get the value to write
   LDR r1, =C_DrvCPU_FPSCR_Init_Val

   ; Form value to write
   ORR r0, r0, r1

   ; Write register
   VMSR FPSCR, r0

   ; Exit Function
   BX   lr

   .end
