#include<stdio.h>
#include"graph.h"

main(void)

{
  int a, x, y;

   printf("aの値を入力してください。:");
  scanf("%d",&a);
  
  initGraph();

  if(a%2 == 0){
    drawCircle(320,200,100,BLUE);
  }
  
  else {
    fillCircle(320,200,100,BLUE);
  }

  waitButtonPress();
  closeGraph();
}
