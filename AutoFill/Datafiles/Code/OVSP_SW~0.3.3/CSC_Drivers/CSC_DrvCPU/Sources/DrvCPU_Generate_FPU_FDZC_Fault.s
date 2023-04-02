;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Generate_FPU_FDZC : To generate Divide-By-Zero FPU Fault
;-------------------------------------------------------------------------------

   .file "DrvCPU_Generate_FPU_FDZC.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
   .set C_PI,  0x40490FD0

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Generate_FPU_FDZC

; DrvCPU_Generate_FPU_FDZC : To generate Divide-By-Zero FPU Fault
;
; Parameters:
;   Inputs: None
;   Outputs: None
;
;

DrvCPU_Generate_FPU_FDZC:
   ; C prototype:
      ; void DrvCPU_Generate_FPU_FDZC (void)
   
   push {r14}

   ; ************************************** 
   ; FDZCE: FPU Divide-by-Zero Interrupt 
   ; ************************************** 


   vldr.f32 s0, =C_PI
   vdiv.f32 s0,s0,s31
   nop
   vmov.f32 s0, s31
   vmov.f32 s1, s31
   bl DrvCPU_Init_FPSCR_Reg
   bl DrvMCM_Reset_ISCR

   nop
   pop {pc}

   .end
