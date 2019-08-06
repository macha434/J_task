#include <stdio.h>

int main(void)
{
  int adt;
  int *pt;

  adt = 1234;
  pt = &adt;

  printf("アドレス &adt = %p\n", &adt);
  printf("アドレス pt   = %p\n", pt);
  printf("値 adt = %d\n", adt);
  printf("値 *pt = %d\n", *pt);

  return 0;
}
