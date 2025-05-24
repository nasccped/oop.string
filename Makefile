CC=gcc
SRC_DIR=src
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OUT_DIR=out
OUT_FILE=$(OUT_DIR)/main


all: build run clean

run: $(OUT_FILE)
	@echo "Isn't possible to pass args when calling Makefile script";
	@echo "Keep it on mind ;^D";
	@echo .
	$(OUT_FILE)

build:
	@if [ ! -d $(OUT_DIR) ]; then \
		mkdir $(OUT_DIR); \
	fi
	$(CC) -o $(OUT_FILE) $(SRC_FILES)

clean: $(OUT_DIR)
	rm -rf $(OUT_DIR)

.PHONY: all build run clean
