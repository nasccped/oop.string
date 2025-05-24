#include <stdio.h>
#include <stdlib.h>

#include "../core/banner.h"
#include "../core/colors.h"

#include "../headers/00-main.h"

int main(int argc, char *argv[]) {
  // if no args
  if (argc < 2) {
    default_message();
    return 0;
  }
  printf(
    "\nDefinitely not a default message %s:^D%s\n" // row 1
    "Arg handling %sshould be implemented%s!\n\n", // row 2
    // row 1
    BLUE_NONE, RESET,
    // row 2
    GREEN_NONE, RESET);
  return 0;
}

char *SECTION_SUBTITLE = "00-Main";

void default_message() {
  print_banner(SECTION_SUBTITLE);
  printf(
    "Welcome to the %sOOP%s.%sString%s, a repository to share most of my\n" // row 1
    "%sString%s related knowledge in a low level way (%sC lang%s)!\n\n",    // row 2
    // row 1
    GREEN_NONE, WHITE_NONE, YELLOW_NONE, RESET,
    // row 2
    YELLOW_NONE, RESET, BLUE_NONE, RESET
  );
}
