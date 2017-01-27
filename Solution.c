#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned a = 1664525;
unsigned c = 1013904223;
unsigned b = 1029349382;
unsigned TARGET = 0;

/*
unsigned next(unsigned x)
{
  return a * x*x + b * x + c ^ b % c*x;
}
*/

void push(unsigned res)
{
    printf("next(%u) == %u\n", res, TARGET);
}

unsigned F(unsigned x)
{
    // TARGET = next(X)
    // a = (b ^ X) - (c ^ X) || fixed a b c, variable x
    return TARGET ^ (a * x*x + b * x + c ^ b % c*x);
}

void recsolve(uint32_t x, uint32_t pbit)
{
    if(!pbit) { push(x); return; }
    void prune(z) { if(!(F(z) & pbit)) recsolve(z, pbit<<1); }
    prune(x); prune(x ^ pbit);
}

int main()
{
    TARGET = 2287831071;
    recsolve(0, 1);
    printf("done.\n");
    return 0;
}
