#include <stdio.h>

int main(void)
{
  int i;
  int num;
  
  printf("Input your number = ");
  scanf("%d", &num);

  i = 0;
  while(i<=num) {
    printf("%d\n", i);
    i++;
  }
  
  return 0;
}
