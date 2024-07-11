BUILD = build.out
PATH_BUILD = $(wildcard $(BUILD))
PRE_BUILD = pre_build.sh
MAIN = teste.c
OUT ?= exec.out


ALL: verify compile

verify:
ifeq ($(wildcard $(PATH_BUILD)),)
	@$(MAKE) build_sh pre_compile
	@echo ""
else
	@$(MAKE) pre_compile 
	@echo ""
endif

pre_compile:
	@./$(BUILD)
	@echo ""

compile:
	@gcc $(MAIN) -o $(OUT)
	@echo ""



build_sh:
	@sh $(PRE_BUILD)
	@echo ""
