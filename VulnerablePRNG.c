#include <stdio.h>

unsigned a = 1664525;
unsigned c = 1013904223;
unsigned b = 1029349382;

unsigned next(unsigned x)
{
  return a * x*x + b * x + c ^ b % c*x;
}

int main()
{
  int i;
  unsigned n = next(0);

  for (i = 0; i < 10; i++)
  {
    printf("%u\n", n);
    n = next(n);
  }

  return(0);
}
