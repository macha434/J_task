#include<stdio.h>
#include<math.h>

int main(void)
{
  int i = 0, num, a;

  printf("Input your number :");
  scanf("%d",&num);

  while(i<=num){
    a = pow(2, i);
    printf("i=%d: %d\n",i,a);
    i++;
  }

  return 0;
}
