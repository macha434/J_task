#include<stdio.h>
#include"graph.h"
main(void)
{
  int i=0;

  initGraph();

  while(i<10){

    i=i+1;
    drawCircle(60*i+20,240,30,BLUE);

    i=i+1;
    drawCircle(60*i+20,240,30,RED);

    i=i+1;
    drawCircle(60*i+20,240,30,GREEN);
  }
  waitButtonPress();
}
