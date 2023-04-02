 ;-------------------------------------------------------------------------------
 ;                        SAFRAN Electronics & Defense
 ;                   Reproduction and disclosure forbidden.
 ;-------------------------------------------------------------------------------
 ; DESCRIPTION : This function write the value given in parameter
 ;               in the MPUCSR0 register.
 ; --------------------------------------------------------------------------


; ---------- include required interface: -----------------------------------


; ---------- internal define constants: ------------------------------------
; none

; ---------- provided datas: -------------------------------------------
; none


;----------------------------------------------------------------------------
;  C PROTOTYPE :
;-----------------
;  void BOOT_MEM_CMPU_CONFIG( te_BOOT_MPU_CONFIG_VAL const p_value)
;

;  STACK USAGE :
; -----------------
;   TBC
;

;  REGISTER USAGE :
; -----------------
;  none

   .file  "BOOT_MEM_CMPU_CONFIG_code.s"
   .globl BOOT_MEM_CMPU_CONFIG
   .align 4

;    Identifier of the MPU0CSR0 special purpose register
   .set     REG_MPU0CSR0        ,1014

; Implements REQ_[User Project Name]_BOOT-LLR_0XX
BOOT_MEM_CMPU_CONFIG:

   MTSPR REG_MPU0CSR0, r3
   MPUSYNC

; End of function
   BLR
