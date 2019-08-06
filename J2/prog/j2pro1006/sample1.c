#include <stdio.h>

void calc_add_sub(int a, int b, int add, int sub)
{
  add = a + b;
  sub = a - b;
}

int main(void)
{
  int a, b;
  int add, sub;

  printf("a=");
  scanf("%d", &a);
  printf("b=");
  scanf("%d", &b);

  add = sub = 0;

  calc_add_sub(a, b, add, sub);

  printf("add=%d, sub=%d\n", add, sub);

  return 0;
}
