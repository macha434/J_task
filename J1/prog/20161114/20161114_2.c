#include<stdio.h>
#include"graph.h"

main(void)

{
  int x, y, r;
  
   printf("xの値を入力してください。:");
  scanf("%d",&x);

   printf("yの値を入力してください。:");
  scanf("%d",&y);

   printf("rの値を入力してください。:");
  scanf("%d",&r);

  initGraph();
  drawCircle(x,y,r,BLUE);

  waitButtonPress();
  closeGraph();
}