#include<stdio.h>
main(void)
  
{
  int tate = 1, n, yoko = 1, a;
  
  printf("nの値を入力してください:");
  scanf("%d",&n);

  printf("aの値を入力してください:");
  scanf("%d",&a);

  while (tate <= n){

    yoko = 1;
    
    while (yoko <= a){
	printf("*");
	yoko = yoko + 1;
    }
      printf("\n");
      tate = tate + 1;
  }
}
