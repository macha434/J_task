#include <stdio.h>

int Exponentiation(int a, int n)
{
  int ex, b;

  ex = a;

  for (b= 0; b< n; b++){
    ex = ex* a;
  }

  return ex;
}

int main(void)
{
  int a, n, ans;

  printf("累乗したい数を入力してください。 :");
  scanf("%d",&a);
  printf("何乗しますか。 :");
  scanf("%d",&n);

  ans = Exponentiation(a,n);

  printf("答えは%dです。\n",ans/a);

  return 0;
}
