#/***********************************************************************************************************************
#*
#*                                                Sagem Defense Securite
#*                                                     SAFRAN Group
#*
#* _BEGIN_FILE_HEADER --------------------------------------------------------------------------------------------------
#*
#* File name  : LIB_MATH_D_LogShift64.s
#* CSC name   : LIB_MATH
#* 
#* Description: This file contains implementation of left and right 64 bits data shift
#*
#* Configuration management identification:
#*    %full_name: sknNEXT#1/ascii/LIBBSP_MATH_LogShift64.s/1 %
#*    Creation  : gt077945 on Fri May 27 08:55:13 2011
#*
#* _END_FILE_HEADER ----------------------------------------------------------------------------------------------------
#*
#* LANGUAGE: ASM - Source file
#*
#* ---------------------------------------------------------------------------------------------------------------------
#* Copyright (c) 2009,2010,2011 SAGEM DS
#* SAGEM Defense Securite document. Reproduction and disclosure forbidden.
#**********************************************************************************************************************/
 

#/* _BEGIN_INCLUDE ========================================== INCLUDE FILES ========================================== */

#/* _END_INCLUDE ===================================================================================================== */

#/* _BEGIN_EXTERN_FUNCTION ========EXTERN FUNCTIONS DEFINITIONS ============ */
 
    .text
    .global __lsr64
    .global __lsl64    
    
#/* _BEGIN_FUNCTION_HEADER ------------------------------------------------------------------------------------------  */
#/*                                                                                                                    */
#/* <<LLR:  >>                                                                                                         */
#/*                                                                                                                    */
#/* <<FUNCTION:  >> __lsl64                                                                                            */
#/*                                                                                                                    */
#/* <<BRIEF:  >> Shift 64 bits data to left.                                                                           */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  Function that shift a 64 bits data to left                                                     */
#/*                                                                                                                    */
#/* <<RETURNED TYPE:  >> tUInt64 or tInt64                                                                             */
#/*                                                                                                                    */
#/* <<PARAMETERS:  >> r5 : shift to apply (tUInt32)                                                                    */
#/*                   r3/r4 : data to shift  (tUInt64 or tInt64)                                                       */
#/*                                                                                                                    */
#/* <<GLOBALS Inputs:  >> None                                                                                         */
#/*                                                                                                                    */
#/* <<GLOBALS Outputs:  >> None                                                                                        */
#/*                                                                                                                    */
#/* <<CALLS:  >> None                                                                                                  */
#/*                                                                                                                    */
#/* <<PRECONDITIONS:  >> None                                                                                          */
#/*                                                                                                                    */
#/*                                                                                                                    */
#/* _END_FUNCTION_HEADER --------------------------------------------------------------------------------------------  */
__lsl64:
# /* Compare shift with 31 */
    cmpwi r5,31
# /* Store high part of data */    
    mr r7,r3
# /* Store low part of data */    
    mr r8,r4
# /* if shift is greater than 31 goto label lsl64_sup31 */   
    bgt lsl64_sup31
# /* else compare shift with 0 */    
    cmpwi r5,0
# /* if shift is positive, i.e. greater than 0 then goto label lsl64_positive */
    bgt lsl64_positive
# /* else shift is negativ then goto end */    
    b lsl64_end
lsl64_positive:
# /* shift is positive or equal to 31*/
# /* compute relative shift by substracting input shift to 32 */
    subfic r10,r5,32
# /* shift right low part of data with relative shift */
    srw r3,r4,r10
# /* shift left high part of data with input shift */
    slw r12,r7,r5
# /* compute new high part with shifted low part and shifted high part*/
    or r4,r3,r12
# /* shift left low part with input shift */    
    slw r6,r8,r5
# /* go to finalization of 64 bits data left shift */
    b lsl64_finalize
lsl64_sup31:
# /* shift is greater than 31 */
# /* compute relative shift by substracting input shift to 32 */
    subi r11,r5,32
# /* shift left low part with computed shift for new high part */
    slw r4,r4,r11
# /* load 0 for new low part */    
    li r6,0
lsl64_finalize:
# /* compute high part with sign extension */
    rotlwi r11,r4,0
# /* load 0 for low part computation */    
    li r12,0
# /* compute return value for low part */
    or r4,r12,r6
# /* store return value for high part */
    mr r3,r11
lsl64_end:
# /* end of function */
    blr
    
#/* _BEGIN_FUNCTION_HEADER ------------------------------------------------------------------------------------------  */
#/*                                                                                                                    */
#/* <<LLR:  >>                                                                                                         */
#/*                                                                                                                    */
#/* <<FUNCTION:  >> __lsr64                                                                                            */
#/*                                                                                                                    */
#/* <<BRIEF:  >> Shift 64 bits data to right.                                                                          */
#/*                                                                                                                    */
#/* <<DESCRIPTION:  >>  Function that shift a 64 bits data to right                                                    */
#/*                                                                                                                    */
#/* <<RETURNED TYPE:  >> tUInt64                                                                                       */
#/*                                                                                                                    */
#/* <<PARAMETERS:  >> r5 : shift to apply (tUInt32)                                                                    */
#/*                   r3/r4 : data to shift  (tUInt64)                                                                 */
#/*                                                                                                                    */
#/* <<GLOBALS Inputs:  >> None                                                                                         */
#/*                                                                                                                    */
#/* <<GLOBALS Outputs:  >> None                                                                                        */
#/*                                                                                                                    */
#/* <<CALLS:  >> None                                                                                                  */
#/*                                                                                                                    */
#/* <<PRECONDITIONS:  >> None                                                                                          */
#/*                                                                                                                    */
#/*                                                                                                                    */
#/* _END_FUNCTION_HEADER --------------------------------------------------------------------------------------------  */
__lsr64:
# /* Compare shift with 31 */
    cmpwi   r5,31
# /* Store high part of data */    
    mr      r7,r3  
# /* if shift is greater than 31 goto label lsr64_sup31 */    
    bgt     lsr64_sup31
# /* else compare shift with 0 */    
    cmpwi   r5,0
# /* if shift is positive, i.e. greater than 0 then goto label lsr64_positive */
    bgt     lsr64_positive
# /* else shift is negativ then goto end */    
    b lsr64_end
lsr64_positive:
# /* shift is positive or equal to 31*/
# /* compute relative shift by substracting input shift to 32 */
    subfic r10,r5,32
# /* shift left high part of data with relative shift */
    slw r3,r3,r10
# /* shift right low part of data with input shift */
    srw r12,r4,r5
# /* compute new low part with shifted low part and shifted high part*/
    or  r6,r3,r12
# /* shift right high part with input shift */    
    srw r5,r7,r5
# /* go to finalization of 64 bits data right shift */
    b lsr64_finalize
lsr64_sup31:
# /* shift is greater than 31 */
# /* compute relative shift by substracting input shift to 32 */
    subi r11,r5,32
# /* shift right high part with computed shift for new low part */
    srw  r6,r3,r11
# /* load 0 for new high part */    
    li r5,0
lsr64_finalize:
# /* compute high part */
    rotlwi  r11,r5,0
# /* load 0 for low part computation */    
    li  r12,0
# /* compute return value for low part */
    or r4,r12,r6
# /* store return value for high part */
    mr r3,r11
lsr64_end:
# /* end of function */
    blr
    
    .end
    
#/* _END_EXTERN_FUNCTION ==================================================== */