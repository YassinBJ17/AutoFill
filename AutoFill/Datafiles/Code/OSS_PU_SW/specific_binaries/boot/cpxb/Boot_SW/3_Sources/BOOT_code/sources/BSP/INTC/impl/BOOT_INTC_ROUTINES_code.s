;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : All cores exceptions handlers
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------
   .text
   .globl BOOT_INTC_CRITICAL_INPUT
   .globl BOOT_INTC_MACHINE_CHK
   .globl BOOT_INTC_DATA_ACCESS
   .globl BOOT_INTC_INST_ACCESS
   .globl BOOT_INTC_EXT_IT
   .globl BOOT_INTC_ALIGNMENT
   .globl BOOT_INTC_PROGRAM
   .globl BOOT_INTC_PERF_MON
   .globl BOOT_INTC_SC
   .globl BOOT_INTC_BRKPT
   .globl BOOT_INTC_EFPU_DATA
   .globl BOOT_INTC_EFPU_ROUND

   .include "BOOT_INTC_private.inc"
   .include "BOOT_RESET_DEF_public.inc"
   .include "BOOT_FAULT_public.inc"
   .align 4

; ---------- internal define constants: ------------------------------------
; none

; ---------- internal types: -----------------------------------------------
; none

; ---------- internal operations: ------------------------------------------
; none

; ---------- internal constants: -------------------------------------------
; none

; ---------- internal data: ------------------------------------------------

BOOT_INTC_CRITICAL_INPUT:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_CRITICAL_INPUT_IT
   ; Return from interrupt required for PBIT
   RFCI

BOOT_INTC_MACHINE_CHK:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_MACHINE_CHECK_IT
   ; Return from interrupt required for PBIT
   RFMCI

BOOT_INTC_DATA_ACCESS:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_DATA_ACCESS_IT

   ; Return from interrupt required for PBIT

   ; The following piece of code is really required only if fonction BOOT_PBIT_CMPU_CHK is called

   ; If return from exception is taken, then this exception
   ; has been raised during BIT.
   ; For the BIT on REG_PROT, supervisor right have to be
   ; restored

   ; Save value of r3
   STWU  r3 , -0x4(r1)

   ; Restore MSR configuration for the boot
   MFMSR r3
   MTSPR REG_SRR1, r3

   ; Restore r3 and r4
   LWZU   r3 , 0x0(r1)
   ADDI   r1, r1, 4

   RFI

BOOT_INTC_INST_ACCESS:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_INST_ACCESS_IT
   ; Return from interrupt required for PBIT
   RFI

BOOT_INTC_EXT_IT:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_EXT_IT
   ; Return from interrupt required for PBIT
   RFI

BOOT_INTC_ALIGNMENT:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_ALIGNMENT_IT
   ; Return from interrupt required for PBIT
   RFI

BOOT_INTC_PROGRAM:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_PROGRAM_IT
   ; Return from interrupt required for PBIT
   RFI

BOOT_INTC_PERF_MON:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_PERF_MON_IT
   ; Return from interrupt required for PBIT
   RFI

BOOT_INTC_SC:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_SC_IT

   ; Return from interrupt required for PBIT
   RFI

BOOT_INTC_BRKPT:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_BRKPT_IT
   ; Return from interrupt required for PBIT
   RFDI

BOOT_INTC_EFPU_DATA:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_EFPU_DATA_IT
;   ; Return from interrupt required for PBIT
;   RFI

BOOT_INTC_EFPU_ROUND:
   BOOT_INTC_MACRO_CALL_ERROR_LOG BOOT_FAULT_EFPU_ROUND_IT
;   ; Return from interrupt required for PBIT
;   RFI

   .end
