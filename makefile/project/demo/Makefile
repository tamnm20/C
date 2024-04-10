#makefile project demo

PRO_DIR 	:= .
PROJ_NAME 	:= demo_stm32
OUTPUT_PATH := $(PRO_DIR)/output

INC_DIR := $(PRO_DIR)/inc
SRC_DIR := $(PRO_DIR)/src
LINKER_FILE := $(PRO_DIR)/linker/STM32F030_mini_board.ld
FILE_TO_LINK:= $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/startup_ARMCM0.o

COMPILER_DIR		:= C:/tools/gcc_10_2023/13_2_Rel1
PREFIX_GCC_COMPILER := arm-none-eabi
CC					:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-gcc
ASM 				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-as
LD					:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-ld


CC_OPT				:= -march=armv6-m -mcpu=cortex-m0 -c -O0 -g -mthumb -I$(INC_DIR)
ASM_OPT				:= -march=armv6-m -mcpu=cortex-m0 -c -mthumb
LD_OPT				:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)

$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.c
	@echo "compile $(SRC_DIR)/main.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o
	
$(OUTPUT_PATH)/startup_ARMCM0.o: $(SRC_DIR)/startup_ARMCM0.S
	@echo "compile $(SRC_DIR)/startup_ARMCM0.S file"
	$(ASM) $(ASM_OPT_OPT) $(SRC_DIR)/startup_ARMCM0.S -o $(OUTPUT_PATH)/startup_ARMCM0.o

build: $(FILE_TO_LINK) $(LINKER_FILE)
	@echo "Link object files create new binary image ($(PROJ_NAME)).elf)"
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf
	
clean:
	@rm -rf $(OUTPUT_PATH)/*