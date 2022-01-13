CROSS_COMPILE=/opt/riscv32_small/bin/riscv32-unknown-elf-
# Include the core environment definitions; this will set $(TOP).
include ../../py/mkenv.mk

# Include py core make definitions.
include $(TOP)/py/py.mk

# Set CFLAGS and libraries.
CFLAGS = -I. -I$(BUILD) -I$(TOP) -static -nostdlib -Os
LIBS = -lm -static -nostdlib

# Define the required source files.
SRC_C = \
    main.c \
    mphalport.c \
    lib/mp-readline/readline.c \
    lib/utils/gchelper_generic.c \
    lib/utils/pyexec.c \
    lib/utils/stdout_helpers.c \
	newlib/syscall.c \
	mmio_basic/mmio_basic.c 

# Define the required object files.
OBJ = $(PY_CORE_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o)) $(addprefix $(BUILD)/, crt0.o sdboot.o)

# Define the top-level target, the main firmware.
all: $(BUILD)/firmware.bin

$(BUILD)/crt0.o: newlib/crt0.S
	$(CROSS_COMPILE)as -march=rv32im -mabi=ilp32 $^ -o $@

$(BUILD)/sdboot.o: sdboot.S
	$(CROSS_COMPILE)as -march=rv32im -mabi=ilp32 $^ -o $@

# Define how to build the firmware.
$(BUILD)/firmware.elf: $(OBJ)
	$(ECHO) "LINK $@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ $(LIBS) -T linker_micropython.ld -lc -lgcc
	$(Q)$(SIZE) $@

$(BUILD)/firmware.bin: $(BUILD)/firmware.elf
	$(CROSS_COMPILE)objcopy -O binary $^ $@


# Include remaining core make rules.
include $(TOP)/py/mkrules.mk

