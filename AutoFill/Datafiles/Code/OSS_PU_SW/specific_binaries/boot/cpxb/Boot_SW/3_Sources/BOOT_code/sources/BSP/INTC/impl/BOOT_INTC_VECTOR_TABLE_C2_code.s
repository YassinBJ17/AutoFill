;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : Exception vector table for core_2
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------
   .extern BOOT_INTC_CRITICAL_INPUT
   .extern BOOT_INTC_MACHINE_CHK
   .extern BOOT_INTC_DATA_ACCESS
   .extern BOOT_INTC_INST_ACCESS
   .extern BOOT_INTC_EXT_IT
   .extern BOOT_INTC_ALIGNMENT
   .extern BOOT_INTC_PROGRAM
   .extern BOOT_INTC_PERF_MON
   .extern BOOT_INTC_SC
   .extern BOOT_INTC_BRKPT
   .extern BOOT_INTC_EFPU_DATA
   .extern BOOT_INTC_EFPU_ROUND

; ---------- internal define constants: ------------------------------------
; none

; ---------- internal types: -----------------------------------------------
; none

; ---------- internal operations: ------------------------------------------
; none

; ---------- internal constants: -------------------------------------------
; none

; ---------- internal data: ------------------------------------------------

;
;   Exception Table definition
;
   .section .ex_vector_table_c2, "ax"
   .global  BOOT_INTC_VECTOR_TABLE_C2
   .align 4

;
BOOT_INTC_VECTOR_TABLE_C2:

; =========================================================================
;                    0000: CRITICAL INPUT
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_077
BOOT_INTC_CRITICAL_INPUT_C2:
  B     BOOT_INTC_CRITICAL_INPUT

   .skip    0x0010 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    0010: MACHINE CHECK
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_078
BOOT_INTC_MACHINE_CHK_C2:
   B     BOOT_INTC_MACHINE_CHK

   .skip    0x0020 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    0020: DATA STORAGE ERROR
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_079
BOOT_INTC_DATA_ACCESS_C2:
   B     BOOT_INTC_DATA_ACCESS

   .skip    0x0030 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    0030:INSTRUCTION STORAGE ERROR
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_080
BOOT_INTC_INST_ACCESS_C2:
   B     BOOT_INTC_INST_ACCESS

   .skip    0x0040 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    0040: EXTERNAL INTERRUPT
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_081
BOOT_INTC_EXT_C2:
   B     BOOT_INTC_EXT_IT

   .skip    0x0050 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    0050: ALIGNMENT ERROR
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_082
BOOT_INTC_ALIGNMENT_C2:
   B     BOOT_INTC_ALIGNMENT

   .skip    0x0060 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; ========================================================================
;                    0060: PROGRAM ERROR
; ========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_083
BOOT_INTC_PROGRAM_C2:
   B     BOOT_INTC_PROGRAM

   .skip    0x0070 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    0070: PERFORMANCE MONITOR
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_084
BOOT_INTC_PERF_MON_C2:
  B     BOOT_INTC_PERF_MON

   .skip    0x0080 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    0080: SYSTEM CALL
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_085
BOOT_INTC_SC_C2:
   B     BOOT_INTC_SC

   .skip    0x0090 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    0090: DEBUG
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_086
BOOT_INTC_BRKPT_C2:
   B     BOOT_INTC_BRKPT

   .skip    0x00A0 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    00A0: FLOATING POINT DATA
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_087
BOOT_INTC_EFPU_DATA_C2:
   B     BOOT_INTC_EFPU_DATA

   .skip    0x00B0 - (.- BOOT_INTC_VECTOR_TABLE_C2)

; =========================================================================
;                    00B0: FLOATING POINT ROUND
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_088
BOOT_INTC_EFPU_ROUND_C2:
   B     BOOT_INTC_EFPU_ROUND


; ---------- provided operation bodies: ------------------------------------
; none



   .end
