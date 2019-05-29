#include <stdio.h>

double yard_(void)
{
  double m;
  double yard;
  
  printf("何ヤードですか。 :");
  scanf("%lf", &yard);
  
  m = yard* 0.9144;

  return m;
}

int main(void)
{
  double m;

  m = yard_();

  printf("\n%fメートルです。\n", m);

  return 0;
}
