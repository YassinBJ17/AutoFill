;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION : This function write a new MPU entry
;
; --------------------------------------------------------------------------


; ---------- include required interface: -----------------------------------


; ---------- internal define constants: ------------------------------------
; none

; ---------- provided datas: -------------------------------------------
; none


;----------------------------------------------------------------------------
;  C PROTOTYPE :
;-----------------
;  void BOOT_MEM_MPU_WRITE_ENTRY ( uint32_t const p_mas0,
;                                      uint32_t const p_mas1,
;                                      uint32_t const p_mas2,
;                                      uint32_t const p_mas3
;                                    );
;

;  STACK USAGE :
; -----------------
;   TBC
;

;  REGISTER USAGE :
; -----------------
;  none

   .file  "BOOT_MEM_MPU_WRITE_ENTRY_code.s"
   .globl BOOT_MEM_MPU_WRITE_ENTRY
   .align 4

   ;    Identifier of the MAS0 special purpose register
   .set     REG_MAS0            ,624

;    Identifier for the MAS1 special purpose register
   .set     REG_MAS1            ,625

;    Identifier for the MAS2 special purposee register
   .set     REG_MAS2            ,626

;    Identifier for the MAS3 special purpose register
   .set     REG_MAS3            ,627

; Implements REQ_[User Project Name]_BOOT-LLR_0XX
BOOT_MEM_MPU_WRITE_ENTRY:

   MTSPR REG_MAS0, r3
   MTSPR REG_MAS1, r4
   MTSPR REG_MAS2, r5
   MTSPR REG_MAS3, r6
   MPUWE
   MPUSYNC

; End of function
   BLR
