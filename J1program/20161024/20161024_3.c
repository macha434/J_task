#include<stdio.h>
main(void)
  
{
  int tate = 1, n, yoko = 1;
  
  printf("nの値を入力してください:");
  scanf("%d",&n);

  while (tate <= n){
    
    yoko = 1;
    
    while (yoko <= n){
	printf("*");
	yoko = yoko + 1;

    }
      printf("\n");
      tate = tate + 1;
  }
}
