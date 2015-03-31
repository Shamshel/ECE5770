CC=gcc

CFLAGS=
TEST_CFLAGS=-lcunit

SRC_DIR=src
INCLUDE_DIR=include

OS_DIR=OS
OBJ_DIR=obj

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

_SYS_INCL=OS.h oserr.h sysConfig.h
SYS_INCL=$(addprefix $(INCLUDE_DIR)/$(OS_DIR)/,$(_OS_INCL))

MAIN=main
MAIN_OBJ=$(addsuffix .bin,$(MAIN))
MAIN_DEP=$(addsuffix .c,$(SRC_DIR)/$(MAIN))

TEST=test
TEST_OBJ=$(addsuffix .bin,$(TEST))
TEST_DEP=$(addsuffix .c,$(SRC_DIR)/$(TEST))

$(MAIN_OBJ): $(MAIN_DEP) $(SYS_INCL) $(MPI_OBJ) $(OSLib_OBJ)
	$(CC) -o $(MAIN_OBJ) -I $(INCLUDE_DIR) $(MAIN_DEP) $(MPI_OBJ) $(OSLib_OBJ) $(CFLAGS)

$(TEST) $(TEST_OBJ): $(TEST_DEP) $(MPI_OBJ) $(OSLib_OBJ) $(KERNEL_OBJ)
	$(CC) -o $(TEST_OBJ) -I $(INCLUDE_DIR) $(TEST_DEP) $(MPI_OBJ) $(OSLib_OBJ) $(KERNEL_OBJ) $(TEST_CFLAGS)

$(OSLib) $(OSLib_OBJ): $(OSLib_DEPS) $(OSLib_INCL)
	$(CC) -c -o $(OSLib_OBJ) -I $(INCLUDE_DIR)  $< $(CFLAGS)

$(MPI) $(MPI_OBJ): $(MPI_DEPS) $(MPI_INCL)
	$(CC) -c -o $(MPI_OBJ) -I $(INCLUDE_DIR)  $< $(CFLAGS)

$(KERNEL) $(KERNEL_OBJ): $(KERNEL_DEPS) $(KERNEL_INCL)
	$(CC) -c -o $(KERNEL_OBJ) -I $(INCLUDE_DIR) $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o *~ *.bin
