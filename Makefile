
BUILD = "build.out"
PRE_BUILD = "pre_build.sh"
MAIN = "teste.c"
OUT ?= "exec.out"


ALL: pre_compile build compile_test

pre_compile:
	@sh ${PRE_BUILD}
	@echo ""

build:
	@./${BUILD}
	@echo ""

compile_test:
	@gcc ${MAIN} -o ${OUT}
	@echo ""

execute:
	@./${OUT}
	@echo ""

