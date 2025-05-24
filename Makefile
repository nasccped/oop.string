CC=gcc
SRC_DIR=src
CORE_DIR=core
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
CORE_FILES=$(wildcard $(CORE_DIR)/*.c)
OUT_DIR=out
BINS=$(patsubst $(SRC_DIR)/%.c,$(OUT_DIR)/%,$(SRC_FILES))

all:
	@echo "Due to complex reasons, you aren't able to run \`make all\`"
	@echo "There's many sources and binaries which should be"
	@echo "compiled and separately runned. But you still can run:"
	@echo ">   make build"
	@echo ">   make clean"
	@echo "Look the official repo: https://github.com/nasccped/oop.string"

run:
	@echo "You can't run all binaries in a row. You should execute"
	@echo "them separately by running \`out/<BIN_NAME>\` (after"
	@echo "compiling, obviously)"

build: $(BINS)

clean: $(OUT_DIR)
	rm -rf $(OUT_DIR)

$(OUT_DIR)/%: $(SRC_DIR)/%.c $(CORE_FILES)
	@if [ ! -d $(OUT_DIR) ]; then \
		mkdir $(OUT_DIR); \
	fi
	$(CC) -o $@ $^

.PHONY: all build run clean
