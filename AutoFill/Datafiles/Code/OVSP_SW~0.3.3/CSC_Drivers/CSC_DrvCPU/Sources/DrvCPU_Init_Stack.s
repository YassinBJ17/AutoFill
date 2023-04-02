;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : DrvCPU_Init_Stack: To initialize the Stack Pointer (SP)
;-------------------------------------------------------------------------------

   .file "DrvCPU_Init_Stack.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
; CONTROL, Thread_mode_privilege=0, stack=SP_main
   .set c_DrvCPU_CONTROL_SP_Mask, 0x00000002
   .set c_DrvCPU_CONTROL_SP_Val,  0x00000002

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Init_Stack
   .type DrvCPU_Init_Stack, $function

;  DrvCPU_Init_Stack: To initialize the Stack Pointer (SP)
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Init_Stack:
   ; C prototype:
      ; void DrvCPU_Init_Stack (void)

   ; ----------------------------------------------------------------------
   ; At init, the current mode is THREAD_MODE and Stack Pointer is SP_MAIN
   ; SP_MAIN is already the Stack Pointer for Exceptions
   ; Set up the SP_PROCESS for THREAD_MODE
   ; ----------------------------------------------------------------------
   ; Cortex-M4 Devices Generic User Guide - Page 2-4
   ; Access these registers individually or as a combination of any two or all three registers,
   ; using the register name as an argument to the MSR or MRS instructions.
   ; For example:
   ;   - read all of the registers using PSR with the MRS instruction
   ;   - write to the APSR N, Z, C, V, and Q bits using APSR_nzcvq with the MSR instruction.
   ; ---------------------------------------------------------------------
    
   ; Read register
   MRS r0, CONTROL

   ; Get the mask to apply
   LDR r1, =c_DrvCPU_CONTROL_SP_Mask

   ; Apply mask
   BIC r0, r0, r1

   ; Get the value to write
   LDR r1, =c_DrvCPU_CONTROL_SP_Val

   ; Form value to write
   ORR r0, r0, r1

   ; Write register
   MSR CONTROL, r0

   ; Instruction Synchronization Barrier (ISB), used ton ensure the effect of the change applies
   ; to subsequent code.
   ISB

   ; Set-up SP_MAIN
   LDR   r0, =__Linker_Stack_Main
   MSR   MSP, r0

   ; Set-up SP_PROCESS
   LDR   r0, =__Linker_Stack_Process
   MSR   PSP, r0

   ; Exit Function
   BX   lr

   .end
