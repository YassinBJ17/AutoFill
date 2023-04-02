;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Init_GPRs: To initialize Global Purpose Registers (GPRs)
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_GPRs.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
; None

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_GPRs
   .type DrvCPU_Init_GPRs, $function

; DrvCPU_Init_GPRs: To initialize Global Purpose Registers (GPRs)
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Init_GPRs:
   ; C prototype:
      ; void DrvCPU_Init_GPRs (void)

   ; Initialize the GPRs
   MOV   r0,  #0
   MOV   r1,  #0
   MOV   r2,  #0
   MOV   r3,  #0
   MOV   r4,  #0
   MOV   r5,  #0
   MOV   r6,  #0
   MOV   r7,  #0
   MOV   r8,  #0
   MOV   r9,  #0
   MOV   r10, #0
   MOV   r11, #0
   MOV   r12, #0

   .end
