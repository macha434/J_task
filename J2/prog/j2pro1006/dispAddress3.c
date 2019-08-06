#include <stdio.h>

int main(void)
{
  int adt;
  int bdt;
  int *pt;

  adt = 1234;
  pt = &adt;
  bdt = *pt;

  printf("値 adt = %d\n", adt);
  printf("値 *pt = %d\n", *pt);
  printf("値 bdt = %d\n\n", bdt);

  adt = 555;
  printf("値 adt = %d\n", adt);
  printf("値 *pt = %d\n", *pt);
  printf("値 bdt = %d\n\n", bdt);

  *pt = 666;
  printf("値 adt = %d\n", adt);
  printf("値 *pt = %d\n", *pt);
  printf("値 bdt = %d\n\n", bdt);

  bdt = 777;
  printf("値 adt = %d\n", adt);
  printf("値 *pt = %d\n", *pt);
  printf("値 bdt = %d\n\n", bdt);

  return 0;
}
