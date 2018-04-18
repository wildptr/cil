#include "testharness.h"

/* This is the same as extinline2.c except
 * we build it with --oldstyleExternInline
 * and expect different behaviour. */
extern inline int f(void) { return 1; }

int g(void)
{
  return f();
}

int f(void) { return 2; }

int h(void)
{
  return f();
}


int main(void)
{
  if (g() != 1) E(1);
  if (h() != 2) E(1);
  SUCCESS;
}
