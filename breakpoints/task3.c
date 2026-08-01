#include <stddef.h>
#include <stdlib.h>

int sum(size_t size, const int arr[size])
{
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += arr[i];
  return sum;
}

int make_fib(const int n, int fib[static 10])
{
  int i;
  fib = malloc(n * sizeof(int));
  fib[0] = 0;
  fib[1] = 1;

  for (i = 2; i <= n; ++i)
  {
    fib[i] = (fib[i - 1] + fib[i - 2]);
  }
  // returning size of fib array
  return i;
}

int main()
{
  int fib[10];
  int fib_len = make_fib(10, fib);

  int sum_fib = sum(fib_len, fib);

  return (sum_fib == 88) ? EXIT_SUCCESS : EXIT_FAILURE;
}
