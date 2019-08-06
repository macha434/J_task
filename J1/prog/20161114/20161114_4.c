#include<stdio.h>
#include"graph.h"

main(void)

{
  int a = 1, r=10;
  
 
  initGraph();

  while(a<=10){
    r = 10;
    r = r * a;
    drawCircle(320,240,100-r,BLUE);
    a = a + 1;
  }
  waitButtonPress();
}
    
