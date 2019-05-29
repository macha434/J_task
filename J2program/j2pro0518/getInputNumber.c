#include <stdio.h>

int getInputNumber(void)
{
  int num;

  printf("input number(1-3) = ");
  scanf("%d", &num);
  while(num<1 || 3<num) {
    printf("input number(1-3) = ");
    scanf("%d", &num);
  }

  return num;
}

int main(void)
{
  int num;
  
  num = getInputNumber();

  num = num * 100;

  printf("num=%d\n", num);

  return 0;
}

