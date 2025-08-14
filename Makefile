SRC_DIR=src
RESET=\e[0m
RED=\e[91m
GREEN=\e[92m
YELLOW=\e[93m
BLUE=\e[94m
FMT_SCRIPT=./scripts/fmt.sh
NEW_SCRIPT=./scripts/new.sh

all:
	@echo -e "$(GREEN)oop.string$(RESET) project: \n\
	\n\
	  This project is a set off cool discoveries that I've made \n\
	  while learning about strings handling and usage with \
	$(BLUE)C lang$(RESET)! \n\
	\n\
	  All the source content can be found at the $(GREEN)src dir$(RESET). \n\
	\n\
	  You can navigate through them and take a look to the READMEs \n\
	  provided in the given dir! \n\
	\n\
	  This makefile provides some scripts also, like:\n\
	    |> $(YELLOW)fmt$(RESET) formats all C sources using the clang-format"

fmt: $(FMT_SCRIPT)
	@if [ ! -x $< ]; then \
		echo -e "$(RED)error$(RESET): $< isn't executable"; \
		echo -e "consider using \`$(YELLOW)chmod +x $<$(RESET)\`"; \
		echo "Aborting."; \
		exit 1; \
	fi;
	@echo -e "Formatting code with \`$(GREEN)scripts/fmt.sh$(RESET)\`"
	@$(FMT_SCRIPT)

new: $(NEW_SCRIPT)
	@if [ ! -x $< ]; then \
		echo -e "$(RED)error$(RESET): $< isn't executable"; \
		echo -e "consider using \`$(YELLOW)chmod +x $<$(RESET)\`"; \
		echo "Aborting."; \
		exit 1; \
	fi;
	@echo -e "Generating a new code group with \`$(GREEN)$(NEW_SCRIPT)$(RESET)\`"
	@$(NEW_SCRIPT)

.PHONY: all fmt new
