
BUILD = "build.out"
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

buld:
	@sh pre_builde.sh
	@echo ""