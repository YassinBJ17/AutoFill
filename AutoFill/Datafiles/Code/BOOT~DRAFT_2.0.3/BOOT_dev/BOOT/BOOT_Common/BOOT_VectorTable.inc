#/***********************************************************************************************************************
#*
#*                                                Safran Electronics & Defense
#*                                                     SAFRAN Group
#*
#* _BEGIN_FILE_HEADER --------------------------------------------------------------------------------------------------
#*
#* File name  : RLB_RBI_VectorTable.P2020.inc
#* CSC name   :
#* 
#* Description: Vector Table CSU header file.
#*
#* Configuration management identification:
#*    %full_name:  sknNEXT#1/ascii/BOOT_VectorTable.inc/1 %
#*    Creation  :
#*
#* _END_FILE_HEADER ----------------------------------------------------------------------------------------------------
#*
#* LANGUAGE: ASM - Header file
#*
#* ---------------------------------------------------------------------------------------------------------------------
#* Copyright (c) 2017, SAFRAN E&D
#* SAFRAN Electronics & Defense document. Reproduction and disclosure forbidden.
#**********************************************************************************************************************/

#/* _BEGIN_STATIC_PROTO ==================================== FUNCTION PROTOTYPES ===================================== */
#/* _END_STATIC_PROTO ================================================================================================ */

   .extern  C_SRC_DLD_sram_s

#/* _BEGIN_CONSTANT ============================================ CONSTANTS =========================================== */

#/* Offset definition for Stack Context Storage organisation ( User Defined ) */
   .set     C_CR_OFFSET           ,0
   .set     C_XER_OFFSET          ,4
   .set     C_LR_OFFSET           ,8
   .set     C_CTR_OFFSET          ,12
   .set     C_SRR0_OFFSET         ,16
   .set     C_SRR1_OFFSET         ,20
   .set     C_BSP_VECT_DEC_OFFSET ,24 #/* Also defined in BSP_export.h*/
   
   .set     C_R0_OFFSET           ,32
   .set     C_R0_OFFSET_LOW       ,36
   .set     C_R1_OFFSET           ,40
   .set     C_R1_OFFSET_LOW       ,44
   .set     C_R2_OFFSET           ,48
   .set     C_R2_OFFSET_LOW       ,52
   .set     C_R3_OFFSET           ,56
   .set     C_R3_OFFSET_LOW       ,60
   .set     C_R4_OFFSET           ,64
   .set     C_R4_OFFSET_LOW       ,68
   .set     C_R5_OFFSET           ,72
   .set     C_R5_OFFSET_LOW       ,76
   .set     C_R6_OFFSET           ,80
   .set     C_R6_OFFSET_LOW       ,84
   .set     C_R7_OFFSET           ,88
   .set     C_R7_OFFSET_LOW       ,92
   .set     C_R8_OFFSET           ,96
   .set     C_R8_OFFSET_LOW       ,100
   .set     C_R9_OFFSET           ,104
   .set     C_R9_OFFSET_LOW       ,108
   .set     C_R10_OFFSET          ,112
   .set     C_R10_OFFSET_LOW      ,116
   .set     C_R11_OFFSET          ,120
   .set     C_R11_OFFSET_LOW      ,124
   .set     C_R12_OFFSET          ,128
   .set     C_R12_OFFSET_LOW      ,132
   .set     C_R13_OFFSET          ,136
   .set     C_R13_OFFSET_LOW      ,140
   .set     C_R14_OFFSET          ,144
   .set     C_R14_OFFSET_LOW      ,148
   .set     C_R15_OFFSET          ,152
   .set     C_R15_OFFSET_LOW      ,156
   .set     C_R16_OFFSET          ,160
   .set     C_R16_OFFSET_LOW      ,164
   .set     C_R17_OFFSET          ,168
   .set     C_R17_OFFSET_LOW      ,172
   .set     C_R18_OFFSET          ,176
   .set     C_R18_OFFSET_LOW      ,180
   .set     C_R19_OFFSET          ,184
   .set     C_R19_OFFSET_LOW      ,188
   .set     C_R20_OFFSET          ,192
   .set     C_R20_OFFSET_LOW      ,196
   .set     C_R21_OFFSET          ,200
   .set     C_R21_OFFSET_LOW      ,204
   .set     C_R22_OFFSET          ,208
   .set     C_R22_OFFSET_LOW      ,212
   .set     C_R23_OFFSET          ,216
   .set     C_R23_OFFSET_LOW      ,220
   .set     C_R24_OFFSET          ,224
   .set     C_R24_OFFSET_LOW      ,228
   .set     C_R25_OFFSET          ,232
   .set     C_R25_OFFSET_LOW      ,236
   .set     C_R26_OFFSET          ,240
   .set     C_R26_OFFSET_LOW      ,244
   .set     C_R27_OFFSET          ,248
   .set     C_R27_OFFSET_LOW      ,252
   .set     C_R28_OFFSET          ,256
   .set     C_R28_OFFSET_LOW      ,260
   .set     C_R29_OFFSET          ,264
   .set     C_R29_OFFSET_LOW      ,268
   .set     C_R30_OFFSET          ,272
   .set     C_R30_OFFSET_LOW      ,276
   .set     C_R31_OFFSET          ,280
   .set     C_R31_OFFSET_LOW      ,284
   
   .set     C_SPEFSCR_OFFSET      ,288

   .set     C_BSP_VECT_EOT_OFFSET ,416 #

   #/* Size of memory to allocate on top of process stack to store context */
   .set     C_BSP_VECT_CONTEXT_SIZE  ,512  #
   
   #/* Size of LR register and back chaine words to respect EABI implementation in process stack. */
   .set     C_BSP_VECT_EABI_REG_SIZE ,8

   #/* HID0 init value, enable timer base */
   .set     C_HID0_INIT_VALUE     ,0x00004000

   #/* BOOT MSR first configuration. Set SPE, ME and DE bits */
   .set     C_MSR_BOOT_CONFIG      ,0x02001200

   #/* Process MSR configuration. Set SPE, PR, EE, ME, DE, IS and DS bits. */
   .set     C_MSR_PROCESS_CONFIG  ,0x0200D230

   #/* Error Codes */
   .set     C_MCHECK_ERROR_CODE   ,0x00000002 #/* Machine Check error code. */
   .set     C_DAE_ERROR_CODE      ,0x00000003 #/* Data access error code. */
   .set     C_IAE_ERROR_CODE      ,0x00000004 #/* Instruction access error code. */
   .set     C_ALIGN_ERROR_CODE    ,0x00000006 #/* Alignement error code. */
   .set     C_PROG_ERROR_CODE     ,0x00000007 #/* Program error code. */   
   .set     C_FPU_ERROR_CODE      ,0x00000008 #/* Floating point unavailable error code. */
   .set     C_CRITICAL_ERROR_CODE ,0x0000000A #/* Critical interrupt error code. */
   .set     C_IMISS_ERROR_CODE    ,0x00000010 #/* Instruction TLB miss error code. */
   .set     C_DMISS_ERROR_CODE    ,0x00000011 #/* Data TLB miss error code. */
   .set     C_DEBUG_ERROR_CODE    ,0x00000013 #/* Debug error code. */
   .set     C_SYSM_ERROR_CODE     ,0x00000014 #/* System management error code. */
   .set     C_TIMER_ERROR_CODE    ,0x00000016 #/* Unexpected timer IT error code. */
   .set     C_SPE_ERROR_CODE      ,0x00000018 #/* SPE Unvailable error code. */
   .set     C_FP_ERROR_CODE       ,0x00000019 #/* SPE error, error code. */
   .set     C_PERF_MON_ERROR_CODE ,0x00000020 #/* Performance monitor error code. */

#/* _END_CONSTANT ==================================================================================================== */

#/* BEGIN FUNCTION HEADER--------------------------------------------------------------------------------------------- */
#/* <<LLR:  >>  SDD_DMS_LLR_REQ_0000150                                                                                */
#/*                                                                                                                    */
#/* <<FUNCTION:  >>  ERROR_IT                                                                                          */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  It is the generic error interrupt handler. It handles errors and POST that use interrupts. Thi */
#/* s is an assembly macro function.                                                                                   */
#/*                                                                                                                    */
#/* END FUNCTION HEADER----------------------------------------------------------------------------------------------- */
ERROR_IT: .macro v_Error

    #/* Save LR in SPRG3 */
    mflr     r3
    mtsprg3  r3

    #/* Restores stack */
    lwz      r1,  0 (r1)

    #/* Sets error code */
    lis      r3,       v_Error@ha
    addi     r3,  r3,  v_Error@l

    #/* Calls error handler function */
    bl      BSP_VECT_ErrorIt

    #/* The following code is executed only in case of POST */

    #/* Restore original LR value in SRR0 */
    #/* Return of IT (rfi) will act "as" return of POST function (blr) */
    mfsprg3  r3
    mtsrr0   r3
    
   .endm
#/*End of ERROR_IT */
