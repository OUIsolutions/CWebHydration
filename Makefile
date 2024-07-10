
BUILD = "build.out"
PRE_BUILD = "pre_build.sh"
MAIN = "teste.c"
OUT ?= "exec.out"


ALL: pre_compile compile execute

pre_compile:
	@./${BUILD}
	@echo ""

compile:
	@gcc ${MAIN} -o ${OUT}
	@echo ""

execute:
	@./${OUT}
	@echo ""

build_sh:
	@sh ${PRE_BUILD}
	@echo ""