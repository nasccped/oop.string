#include "./arg_handler.h"
#include <stdlib.h>

typedef struct _ArgHandlerStruct ArgHandler;

ArgHandler ARG_HANDLER = {
  .count = 0,
  .arguments = NULL,
  .set_fields = set_fields,
  .have_args = have_args
};

void set_fields(ArgHandler *self, int count, char *arguments[]) {
  self -> count = count - 1;
  self -> arguments = arguments;
}

int have_args(ArgHandler *self) {
  return self -> count > 0;
}
