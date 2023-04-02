KRONO_SAFE_INSTALL_DIR ?= C:\Program Files (x86)\Krono-Safe
#CLI_VERSION ?= 8.13.1
CLI_VERSION ?= 9.5.0
PSYKO_VERSION ?= $(CLI_VERSION)
KSIM_VERSION ?= $(CLI_VERSION)
#RTK = C:\Program Files (x86)\Krono-Safe\rtk-power-qoriq-p1011-ganav-1.0.0
RTK = C:\Program Files (x86)\Krono-Safe\rtk-power-qoriq-p1011-ganav800-2.2.0
LINK_WITH_O = TRUE
PSYKO ?= $(KRONO_SAFE_INSTALL_DIR)\psyko-$(PSYKO_VERSION)\bin\psyko.exe
KSIM_DIR ?= $(KRONO_SAFE_INSTALL_DIR)\ksim-$(KSIM_VERSION)
PRODUCT ?= power-qoriq-p1011-ganav800
SRC_PATH = $(RTK)/$(PRODUCT)/sources/xt_source/linked
CSCI_SRC = source_xt_source
# `psyko` base command line
PSYKO_BASE_CMD = "$(PSYKO)" -p "$(PRODUCT)" -K "$(RTK)"
# INSPEKT
INSPEKT ?= $(KRONO_SAFE_INSTALL_DIR)\psyko-$(PSYKO_VERSION)\bin\inspekt.exe
INSPEKT_CMD = "$(INSPEKT)"
CREEK_CMD = "C:\Program Files (x86)\Krono-Safe\utilities-1.2.11\bin\creek.bat"
COMPILATION_REPORT = c:/temp/CompilationReport.html
DUMP := ddump
DUMP_OPT := -R -n .ExceptionTable,.flash_table_data,.text,.sdata,.sdata2,.rodata
d := -R -n .ExceptionTable,.flash_table_data,.text,.sdata,.sdata2,.rodata
OBJ_COPY := objcopy
OBJ_COPY_OPT := -I elf32-big -O binary
# Generated Files
BUILD_DIR = ../../$(PROJECT)_gen/astgen/gen
GEN_DIR = ../../$(PROJECT)_gen/astgen/build
LOADS_DIR = ../../$(PROJECT)_gen/loads
INSPEKT_APP_MEMORY = ../../$(PROJECT)_gen/astgen/gen/memory
INSPEKT_APP_CONFIG = ../../$(PROJECT)_gen/astgen/gen/config
CURRENT_DIR = $(shell pwd)
COMPILATION_REPORT = $(CURRENT_DIR)/$(BUILD_DIR)/CompilationReport.html

create_dir_elf:
	$(shell mkdir -p $(GEN_DIR))
	$(shell mkdir -p $(BUILD_DIR))
create_dir_lup:
	$(shell mkdir -p $(LOADS_DIR))


PARTOS := $(foreach f, $(CSCI_PARTITIONS), ../../$(f)_gen/astgen/gen/$(f).parto)
EMO := $(foreach f, $(CSCI_ERR), ../../$(f)_gen/astgen/gen/$(f).emo)
SRCO := "$(SRC_PATH)/$(CSCI_SRC).srco"
BUDGETS := $(foreach f, $(CSCI_PARTITIONS), ../../$(PROJECT)_dev/APP/budgets/$(f)_Budgets.bgt)

OUTPUT_EXE = $(BUILD_DIR)/$(PARTITION).elf
OUTPUT_APP = $(BUILD_DIR)/$(PARTITION).app
OUTPUT_APP_LUP = $(LOADS_DIR)/$(PARTITION).lup

elf : $(OUTPUT_EXE) $(OUTPUT_APP)


#compute the .LUP for asterios provided elf	
$(LOADS_DIR)/k2.LUP: 
	$(DUMP) -R -u -y 0x10000 -o $@ "$(RTK)/$(PRODUCT)/bin/k2.elf"
	@echo "Modification of the RTK BOOT Configuration Structure for K2.LUP"
	@echo "BOOT structure is at adress 0x2003a000"
	cp $@ $@.UNMODIFIED
	python $(PYTHON_BOOT_SCRIPT) $@
$(LOADS_DIR)/$(CSCI_SRC).LUP:  
	$(OBJ_COPY) $(OBJ_COPY_OPT) "$(SRC_PATH)/$(CSCI_SRC).elf" $@
lup : $(LOADS_DIR)/k2.LUP $(LOADS_DIR)/$(CSCI_SRC).LUP $(OUTPUT_APP_LUP)
$(OUTPUT_APP_LUP) :$(OUTPUT_EXE)
	$(OBJ_COPY) $(OBJ_COPY_OPT) $< $@
	

#####################################################################
# Build the final binary from the .partos, .emo and .srco
#####################################################################
$(OUTPUT_EXE) $(OUTPUT_APP): $(PARTOS) $(EMO) $(KMEMORY) $(LINKAPP) $(BUDGETS) $(APPLICATION_POS)
	$(PSYKO_BASE_CMD) gen-mem-conf --target app  --gendir $(GEN_DIR)/APP --output memoryAPP.json  -- $(PARTOS)  $(APPLICATION_POS) $(LINKAPP) $(BUDGETS) $(KMEMORY) $(EMO) $(SRCO)
	python $(PYTHON_MODIFICATION_SCRIPT)
	$(PSYKO_BASE_CMD) app --gui --gendir $(GEN_DIR)/APP --binary-output $(OUTPUT_EXE) --app-output $(OUTPUT_APP) --overwrite-memory-configuration  memoryAPP_mod.json -- $(PARTOS)  $(APPLICATION) $(LINKAPP) $(BUDGETS) $(KMEMORY) $(EMO) $(SRCO)
	mv ./MappingErrorsApp.map $(BUILD_DIR)
	mv ./MappingApp.map $(BUILD_DIR)
	mv ./memoryAPP.json $(BUILD_DIR)
	mv ./memoryAPP_mod.json $(BUILD_DIR)
	$(INSPEKT_CMD) memory $(OUTPUT_APP) $(INSPEKT_APP_MEMORY) --force
	$(INSPEKT_CMD) config $(OUTPUT_APP) $(INSPEKT_APP_CONFIG) --force    
	$(INSPEKT_CMD) uid $(OUTPUT_APP)
	$(INSPEKT_CMD) uid $(OUTPUT_EXE)
	$(INSPEKT_CMD) psy-ids $(OUTPUT_APP) $(BUILD_DIR)/AppRepport.json
	$(PSYKO_BASE_CMD) check-memory $(OUTPUT_APP)
	cp "$(SRC_PATH)/$(CSCI_SRC).elf" $(BUILD_DIR)
	cp "$(RTK)/$(PRODUCT)/bin/k2.elf" $(BUILD_DIR)
	
	
clean_elf:
	@echo "elf deletion made twice since it sometimes fails"
	$(RM) -rf $(BUILD_DIR)
	$(RM) -rf $(GEN_DIR)
	$(RM) -rf $(BUILD_DIR)
	$(RM) -rf $(GEN_DIR)

clean_lup:
	@echo "lup deletion made twice since it sometimes fails"
	$(RM) -rf $(LOADS_DIR)
	$(RM) -rf $(LOADS_DIR)
#####################################################################
.PHONY: all link clean_elf create_dir_elf create_dir_lup elf clean_lup all_elf all_lup clean_all
all_elf : clean_elf create_dir_elf elf
all_lup : clean_lup create_dir_lup lup
clean_all : clean_elf clean_lup
all: clean_elf clean_lup create_dir_lup create_dir_elf elf lup