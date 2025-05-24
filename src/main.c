#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc > 1) {
    char *arg = argv[1];
    printf("The first arg is: %s\n", arg);
  } else
    printf("No arg was given!\n");
  return 0;
}
