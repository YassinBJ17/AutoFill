;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Init_VTOR_InSRAM: To relocate vector table to RAM during boot
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_VTOR_InSRAM.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
.set C_DrvCPU_VECTOR_REG,  0xE000ED08

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_VTOR_InSRAM
   .type DrvCPU_Init_VTOR_InSRAM, $function

; DrvCPU_Init_VTOR_InSRAM: To relocate vector table to RAM during boot
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Init_VTOR_InSRAM:
   ; C prototype:
      ; void DrvCPU_Init_VTOR_InSRAM (void)

   ; push {r4-r11, r14}

   ; Relocate vector table to RAM during Boot
   LDR  r0, =C_DrvCPU_VECTOR_REG
   LDR  r1, =C_DrvNVIC_VectorsTable_CPU
   STR  r1,[r0]

   ; Exit Function
   ; pop {r4-r11, r15}
   BX   r14

   .end
