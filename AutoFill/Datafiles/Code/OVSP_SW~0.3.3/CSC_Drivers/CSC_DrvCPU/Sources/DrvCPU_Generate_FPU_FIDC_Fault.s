;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Generate_FPU_FIDC : To generate Input Denormal/Subnormal 
;               faults for built-in tests
;-------------------------------------------------------------------------------

   .file "DrvCPU_Generate_FPU_FIDC.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   .set C_FLOAT_SUBNORM, 0x007FFFFF
   .set C_ONE_FLOAT, 0x3F800000

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Generate_FPU_FIDC
   .type DrvCPU_Generate_FPU_FIDC, $function

; DrvCPU_Generate_FPU_FIDC : To generate Input Denormal/Subnormal faults
;                            for built-in tests
;   Inputs: None
;   Outputs: None
;   Function return: None
;   Pre-condition: None
;

DrvCPU_Generate_FPU_FIDC:
   ; C prototype:
      ; void DrvCPU_Generate_FPU_FIDC (void)

   push {r14}

   ; ************************************************* 
   ;   FIDCE: FPU Input Denormal/Subnormal Interrupt   
   ; ************************************************* 

   vldr.f32 s0, =C_FLOAT_SUBNORM
   vldr.f32 s1, =C_ONE_FLOAT
   vsub.f32 s0,s0,s1
   ; nop
   vmov.f32 s0, s31
   vmov.f32 s1, s31

   bl DrvMCM_Reset_ISCR
   bl DrvCPU_Init_FPSCR_Reg

   nop
   pop {pc}
   
   .end
