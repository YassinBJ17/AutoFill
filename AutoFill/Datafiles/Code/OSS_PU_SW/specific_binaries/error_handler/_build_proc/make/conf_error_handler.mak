# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Configuration for error_handler makefile
# ----------------------------------------------------------------------------------------------------------------------

# Source directory
ERROR_HANDLER_SRCDIR = R:/specific_binaries/error_handler/source

# Object directory
ERROR_HANDLER_OBJDIR	= R:/specific_binaries/error_handler/_build_out/obj

# CFLAG options
CFLAG_ERROR_HANDLER = R:/specific_binaries/error_handler/_build_proc/flag/cflag_error_handler.hjson

# Link options
LINK_EMO_ERROR_HANDLER = R:/specific_binaries/error_handler/_build_out/link/link_emo_error_handler.hjson

# Configuration to generate kmemory
CONF_TO_GEN_KMEM_EMO_ERROR_HANDLER = R:/specific_binaries/error_handler/_build_proc/conf_kmem/conf_to_gen_kmem_emo_error_handler.hjson

# Repository used to generate the psyko internal files
ERROR_HANDLER_PSYKO_GENDIR = R:/specific_binaries/error_handler/_build_out/ast/psyko_temp
EMO_ERROR_HANDLER_GENDIR = R:/specific_binaries/error_handler/_build_out/ast/error_handler

# Binaries generated
EMO_ERROR_HANDLER_EMO = R:/specific_binaries/error_handler/_build_out/gen/emo_error_handler.emo
EMO_ERROR_HANDLER_ELF = R:/specific_binaries/error_handler/_build_out/gen/emo_error_handler.elf
