#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cycle.h"

#define N1 (1024)
#define N2 (1024)

int main(int argc, char **argv)
{
  ticks t0, t1, t2;

  size_t n1 = (argc > 1) ? atoi(argv[1]) : N1;
  size_t n2 = (argc > 2) ? atoi(argv[2]) : N2;
  size_t sz = n1 * n2, i;

  double *dst = malloc(sizeof(double) * sz);
  double *src = malloc(sizeof(double) * sz);

  for(i = 0; i < sz; ++i) src[i] = 3.14159;

  fputs("When copying an array of double, "
        "for-loop is ually 2 times faster than memcpy().\n", stdout);

  t0 = getticks();
  memcpy(dst, src, sizeof(double) * sz);
  t1 = getticks();
  for(i = 0; i < sz; ++i) dst[i] = src[i];
  t2 = getticks();

  printf("memcpy:   %12.0f\n", elapsed(t1, t0));
  printf("for loop: %12.0f\n", elapsed(t2, t1));

  free(dst);
  free(src);

  return 0;
}
