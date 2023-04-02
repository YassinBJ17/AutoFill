#/* --------------------------------------------------------------------------
# *                        SAFRAN Electronics & Defense
# *                   Reproduction and disclosure forbidden.
# * --------------------------------------------------------------------------
# * DESCRIPTION : Performs a initialization of a memory area
# * -------------------------------------------------------------------------- */

#/* ---------- include required interface: ----------------------------------- */

#/* ---------- internal define constants: ------------------------------------ */

#/* ---------- internal types: ----------------------------------------------- */

#/* ---------- internal operations: ------------------------------------------ */

#/* ---------- internal constants: ------------------------------------------- */

#/* ---------- internal data: ------------------------------------------------ */

#/* ---------- provided operation bodies: ------------------------------------ */
    
#/*   
#void LIB_MEM_SET32( int8_t  const * buffer_pt,
#                          int32_t  const init_value,
#                          int32_t const length )
#*/

   .text
   .global LIB_MEM_SET32
#   .type   LIB_MEM_SET32, %function
   .align 4

#/* */
LIB_MEM_SET32:
#save in stack the register used for the stmw
	stwu  r31,-4(r1)
   stwu  r30,-4(r1)
   stwu  r29,-4(r1)
   stwu  r28,-4(r1)
   stwu  r27,-4(r1)
   stwu  r26,-4(r1)
   stwu  r25,-4(r1)
   stwu  r24,-4(r1)

# default value for the register used in multiword 
   mr   r24, r4
   mr   r25, r4
   mr   r26, r4
   mr   r27, r4
   mr   r28, r4
   mr   r29, r4
   mr   r30, r4
   mr   r31, r4

# The use "stmw" permits reduce significantly the execution time of the loop
# by doing burst writes on memory bus.
 
   mtctr    r5     # write the loop counter into counter register

# performing the loop writting
loop_int:
   stmw    r24, 0x0(r3)
   addi    r3, r3, 32
   bdnz    loop_int

# restore the r24 to r31 register
   lwz   r24,0(r1)
   addi  r1,r1,4
   lwz   r25,0(r1)
   addi  r1,r1,4
   lwz   r26,0(r1)
   addi  r1,r1,4
   lwz   r27,0(r1)
   addi  r1,r1,4
   lwz   r28,0(r1)
   addi  r1,r1,4
   lwz   r29,0(r1)
   addi  r1,r1,4
   lwz   r30,0(r1)
   addi  r1,r1,4
   lwz   r31,0(r1)
   addi  r1,r1,4
  
   blr

   .end



