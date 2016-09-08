#include "prime.h"
#include "boolean.h"

Bool is_prime(int n)
{
  int divisor;

  if (n <= 1)
    return FALSE;
  for (divisor = 2; divisor * divisor <= n; divisor++)
    if (n % divisor == 0)
      return FALSE;
  return TRUE;
}