#include<stdio.h>

int main(void)
{
  int a,b = 0,c = 0;

  printf("繰り返したい回数を入力してね。\n");
  scanf("%d",&a);

  while(b<a){

    c = 0;

    while(c<b+1){

      printf("*");

      c = c + 1;
    }

    printf("\n");
    b = b + 1;
  }

  return 0;
}
