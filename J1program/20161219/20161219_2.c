#include<stdio.h>
main(void)
{
  int a[3][10], b, c = 0;
    while(b < 3){
    c = 0;
    while(c < 10){
      a[b][c] = 0;
      c = c + 1;    
    }
    b = b + 1;    
  }
  while(b < 3){
    c = 0;
    while(c < 10){
      a[b][c] = 0;
      printf("a[%d][%d] = %d\n",b,c,a[b][c]);
      c = c + 1;  
    }
    b = b + 1;  
  }
}

