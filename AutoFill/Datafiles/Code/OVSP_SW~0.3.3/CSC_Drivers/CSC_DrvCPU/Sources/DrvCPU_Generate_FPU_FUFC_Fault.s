;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Generate_FPU_FUFC: To generate FPU Underflow fault for
;               built-in tests
;-------------------------------------------------------------------------------

   .file "DrvCPU_Generate_FPU_FUFC.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   .set C_FLOAT_MIN, 0x00800000
   .set C_TWO_FLOAT, 0x40000000

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Generate_FPU_FUFC
   .type DrvCPU_Generate_FPU_FUFC, $function

; DrvCPU_Generate_FPU_FUFC: To generate FPU Underflow fault for built-in tests
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Generate_FPU_FUFC:
   ; C prototype:
      ; void DrvCPU_Generate_FPU_FUFC (void)
   
   push {r14}

   ; ************************************** 
   ; FUFCE: FPU Underflow Interrupt  
   ; ************************************** 

   ; C_FLOAT_MIN / 2.0 
   vldr.f32 s0, =C_FLOAT_MIN
   vldr.f32 s1, =C_TWO_FLOAT
   vdiv.f32 s0,s0,s1
   nop
   vmov.f32 s0, s31
   vmov.f32 s1, s31
   bl DrvCPU_Init_FPSCR_Reg
   bl DrvMCM_Reset_ISCR  

   ; Exit Function
   pop {pc}

   .end
