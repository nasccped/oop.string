#include <stdio.h>

#include "../core/banner.h"
#include "../core/colors.h"

int get_subtitle_length(char *subtitle) {
  int i;
  for (i = 0; subtitle[i] != '\0'; i++);
  return i;
}

void print_banner(char *subtitle) {
  int right_gap = BANNER_MAX_LENGTH // get max len
    - SUBTITLE_LEFT_GAP             // subtract the default left gap
    - get_subtitle_length(subtitle) // subctract the subtitle len
    - 1;                            // subtract 1 (right border)

  printf("%s.===================================================================.%s\n",
      WHITE_NONE,
      RESET);
  printf("| %sOOP.String%s: %s%s%s",
      GREEN_NONE,
      WHITE_NONE,
      YELLOW_NONE,
      subtitle,
      WHITE_NONE);
  for (int i = 0; i < right_gap; i++)
    printf(" ");
  printf("|%s\n", RESET);
  printf("%s'==================================================================='%s\n",
      WHITE_NONE,
      RESET);
}
