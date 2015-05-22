CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
OBCPY=arm-none-eabi-objcopy

PART=TM4C123GH6PM

# For release, remove the '-g' to remove debugging flags
CFLAGS=-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -ffunction-sections -fdata-sections -MD -std=c99 -Wall -pedantic -DPART_TM4C123GH6PM -c -DTARGET_IS_BLIZZARD_RB1 -Dgcc -I/usr/lib/arm-none-eabi/include -L/usr/lib/arm-none-eabi/newlib
TEST_CFLAGS=-lcunit
OBJ_COPY_FLAGS=-O binary
LDFLAGS=--entry ResetISR --gc-sections ${shell ${CC} ${CFLAGS} -print-file-name=libm.a} ${shell ${CC} ${CFLAGS} -print-file-name=libc.a} ${shell ${CC} ${CFLAGS} -print-libgcc-file-name} -T OS.ld

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

UART_DRIVER=UART_driver
_UART_DRIVER_OBJ=$(addsuffix .o,$(UART_DRIVER))
UART_DRIVER_OBJ=$(addprefix $(OBJ_DIR)/,$(_UART_DRIVER_OBJ))

_UART_DRIVER_DEPS=UART_driver.c
UART_DRIVER_DEPS=$(addprefix $(SRC_DIR)/$(TASK_DIR)/,$(_UART_DRIVER_DEPS))
_UART_DRIVER_INCL=UART_driver.h
UART_DRIVER_INCL=$(addprefix $(INCLUDE_DIR)/$(TASK_DIR)/,$(_UART_DRIVER_INCL))

WIFI_DRIVER=Wi-Fi_driver
_WIFI_DRIVER_OBJ=$(addsuffix .o,$(WIFI_DRIVER))
WIFI_DRIVER_OBJ=$(addprefix $(OBJ_DIR)/,$(_WIFI_DRIVER_OBJ))

_WIFI_DRIVER_DEPS=Wi-Fi_driver.c
WIFI_DRIVER_DEPS=$(addprefix $(SRC_DIR)/$(TASK_DIR)/,$(_WIFI_DRIVER_DEPS))
_WIFI_DRIVER_INCL=Wi-Fi_driver.h
WIFI_DRIVER_INCL=$(addprefix $(INCLUDE_DIR)/$(TASK_DIR)/,$(_WIFI_DRIVER_INCL))

WIFI_CONTROLLER=Wi-Fi_controller
_WIFI_CONTROLLER_OBJ=$(addsuffix .o,$(WIFI_CONTROLLER))
WIFI_CONTROLLER_OBJ=$(addprefix $(OBJ_DIR)/,$(_WIFI_CONTROLLER_OBJ))

_WIFI_CONTROLLER_DEPS=Wi-Fi_controller.c
WIFI_CONTROLLER_DEPS=$(addprefix $(SRC_DIR)/$(TASK_DIR)/,$(_WIFI_CONTROLLER_DEPS))
_WIFI_CONTROLLER_INCL=Wi-Fi_controller.h
WIFI_CONTROLLER_INCL=$(addprefix $(INCLUDE_DIR)/$(TASK_DIR)/,$(_WIFI_CONTROLLER_INCL))

MOTOR_DRIVER=Motor_driver
_MOTOR_DRIVER_OBJ=$(addsuffix .o,$(MOTOR_DRIVER))
MOTOR_DRIVER_OBJ=$(addprefix $(OBJ_DIR)/,$(_MOTOR_DRIVER_OBJ))

_MOTOR_DRIVER_DEPS=Motor_driver.c
MOTOR_DRIVER_DEPS=$(addprefix $(SRC_DIR)/$(TASK_DIR)/,$(_MOTOR_DRIVER_DEPS))
_MOTOR_DRIVER_INCL=Motor_driver.h
MOTOR_DRIVER_INCL=$(addprefix $(INCLUDE_DIR)/$(TASK_DIR)/,$(_MOTOR_DRIVER_INCL))

KERNEL_DRIVER=Kernel_driver
_KERNEL_DRIVER_OBJ=$(addsuffix .o,$(KERNEL_DRIVER))
KERNEL_DRIVER_OBJ=$(addprefix $(INCLUDE_DIR)/$(TASK_DIR)/,$(_KERNEL_DRIVER_OBJ))

_KERNEL_DRIVER_DEPS=Kernel_driver.c
KERNEL_DRIVER_DEPS=$(addprefix $(SRC_DIR)/$(TASK_DIR)/,$(_KERNEL_DRIVER_DEPS))
_KERNEL_DRIVER_INCL=Kernel_driver.h
KERNEL_DRIVER_INCL=$(addprefix $(INCLUDE_DIR)/$(TASK_DIR)/,$(_KERNEL_DRIVER_INCL))

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
MAIN_AXF=$(addsuffix .axf,$(MAIN))
MAIN_ELF=$(addsuffix .elf, $(MAIN))
MAIN_BIN=$(addsuffix .bin, $(MAIN))

TEST=test
TEST_OBJ=$(addsuffix .bin,$(TEST))
TEST_DEP=$(addsuffix .c,$(SRC_DIR)/$(TEST))

LINK_DIRECTORY=driverlib/gcc
TIVA_DRIVER=driver

$(MAIN_BIN): $(MAIN_AXF)
	$(OBCPY) $(OBJ_COPY_FLAGS) $< $@

$(MAIN_AXF): $(MAIN_OBJ) $(KERNEL_OBJ) $(MPI_OBJ) $(OSLib_OBJ) $(STARTUP_OBJ) $(WIFI_DRIVER_OBJ) $(WIFI_CONTROLLER_OBJ) $(UART_DRIVER_OBJ) $(MOTOR_DRIVER_OBJ)
	$(LD) -o $@ $^ -L./$(INCLUDE_DIR)/$(LINK_DIRECTORY) -l$(TIVA_DRIVER) $(LDFLAGS)

$(MAIN) $(MAIN_OBJ): $(MAIN_DEP) $(SYS_INCL)
	$(CC) -o $@ -I $(INCLUDE_DIR) $< $(CFLAGS)

$(TEST) $(TEST_OBJ): $(TEST_DEP) $(MPI_OBJ) $(OSLib_OBJ) $(KERNEL_OBJ)
	$(CC) -o $@ -I $(INCLUDE_DIR) $(TEST_DEP) $(MPI_OBJ) $(OSLib_OBJ) $(KERNEL_OBJ) $(TEST_CFLAGS)

$(OSLib) $(OSLib_OBJ): $(OSLib_DEPS) $(OSLib_INCL)
	$(CC) -c -o $@ -I $(INCLUDE_DIR)  $< $(CFLAGS)

$(MPI) $(MPI_OBJ): $(MPI_DEPS) $(MPI_INCL)
	$(CC) -c -o $@ -I $(INCLUDE_DIR)  $< $(CFLAGS)

$(KERNEL) $(KERNEL_OBJ): $(KERNEL_DEPS) $(KERNEL_INCL)
	$(CC) -c -o $@ -I $(INCLUDE_DIR) $< $(CFLAGS)

$(WIFI_DRIVER) $(WIFI_DRIVER_OBJ): $(WIFI_DRIVER_DEPS) $(WIFI_DRIVER_INCL)
	$(CC) -c -o $@ -I $(INCLUDE_DIR) $< $(CFLAGS)

$(WIFI_CONTROLLER) $(WIFI_CONTROLLER_OBJ): $(WIFI_CONTROLLER_DEPS) $(WIFI_CONTROLLER_INCL)
	$(CC) -c -o $@ -I $(INCLUDE_DIR) $< $(CFLAGS)

$(UART_DRIVER) $(UART_DRIVER_OBJ): $(UART_DRIVER_DEPS) $(UART_DRIVER_INCL)
	$(CC) -c -o $@ -I $(INCLUDE_DIR) $< $(CFLAGS)

$(MOTOR_DRIVER) $(MOTOR_DRIVER_OBJ): $(MOTOR_DRIVER_DEPS) $(MOTOR_DRIVER_INCL)
	$(CC) -c -o $@ -I $(INCLUDE_DIR) $< $(CFLAGS)

$(STARTUP) $(STARTUP_OBJ): $(STARTUP_DEPS)
	$(CC) -c -o $@ -I $(INCLUDE_DIR) $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d *~ *.bin *.elf *.axf
