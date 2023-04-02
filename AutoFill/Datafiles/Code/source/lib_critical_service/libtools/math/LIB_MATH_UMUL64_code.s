###
### Unsigned 64 bit multiplication function
### This function should be called from C code instead of directly using `*` operator,
### because Diab compiler wrongly encodes unsigned 64 bits multiplication.
### See TCDIAB-17794 erratum.
###
### Parameters :
### r3: Most Significant Bits of operand a
### r4: Least Significant Bits of operand a
### r5: Most Significant Bits of operand b
### r6: Least Significant Bits of operand b
###
### Returns:
### r3: Most Significant Bits of the resulting product value a * b
### r4: Least Significant Bits of the resulting product value a * b
   .text_vle
   .global lib_math_umul64

   .align 4

lib_math_umul64:

# r0 = x0 × y1
   mullw    r0, r5, r4

# r3 = x1 × y0
   se_mullw r3, r6

# r3 = r3 + r0 =>MSB_z
   se_add   r3, r0

# à ce stade on vient de réaliser (x0 × y1 + x1 × y0)

# r0 = x0 × y0=> MSB_z inter
   mulhwu   r0, r4, r6

# r4 = x0 × y0=> LSB_z
   se_mullw r4, r6

# r3 = MSB_z + MSB_z_intern
   se_add   r3, r0

# return
   se_blr

   .end
