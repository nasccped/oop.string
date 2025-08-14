CC=gcc
SRC=src
FLS=$(wildcard $(SRC)/*.c)
OUT=./out
MAIN_OUT=$(OUT)/main

build: $(OUT)
	$(CC) -o $(MAIN_OUT) $(FLS)

$(OUT):
	@mkdir $@

run: $(MAIN_OUT)
	$<

$(MAIN_OUT):
	$(CC) -o $(MAIN_OUT) $(FLS)

clean:
	@if [ -d $(OUT) ]; then \
	  rm -rf $(OUT); \
	fi;


.PHONY: build run clean
