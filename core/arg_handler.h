#ifndef _CORE_ARG_HANDLER
#define _CORE_ARG_HANDLER

struct _ArgHandlerStruct {
  int    count;
  char **arguments;
  void (*set_fields)(struct _ArgHandlerStruct *, int, char*[]);
  int  (*have_args)(struct _ArgHandlerStruct *);
};

void set_fields(struct _ArgHandlerStruct *, int, char*[]);
int have_args(struct _ArgHandlerStruct *);

extern struct _ArgHandlerStruct ARG_HANDLER;

#endif // !_CORE_ARG_HANDLER
