#include <stdio.h>

int calc_sum(int m, int n)
{
  int total;

  total = m + n;

  return total;
}

int main(void)
{
  int a = 10;
  int b = 20;
  int y;
  
  y = calc_sum(a, b);

  printf("合計は%dです。\n",y);

  return 0;
}
