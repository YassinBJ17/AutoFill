# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Makefile for error_handler directory
# ----------------------------------------------------------------------------------------------------------------------

# List .o files to compile and their location
ERROR_HANDLER_C_OBJ = $(subst .c,.o,$(subst $(ERROR_HANDLER_SRCDIR),$(ERROR_HANDLER_OBJDIR),$(wildcard $(ERROR_HANDLER_SRCDIR)/*.c \
									$(ERROR_HANDLER_SRCDIR)/**/*.c $(ERROR_HANDLER_SRCDIR)/**/**/*.c)))

# List .h / .psyh and their location
ERROR_HANDLER_H = $(wildcard $(ERROR_HANDLER_SRCDIR)/*.h $(ERROR_HANDLER_SRCDIR)/**/*.h $(ERROR_HANDLER_SRCDIR)/**/**/*.h)

# .o compiling
$(ERROR_HANDLER_C_OBJ): $(ERROR_HANDLER_OBJDIR)/%.o:$(ERROR_HANDLER_SRCDIR)/%.c $(ERROR_HANDLER_H)
	@R:/tools/deltree/deltree.bat $(ERROR_HANDLER_PSYKO_GENDIR)
	$(PSYKO) --gendir $(ERROR_HANDLER_PSYKO_GENDIR) cc --output $@ -- $< $(CFLAG_ERROR_HANDLER)

# Generate link options
$(LINK_EMO_ERROR_HANDLER):
	@mkdir -p $(@D)
	@echo {\"link_options\":{\"ldflags\":[\"-@O=R:/specific_binaries/error_handler/_build_out/gen/emo_error_handler.map\"\, \"-@E=R:/specific_binaries/error_handler/_build_out/gen/emo_error_handler_err.map\"]}} > $@

# Generate partition
$(EMO_ERROR_HANDLER_EMO) : $(ERROR_HANDLER_C_OBJ) $(CONF_TO_GEN_KMEM_EMO_ERROR_HANDLER) $(LINK_EMO_ERROR_HANDLER)
	@R:/tools/deltree/deltree.bat $(EMO_ERROR_HANDLER_GENDIR)
	$(PSYKO) em --output $@ --gendir $(EMO_ERROR_HANDLER_GENDIR) --binary-output $(EMO_ERROR_HANDLER_ELF) -- $^

eh: $(EMO_ERROR_HANDLER_EMO)

my_objdump_eh:
	@R:/tools/my_objdump/my_objdump.bat $(EMO_ERROR_HANDLER_ELF) StartAddr

clean_eh:
	@R:/tools/deltree/deltree.bat R:/specific_binaries/error_handler/_build_out/ast
	@R:/tools/deltree/deltree.bat R:/specific_binaries/error_handler/_build_out/gen
	@R:/tools/deltree/deltree.bat R:/specific_binaries/error_handler/_build_out/link
	@R:/tools/deltree/deltree.bat R:/specific_binaries/error_handler/_build_out/obj