;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION  : Common macro for all exception 
; --------------------------------------------------------------------------
;
; ---------- include required interface: -----------------------------------
; none
;
; ---------- provided macro: -----------------------------------------------
;

BOOT_INTC_MACRO_CALL_ERROR_LOG: .macro param1
   SYNC

; The code line 19 to 24 and 31 to 37 is required for PBIT on INTC and REG_PROT

   ; Save stack pointer value
   MTSPR REG_SPRG0, r1
   ; Save values of r3, r4 and LR in stack before using them
   STWU  r3 , -0x4(r1)
   STWU  r4 , -0x4(r1)
   ; Save REG_LR in stack
   MFSPR  r4, REG_LR
   STWU  r4 , -0x4(r1)

   LI     r3, param1
   BL BOOT_INTC_ERROR_LOG
   ; Now the context is restored. Every registers must be saved before use.

   ; If return from exception is taken, then this exception
   ; has been raised during CMPU PBIT, supervisor rights have to be
   ; restored
   ; Restore MSR configuration for the boot
   MFMSR r3
   MTSPR REG_SRR1, r3

   ; Restore r3, r4, REG_LR
   LWZU   r4 , 0x0(r1)
   MTSPR  REG_LR, r4
   LWZU   r4 , 0x4(r1)
   LWZU   r3 , 0x4(r1)

   ADDI   r1, r1, 4

   .endm
; ---------- provided constant: ------------------------------------------------
; none


; ---------- provided operation: -------------------------------------------
; none
