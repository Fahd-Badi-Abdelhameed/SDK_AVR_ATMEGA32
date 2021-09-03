################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Software_ICU.lss \

FLASH_IMAGE += \
Software_ICU.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Software_ICU.elf secondary-outputs

# Tool invocations
Software_ICU.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Software_ICU.map -mmcu=atmega32 -o "Software_ICU.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Software_ICU.lss: Software_ICU.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Software_ICU.elf  >"Software_ICU.lss"
	@echo 'Finished building: $@'
	@echo ' '

Software_ICU.hex: Software_ICU.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Software_ICU.elf  "Software_ICU.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Software_ICU.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Software_ICU.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Software_ICU.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
