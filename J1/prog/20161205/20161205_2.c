#include<stdio.h>
main(void)
{
  int a[9], b=0, c[9];

  while(b<10){
    
    a[b] = 0;
    b = b + 1;
    
  }
  b = 0;
  while(b<10){

    c[b] = 0;
    printf("c[%d]=%d\n",b,c[b]);
    b = b + 1;
    
  }
}
