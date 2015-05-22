# Tiva-C specific tasks Makefile
# based on TI's libdriver.a makefile

ROOT=../../..

IPATH=../..

all: ${TIVA_CC}
all: ${TIVA_CC}/Tiva_C_Tasks.a

clean:
	@rm -rf ${TIVA_CC} ${wildcard *~}

${TIVA_CC}:
	@makedir -p ${TIVA_CC}

${TIVA_CC}/Tiva_C_Tasks.a:
	$(TIVA_LD) 
