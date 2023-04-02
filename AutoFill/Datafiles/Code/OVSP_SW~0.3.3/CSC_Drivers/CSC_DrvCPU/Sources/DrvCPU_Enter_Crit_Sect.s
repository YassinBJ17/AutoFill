;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                    Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION  : DrvCPU Enter Critical Section: To Enable interrupts in the
;                ARM Exception Mask Register
;-------------------------------------------------------------------------------

   .file "DrvCPU_Enter_Crit_Sect.s"

;------------ include interface: -----------------------------------------------
; None

;------------ local objects: ---------------------------------------------------
; None

;------------ function bodies: -------------------------------------------------
   .text
   .global DrvCPU_Enter_Crit_Sect
   .type DrvCPU_Enter_Crit_Sect, $function

; BOOT PROC Enter Critical Section: To disable interrupt (enter critical section)
;
;  Inputs: None
;  Outputs: None
;  Function return: None
;  Pre-condition: None
;

DrvCPU_Enter_Crit_Sect:
   ; C prototype:
      ; void DrvCPU_Enter_Crit_Sect(void)

   ; Register usage:
      ; CPSID means Current Processor Status Interrupt Disable
      ; Disable Interrupts in the exception mask register (PRIMASK)

   CPSID    I
  
   BX   lr

   .end
