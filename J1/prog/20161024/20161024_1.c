#include<stdio.h>
main(void)

{
  int yoko = 1, n;
  
  printf("nの値を入力してください:");
  scanf("%d",&n);

  while (yoko <= n){
    printf("*");
    yoko = yoko + 1;
  }
  printf("\n");
}
