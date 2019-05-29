#include <stdio.h>

int calc_sum(int begin, int end)
{
  int ans;
  
  for (begin= begin; begin<= end; begin++){
    ans = ans+ begin;
  }
  return ans;
}

int main(void)
{
  int begin, end, ans;

  printf("初めの値を入力してください。 :");
  scanf("%d", &begin);

  printf("終りの値を入力してください。 :");
  scanf("%d", &end);

  ans = calc_sum(begin, end);

  printf("結果は%dです。\n", ans);

  return 0;
}
