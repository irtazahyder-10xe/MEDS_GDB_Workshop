#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int *memoized_seq;
} fib_seq;

fib_seq cache;

void init_cache()
{
  cache.memoized_seq = NULL;
  cache.size = 0;
}

void free_cache()
{
  free(cache.memoized_seq);
}

int sum_fib(const char n)
{
  if (n < cache.size) {
    printf("Cache Hit\n");
    return cache.memoized_seq[n];
  } else {
    cache.memoized_seq = realloc(cache.memoized_seq, n);
    cache.size = n;
  }

  int fib[2] = {0, 1};
  for (size_t i = 2; i < n; ++i)
  {
    fib[i % 3] = fib[0] + fib[1];
    cache.memoized_seq[i] = cache.memoized_seq[i-1] + fib[i % 2];
  }
  // returning size of fib array
  return cache.memoized_seq[n - 1];
}

int main()
{
  init_cache();
  int n;
  int bytes;

  do {
    printf("Enter length of fib: ");
    bytes = scanf("%d", &n);
    if (bytes < 0)
      break;
    printf("\nSum of Fibonnaci of length %d = %d\n", n, sum_fib(n));
  } while(n >= 0);

  free_cache();
}
