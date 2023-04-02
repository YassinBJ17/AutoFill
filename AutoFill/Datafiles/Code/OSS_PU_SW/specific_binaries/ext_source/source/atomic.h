/************ Copyright Krono-Safe S.A. 2019, All rights reserved ************/

/**
 * @file        atomic.h
 * @brief       Atomic operations
 * @copyright   Copyright Krono-Safe S.A. 2019, All rights reserved.
 */

#ifndef AST_HELPERS_ATOMIC_H_
# define AST_HELPERS_ATOMIC_H_

# include <kcompiler.h>
# include <kstdint_private.h>

/**
 * Atomically load an t_ast_uint32.
 *
 * @param address   Address in memory to be loaded
 * @return The value read.
 */
asm volatile t_ast_uint32 atomic_load_uint32(const volatile t_ast_uint32* address)
{
% reg address
!
  sync
  lwz r3, 0(address)
}

/**
 * Atomically store an t_ast_uint32.
 *
 * @param address   Storage address in memory
 * @param value     Value to store
 *
 */
asm volatile void atomic_store_uint32(volatile t_ast_uint32* address, t_ast_uint32 value)
{
% reg address; reg value
!
  stw value, 0(address)
  sync
}


/**
 * Issue a hardware and software read memory barrier.
 */
# define atomic_load_fence() asm volatile ("sync")

/**
 * Issue a hardware and software store memory barrier.
 */
# define atomic_store_fence() asm volatile ("sync")


/**
 * @brief Data cache flush operation
 *
 * Flush *one* cache line, the caller may need to call this
 * several times to flush a whole block.
 * Flush = Writeback (if and only if modified) then Invalidate
 *
 * @param addr The address of the line to invalidate
 */
asm volatile void data_cache_flush(const t_ast_uint32* addr)
{
% reg addr
!
  dcbf 0, addr     ## Data Cache Block Flush
}

#endif /* !AST_HELPERS_ATOMIC_H_ */
