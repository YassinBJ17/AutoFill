;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Init_FPU_Sn_Reg: To initialize S0 to S31 
;               single-precision registers from FPU
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_FPU_Sn_Reg.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   .set C_DrvCPU_Init_Sn_Val,  0x00000000

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_FPU_Sn_Reg
   .global DrvCPU_Init_FPU_Sn_Reg, $function

; DrvCPU_Init_FPU_Sn_Reg: To initialize S0 to S31 single-precision registers from FPU
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Init_FPU_Sn_Reg:
   ; C prototype:
      ; void DrvCPU_Init_FPU_Sn_Reg (void)
    
   push {r14}

   vldr.f32 s31, =C_DrvCPU_Init_Sn_Val

   vmov.f32 s0, s31
   vmov.f32 s1, s31
   vmov.f32 s2, s31
   vmov.f32 s3, s31
   vmov.f32 s4, s31
   vmov.f32 s5, s31
   vmov.f32 s6, s31
   vmov.f32 s7, s31
   vmov.f32 s8, s31
   vmov.f32 s9, s31
   vmov.f32 s10, s31
   vmov.f32 s11, s31
   vmov.f32 s12, s31
   vmov.f32 s13, s31
   vmov.f32 s14, s31
   vmov.f32 s15, s31
   vmov.f32 s16, s31
   vmov.f32 s17, s31
   vmov.f32 s18, s31
   vmov.f32 s19, s31
   vmov.f32 s20, s31
   vmov.f32 s21, s31
   vmov.f32 s22, s31
   vmov.f32 s23, s31
   vmov.f32 s24, s31
   vmov.f32 s25, s31
   vmov.f32 s26, s31
   vmov.f32 s27, s31
   vmov.f32 s28, s31
   vmov.f32 s29, s31
   vmov.f32 s30, s31

   ; Exit Function
   nop
   pop {pc}

   .end
