BASE_DIR := ../..

include $(BASE_DIR)/Makefile/MakefileVar.mk

SCI := RAMBOOT
GEN_DIR := $(BASE_DIR)/BOOT_gen/$(SCI)
CSC_DIRS := RAMBOOT_Common \
			RAMBOOT_CopyAndBootBoot_CBB \
			RAMBOOT_TestAndConfigureBasicHW_TCBHW \
			RAMBOOT_TestSelfIntegrity_TSI

LIBBSP_GEN_DIR := $(BASE_DIR)/LIBBSP_gen
LIBUTI_GEN_DIR := $(BASE_DIR)/LIBUTI_gen

SNT_SPI := ../createSPI.py

CONF_SPI := spi.ini
CONF_DLD := $(SCI).dld

export EXTRA_CFLAGS :=

CSC_A := $(foreach csd, $(CSC_DIRS), $(GEN_DIR)/$(csd)/lib/$(csd).a)

LD_A := $(LIBBSP_GEN_DIR)/LIBBSP_CMN/lib/LIBBSP_CMN.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_FNOR/lib/LIBBSP_FNOR.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_GPIO/lib/LIBBSP_GPIO.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_PLDCMP/lib/LIBBSP_PLDCMP.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_SHM/lib/LIBBSP_SHM.a \
		$(LIBBSP_GEN_DIR)/LIBBSP_SPI/lib/LIBBSP_SPI.a \
		$(LIBUTI_GEN_DIR)/SHA/lib/SHA.a \
		$(LIBUTI_GEN_DIR)/MEM/lib/MEM.a \
		$(LIBUTI_GEN_DIR)/COMMON/lib/COMMON.a

OUT_EXE := $(GEN_DIR)/$(SCI).elf
OUT_MAP := $(GEN_DIR)/$(SCI).map
OUT_LUP := $(GEN_DIR)/$(SCI).lup
OUT_S37 := $(GEN_DIR)/$(SCI).s37
OUT_SPI := $(GEN_DIR)/$(SCI).spi

all: $(OUT_LUP) $(OUT_SPI)

clean:
	@$(foreach csd, $(CSC_DIRS), ("$(MAKE)" -C $(csd) -I $(BASE_DIR) -f ../SubMakefile.mk clean);)
	rm -rf $(OUT_EXE)
	rm -rf $(OUT_MAP)
	rm -rf $(OUT_LUP)
	rm -rf $(OUT_S37)
	rm -rf $(OUT_SPI)

$(CSC_DIRS):
	@$(MAKE) -C $@ -I $(BASE_DIR) -f ../SubMakefile.mk all

$(OUT_EXE): $(CONF_DLD) $(CSC_DIRS)
	@echo Creation of the elf $@
	$(LD) $(LDFLAGS) $(CSC_A) $(LD_A) -o$@ "$<" -@O="$(OUT_MAP)"

$(OUT_S37): $(OUT_EXE)
	@echo Creation of the Motorola S-Record $@
	@$(DUMP) $(DD_ARG) -o $@ $^

$(OUT_LUP): $(OUT_S37)
	@echo Creation of the LUP File $@
	@$(LUP) $(LUP_ARG) $^ $@

$(OUT_SPI): $(CONF_SPI)
	@echo Creation of the SPI Config File $@
	@py -3 $(SNT_SPI) -o $@ $^

.PHONY: all clean $(CSC_DIRS)
