KRONO_SAFE_INSTALL_DIR ?= C:\Program Files (x86)\Krono-Safe
CLI_VERSION ?= 9.5.0
PSYKO_VERSION ?= $(CLI_VERSION)
KSIM_VERSION ?= $(CLI_VERSION)
RTK ?= C:\Program Files (x86)\Krono-Safe\rtk-power-qoriq-p1011-ganav800-2.2.0
LINK_WITH_O = TRUE
PSYKO ?= $(KRONO_SAFE_INSTALL_DIR)\psyko-$(PSYKO_VERSION)\bin\psyko.exe
KSIM_DIR ?= $(KRONO_SAFE_INSTALL_DIR)\ksim-$(KSIM_VERSION)
PRODUCT ?= power-qoriq-p1011-ganav800

# `psyko` base command line
PSYKO_BASE_CMD = "$(PSYKO)" -p "$(PRODUCT)" -K "$(RTK)"
# INSPEKT
INSPEKT ?= $(KRONO_SAFE_INSTALL_DIR)\psyko-$(PSYKO_VERSION)\bin\inspekt.exe
INSPEKT_CMD = "$(INSPEKT)"
CREEK_CMD = "C:\Program Files (x86)\Krono-Safe\utilities-1.2.11\bin\creek.bat"
COMPILATION_REPORT = c:/temp/CompilationReport.html
# Generated Files
BUILD_DIR = ../../$(PARTITION)_gen/astgen/gen
GEN_DIR = ../../$(PARTITION)_gen/astgen/build
CONF_DIR = ../../$(PARTITION)_gen/astgen/conf


CURRENT_DIR = $(shell pwd)
COMPILATION_REPORT = $(CURRENT_DIR)/$(BUILD_DIR)/CompilationReport.html


C_OBJ_BUILD_DIR = $(BUILD_DIR)/objects
MODULES_BUILD_DIR = $(BUILD_DIR)/modules



create_dir:
	$(shell mkdir -p $(GEN_DIR))
	$(shell mkdir -p $(BUILD_DIR))
	$(shell mkdir -p $(CONF_DIR))
	$(shell mkdir -p $(MODULES_BUILD_DIR))
	$(shell mkdir -p $(C_OBJ_BUILD_DIR))
ifeq (${LINK_WITH_O}, TRUE)
	$(shell mkdir -p temp)
endif


###############################################################################
# Sources
MODULES := $(MODULES_PARTITION)

LIBS := $(PARTITION_LIBS)
LIBS2 := $(LIBS)


ifeq (${LINK_WITH_O}, TRUE)
# get the list of the o files
LIB_O := $(foreach f, $(LIBS), $(shell dar -t $(f)))
LIB_O := $(filter-out kcg_types.o ,$(LIB_O))
LIB_O := $(foreach f, $(LIB_O), ./temp/$(notdir $(f)))
endif
ifeq (${LINK_WITH_O}, TRUE)
LIBS := @./temp/ofiles.txt
endif



INSPEKT_CONFIG = $(BUILD_DIR)/Inspect_Config_$(PARTITION)

INSPEKT_MEMORY = $(BUILD_DIR)/Inspect_Memory_$(PARTITION)



MODULES_CONF = $(PSYMODULE_JSON)
COMPILE_CONF = $(COMPILE_JSON)
PARTITION_CONF = $(PARTITION_JSON)


PARTITION_CONF_POS = $(PARTITION_JSON_POS)

EMO = $(BUILD_DIR)/em.emo

###############################################################################
# Intermediate targets


PARTO = $(BUILD_DIR)/$(PARTITION).parto

EMO = $(BUILD_DIR)/$(PARTITION).emo

PSYO_FILES = $(MODULES:$(PATH_PSY)/%.psy=$(MODULES_BUILD_DIR)/%.psyo)
O_FILES = $(MODULES_SRC:$(PATH_C)/%.c=$(C_OBJ_BUILD_DIR)/%.o)

elf: clean_elf create_dir build

ifeq (${PARTITION}, ERH)
OUTPUT_ELF = $(EMO)
else
OUTPUT_ELF = $(PARTO)
endif

build: $(OUTPUT_ELF)

#####################################################################
# Build .srco from .c files
#####################################################################
$(C_OBJ_BUILD_DIR)/%.o : $(PATH_C)/%.c
	$(PSYKO_BASE_CMD) cc --output $@ -- $< $(COMPILE_CONF)
$(PATH_C)/%.c : $(PATH_C)/%.h

#####################################################################
# Build .psyo from .psy files
#####################################################################
$(PSYO_FILES): $(MODULES_BUILD_DIR)/%.psyo: $(PATH_PSY)/%.psy $(MODULES_CONF)
	$(PSYKO_BASE_CMD) module --gendir $(GEN_DIR)/$(basename $(notdir $@)) --output $@ -- $< $(MODULES_CONF)


#####################################################################
# Partition COMPILATION
#####################################################################
$(PARTO): $(PARTITION_CONF_POS) $(PSYO_FILES) $(LIBS2) $(O_FILES)
ifeq (${LINK_WITH_O}, TRUE)	
	$(foreach f, $(LIBS2), $(shell cd temp; dar -x ../$(f)))
	$(file >./temp/ofiles.txt,$(LIB_O) )
endif
	$(PSYKO_BASE_CMD)  gen-mem-conf --target partition --gendir $(GEN_DIR)/$(PARTITION)_GEN_MEM_CONF  --output memory$(PARTITION).json  -- $(PARTITION_CONF_POS) $(PSYO_FILES) $(O_FILES) $(LIBS) 
	python $(PYTHON_MODIFICATION_SCRIPT)
	$(PSYKO_BASE_CMD)  partition --gui --gendir $(GEN_DIR)/$(PARTITION) --output $@ --binary-output $(BUILD_DIR)/$(PARTITION).elf --overwrite-memory-configuration  memory$(PARTITION)_mod.json -- $(PARTITION_CONF) $(PSYO_FILES)  $(O_FILES) $(LIBS)
	mv ./MappingErrors$(PARTITION).map $(BUILD_DIR)
	mv ./Mapping$(PARTITION).map $(BUILD_DIR)
	mv ./memory$(PARTITION).json $(BUILD_DIR)
	mv ./memory$(PARTITION)_mod.json $(BUILD_DIR)
ifeq (${LINK_WITH_O}, TRUE)
	$(RM) -rf ./temp
endif
	$(INSPEKT_CMD) memory $(PARTO) $(INSPEKT_MEMORY) --force
	$(INSPEKT_CMD) config $(PARTO) $(INSPEKT_CONFIG) --force
	$(INSPEKT_CMD) uid $(PARTO)
	$(INSPEKT_CMD) uid $(BUILD_DIR)/$(PARTITION).elf
	@echo copy of the asterios file to have all the files in the gen directory 
	cp -R ../$(PARTITION)_RealTimeSchedule/* ../../$(PARTITION)_gen/astgen/conf
	@echo copy of the .a files
	$(foreach f, $(LIBS2), $(shell cp $(f) ../../$(PARTITION)_gen/astgen/conf))
	@echo copy of the .o files
	$(foreach f, $(O_FILES), $(shell cp $(f) ../../$(PARTITION)_gen/astgen/conf))
	@echo the conf and build direcroty are zipped to ease the configuration gestion 
	pwd && cd $(GEN_DIR) && pwd && 7z a -r -mx9 ./$(PARTITION)_BUILD.zip ./*
	pwd && cd $(CONF_DIR) && pwd && 7z a -r -mx9 ./$(PARTITION)_CONF.zip ./*













#####################################################################
# Compile the error handlers
#####################################################################
$(EMO): $(O_FILES) $(ERROR_CONF) $(PARTITION_JSON) $(LIBS2)
ifeq (${LINK_WITH_O}, TRUE)	
	$(foreach f, $(LIBS2), $(shell cd temp; dar -x ../$(f)))
	$(file >./temp/ofiles.txt,$(LIB_O) )
endif
	$(PSYKO_BASE_CMD) em --output $@ --gendir $(GEN_DIR)/ERH --binary-output $(BUILD_DIR)/$(PARTITION).elf $(LIB_FOR_ERH) -- $^ $(LIBS)
	mv ./MappingErrorsERH.map $(BUILD_DIR)
	mv ./MappingERH.map $(BUILD_DIR)
ifeq (${LINK_WITH_O}, TRUE)
	$(RM) -rv ./temp
endif
	#$(INSPEKT_CMD) memory $(EMO) $(INSPEKT_ERH_MEMORY) --force
	$(INSPEKT_CMD) config $(EMO) $(INSPEKT_CONFIG) --force
	$(INSPEKT_CMD) uid $(EMO)
	$(INSPEKT_CMD) uid $(BUILD_DIR)/$(PARTITION).elf




clean_elf:
	@echo "delete made twice since it sometimes fails for an unknown reason"
	$(RM) -rf $(BUILD_DIR)
	$(RM) -rf $(GEN_DIR)
	$(RM) -rf $(CONF_DIR)
	$(RM) -rf $(BUILD_DIR)
	$(RM) -rf $(GEN_DIR)
	$(RM) -rf $(CONF_DIR)
ifeq (${LINK_WITH_O}, TRUE)
	$(RM) -rf ./temp
	$(RM) -rf ./temp
endif
#####################################################################
.PHONY: all compile link clean_elf psyids create_dir

