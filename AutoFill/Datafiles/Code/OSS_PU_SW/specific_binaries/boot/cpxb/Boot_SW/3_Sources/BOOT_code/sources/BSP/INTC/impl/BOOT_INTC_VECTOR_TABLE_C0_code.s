;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : Exception vector table for core_0
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
   .section .ex_vector_table_c0, "ax"
   .global  BOOT_INTC_VECTOR_TABLE_C0
   .align 4

;
BOOT_INTC_VECTOR_TABLE_C0:

; =========================================================================
;                    0000: CRITICAL INPUT
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_024
BOOT_INTC_CRITICAL_INPUT_C0:
  B     BOOT_INTC_CRITICAL_INPUT

   .skip    0x0010 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    0010: MACHINE CHECK
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_025
BOOT_INTC_MACHINE_CHK_C0:
   B     BOOT_INTC_MACHINE_CHK

   .skip    0x0020 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    0020: DATA STORAGE ERROR
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_026
BOOT_INTC_DATA_ACCESS_C0:
   B     BOOT_INTC_DATA_ACCESS

   .skip    0x0030 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    0030:INSTRUCTION STORAGE ERROR
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_027
BOOT_INTC_INST_ACCESS_C0:
   B     BOOT_INTC_INST_ACCESS

   .skip    0x0040 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    0040: EXTERNAL INTERRUPT
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_028
BOOT_INTC_EXT_C0:
   B     BOOT_INTC_EXT_IT

   .skip    0x0050 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    0050: ALIGNMENT ERROR
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_029
BOOT_INTC_ALIGNMENT_C0:
   B     BOOT_INTC_ALIGNMENT

   .skip    0x0060 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; ========================================================================
;                    0060: PROGRAM ERROR
; ========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_030
BOOT_INTC_PROGRAM_C0:
   B     BOOT_INTC_PROGRAM

   .skip    0x0070 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    0070: PERFORMANCE MONITOR
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_031
BOOT_INTC_PERF_MON_C0:
  B     BOOT_INTC_PERF_MON

   .skip    0x0080 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    0080: SYSTEM CALL
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_032
BOOT_INTC_SC_C0:
   B     BOOT_INTC_SC

   .skip    0x0090 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    0090: DEBUG
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_033
BOOT_INTC_BRKPT_C0:
   B     BOOT_INTC_BRKPT

   .skip    0x00A0 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    00A0: FLOATING POINT DATA
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_034
BOOT_INTC_EFPU_DATA_C0:
   B     BOOT_INTC_EFPU_DATA

   .skip    0x00B0 - (.- BOOT_INTC_VECTOR_TABLE_C0)

; =========================================================================
;                    00B0: FLOATING POINT ROUND
; =========================================================================
; Implements REQ_[User Project Name]_BOOT-LLR_035
BOOT_INTC_EFPU_ROUND_C0:
   B     BOOT_INTC_EFPU_ROUND


; ---------- provided operation bodies: ------------------------------------
; none



   .end
