// Credit: https://github.com/wwu-mentors
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

static const ssize_t string_length = 12;
int main() {
  char *maybe_a_string = malloc(string_length);
  ssize_t bytes_read;

  assert(maybe_a_string != NULL);
  memset(maybe_a_string, 0, string_length);

  bytes_read = read(STDIN_FILENO, maybe_a_string, string_length+1);

  if(bytes_read >= 0 ) {
    printf("You entered: %s\n", maybe_a_string);
  }

  free(maybe_a_string);
  free(maybe_a_string);
  return EXIT_SUCCESS;
}
