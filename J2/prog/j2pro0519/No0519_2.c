#include <stdio.h>

double lb_(void)
{
  double Kg, lb;

  printf("何ポンドですか。 :");
  scanf("%lf", &lb);

  Kg = lb* 0.453592;

  return Kg;
}

int main(void)
{
  double Kg;

  Kg = lb_();

  printf("%fKgです。\n",Kg);

  return 0;

}