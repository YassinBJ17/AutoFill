; HID0 init value, enable timer base
.set     C_HID0_INIT_VALUE     ,0x00004000

; Hardware Implementation Dependent registers
.set    REG_HID0    ,1008
.set    REG_HID1    ,1009

; Branch Unit Control and Status Register
.set    REG_BUCSR   ,1013

; MMU Assist registers
.set    REG_MAS0        ,624
.set    REG_MAS1        ,625
.set    REG_MAS2        ,626
.set    REG_MAS3        ,627
.set    REG_MAS4        ,628
.set    REG_MAS6        ,630
.set    REG_MAS7        ,944

#/* _END_CONSTANT ==================================================================================================== */

#/* _BEGIN_MACRO ================================================ MACROS ============================================= */

#/*=================================================================================================================== */
#/*                                                        MSR                                                         */
#/*=================================================================================================================== */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000022                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  REG_MSR_WRITE                                                                                     */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function writes a new MSR value. The MSR register is writeable only in supervisor mode. I */
#/* t is a macro function in assembly language.                                                                        */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
REG_MSR_WRITE: .macro v_reg1
	sync
	mtmsr    v_reg1
	sync
	isync
	.endm

#/*End of REG_MSR_WRITE*/

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000021                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  REG_DTLB_LOAD                                                                                     */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  This function loads a PTE into a DTLB register by using the "tlbld" instruction that loads the */
#/*  data TLB entry from DCMP and RPA registers value. The register in parameter contains the value of the effective a */
#/* ddress of the TLB entry. It is a macro function in assembly language.                                              */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
REG_TLB_LOAD: .macro
	sync
	tlbwe
	isync

	.endm
#/*End of REG_DTLB_LOAD*/

#/* _END_MACRO ======================================================================================================= */
