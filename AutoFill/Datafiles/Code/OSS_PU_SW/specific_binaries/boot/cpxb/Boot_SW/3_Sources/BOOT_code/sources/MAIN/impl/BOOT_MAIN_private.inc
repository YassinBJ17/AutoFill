;-------------------------------------------------------------------------------
;                        SAFRAN Electronics & Defense
;                   Reproduction and disclosure forbidden.
;-------------------------------------------------------------------------------
; DESCRIPTION  :
; --------------------------------------------------------------------------

; ---------- include required interface: -----------------------------------
; none



; ---------- provided constant: ------------------------------------------------

; Address where to write the address of the ASTEKCONF.
   .set RSF_ADDR, 0x40000100

; Address where to write the value of the FPGA RTC period required by ASTERIOS kernel.
   .set RTC_FPGA_PERIOD_ADDR, 0x40002000

; Address where to write the value of FPGA RTC timeout required by ASTERIOS kernel.
   .set RTC_FPGA_TIMEOUT_ADDR, 0x40003000

; ---------- provided operation: -------------------------------------------
; none
