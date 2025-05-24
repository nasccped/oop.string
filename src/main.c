#include <stdio.h>

const char *BLUE  = "\x1b[37;44m";
const char *RESET = "\x1b[0m"    ;

// test new functions
int add_ints(int a, int b);

int main(int argc, char *argv[]) {
  int a, b;
  printf("Say an integer: ");
  scanf("%d", &a);
  printf("Say another integer: ");
  scanf("%d", &b);

  printf("The sum of them is %s %d %s\n",
         BLUE, add_ints(a, b), RESET);
}

int add_ints(int a, int b) {
  return a + b;
}
