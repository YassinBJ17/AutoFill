;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Init_APSR_Reg: To initialize APSR system register
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_APSR_Reg.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   ; APSR, APSR=0 */
   .set C_DrvCPU_APSR_Mask,     0xF8000000
   .set C_DrvCPU_APSR_Init_Val, 0

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_APSR_Reg
   .type DrvCPU_Init_APSR_Reg, $function

; DrvCPU_Init_APSR_Reg: To initialize APSR system register
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;


DrvCPU_Init_APSR_Reg:
   ; C prototype:
      ; void DrvCPU_Init_APSR_Reg (void)

   ; ----------------------------------------------------------------------
   ; Cortex-M4 Devices Generic User Guide - Page 2-4
   ; Access these registers individually or as a combination of any two or all three registers,
   ; using the register name as an argument to the MSR or MRS instructions.
   ; For example:
   ;    - read all of the registers using PSR with the MRS instruction
   ;    - write to the APSR N, Z, C, V, and Q bits using APSR_nzcvq with the MSR instruction.
   ; ---------------------------------------------------------------------
    
   ; Read register */
   MRS   r0, APSR

   ; Get the mask to apply */
   LDR   r1, =C_DrvCPU_APSR_Mask

   ; Apply mask */
   BIC   r0, r0, r1

   ; Get the value to write */
   LDR   r1, =C_DrvCPU_APSR_Init_Val

   ; Form value to write */
   ORR   r0, r0, r1

   ; Write register */
   MSR   APSR, r0

   ; Exit Function
   BX    lr

   .end
