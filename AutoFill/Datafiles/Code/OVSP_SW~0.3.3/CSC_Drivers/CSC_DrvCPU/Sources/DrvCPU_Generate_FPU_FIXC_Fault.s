;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Generate_FPU_FIXC: To generate FPU Inexact fault for
;               built-in tests
;-------------------------------------------------------------------------------

   .file "DrvCPU_Generate_FPU_FIXC.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   .set C_ONE_FLOAT, 0x3F800000
   .set C_FLOAT_MIN, 0x00800000

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Generate_FPU_FIXC
   .type DrvCPU_Generate_FPU_FIXC, $function

; DrvCPU_Generate_FPU_FIXC: To generate FPU Inexact fault for built-in tests
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Generate_FPU_FIXC:
   ; C prototype:
      ; void DrvCPU_Generate_FPU_FIXC (void)

   push {r14}

   ; ************************************** 
   ;      FIXCE: FPU Inexact Interrupt       
   ; ************************************** 

   ; C_FLOAT_MIN - 1.0 
   ; Creates an inexact float value as it is lower than the lowest resolution of IEEE-754 single precision 

   vldr.f32 s0, =C_FLOAT_MIN
   vldr.f32 s1, =C_ONE_FLOAT
   vsub.f32 s0,s0,s1
   nop
   vmov.f32 s0, s31
   vmov.f32 s1, s31
   bl DrvCPU_Init_FPSCR_Reg
   bl DrvMCM_Reset_ISCR   

   ; Exit Function
   nop
   pop {pc}

   .end
