#include <stdio.h>

int mul(void)
{
  int Num, ans= 0;

  for (Num= 1; Num<= 1000; Num++){

    if (Num% 9==0){

      ans= ans+ Num;
    }
  }

  return ans;
}

int main(void)
{
  int ans;

  ans= mul();

  printf("9の倍数の合計は%dです。\n", ans);

  return 0;
}