 ;-------------------------------------------------------------------------------
 ;                        SAFRAN Electronics & Defense
 ;                   Reproduction and disclosure forbidden.
 ;-------------------------------------------------------------------------------
 ; DESCRIPTION : This function configure the registers SPEFSCR and MSR
 ;
 ; --------------------------------------------------------------------------


; ---------- include required interface: -----------------------------------
   .include "BOOT_RESET_DEF_public.inc"

; ---------- internal define constants: ------------------------------------
; none

	.set C_SET_PR_BIT_MASK     ,0x4000     ; MSR bit mask
; ---------- provided datas: -------------------------------------------
; none


;----------------------------------------------------------------------------
;  C PROTOTYPE :
;-----------------
;  void BOOT_RESET_SET_SPEFSCR( uint32_t const p_value)
;  void BOOT_RESET_SET_USER_MODE( void)
;  void BOOT_RESET_REG_MCSR(void)

;  STACK USAGE :
; -----------------
;   TBC
;

;  REGISTER USAGE :
; -----------------
;  none

   .file  "BOOT_RESET_REG_code.s"
   .globl BOOT_RESET_SET_SPEFSCR
   .globl BOOT_RESET_SET_USER_MODE
   .globl BOOT_RESET_CLEAR_MCSR
   .align 4

; Implements REQ_[User Project Name]_BOOT-LLR_0XX
BOOT_RESET_SET_SPEFSCR:

   MTSPR  REG_SPEFSCR, r3

; End of function
   BLR

   ; Implements REQ_[User Project Name]_BOOT-LLR_0XX
BOOT_RESET_SET_USER_MODE:

   MFMSR  r3
   ORI    r3, r3, C_SET_PR_BIT_MASK
   MTMSR  r3

; End of function
   BLR

; Implements REQ_[User Project Name]_BOOT-LLR_0XX
BOOT_RESET_CLEAR_MCSR:

   LIS   r3, MCSR_CLEAR_VALUE@ha
   ADDI  r3, r3, MCSR_CLEAR_VALUE@l
   MTSPR REG_MCSR, r3

; End of function
   BLR
