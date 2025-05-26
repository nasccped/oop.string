#include <stdio.h>
#include <stdlib.h>

#include "../core/arg_handler.h"
#include "../core/banner.h"
#include "../core/colors.h"

#include "../headers/00-main.h"

typedef struct _SubcommandStruct Subcommand;

Subcommand SUBCOMMANDS[] = {
  {"help", "Show this panel", help_function},
  {NULL, NULL, NULL},
};

int main(int argc, char *argv[]) {
  ARG_HANDLER.set_fields(&ARG_HANDLER, argc, argv, SUBCOMMANDS);
  // if invalid argc (> 1)
  if (!ARG_HANDLER.argc_is_valid(&ARG_HANDLER)) {
    ARG_HANDLER.invalid_argc_message(&ARG_HANDLER);
    printf("\n");
    return 0;
  }
  // get function point. + subcommand and test if are valids
  Function func = ARG_HANDLER.get_function(&ARG_HANDLER);
  char *target_argv = ARG_HANDLER.get_argv(&ARG_HANDLER);
  if (!func && target_argv) {
    ARG_HANDLER.invalid_subcommand_message(&ARG_HANDLER);
    printf("\n");
    return 0;
  }
  if (func) {
    func();
    printf("\n");
    return 0;
  }

  default_message();
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
  printf(
    "Here's the init point (%sas you can see%s in title `%s%s%s`).\n"           // row 1
    "Also, there's an %sArgument Handler%s. This program work as an %sCLI%s.\n" // row 2
    "Try it by passing `%shelp%s` after the binary\n"                           // row 3
    "path! (e.g., path/to/bin help)\n\n",
    // row 1
    RED_NONE, RESET, YELLOW_NONE, SECTION_SUBTITLE, RESET,
    // row 2
    BLUE_NONE, RESET, BLUE_NONE, RESET,
    // row 3
    YELLOW_NONE, RESET
  );
}

void help_function() {
  ARG_HANDLER.print_subcommands(&ARG_HANDLER);
}
