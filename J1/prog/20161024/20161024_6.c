#include<stdio.h>
main(void)
  
{
  int   t=1, y, a=1, b=0, c;

  printf("縦の値を入れてね:");
  scanf("%d",&y);

  printf("横の値を入れてね:");
  scanf("%d",&c);
  
  while(t <= y){
    
    a = 1;
    
    while (a <= c){

      b = 0;
      b = t * a;
      printf("%4d",b);
      a = a +1;
      
    }
    printf("\n");
    t = t + 1;
  }
}



