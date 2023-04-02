;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : This CSU manages SRAM ECC activation and ECC error injection
; --------------------------------------------------------------------------


; ---------- include required interface: -----------------------------------
   .include "BOOT_MEM_LRAM_public.inc"

; ---------- internal define constants: ------------------------------------
; none

; ---------- provided datas: -------------------------------------------

; Identifier End-to-End ECC Control Register 0 (E2ECTL0)
   .set     REG_DCR                  ,510
   .set     REG_E2EECSR0             ,511
   .set     E2EECSR0_RESET_VAL       ,0x0

;----------------------------------------------------------------------------
;  C PROTOTYPE :
;-----------------
;  void BOOT_MEM_ECC_CONFIG( uint32_t p_DCR_init_value );
;

;  STACK USAGE :
; -----------------
;   TBC
;

;  REGISTER USAGE :
; -----------------
;  none

   .file  "BOOT_MEM_ECC_code.s"
   .globl BOOT_MEM_ECC_CONFIG
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_042
BOOT_MEM_ECC_CONFIG:
; Configure access to RAMs by modifying End-to-End ECC Control Register 0 (E2ECTL0)
; Without this, theses areas are not readable before being written
   MTDCR    REG_DCR, r3

; End of function
   BLR












