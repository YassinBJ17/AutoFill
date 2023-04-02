# ----------------------------------------------------------------------------------------------------------------------
#                                             SAFRAN Electronics & Defense
#                                        Reproduction and disclosure forbidden.
# ----------------------------------------------------------------------------------------------------------------------
# DESCRIPTION : Specific sub-makefile to display warnings for any target
# ----------------------------------------------------------------------------------------------------------------------

# Execute the standard target $(MAIN_TGT) and store output in general log file, then display warnings to user :
$(MAIN_TGT)_with_warnings:   SUB_TGT := $(MAIN_TGT)
$(MAIN_TGT)_with_warnings:
	@mkdir -p $(DIR_LOG)
	@attrib -R $(LOG) > NUL
	$(MAKE) $(SUB_TGT) 2>&1 | tee $(LOG)
	@echo " "
	@echo "============================================================================================================="
	@echo "                                             Warning(s) summary:                                             "
	@echo "============================================================================================================="
	@echo "anything" | { grep ": warning" $(LOG) || true; }
	@echo " "
	@echo "============================================================================================================="
