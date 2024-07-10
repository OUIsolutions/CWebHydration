
BUILD = "build.out"
MAIN = "teste.c"
OUT ?= "exec.out"


ALL: pre_compile compile execute

pre_compile:
	./${BUILD}

compile:
	gcc ${MAIN} -o ${OUT}

execute:
	./${OUT}