;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Init_CPACR_Reg: To initialize CPACR system register
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_CPACR_Reg.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   ; R/W, CPACR, Coprocessor Access Control Register
   .set C_DrvCPU_CPACR_Reg,      0xE000ED88
   .set C_DrvCPU_CPACR_Reg_Mask, 0x00F00000
   .set C_DrvCPU_CPACR_REG_VAL,  0x00F00000

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_CPACR_Reg
   .type DrvCPU_Init_CPACR_Reg, $function

; DrvCPU_Init_CPACR_Reg: To initialize CPACR system register
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Init_CPACR_Reg:
   ; C prototype:
      ; void DrvCPU_Init_CPACR_Reg (void)

   ; ----------------------------------------------------------------------
   ; Cortex-M4 Devices Generic User Guide - Page 2-4
   ; Access these registers individually or as a combination of any two or all three registers,
   ; using the register name as an argument to the MSR or MRS instructions.
   ; For example:
   ;    - read all of the registers using PSR with the MRS instruction
   ;    - write to the APSR N, Z, C, V, and Q bits using APSR_nzcvq with the MSR instruction.
   ; --------------------------------------------------------------------- */
    
   ; Read register
   LDR.W r0, =C_DrvCPU_CPACR_Reg
   LDR   r1, [r0]

   ; Get the mask to apply
   LDR   r2, =C_DrvCPU_CPACR_Reg_Mask

   ; Apply mask
   BIC   r1, r1, r2

   ; Get the value to write
   LDR   r2, =C_DrvCPU_CPACR_REG_VAL

   ; Form value to write
   ORR   r1, r1, r2

   ; Write register
   STR   r1, [r0]

   ; Exit Function
   BX    lr

   .end
