#include <stdio.h>

int main(void)
{
  int i = 0, num;

  printf("Input your number :");
  scanf("%d",&num);
  
  while(i<=num) {
    printf("i=%d: %d\n", i, i * 2);
    i++;
  }
  
  return 0;
}
