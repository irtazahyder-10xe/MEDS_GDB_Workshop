// Credit: https://github.com/wwu-mentors
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

int main() {
  char *a_string = NULL;
  int offset;
  size_t buffsize = 0;
  ssize_t string_length = 0;

  fprintf(stderr, "Please enter a string:");

  string_length = getline(&a_string, &buffsize, stdin);

  fprintf(stderr, "Please enter an offset:");
  scanf("%d", &offset);

  assert(string_length >= 0);

  strncpy(a_string, a_string + offset, strlen(a_string));

  fprintf(stderr, "Your modified string is: %s", a_string);
  free(a_string);

  return EXIT_SUCCESS;
}
