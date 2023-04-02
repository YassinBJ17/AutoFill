BASE_DIR := ../..

include $(BASE_DIR)/Makefile/MakefileVar.mk

SCI := ELBCBOOT
GEN_DIR := $(BASE_DIR)/BOOT_gen/$(SCI)
CSC_DIRS := ELBCBOOT_Common \
			ELBCBOOT_CopyAndBootRamBoot_CBRB \
			ELBCBOOT_ConfigureBasicHW_CBHW

CONF_DLD := $(SCI).dld

export EXTRA_CFLAGS :=

CSC_A := $(foreach csd, $(CSC_DIRS), $(GEN_DIR)/$(csd)/lib/$(csd).a)

OUT_EXE := $(GEN_DIR)/$(SCI).elf
OUT_MAP := $(GEN_DIR)/$(SCI).map
OUT_LUP := $(GEN_DIR)/$(SCI).lup
OUT_S37 := $(GEN_DIR)/$(SCI).s37

all: $(OUT_LUP)

clean:
	@$(foreach csd, $(CSC_DIRS), ("$(MAKE)" -C $(csd) -I $(BASE_DIR) -f ../SubMakefile.mk clean);)
	rm -rf $(OUT_EXE)
	rm -rf $(OUT_MAP)
	rm -rf $(OUT_LUP)
	rm -rf $(OUT_S37)

$(CSC_DIRS):
	@$(MAKE) -C $@ -I $(BASE_DIR) -f ../SubMakefile.mk all

$(OUT_EXE): $(CONF_DLD) $(CSC_DIRS)
	@echo Creation of the elf $@
	$(LD) $(LDFLAGS) $(CSC_A) -o$@ "$<" -@O="$(OUT_MAP)"

$(OUT_S37): $(OUT_EXE)
	@echo Creation of the Motorola S-Record $@
	@$(DUMP) $(DD_ARG) -o $@ $^

$(OUT_LUP): $(OUT_S37)
	@echo Creation of the LUP File $@
	@$(LUP) $(LUP_ARG) $^ $@

.PHONY: all clean $(CSC_DIRS)
