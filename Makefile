RESET=\e[0m
GREEN=\e[92m
BLUE=\e[94m

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
	  provided in the given dir!"

.PHONY: all
