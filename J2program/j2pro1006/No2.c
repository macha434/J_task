#include <stdio.h>

int main(void)
{
  int a;
  int *x, *y;

  a = 7;
  x = &a;
  printf("*x= %d\n", *x);

  a = 8;
  y = x;
  printf("*y= %d\n", *y);

  *y = 3;
  printf(" a= %d\n", a);
  printf("*x= %d\n", *x);
  printf("*y= %d\n", *y);

  return 0;
}
