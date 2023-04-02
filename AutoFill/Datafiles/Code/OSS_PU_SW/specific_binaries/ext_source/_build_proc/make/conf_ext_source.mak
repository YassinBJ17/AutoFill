# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Configuration for ext_source makefile
# ----------------------------------------------------------------------------------------------------------------------

# Source directory
EXT_SOURCE_SRCDIR = R:/specific_binaries/ext_source/source

# Object directory
EXT_SOURCE_OBJDIR	= R:/specific_binaries/ext_source/_build_out/obj

# CFLAG options
CFLAG_EXT_SOURCE = R:/specific_binaries/ext_source/_build_proc/flag/cflag_ext_source.hjson

# Link options
LINK_SRCO_EXT_SOURCE = R:/specific_binaries/ext_source/_build_out/link/link_srco_ext_source.hjson

# Configuration to generate kmemory
CONF_TO_GEN_KMEM_SRCO_EXT_SOURCE = R:/specific_binaries/ext_source/_build_proc/conf_kmem/conf_to_gen_kmem_srco_ext_source.hjson

# Repository used to generate the psyko internal files
EXT_SOURCE_PSYKO_GENDIR = R:/specific_binaries/ext_source/_build_out/ast/psyko_temp
SRCO_EXT_SOURCE_GENDIR = R:/specific_binaries/ext_source/_build_out/ast/ext_source

# Binaries generated
SRCO_EXT_SOURCE_SRCO = R:/specific_binaries/ext_source/_build_out/gen/xt_source.srco
SRCO_EXT_SOURCE_ELF = R:/specific_binaries/ext_source/_build_out/gen/xt_source.elf