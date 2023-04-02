;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Generate_FPU_FOFC: To generate FPU Overflow fault for
;               built-in tests
;-------------------------------------------------------------------------------

   .file "DrvCPU_Generate_FPU_FOFC.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   .set C_TWO_FLOAT, 0x40000000
   .set C_FLOAT_MAX, 0x7F7FFFFF

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Generate_FPU_FOFC
   .type DrvCPU_Generate_FPU_FOFC, $function

; DrvCPU_Generate_FPU_FOFC: To generate FPU Overflow fault for built-in tests
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Generate_FPU_FOFC:
   ; C prototype:
      ; void DrvCPU_Generate_FPU_FOFC (void)
    
   push {r14}
   
   ; ************************************** 
   ;      FOFCE: FPU Overflow Interrupt      
   ; ************************************** 

   ; C_FLOAT_MAX * 2.0 
   vldr.f32 s0, =C_FLOAT_MAX
   vldr.f32 s1, =C_TWO_FLOAT
   vmul.f32 s0,s0,s1
   nop
   vmov.f32 s0, s31
   vmov.f32 s1, s31
   bl DrvCPU_Init_FPSCR_Reg
   bl DrvMCM_Reset_ISCR   
   
   ; Exit Function
   pop {pc}

   .end
