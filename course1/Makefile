#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 
# course switch flags
ifeq ($(DEBUG),1)
  CRSFLAGS = -DCOURSE1
endif
#verbose switch
ifeq ($(VERBOSE),1)
  VERBFLAGS = -DVERBOSE
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	LDFLAGS = -Wl,-Map=c1m2.map $(INCLUDES)
	CPPFLAGS = -DHOST -MD
endif

ifeq ($(PLATFORM),MSP432)
	#Architecture Specific Flags
	CPU = cortex-m4
	MODE = thumb
	LINKER_FILE = msp432p401r.lds
	LDFLAGS = -Wl,-Map=c1m2.map -T../$(LINKER_FILE) $(INCLUDES)
	CPPFLAGS = -DMSP432 -MD
	SPECS = nosys.specs
	ARCH = armv7e-m
	FLOATABI = hard
	FPU = fpv4-sp-d16
	CC = arm-none-eabi-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -m$(MODE) -march=$(ARCH) -mfpu=$(FPU) -mfloat-abi=$(FLOATABI) --specs=$(SPECS)
endif

#object files
%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $< -o $@

#preprocessor output
%.i : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -E $< -o $@

#assembly files
%.asm : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $< -o $@
	objdump -S $@

OBJS = $(SOURCES:.c=.o)

#all object files without compilation
.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(VERBFLAGS) $(CRSFLAGS) -c

.PHONY: build
build: c1m2.out
c1m2.out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(VERBFLAGS) $(CRSFLAGS) -o $@
	size c1m2.out

.PHONY: clean
clean:
	rm -f  *.asm *.i *.d *.map *.o *.out
