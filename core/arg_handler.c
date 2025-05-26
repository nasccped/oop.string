#include "./arg_handler.h"
#include "./colors.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _ArgHandlerStruct ArgHandler;
typedef struct _SubcommandStruct Subcommand;

ArgHandler ARG_HANDLER = {
  // attributes
  .argc        = -1,
  .subcommands = NULL,
  .argv        = NULL,

  // setters
  .set_fields = set_fields,

  // getters
  .argc_is_valid = argc_is_valid,
  .get_argv      = get_argv,
  .get_function  = get_function,

  // others
  .print_subcommands          = print_subcommands,
  .invalid_argc_message       = invalid_argc_message,
  .invalid_subcommand_message = invalid_subcommand_message
};

// setters ----------------------------------------------------------
/*
 * Set all missing fields for ArgHandler struct, such as:
 *    - arg counting
 *    - target subcommand
 *    - Subcommands strucut array
 * */
void set_fields(ArgHandler *self,
                int argc,
                char *argv[],
                Subcommand subcommands[]) {
  self -> argc = argc - 1;
  self -> argv = (argc == 2) ? argv[1] : NULL;
  self -> subcommands = subcommands;
}

// getters ----------------------------------------------------------
int argc_is_valid(ArgHandler *self) {
  return self -> argc < 2;
}

char *get_argv(ArgHandler *self) {
  if (!self) return NULL;
  return self -> argv;
}

void print_subcommands(ArgHandler *self) {

  char *subcommand  = self -> subcommands[0].name,
       *description = self -> subcommands[0].description;

  for (int i = 1; subcommand && description; i++) {
    printf("  %s%s%s:",
           YELLOW_NONE,
           subcommand,
           RESET);
    for (int j = strlen(subcommand); j < SUBCOMMAND_NAME_MAX_LEN; j++)
      printf(" ");
    printf("%s\n", description);
    subcommand = self -> subcommands[i].name;
    description = self -> subcommands[i].description;
  }
}

/*
 * Print this message when struct has invalid arg count (> 1)
 * */
void invalid_argc_message(ArgHandler *self) {
  printf(
    "%s ERR: %s The valid arg counting are %s0%s or %s1%s, but\n"
    "       %s%d%s was found!\n"
    "\n"
    "Use `%s<BIN_PATH> %shelp%s` to see subcommands and their\n"
    "descriptions!\n",
    YELLOW_RED, RESET, GREEN_NONE, RESET, GREEN_NONE, RESET,
    RED_NONE, self -> argc, RESET,
    GREEN_NONE, YELLOW_NONE, RESET
  );
}

void invalid_subcommand_message(ArgHandler *self) {
  printf(
    "%s ERR: %s There's no action for the given subcommand (%s%s%s)\n"
    "\n"
    "Use `%s<BIN_PATH> %shelp%s` to see subcommands and their\n"
    "descriptions!\n",
    YELLOW_RED, RESET, RED_NONE, self -> argv, RESET,
    GREEN_NONE, YELLOW_NONE, RESET
  );
}

Function get_function(ArgHandler *self) {
  char *target = self -> argv;
  if (!target) return NULL;
  char *name = self -> subcommands[0].name,
       *description = self -> subcommands[0].description;
  Function func = self -> subcommands[0].function;

  for (int i = 1; name && description; i++) {
    if (!strcmp(name, target)) return func;
    name = self -> subcommands[i].name;
    description = self -> subcommands[i].description;
    func = self -> subcommands[i].function;
  }
  return NULL;
}
