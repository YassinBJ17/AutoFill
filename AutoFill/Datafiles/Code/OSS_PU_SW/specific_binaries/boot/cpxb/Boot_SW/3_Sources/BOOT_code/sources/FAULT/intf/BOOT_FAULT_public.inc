;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION  :
; --------------------------------------------------------------------------
;
;
; ---------- include required interface: -----------------------------------
; none
;
; ---------- provided macro: -----------------------------------------------
;

; ---------- provided constant: ------------------------------------------------

; Exceptions error code
   .set BOOT_FAULT_POWERDOWN_IT,         0
   .set BOOT_FAULT_CRITICAL_INPUT_IT,    1
   .set BOOT_FAULT_MACHINE_CHECK_IT,     2
   .set BOOT_FAULT_DATA_ACCESS_IT,       3
   .set BOOT_FAULT_INST_ACCESS_IT,       4
   .set BOOT_FAULT_EXT_IT,		         5
   .set BOOT_FAULT_ALIGNMENT_IT,         6
   .set BOOT_FAULT_PROGRAM_IT,           7
   .set BOOT_FAULT_PERF_MON_IT,          8
   .set BOOT_FAULT_SC_IT,                9
   .set BOOT_FAULT_BRKPT_IT,            10
   .set BOOT_FAULT_EFPU_DATA_IT,        11
   .set BOOT_FAULT_EFPU_ROUND_IT,       12
   .set BOOT_FAULT_FCCU_IT,             13

; Exeption origin ID
   .set INTC_ORIGIN,                    2

; ---------- provided operation: -------------------------------------------
; none
