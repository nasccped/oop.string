#include <stdio.h>
#include <stdlib.h>

#include "../core/banner.h"
#include "../core/colors.h"

char *SECTION_SUBTITLE = "00-Main";

int main(int argc, char *argv[]) {
  print_banner(SECTION_SUBTITLE);
  printf(
    "Welcome to the %sOOP%s.%sString%s, a repository to share most of my\n" // row 1
    "%sString%s related knowledge in a low level way (%sC lang%s)!\n",      // row 2
    // row 1
    GREEN_NONE, WHITE_NONE, YELLOW_NONE, RESET,
    // row 2
    YELLOW_NONE, RESET, BLUE_NONE, RESET
  );
  return 0;
}
