#include <stdio.h>

int main(void)
{
  char ca, cb, cc;
  int ia, ib, ic;
  double da, db, dc;

  char c1, c2;
  int i3;
  char c4;
  double d5;
  int i6, i7;

  printf("caのアドレスは%p\n", &ca);
  printf("cbのアドレスは%p\n", &cb);
  printf("ccのアドレスは%p\n", &cc);
  printf("\n");

  printf("iaのアドレスは%p\n", &ia);
  printf("ibのアドレスは%p\n", &ib);
  printf("icのアドレスは%p\n", &ic);
  printf("\n");

  printf("daのアドレスは%p\n", &da);
  printf("dbのアドレスは%p\n", &db);
  printf("dcのアドレスは%p\n", &dc);
  printf("\n");

  printf("c1のアドレスは%p\n", &c1);
  printf("c2のアドレスは%p\n", &c2);
  printf("i3のアドレスは%p\n", &i3);
  printf("c4のアドレスは%p\n", &c4);
  printf("d5のアドレスは%p\n", &d5);
  printf("i6のアドレスは%p\n", &i6);
  printf("i7のアドレスは%p\n", &i7);
  printf("\n");

  return 0;
}
