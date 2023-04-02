# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Makefile for ext_source directory
# ----------------------------------------------------------------------------------------------------------------------

# List .o files to compile and their location
EXT_SOURCE_C_OBJ = $(subst .c,.o,$(subst $(EXT_SOURCE_SRCDIR),$(EXT_SOURCE_OBJDIR),$(wildcard $(EXT_SOURCE_SRCDIR)/*.c \
									$(EXT_SOURCE_SRCDIR)/**/*.c $(EXT_SOURCE_SRCDIR)/**/**/*.c)))

# List .h and their location
EXT_SOURCE_H = $(wildcard $(EXT_SOURCE_SRCDIR)/*.h $(EXT_SOURCE_SRCDIR)/**/*.h $(EXT_SOURCE_SRCDIR)/**/**/*.h)

# .o compiling
$(EXT_SOURCE_C_OBJ): $(EXT_SOURCE_OBJDIR)/%.o:$(EXT_SOURCE_SRCDIR)/%.c $(EXT_SOURCE_H)
	@R:/tools/deltree/deltree.bat $(PSYKO_GENDIR)
	$(PSYKO) --gendir $(PSYKO_GENDIR) cc --output $@ -- $< $(CFLAG_EXT_SOURCE)

# Generate link options
$(LINK_SRCO_EXT_SOURCE):
	@mkdir -p $(@D)
	@echo {\"link_options\":{\"ldflags\":[\"-@O=R:/specific_binaries/ext_source/_build_out/gen/srco_ext_source.map\"\, \"-@E=R:/specific_binaries/ext_source/_build_out/gen/srco_ext_source_err.map\"]}} > $@

# Generate partition
$(SRCO_EXT_SOURCE_SRCO) : $(EXT_SOURCE_C_OBJ) $(CONF_TO_GEN_KMEM_SRCO_EXT_SOURCE) $(LINK_SRCO_EXT_SOURCE)
	@R:/tools/deltree/deltree.bat $(SRCO_EXT_SOURCE_GENDIR)
	$(PSYKO) source --output $@ --gendir $(SRCO_EXT_SOURCE_GENDIR) --binary-output $(SRCO_EXT_SOURCE_ELF) -- $^

ext_src: $(SRCO_EXT_SOURCE_SRCO)

my_objdump_ext_src:
	@R:/tools/my_objdump/my_objdump.bat $(SRCO_EXT_SOURCE_ELF) StartAddr

clean_ext_src:
	@R:/tools/deltree/deltree.bat R:/specific_binaries/ext_source/_build_out/ast
	@R:/tools/deltree/deltree.bat R:/specific_binaries/ext_source/_build_out/gen
	@R:/tools/deltree/deltree.bat R:/specific_binaries/ext_source/_build_out/link
	@R:/tools/deltree/deltree.bat R:/specific_binaries/ext_source/_build_out/obj