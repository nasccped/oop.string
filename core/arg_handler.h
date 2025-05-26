#ifndef _CORE_ARG_HANDLER
#define _CORE_ARG_HANDLER

#define SUBCOMMAND_NAME_MAX_LEN 10

typedef void (*Function)();

struct _SubcommandStruct {
  char *name;
  char *description;
  void (*function)();
};

struct _ArgHandlerStruct {
  // attributes
  int    argc;
  char  *argv;
  struct _SubcommandStruct *subcommands;

  // setters
  void (*set_fields)(struct _ArgHandlerStruct *,
                     int,
                     char **,
                     struct _SubcommandStruct *);

  // getters
  int      (*argc_is_valid)(struct _ArgHandlerStruct *);
  Function (*get_function)(struct _ArgHandlerStruct *);
  char    *(*get_argv)(struct _ArgHandlerStruct *);

  // others
  void (*print_subcommands)(struct _ArgHandlerStruct *);
  void (*invalid_argc_message)(struct _ArgHandlerStruct *);
  void (*invalid_subcommand_message)(struct _ArgHandlerStruct *);
};

// setters
void set_fields(struct _ArgHandlerStruct *,
                int,
                char **,
                struct _SubcommandStruct *);

// getters
int argc_is_valid(struct _ArgHandlerStruct *);
Function get_function(struct _ArgHandlerStruct *);
char *get_argv(struct _ArgHandlerStruct *);

// others
void print_subcommands(struct _ArgHandlerStruct *);
void invalid_argc_message(struct _ArgHandlerStruct *);
void invalid_subcommand_message(struct _ArgHandlerStruct *);

void default_message();

extern struct _ArgHandlerStruct ARG_HANDLER;
extern struct _SubcommandStruct SUBCOMMANDS[];

#endif // !_CORE_ARG_HANDLER
