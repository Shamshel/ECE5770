CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
OBCPY=arm-none-eabi-objcopy

PART=TM4C123GH6PM

CFLAGS=-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -ffunction-sections -fdata-sections -MD -std=c99 -Wall -pedantic -DPART_TM4C123GH6PM -c -DTARGET_IS_BLIZZARD_RB1 -Dgcc -I/usr/lib/arm-none-eabi/include -L/usr/lib/arm-none-eabi/newlib
TEST_CFLAGS=-lcunit
OBJ_COPY_FLAGS=-O binary

SRC_DIR=src
INCLUDE_DIR=include

OS_DIR=OS
OBJ_DIR=obj
TASK_DIR=Tasks

OSLib=OSLib
_OSLib_OBJ=$(addsuffix .o,$(OSLib))
OSLib_OBJ=$(addprefix $(OBJ_DIR)/,$(_OSLib_OBJ))

_OSLib_DEPS=OSLib.c
OSLib_DEPS=$(addprefix $(SRC_DIR)/$(OS_DIR)/,$(_OSLib_DEPS))
_OSLib_INCL=OSLib.h
OSLib_INCL=$(addprefix $(INCLUDE_DIR)/$(OS_DIR)/,$(_OSLib_INCL))

MPI=MPI
_MPI_OBJ=$(addsuffix .o,$(MPI))
MPI_OBJ=$(addprefix $(OBJ_DIR)/,$(_MPI_OBJ))

_MPI_DEPS=MPI.c
MPI_DEPS=$(addprefix $(SRC_DIR)/$(OS_DIR)/,$(_MPI_DEPS))
_MPI_INCL=MPI.h
MPI_INCL=$(addprefix $(INCLUDE_DIR)/$(OS_DIR)/,$(_MPI_INCL))

KERNEL=Kernel
_KERNEL_OBJ=$(addsuffix .o,$(KERNEL))
KERNEL_OBJ=$(addprefix $(OBJ_DIR)/,$(_KERNEL_OBJ))

_KERNEL_DEPS=Kernel.c
KERNEL_DEPS=$(addprefix $(SRC_DIR)/$(OS_DIR)/,$(_KERNEL_DEPS))
_KERNEL_INCL=Kernel.h
KERNEL_INCL=$(addprefix $(INCLUDE_DIR)/$(OS_DIR)/,$(_KERNEL_INCL))

UART_DRIVER=UART
_UART_DRIVER_OBJ=$(addsuffix .o,$(UART_DRIVER))
UART_DRIVER_OBJ=$(addprefix $(OBJ_DIR)/,$(_UART_DRIVER_OBJ))

_UART_DRIVER_DEPS=UART_driver.c
UART_DRIVER_DEPS=$(addprefix $(SRC_DIR)/$(TASK_DIR)/,$(_UART_DRIVER_DEPS))
_UART_DRIVER_INCL=UART_driver.h
UART_DRIVER_INCL=$(addprefix $(INCLUDE_DIR)/$(TASK_DIR)/,$(_UART_DRIVER_INCL))

_SYS_INCL=OS.h oserr.h sysConfig.h
SYS_INCL=$(addprefix $(INCLUDE_DIR)/$(OS_DIR)/,$(_OS_INCL))

STARTUP=startup_gcc
_STARTUP_OBJ=$(addsuffix .o,$(STARTUP))
STARTUP_OBJ=$(addprefix $(OBJ_DIR)/,$(_STARTUP_OBJ))

_STARTUP_DEPS=startup_gcc.c
STARTUP_DEPS=$(addprefix $(SRC_DIR)/,$(_STARTUP_DEPS))

MAIN=main
_MAIN_OBJ=$(addsuffix .o,$(MAIN))
MAIN_OBJ=$(addprefix $(OBJ_DIR)/,$(_MAIN_OBJ))
MAIN_DEP=$(addsuffix .c,$(SRC_DIR)/$(MAIN))
MAIN_AXF=main.axf
MAIN_BIN=main.bin

TEST=test
TEST_OBJ=$(addsuffix .bin,$(TEST))
TEST_DEP=$(addsuffix .c,$(SRC_DIR)/$(TEST))

LINK_DIRECTORY=driverlib/gcc
TIVA_DRIVER=driver

$(MAIN_BIN): $(MAIN_AXF)
	$(OBCPY) $(OBJ_COPY_FLAGS) $< $(MAIN_BIN)

$(MAIN_AXF): $(MAIN_OBJ) $(MPI_OBJ) $(OSLib_OBJ) $(STARTUP_OBJ)
	$(LD) -o $(MAIN_AXF) $(MAIN_OBJ) $(MPI_OBJ) $(OSLib_OBJ) $(STARTUP_OBJ) -L./$(INCLUDE_DIR)/$(LINK_DIRECTORY) -l$(TIVA_DRIVER) -T OS.ld

$(MAIN) $(MAIN_OBJ): $(MAIN_DEP) $(SYS_INCL)
	$(CC) -o $(MAIN_OBJ) -I $(INCLUDE_DIR) $< $(CFLAGS)

$(TEST) $(TEST_OBJ): $(TEST_DEP) $(MPI_OBJ) $(OSLib_OBJ) $(KERNEL_OBJ)
	$(CC) -o $(TEST_OBJ) -I $(INCLUDE_DIR) $(TEST_DEP) $(MPI_OBJ) $(OSLib_OBJ) $(KERNEL_OBJ) $(TEST_CFLAGS)

$(OSLib) $(OSLib_OBJ): $(OSLib_DEPS) $(OSLib_INCL)
	$(CC) -c -o $(OSLib_OBJ) -I $(INCLUDE_DIR)  $< $(CFLAGS)

$(MPI) $(MPI_OBJ): $(MPI_DEPS) $(MPI_INCL)
	$(CC) -c -o $(MPI_OBJ) -I $(INCLUDE_DIR)  $< $(CFLAGS)

$(KERNEL) $(KERNEL_OBJ): $(KERNEL_DEPS) $(KERNEL_INCL)
	$(CC) -c -o $(KERNEL_OBJ) -I $(INCLUDE_DIR) $< $(CFLAGS)

$(UART_DRIVER) $(UART_DRIVER_OBJ): $(UART_DRIVER_DEPS) $(UART_DRIVER_INCL)
	$(CC) -c -o $(UART_DRIVER_OBJ) -I $(INCLUDE_DIR) $< $(CFLAGS)

$(STARTUP) $(STARTUP_OBJ): $(STARTUP_DEPS)
	$(CC) -c -o $(STARTUP_OBJ) -I $(INCLUDE_DIR) $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o *~ *.bin *.elf *.axf
