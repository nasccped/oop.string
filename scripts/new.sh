#!/bin/sh

# color escapes
RESET="\e[0m"
RED="\e[91m"

SRC_DIR=./src

# file content templates
MAKEFILE_CONTENT="CC=gcc
SRC=src
FLS=\$(wildcard \$(SRC)/*.c)
OUT=./out
MAIN_OUT=\$(OUT)/main

build: \$(OUT)
	\$(CC) -o \$(MAIN_OUT) \$(FLS)

\$(OUT):
	@mkdir \$@

run: \$(MAIN_OUT)
	$<

\$(MAIN_OUT):
	\$(CC) -o \$(MAIN_OUT) \$(FLS)

clean:
	@if [ -d \$(OUT) ]; then \
	  rm -rf \$(OUT); \
	fi;


.PHONY: build run clean
"
C_CONTENT="/* This file belongs to the oop.string repository by nasccped. Take a look at
 * https://github.com/nasccped/oop.string/blob/main/LICENSE if you're unsure
 * about the use/reproduction conditions */

#include <stdio.h>

int main(int adrgc, char *argv[]) {
    printf(\"Hello, World :^D\\n\");
    return 0;
}
"

# get project name
read -p "The new project name: " name

# if directory already exists
if [ -d "${SRC_DIR}/${name}" ]; then
	echo -e "${RED}error${RESET}: this code group already exists"
	echo "Aborting."
	exit 1
fi

# generate absolute path for each file/dir
ABSPTH="${SRC_DIR}/$name"
ABSRDM="${ABSPTH}/README.md"
ABSSRC="${ABSPTH}/src"
ABSMKF="${ABSPTH}/Makefile"

# create project dir
mkdir $ABSPTH
# create README
printf "%s\n%s" "\`$name\`" "$(printf '%*s\n' "$(( ${#name} + 2 ))" '' | tr ' ' '=')" > $ABSRDM
# create source dir
mkdir $ABSSRC
# create c file
echo "$C_CONTENT" > "$ABSSRC/main.c"
# create makefile
echo "$MAKEFILE_CONTENT" > "$ABSMKF"
