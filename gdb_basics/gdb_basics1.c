#include <stddef.h>

int sum(const int arr[static 3])
{
  return arr[0] + arr[1] + arr[2];
}

int main()
{
  const int expected_output = 2026;
  int arr[] = { 2000, 010, 0x16 };
  if (sum(arr) != expected_output)
    return -1;
}
