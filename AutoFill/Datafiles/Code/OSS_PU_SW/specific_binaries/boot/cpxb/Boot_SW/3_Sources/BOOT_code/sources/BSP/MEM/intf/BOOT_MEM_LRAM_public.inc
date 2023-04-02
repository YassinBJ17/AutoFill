;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION  : 
;---------------------------------------------------------------------------
;
;
; ---------- include required interface: -----------------------------------
; none
;
; ---------- provided macro: -----------------------------------------------
; none
;
; ---------- provided constant: ------------------------------------------------

;    Identifier for the Local Data memory special purposee register
   .set     REG_DMEMCFG0        ,694
;    Identifier for the local instruction memory special purpose register
   .set     REG_IMEMCFG0        ,695
;    Identifier DMEM Control Register 0 (DMEMCTL0)
   .set     REG_DMEMCTL0        ,496
;    Identifier IMEM Control Register 0 (IMEMCTL0)
   .set     REG_IMEMCTL0        ,497
;    Identifier DMEM Control Register 1 (DMEMCTL1)
   .set     REG_DMEMCTL1        ,498
;    Identifier IMEM Control Register 1 (IMEMCTL1)
   .set     REG_IMEMCTL1        ,499

; Configuration of DMEMCTL0: Disable ECC
   .set     REG_DMEMCFG0_MASK_VALUE, 0xFFFFF000
   .set     REG_DMEMCTL0_INIT_VALUE, 0x00000000
   .set     REG_DMEMCTL1_INIT_VALUE, 0x00000000

; Configuration of IMEMCTL0: Disable ECC
   .set     REG_IMEMCFG0_MASK_VALUE, 0xFFFFF000
   .set     REG_IMEMCTL0_INIT_VALUE, 0x00000000
   .set     REG_IMEMCTL1_INIT_VALUE, 0x00000000


; ---------- provided operation: -------------------------------------------
; none
