#include <stdio.h>

int main(void)
{
  int a, b = 0;

  for(a = 1; a <=1000; a++){

    if(a%2==0){
      printf("a＝%d\n",a);
      b = b + a;
      printf("b=%d\n",b);
    }

  }
  printf("bの最終値=%d\n",b);
  return 0;
}
