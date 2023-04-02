;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION  : DrvCPU Exit Critical Section: To Enable interrupts in the
;                ARM Exception Mask Register
;-------------------------------------------------------------------------------

   .file "DrvCPU_Exit_Crit_Sect.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
; None

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Exit_Crit_Sect
   .type DrvCPU_Exit_Crit_Sect, $function
; BOOT PROC Exit Critical Section: To enable interrupt (exit critical section)
;
; Parameters:
;   Inputs: None
;   Outputs: None
;
;

DrvCPU_Exit_Crit_Sect:
   ; C prototype:
      ; void DrvCPU_Exit_Crit_Sect(void)

   ; Register usage:
      ; CPSIE means Current Processor Status Interrupt Enable
      ; Enable Interrupts in the exception mask register (PRIMASK)

   CPSIE    I
  
   BX   lr

   .end
