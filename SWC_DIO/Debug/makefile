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
SWC_DIO_ESLAM.lss \

FLASH_IMAGE += \
SWC_DIO_ESLAM.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SWC_DIO_ESLAM.elf secondary-outputs

# Tool invocations
SWC_DIO_ESLAM.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SWC_DIO_ESLAM.map -mmcu=atmega32 -o "SWC_DIO_ESLAM.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SWC_DIO_ESLAM.lss: SWC_DIO_ESLAM.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SWC_DIO_ESLAM.elf  >"SWC_DIO_ESLAM.lss"
	@echo 'Finished building: $@'
	@echo ' '

SWC_DIO_ESLAM.hex: SWC_DIO_ESLAM.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SWC_DIO_ESLAM.elf  "SWC_DIO_ESLAM.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SWC_DIO_ESLAM.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SWC_DIO_ESLAM.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SWC_DIO_ESLAM.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
