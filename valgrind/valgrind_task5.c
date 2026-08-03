#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

int main() {
  char maybe_a_string[12];
  printf("Your string is: %s\n", maybe_a_string);

  char *my_strings[4];
  char s[16];
  for (int i = 0; i < 4; i++) {
    sprintf(s, "Some value = %d\n", i);
    my_strings[i] = strdup(s);
  }

  for (int i = 0; i < 4;) {
    printf("%s", my_strings[i]);
    free(my_strings[++i]);
  }
  return EXIT_SUCCESS;
}
